#include "Game/Entities/ChappyBase.h"
#include "Game/EnemyAnimKeyEvent.h"
#include "Game/EnemyFunc.h"

namespace Game {
namespace ChappyBase {

/*
 * --INFO--
 * Address:	80116648
 * Size:	000150
 */
void ChappyBase::FSM::init(EnemyBase* base)
{
	create(CHAPPY_Count);

	registerState(new StateDead(CHAPPY_Dead));
	registerState(new StateTurn(CHAPPY_Turn));
	registerState(new StateWalk(CHAPPY_Walk));
	registerState(new StateAttack(CHAPPY_Attack));
	registerState(new StateFlick(CHAPPY_Flick));
	registerState(new StateTurnToHome(CHAPPY_TurnToHome));
	registerState(new StateGoHome(CHAPPY_GoHome));
	registerState(new StateSleep(CHAPPY_Sleep));
}

/*
 * --INFO--
 * Address:	........
 * Size:	000040
 */
StateCautionBase::StateCautionBase(int stateID)
    : State(stateID)
{
	mName = "StateCautionBase";
}

/*
 * --INFO--
 * Address:	........
 * Size:	000194
 */
void StateCautionBase::cautionProc(EnemyBase* enemy)
{
	bool doAlert;
	switch (enemy->getEnemyTypeID()) {
	case EnemyTypeID::EnemyID_BlueChappy: {
		f32 wakeRadius = CG_PROPERPARMS(OBJ(enemy)).mBulborbWakeRadius.mValue;
		doAlert        = EnemyFunc::isPikminOrNaviInRange(enemy, wakeRadius);

		if (!doAlert) {
			doAlert = enemy->mHealth < CG_PARMS(enemy)->mGeneral.mLifeBeforeAlert.mValue;
		}
		break;
	}

	default: {
		f32 wakeRadius = CG_PARMS(enemy)->mGeneral.mPrivateRadius.mValue;
		doAlert        = EnemyFunc::isPikminOrNaviInRange(enemy, wakeRadius);

		if (!doAlert) {
			doAlert = enemy->mHealth < CG_PARMS(enemy)->mGeneral.mLifeBeforeAlert.mValue;
		}
		break;
	}
	}

	if (doAlert) {
		OBJ(enemy)->_2CC = 0.0f;
	}

	if (OBJ(enemy)->_2CC < CG_PARMS(enemy)->mGeneral.mAlertDuration.mValue) {
		OBJ(enemy)->_2CC += sys->mDeltaTime;
		OBJ(enemy)->_2DC = 180.0f;
		OBJ(enemy)->_2E0 = 180.0f;

	} else {
		OBJ(enemy)->_2DC = CG_PARMS(enemy)->mGeneral.mViewAngle.mValue;
		OBJ(enemy)->_2E0 = CG_PARMS(enemy)->mGeneral.mSearchAngle.mValue;
	}
}

/*
 * --INFO--
 * Address:	80116798
 * Size:	00003C
 */
StateSleep::StateSleep(int stateID)
    : State(stateID)
{
	mName = "sleep";
}

/*
 * --INFO--
 * Address:	801167D4
 * Size:	0000BC
 */
void StateSleep::init(EnemyBase* enemy, StateArg* stateArg)
{
	SleepArg* arg = static_cast<SleepArg*>(stateArg);
	if (arg && arg->_00) {
		enemy->startMotion(4, nullptr);
		enemy->setMotionFrame(70.0f);
	} else {
		enemy->startMotion(6, nullptr);
	}

	enemy->mTargetCreature = nullptr;

	// Creeping Chrysanthemum
	if (enemy->getEnemyTypeID() == EnemyTypeID::EnemyID_Hana) {
		enemy->hardConstraintOn();
	} else {
		enemy->enableEvent(0, EB_Constraint);
	}

	OBJ(enemy)->setUnderGround();
}

/*
 * --INFO--
 * Address:	80116890
 * Size:	0001B0
 * 70%
 */
void StateSleep::exec(EnemyBase* enemy)
{
	if (enemy->getCurrAnimIndex() == 6) {
		if (enemy->mCurAnim->mIsPlaying && enemy->mCurAnim->mType == KEYEVENT_END) {
			if (enemy->isEvent(0, EB_IsTakingDamage)) {
				transit(enemy, CHAPPY_Turn, nullptr);
			} else {
				enemy->startMotion(4, nullptr);
			}
		}

	} else {
		if (!enemy->isFinishMotion() && OBJ(enemy)->isWakeup()) {
			setNextState(enemy, CHAPPY_Turn);
		}

		if (enemy->mCurAnim->mIsPlaying) {
			// WTF?
			if (enemy->mCurAnim->mType == KEYEVENT_NULL) {
				OBJ(enemy)->startSleepEffect();

			} else if (enemy->mCurAnim->mType == KEYEVENT_3) {
				OBJ(enemy)->finishSleepEffect();

			} else if (enemy->mCurAnim->mType == KEYEVENT_4) {
				OBJ(enemy)->createSmokeEffect();

			} else if (enemy->mCurAnim->mType == KEYEVENT_END) {
				transit(enemy, mNextState, nullptr);
			}
		}
	}

	if (enemy->mHealth <= 0.0f) {
		transit(enemy, CHAPPY_Dead, nullptr);
	}
}

/*
 * --INFO--
 * Address:	80116A40
 * Size:	000098
 */
void StateSleep::cleanup(EnemyBase* enemy)
{
	OBJ(enemy)->setAnimationSpeed(30.0f);

	if (enemy->getEnemyTypeID() == EnemyTypeID::EnemyID_Hana) {
		enemy->hardConstraintOff();
	} else {
		enemy->constraintOff();
	}

	OBJ(enemy)->resetUnderGround();
	OBJ(enemy)->finishSleepEffect();
}

/*
 * --INFO--
 * Address:	80116AD8
 * Size:	000064
 */
void StateSleep::setNextState(EnemyBase* enemy, int stateID)
{
	OBJ(enemy)->setAnimationSpeed(60.0f);
	enemy->finishMotion();
	mNextState = stateID;
}

/*
 * --INFO--
 * Address:	80116B3C
 * Size:	000054
 */
StateDead::StateDead(int stateID)
    : StateCautionBase(stateID)
{
	mName = "dead";
}

/*
 * --INFO--
 * Address:	80116B90
 * Size:	000040
 */
void StateDead::init(EnemyBase* enemy, StateArg* stateArg)
{
	enemy->startMotion(1, nullptr);
	enemy->deathProcedure();
}

/*
 * --INFO--
 * Address:	80116BD0
 * Size:	000064
 */
void StateDead::exec(EnemyBase* enemy)
{
	if (enemy->mCurAnim->mIsPlaying) {
		if (enemy->mCurAnim->mType == KEYEVENT_2) {
			OBJ(enemy)->flickAttackBomb();
		} else if (enemy->mCurAnim->mType == KEYEVENT_END) {
			enemy->kill(nullptr);
		}
	}
}

/*
 * --INFO--
 * Address:	80116C34
 * Size:	000004
 */
void StateDead::cleanup(EnemyBase* enemy) { }

/*
 * --INFO--
 * Address:	........
 * Size:	00004C
 */
StateTurnBase::StateTurnBase(int stateID)
    : StateCautionBase(stateID)
{
}

/*
 * --INFO--
 * Address:	........
 * Size:	0001E0
 */
void StateTurnBase::turnToTarget(EnemyBase* enemy, Vector3f& targetPos) { }

/*
 * --INFO--
 * Address:	80116C38
 * Size:	000060
 */
StateTurn::StateTurn(int stateID)
    : StateTurnBase(stateID)
{
	mName = "turn";
}

/*
 * --INFO--
 * Address:	80116C98
 * Size:	000058
 */
void StateTurn::init(EnemyBase* enemy, StateArg* stateArg)
{
	enemy->setEmotionExcitement();
	OBJ(enemy)->setAnimationSpeed(40.0f);
	enemy->startMotion(7, nullptr);
}

/*
 * --INFO--
 * Address:	80116CF0
 * Size:	0007F0
 */
void StateTurn::exec(EnemyBase* enemy)
{
	cautionProc(enemy);

	if (!enemy->isFinishMotion()) {
		Creature* target = EnemyFunc::getNearestPikminOrNavi(enemy, OBJ(enemy)->_2E0, CG_PARMS(enemy)->mGeneral.mSearchDistance.mValue,
		                                                     nullptr, nullptr, nullptr);
		if (target) {
			enemy->mTargetCreature = target;

			Vector3f targetPos = enemy->mTargetCreature->getPosition();

			f32 turnSpeed  = CG_PARMS(enemy)->mGeneral.mMaxTurnAngle.mValue;
			f32 turnFactor = CG_PARMS(enemy)->mGeneral.mTurnSpeed.mValue;

			Vector3f pos = enemy->getPosition();

			f32 angleDist = angDist(_angXZ(targetPos.x, targetPos.z, pos.x, pos.z), enemy->getFaceDir());

			bool check     = false;
			f32 radius     = CG_PARMS(enemy)->mGeneral.mMaxAttackRange.mValue;
			f32 angleLimit = CG_PARMS(enemy)->mGeneral.mMinAttackRange.mValue;

			f32 x = enemy->mTargetCreature->getPosition().x - enemy->getPosition().x;
			f32 y = enemy->mTargetCreature->getPosition().y - enemy->getPosition().y;
			f32 z = enemy->mTargetCreature->getPosition().z - enemy->getPosition().z;

			f32 sqrDist = SQUARE(x) + SQUARE(y) + SQUARE(z);
			if (sqrDist < SQUARE(radius) && FABS(angleDist) <= PI * (DEG2RAD * angleLimit)) {
				check = true;
			}

			if (check) {
				enemy->finishMotion();
				OBJ(enemy)->setAnimationSpeed(60.0f);
				_10 = CHAPPY_Attack;

			} else {
				Vector3f pos2       = Vector3f(enemy->mPosition.x, 0.0f, enemy->mPosition.z);
				Vector3f targetPos2 = Vector3f(enemy->mTargetCreature->getPosition().x, 0.0f, enemy->mTargetCreature->getPosition().z);
			}
		}
		if (EnemyFunc::isStartFlick(enemy, true)) {
			transit(enemy, CHAPPY_Flick, nullptr);
		}
	} else if (enemy->mCurAnim->mIsPlaying && enemy->mCurAnim->mType == KEYEVENT_END) {
		transit(enemy, _10, nullptr);
	}

	if (enemy->mHealth <= 0.0f) {
		transit(enemy, CHAPPY_Dead, nullptr);
	}
	/*
	stwu     r1, -0x190(r1)
	mflr     r0
	stw      r0, 0x194(r1)
	stfd     f31, 0x180(r1)
	psq_st   f31, 392(r1), 0, qr0
	stfd     f30, 0x170(r1)
	psq_st   f30, 376(r1), 0, qr0
	stfd     f29, 0x160(r1)
	psq_st   f29, 360(r1), 0, qr0
	stfd     f28, 0x150(r1)
	psq_st   f28, 344(r1), 0, qr0
	stfd     f27, 0x140(r1)
	psq_st   f27, 328(r1), 0, qr0
	stfd     f26, 0x130(r1)
	psq_st   f26, 312(r1), 0, qr0
	stfd     f25, 0x120(r1)
	psq_st   f25, 296(r1), 0, qr0
	stfd     f24, 0x110(r1)
	psq_st   f24, 280(r1), 0, qr0
	stw      r31, 0x10c(r1)
	stw      r30, 0x108(r1)
	stw      r29, 0x104(r1)
	stw      r28, 0x100(r1)
	mr       r31, r4
	mr       r30, r3
	mr       r3, r31
	lwz      r12, 0(r31)
	lwz      r12, 0x258(r12)
	mtctr    r12
	bctrl
	cmpwi    r3, 0x2a
	beq      lbl_80116D74
	b        lbl_80116DE4

lbl_80116D74:
	lwz      r5, 0xc0(r31)
	mr       r3, r31
	li       r4, 0
	lfs      f24, 0x870(r5)
	fmr      f1, f24
	bl
"isThereOlimar__Q24Game9EnemyFuncFPQ24Game8CreaturefP23Condition<Q24Game4Navi>"
	clrlwi.  r0, r3, 0x18
	beq      lbl_80116D9C
	li       r3, 1
	b        lbl_80116DC0

lbl_80116D9C:
	fmr      f1, f24
	mr       r3, r31
	li       r4, 0
	bl
"isTherePikmin__Q24Game9EnemyFuncFPQ24Game8CreaturefP23Condition<Q24Game4Piki>"
	clrlwi.  r0, r3, 0x18
	beq      lbl_80116DBC
	li       r3, 1
	b        lbl_80116DC0

lbl_80116DBC:
	li       r3, 0

lbl_80116DC0:
	clrlwi.  r0, r3, 0x18
	bne      lbl_80116E50
	lwz      r3, 0xc0(r31)
	lfs      f1, 0x200(r31)
	lfs      f0, 0x17c(r3)
	fcmpo    cr0, f1, f0
	mfcr     r0
	srwi     r3, r0, 0x1f
	b        lbl_80116E50

lbl_80116DE4:
	lwz      r5, 0xc0(r31)
	mr       r3, r31
	li       r4, 0
	lfs      f24, 0x3ac(r5)
	fmr      f1, f24
	bl
"isThereOlimar__Q24Game9EnemyFuncFPQ24Game8CreaturefP23Condition<Q24Game4Navi>"
	clrlwi.  r0, r3, 0x18
	beq      lbl_80116E0C
	li       r3, 1
	b        lbl_80116E30

lbl_80116E0C:
	fmr      f1, f24
	mr       r3, r31
	li       r4, 0
	bl
"isTherePikmin__Q24Game9EnemyFuncFPQ24Game8CreaturefP23Condition<Q24Game4Piki>"
	clrlwi.  r0, r3, 0x18
	beq      lbl_80116E2C
	li       r3, 1
	b        lbl_80116E30

lbl_80116E2C:
	li       r3, 0

lbl_80116E30:
	clrlwi.  r0, r3, 0x18
	bne      lbl_80116E50
	lwz      r3, 0xc0(r31)
	lfs      f1, 0x200(r31)
	lfs      f0, 0x17c(r3)
	fcmpo    cr0, f1, f0
	mfcr     r0
	srwi     r3, r0, 0x1f

lbl_80116E50:
	clrlwi.  r0, r3, 0x18
	beq      lbl_80116E60
	lfs      f0, lbl_80517AA0@sda21(r2)
	stfs     f0, 0x2cc(r31)

lbl_80116E60:
	lwz      r3, 0xc0(r31)
	lfs      f2, 0x2cc(r31)
	lfs      f0, 0x62c(r3)
	fcmpo    cr0, f2, f0
	bge      lbl_80116E94
	lwz      r3, sys@sda21(r13)
	lfs      f0, lbl_80517AA4@sda21(r2)
	lfs      f1, 0x54(r3)
	fadds    f1, f2, f1
	stfs     f1, 0x2cc(r31)
	stfs     f0, 0x2dc(r31)
	stfs     f0, 0x2e0(r31)
	b        lbl_80116EA8

lbl_80116E94:
	lfs      f0, 0x424(r3)
	stfs     f0, 0x2dc(r31)
	lwz      r3, 0xc0(r31)
	lfs      f0, 0x49c(r3)
	stfs     f0, 0x2e0(r31)

lbl_80116EA8:
	mr       r3, r31
	bl       isFinishMotion__Q24Game9EnemyBaseFv
	clrlwi.  r0, r3, 0x18
	bne      lbl_80117410
	lwz      r5, 0xc0(r31)
	mr       r3, r31
	lfs      f1, 0x2e0(r31)
	li       r4, 0
	lfs      f2, 0x44c(r5)
	li       r5, 0
	li       r6, 0
	bl
"getNearestPikminOrNavi__Q24Game9EnemyFuncFPQ24Game8CreatureffPfP23Condition<Q24Game4Navi>P23Condition<Q24Game4Piki>"
	cmplwi   r3, 0
	beq      lbl_801173C8
	stw      r3, 0x230(r31)
	addi     r3, r1, 0xc8
	lwz      r4, 0x230(r31)
	lwz      r12, 0(r4)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	mr       r4, r31
	lfs      f2, 0xc8(r1)
	lwz      r12, 0(r31)
	addi     r3, r1, 0xd4
	lfs      f1, 0xcc(r1)
	lfs      f0, 0xd0(r1)
	lwz      r12, 8(r12)
	stfs     f2, 0xb0(r1)
	stfs     f1, 0xb4(r1)
	stfs     f0, 0xb8(r1)
	mtctr    r12
	bctrl
	lfs      f5, 0xd4(r1)
	lis      r3, atanTable___5JMath@ha
	lfs      f3, 0xdc(r1)
	addi     r3, r3, atanTable___5JMath@l
	lfs      f1, 0xb0(r1)
	lfs      f0, 0xb8(r1)
	lfs      f4, 0xd8(r1)
	fsubs    f1, f1, f5
	fsubs    f2, f0, f3
	stfs     f5, 0xbc(r1)
	stfs     f4, 0xc0(r1)
	stfs     f3, 0xc4(r1)
	bl       "atan2___Q25JMath18TAtanTable<1024,f>CFff"
	bl       roundAng__Ff
	lwz      r12, 0(r31)
	fmr      f24, f1
	mr       r3, r31
	lwz      r12, 0x64(r12)
	mtctr    r12
	bctrl
	fmr      f2, f1
	fmr      f1, f24
	bl       angDist__Fff
	mr       r4, r31
	lwz      r5, 0xc0(r31)
	lwz      r12, 0(r31)
	fmr      f31, f1
	addi     r3, r1, 0x2c
	lfs      f28, 0x58c(r5)
	lwz      r12, 8(r12)
	li       r28, 0
	lfs      f30, 0x564(r5)
	lwz      r29, 0x230(r31)
	mtctr    r12
	bctrl
	mr       r4, r29
	addi     r3, r1, 0x20
	lwz      r12, 0(r29)
	lfs      f29, 0x2c(r1)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	mr       r4, r31
	lfs      f0, 0x20(r1)
	lwz      r12, 0(r31)
	addi     r3, r1, 0x44
	fsubs    f25, f0, f29
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	mr       r4, r29
	addi     r3, r1, 0x38
	lwz      r12, 0(r29)
	lfs      f29, 0x48(r1)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	mr       r4, r31
	lfs      f0, 0x3c(r1)
	lwz      r12, 0(r31)
	addi     r3, r1, 0x5c
	fsubs    f24, f0, f29
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	mr       r4, r29
	addi     r3, r1, 0x50
	lwz      r12, 0(r29)
	lfs      f29, 0x64(r1)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	fmuls    f1, f24, f24
	lfs      f2, 0x58(r1)
	fmuls    f0, f30, f30
	fsubs    f2, f2, f29
	fmadds   f1, f25, f25, f1
	fmadds   f1, f2, f2, f1
	fcmpo    cr0, f1, f0
	bge      lbl_80117094
	lfs      f0, lbl_80517AD4@sda21(r2)
	fabs     f2, f31
	lfs      f1, lbl_80517AD0@sda21(r2)
	fmuls    f0, f0, f28
	frsp     f2, f2
	fmuls    f0, f1, f0
	fcmpo    cr0, f2, f0
	cror     2, 0, 2
	bne      lbl_80117094
	li       r28, 1

lbl_80117094:
	clrlwi.  r0, r28, 0x18
	beq      lbl_801170C8
	mr       r3, r31
	bl       finishMotion__Q24Game9EnemyBaseFv
	mr       r3, r31
	lfs      f1, lbl_80517AB8@sda21(r2)
	lwz      r12, 0(r31)
	lwz      r12, 0x300(r12)
	mtctr    r12
	bctrl
	li       r0, 4
	stw      r0, 0x10(r30)
	b        lbl_801173D8

lbl_801170C8:
	mr       r4, r31
	lwz      r5, 0xc0(r31)
	lwz      r12, 0(r31)
	addi     r3, r1, 0x74
	lfs      f30, 0x2dc(r31)
	lwz      r12, 8(r12)
	lfs      f24, 0x3fc(r5)
	lfs      f25, 0x3d4(r5)
	lfs      f26, 0x3ac(r5)
	lwz      r28, 0x230(r31)
	mtctr    r12
	bctrl
	mr       r4, r28
	addi     r3, r1, 0x68
	lwz      r12, 0(r28)
	lfs      f29, 0x74(r1)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	mr       r4, r31
	lfs      f0, 0x68(r1)
	lwz      r12, 0(r31)
	addi     r3, r1, 0x8c
	fsubs    f27, f0, f29
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	mr       r4, r28
	addi     r3, r1, 0x80
	lwz      r12, 0(r28)
	lfs      f29, 0x90(r1)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	mr       r4, r31
	lfs      f0, 0x84(r1)
	lwz      r12, 0(r31)
	addi     r3, r1, 0xa4
	fsubs    f28, f0, f29
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	mr       r4, r28
	addi     r3, r1, 0x98
	lwz      r12, 0(r28)
	lfs      f29, 0xac(r1)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	lfs      f0, 0xa0(r1)
	fmuls    f26, f26, f26
	fmuls    f25, f25, f25
	li       r3, 1
	fsubs    f0, f0, f29
	li       r4, 0
	fmuls    f0, f0, f0
	fmadds   f0, f27, f27, f0
	fcmpo    cr0, f0, f26
	ble      lbl_801171E0
	fcmpo    cr0, f0, f25
	mr       r0, r4
	ble      lbl_801171D4
	fabs     f0, f28
	frsp     f0, f0
	fcmpo    cr0, f0, f24
	bge      lbl_801171D4
	mr       r0, r3

lbl_801171D4:
	clrlwi.  r0, r0, 0x18
	beq      lbl_801171E0
	li       r4, 1

lbl_801171E0:
	clrlwi.  r0, r4, 0x18
	bne      lbl_80117218
	lfs      f0, lbl_80517AD4@sda21(r2)
	fabs     f2, f31
	lfs      f1, lbl_80517AD0@sda21(r2)
	fmuls    f0, f0, f30
	frsp     f2, f2
	fmuls    f0, f1, f0
	fcmpo    cr0, f2, f0
	cror     2, 0, 2
	mfcr     r0
	rlwinm.  r0, r0, 3, 0x1f, 0x1f
	beq      lbl_80117218
	li       r3, 0

lbl_80117218:
	clrlwi.  r0, r3, 0x18
	beq      lbl_80117234
	li       r0, 5
	mr       r3, r31
	stw      r0, 0x10(r30)
	bl       finishMotion__Q24Game9EnemyBaseFv
	b        lbl_801173D8

lbl_80117234:
	lwz      r4, 0x230(r31)
	addi     r3, r1, 0xe0
	lwz      r12, 0(r4)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	lwz      r5, 0xc0(r31)
	mr       r3, r31
	lfs      f26, 0xe0(r1)
	li       r4, 0
	lfs      f27, 0xe8(r1)
	lfs      f1, 0x820(r5)
	bl
"getSurroundPikminNum__Q24Game9EnemyFuncFPQ24Game8CreaturefP23Condition<Q24Game4Piki>"
	cmpwi    r3, 0xa
	ble      lbl_80117274
	li       r3, 0xa

lbl_80117274:
	xoris    r3, r3, 0x8000
	lis      r0, 0x4330
	stw      r3, 0xf4(r1)
	mr       r4, r31
	lwz      r5, 0xc0(r31)
	addi     r3, r1, 0x14
	stw      r0, 0xf0(r1)
	lfd      f1, lbl_80517AD8@sda21(r2)
	lfd      f0, 0xf0(r1)
	lfs      f2, lbl_80517AC8@sda21(r2)
	fsubs    f0, f0, f1
	lwz      r12, 0(r31)
	lfs      f1, lbl_80517ACC@sda21(r2)
	lfs      f3, lbl_80517AC4@sda21(r2)
	fmuls    f2, f2, f0
	lfs      f0, 0x334(r5)
	lwz      r12, 8(r12)
	lfs      f31, 0x58c(r5)
	fdivs    f1, f2, f1
	lfs      f24, 0x30c(r5)
	fsubs    f1, f3, f1
	fmuls    f25, f1, f0
	mtctr    r12
	bctrl
	lfs      f4, 0x14(r1)
	lis      r3, atanTable___5JMath@ha
	lfs      f0, 0x1c(r1)
	addi     r3, r3, atanTable___5JMath@l
	lfs      f3, 0x18(r1)
	fsubs    f1, f26, f4
	fsubs    f2, f27, f0
	stfs     f4, 8(r1)
	stfs     f3, 0xc(r1)
	stfs     f0, 0x10(r1)
	bl       "atan2___Q25JMath18TAtanTable<1024,f>CFff"
	bl       roundAng__Ff
	lwz      r12, 0(r31)
	fmr      f26, f1
	mr       r3, r31
	lwz      r12, 0x64(r12)
	mtctr    r12
	bctrl
	fmr      f2, f1
	fmr      f1, f26
	bl       angDist__Fff
	fmr      f30, f1
	lfs      f0, lbl_80517AD4@sda21(r2)
	lfs      f1, lbl_80517AD0@sda21(r2)
	fmuls    f0, f0, f25
	fmuls    f24, f30, f24
	fmuls    f1, f1, f0
	fabs     f0, f24
	frsp     f0, f0
	fcmpo    cr0, f0, f1
	ble      lbl_80117368
	lfs      f0, lbl_80517AA0@sda21(r2)
	fcmpo    cr0, f24, f0
	ble      lbl_80117364
	fmr      f24, f1
	b        lbl_80117368

lbl_80117364:
	fneg     f24, f1

lbl_80117368:
	mr       r3, r31
	lwz      r12, 0(r31)
	lwz      r12, 0x64(r12)
	mtctr    r12
	bctrl
	fadds    f1, f24, f1
	bl       roundAng__Ff
	lfs      f0, lbl_80517AD4@sda21(r2)
	fabs     f2, f30
	stfs     f1, 0x1fc(r31)
	fmuls    f0, f0, f31
	lfs      f1, lbl_80517AD0@sda21(r2)
	lfs      f3, 0x1fc(r31)
	frsp     f2, f2
	fmuls    f0, f1, f0
	stfs     f3, 0x1a8(r31)
	fcmpo    cr0, f2, f0
	cror     2, 0, 2
	bne      lbl_801173D8
	li       r0, 3
	mr       r3, r31
	stw      r0, 0x10(r30)
	bl       finishMotion__Q24Game9EnemyBaseFv
	b        lbl_801173D8

lbl_801173C8:
	li       r0, 5
	mr       r3, r31
	stw      r0, 0x10(r30)
	bl       finishMotion__Q24Game9EnemyBaseFv

lbl_801173D8:
	mr       r3, r31
	li       r4, 1
	bl       isStartFlick__Q24Game9EnemyFuncFPQ24Game9EnemyBaseb
	clrlwi.  r0, r3, 0x18
	beq      lbl_8011744C
	mr       r3, r30
	mr       r4, r31
	lwz      r12, 0(r30)
	li       r5, 2
	li       r6, 0
	lwz      r12, 0x1c(r12)
	mtctr    r12
	bctrl
	b        lbl_8011744C

lbl_80117410:
	lwz      r3, 0x188(r31)
	lbz      r0, 0x24(r3)
	cmplwi   r0, 0
	beq      lbl_8011744C
	lwz      r0, 0x1c(r3)
	cmplwi   r0, 0x3e8
	bne      lbl_8011744C
	mr       r3, r30
	mr       r4, r31
	lwz      r12, 0(r30)
	li       r6, 0
	lwz      r5, 0x10(r30)
	lwz      r12, 0x1c(r12)
	mtctr    r12
	bctrl

lbl_8011744C:
	lfs      f1, 0x200(r31)
	lfs      f0, lbl_80517AA0@sda21(r2)
	fcmpo    cr0, f1, f0
	cror     2, 0, 2
	bne      lbl_80117480
	mr       r3, r30
	mr       r4, r31
	lwz      r12, 0(r30)
	li       r5, 1
	li       r6, 0
	lwz      r12, 0x1c(r12)
	mtctr    r12
	bctrl

lbl_80117480:
	psq_l    f31, 392(r1), 0, qr0
	lfd      f31, 0x180(r1)
	psq_l    f30, 376(r1), 0, qr0
	lfd      f30, 0x170(r1)
	psq_l    f29, 360(r1), 0, qr0
	lfd      f29, 0x160(r1)
	psq_l    f28, 344(r1), 0, qr0
	lfd      f28, 0x150(r1)
	psq_l    f27, 328(r1), 0, qr0
	lfd      f27, 0x140(r1)
	psq_l    f26, 312(r1), 0, qr0
	lfd      f26, 0x130(r1)
	psq_l    f25, 296(r1), 0, qr0
	lfd      f25, 0x120(r1)
	psq_l    f24, 280(r1), 0, qr0
	lfd      f24, 0x110(r1)
	lwz      r31, 0x10c(r1)
	lwz      r30, 0x108(r1)
	lwz      r29, 0x104(r1)
	lwz      r0, 0x194(r1)
	lwz      r28, 0x100(r1)
	mtlr     r0
	addi     r1, r1, 0x190
	blr
	*/
}

/*
 * --INFO--
 * Address:	801174E0
 * Size:	000038
 */
void ChappyBase::StateTurn::cleanup(EnemyBase* enemy)
{
	enemy->setEmotionCaution();
	enemy->resetAnimSpeed();
}

/*
 * --INFO--
 * Address:	80117518
 * Size:	000054
 */
StateWalk::StateWalk(int stateID)
    : StateCautionBase(stateID)
{
	mName = "Walk";
}

/*
 * --INFO--
 * Address:	8011756C
 * Size:	000058
 */
void StateWalk::init(EnemyBase* enemy, StateArg* stateArg)
{
	enemy->setEmotionExcitement();
	OBJ(enemy)->setAnimationSpeed(40.0f);
	enemy->startMotion(3, nullptr);
}

/*
 * --INFO--
 * Address:	801175C4
 * Size:	0007FC
 */
void StateWalk::exec(EnemyBase* enemy)
{
	cautionProc(enemy);
	/*
	stwu     r1, -0x170(r1)
	mflr     r0
	stw      r0, 0x174(r1)
	stfd     f31, 0x160(r1)
	psq_st   f31, 360(r1), 0, qr0
	stfd     f30, 0x150(r1)
	psq_st   f30, 344(r1), 0, qr0
	stfd     f29, 0x140(r1)
	psq_st   f29, 328(r1), 0, qr0
	stfd     f28, 0x130(r1)
	psq_st   f28, 312(r1), 0, qr0
	stfd     f27, 0x120(r1)
	psq_st   f27, 296(r1), 0, qr0
	stfd     f26, 0x110(r1)
	psq_st   f26, 280(r1), 0, qr0
	stfd     f25, 0x100(r1)
	psq_st   f25, 264(r1), 0, qr0
	stfd     f24, 0xf0(r1)
	psq_st   f24, 248(r1), 0, qr0
	stw      r31, 0xec(r1)
	stw      r30, 0xe8(r1)
	stw      r29, 0xe4(r1)
	stw      r28, 0xe0(r1)
	mr       r31, r4
	mr       r30, r3
	mr       r3, r31
	lwz      r12, 0(r31)
	lwz      r12, 0x258(r12)
	mtctr    r12
	bctrl
	cmpwi    r3, 0x2a
	beq      lbl_80117648
	b        lbl_801176B8

lbl_80117648:
	lwz      r5, 0xc0(r31)
	mr       r3, r31
	li       r4, 0
	lfs      f24, 0x870(r5)
	fmr      f1, f24
	bl
"isThereOlimar__Q24Game9EnemyFuncFPQ24Game8CreaturefP23Condition<Q24Game4Navi>"
	clrlwi.  r0, r3, 0x18
	beq      lbl_80117670
	li       r3, 1
	b        lbl_80117694

lbl_80117670:
	fmr      f1, f24
	mr       r3, r31
	li       r4, 0
	bl
"isTherePikmin__Q24Game9EnemyFuncFPQ24Game8CreaturefP23Condition<Q24Game4Piki>"
	clrlwi.  r0, r3, 0x18
	beq      lbl_80117690
	li       r3, 1
	b        lbl_80117694

lbl_80117690:
	li       r3, 0

lbl_80117694:
	clrlwi.  r0, r3, 0x18
	bne      lbl_80117724
	lwz      r3, 0xc0(r31)
	lfs      f1, 0x200(r31)
	lfs      f0, 0x17c(r3)
	fcmpo    cr0, f1, f0
	mfcr     r0
	srwi     r3, r0, 0x1f
	b        lbl_80117724

lbl_801176B8:
	lwz      r5, 0xc0(r31)
	mr       r3, r31
	li       r4, 0
	lfs      f24, 0x3ac(r5)
	fmr      f1, f24
	bl
"isThereOlimar__Q24Game9EnemyFuncFPQ24Game8CreaturefP23Condition<Q24Game4Navi>"
	clrlwi.  r0, r3, 0x18
	beq      lbl_801176E0
	li       r3, 1
	b        lbl_80117704

lbl_801176E0:
	fmr      f1, f24
	mr       r3, r31
	li       r4, 0
	bl
"isTherePikmin__Q24Game9EnemyFuncFPQ24Game8CreaturefP23Condition<Q24Game4Piki>"
	clrlwi.  r0, r3, 0x18
	beq      lbl_80117700
	li       r3, 1
	b        lbl_80117704

lbl_80117700:
	li       r3, 0

lbl_80117704:
	clrlwi.  r0, r3, 0x18
	bne      lbl_80117724
	lwz      r3, 0xc0(r31)
	lfs      f1, 0x200(r31)
	lfs      f0, 0x17c(r3)
	fcmpo    cr0, f1, f0
	mfcr     r0
	srwi     r3, r0, 0x1f

lbl_80117724:
	clrlwi.  r0, r3, 0x18
	beq      lbl_80117734
	lfs      f0, lbl_80517AA0@sda21(r2)
	stfs     f0, 0x2cc(r31)

lbl_80117734:
	lwz      r3, 0xc0(r31)
	lfs      f2, 0x2cc(r31)
	lfs      f0, 0x62c(r3)
	fcmpo    cr0, f2, f0
	bge      lbl_80117768
	lwz      r3, sys@sda21(r13)
	lfs      f0, lbl_80517AA4@sda21(r2)
	lfs      f1, 0x54(r3)
	fadds    f1, f2, f1
	stfs     f1, 0x2cc(r31)
	stfs     f0, 0x2dc(r31)
	stfs     f0, 0x2e0(r31)
	b        lbl_8011777C

lbl_80117768:
	lfs      f0, 0x424(r3)
	stfs     f0, 0x2dc(r31)
	lwz      r3, 0xc0(r31)
	lfs      f0, 0x49c(r3)
	stfs     f0, 0x2e0(r31)

lbl_8011777C:
	mr       r3, r31
	bl       isFinishMotion__Q24Game9EnemyBaseFv
	clrlwi.  r0, r3, 0x18
	bne      lbl_80117CF0
	lwz      r5, 0xc0(r31)
	mr       r3, r31
	lfs      f1, 0x2e0(r31)
	li       r4, 0
	lfs      f2, 0x44c(r5)
	li       r5, 0
	li       r6, 0
	bl
"getNearestPikminOrNavi__Q24Game9EnemyFuncFPQ24Game8CreatureffPfP23Condition<Q24Game4Navi>P23Condition<Q24Game4Piki>"
	cmplwi   r3, 0
	beq      lbl_80117BE8
	stw      r3, 0x230(r31)
	addi     r3, r1, 0xbc
	lwz      r4, 0x230(r31)
	lwz      r12, 0(r4)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	mr       r4, r31
	lfs      f2, 0xbc(r1)
	lwz      r12, 0(r31)
	addi     r3, r1, 0xc8
	lfs      f1, 0xc0(r1)
	lfs      f0, 0xc4(r1)
	lwz      r12, 8(r12)
	stfs     f2, 0xa4(r1)
	stfs     f1, 0xa8(r1)
	stfs     f0, 0xac(r1)
	mtctr    r12
	bctrl
	lfs      f5, 0xc8(r1)
	lis      r3, atanTable___5JMath@ha
	lfs      f3, 0xd0(r1)
	addi     r3, r3, atanTable___5JMath@l
	lfs      f1, 0xa4(r1)
	lfs      f0, 0xac(r1)
	lfs      f4, 0xcc(r1)
	fsubs    f1, f1, f5
	fsubs    f2, f0, f3
	stfs     f5, 0xb0(r1)
	stfs     f4, 0xb4(r1)
	stfs     f3, 0xb8(r1)
	bl       "atan2___Q25JMath18TAtanTable<1024,f>CFff"
	bl       roundAng__Ff
	lwz      r12, 0(r31)
	fmr      f24, f1
	mr       r3, r31
	lwz      r12, 0x64(r12)
	mtctr    r12
	bctrl
	fmr      f2, f1
	fmr      f1, f24
	bl       angDist__Fff
	mr       r4, r31
	lwz      r5, 0xc0(r31)
	lwz      r12, 0(r31)
	fmr      f31, f1
	addi     r3, r1, 0x14
	lfs      f28, 0x58c(r5)
	lwz      r12, 8(r12)
	li       r28, 0
	lfs      f30, 0x564(r5)
	lwz      r29, 0x230(r31)
	mtctr    r12
	bctrl
	mr       r4, r29
	addi     r3, r1, 8
	lwz      r12, 0(r29)
	lfs      f29, 0x14(r1)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	mr       r4, r31
	lfs      f0, 8(r1)
	lwz      r12, 0(r31)
	addi     r3, r1, 0x2c
	fsubs    f25, f0, f29
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	mr       r4, r29
	addi     r3, r1, 0x20
	lwz      r12, 0(r29)
	lfs      f29, 0x30(r1)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	mr       r4, r31
	lfs      f0, 0x24(r1)
	lwz      r12, 0(r31)
	addi     r3, r1, 0x44
	fsubs    f24, f0, f29
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	mr       r4, r29
	addi     r3, r1, 0x38
	lwz      r12, 0(r29)
	lfs      f29, 0x4c(r1)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	fmuls    f1, f24, f24
	lfs      f2, 0x40(r1)
	fmuls    f0, f30, f30
	fsubs    f2, f2, f29
	fmadds   f1, f25, f25, f1
	fmadds   f1, f2, f2, f1
	fcmpo    cr0, f1, f0
	bge      lbl_80117968
	lfs      f0, lbl_80517AD4@sda21(r2)
	fabs     f2, f31
	lfs      f1, lbl_80517AD0@sda21(r2)
	fmuls    f0, f0, f28
	frsp     f2, f2
	fmuls    f0, f1, f0
	fcmpo    cr0, f2, f0
	cror     2, 0, 2
	bne      lbl_80117968
	li       r28, 1

lbl_80117968:
	clrlwi.  r0, r28, 0x18
	beq      lbl_801179B8
	li       r0, 4
	mr       r3, r31
	stw      r0, 0x10(r30)
	bl       finishMotion__Q24Game9EnemyBaseFv
	lfs      f0, lbl_80517AA0@sda21(r2)
	stfs     f0, 0x1d4(r31)
	stfs     f0, 0x1d8(r31)
	stfs     f0, 0x1dc(r31)
	lwz      r0, 0x10(r30)
	cmpwi    r0, 4
	bne      lbl_80117BF8
	mr       r3, r31
	lfs      f1, lbl_80517AB8@sda21(r2)
	lwz      r12, 0(r31)
	lwz      r12, 0x300(r12)
	mtctr    r12
	bctrl
	b        lbl_80117BF8

lbl_801179B8:
	mr       r4, r31
	lwz      r5, 0xc0(r31)
	lwz      r12, 0(r31)
	addi     r3, r1, 0x68
	lfs      f30, 0x2dc(r31)
	lwz      r12, 8(r12)
	lfs      f24, 0x3fc(r5)
	lfs      f25, 0x3d4(r5)
	lfs      f26, 0x3ac(r5)
	lwz      r28, 0x230(r31)
	mtctr    r12
	bctrl
	mr       r4, r28
	addi     r3, r1, 0x5c
	lwz      r12, 0(r28)
	lfs      f29, 0x68(r1)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	mr       r4, r31
	lfs      f0, 0x5c(r1)
	lwz      r12, 0(r31)
	addi     r3, r1, 0x80
	fsubs    f27, f0, f29
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	mr       r4, r28
	addi     r3, r1, 0x74
	lwz      r12, 0(r28)
	lfs      f29, 0x84(r1)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	mr       r4, r31
	lfs      f0, 0x78(r1)
	lwz      r12, 0(r31)
	addi     r3, r1, 0x98
	fsubs    f28, f0, f29
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	mr       r4, r28
	addi     r3, r1, 0x8c
	lwz      r12, 0(r28)
	lfs      f29, 0xa0(r1)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	lfs      f0, 0x94(r1)
	fmuls    f26, f26, f26
	fmuls    f25, f25, f25
	li       r3, 1
	fsubs    f0, f0, f29
	li       r4, 0
	fmuls    f0, f0, f0
	fmadds   f0, f27, f27, f0
	fcmpo    cr0, f0, f26
	ble      lbl_80117AD0
	fcmpo    cr0, f0, f25
	mr       r0, r4
	ble      lbl_80117AC4
	fabs     f0, f28
	frsp     f0, f0
	fcmpo    cr0, f0, f24
	bge      lbl_80117AC4
	mr       r0, r3

lbl_80117AC4:
	clrlwi.  r0, r0, 0x18
	beq      lbl_80117AD0
	li       r4, 1

lbl_80117AD0:
	clrlwi.  r0, r4, 0x18
	bne      lbl_80117B08
	lfs      f0, lbl_80517AD4@sda21(r2)
	fabs     f2, f31
	lfs      f1, lbl_80517AD0@sda21(r2)
	fmuls    f0, f0, f30
	frsp     f2, f2
	fmuls    f0, f1, f0
	fcmpo    cr0, f2, f0
	cror     2, 0, 2
	mfcr     r0
	rlwinm.  r0, r0, 3, 0x1f, 0x1f
	beq      lbl_80117B08
	li       r3, 0

lbl_80117B08:
	clrlwi.  r0, r3, 0x18
	beq      lbl_80117B58
	li       r0, 5
	mr       r3, r31
	stw      r0, 0x10(r30)
	bl       finishMotion__Q24Game9EnemyBaseFv
	lfs      f0, lbl_80517AA0@sda21(r2)
	stfs     f0, 0x1d4(r31)
	stfs     f0, 0x1d8(r31)
	stfs     f0, 0x1dc(r31)
	lwz      r0, 0x10(r30)
	cmpwi    r0, 4
	bne      lbl_80117BF8
	mr       r3, r31
	lfs      f1, lbl_80517AB8@sda21(r2)
	lwz      r12, 0(r31)
	lwz      r12, 0x300(r12)
	mtctr    r12
	bctrl
	b        lbl_80117BF8

lbl_80117B58:
	lwz      r5, 0xc0(r31)
	fabs     f2, f31
	lfs      f0, lbl_80517AD4@sda21(r2)
	lfs      f3, 0x424(r5)
	lfs      f1, lbl_80517AD0@sda21(r2)
	frsp     f2, f2
	fmuls    f0, f0, f3
	fmuls    f0, f1, f0
	fcmpo    cr0, f2, f0
	cror     2, 0, 2
	bne      lbl_80117BA0
	lwz      r4, 0x230(r31)
	mr       r3, r31
	lfs      f1, 0x2e4(r5)
	lfs      f2, 0x30c(r5)
	lfs      f3, 0x334(r5)
	bl walkToTarget__Q24Game9EnemyFuncFPQ24Game9EnemyBasePQ24Game8Creaturefff b
lbl_80117BF8

lbl_80117BA0:
	li       r0, 0
	mr       r3, r31
	stw      r0, 0x10(r30)
	bl       finishMotion__Q24Game9EnemyBaseFv
	lfs      f0, lbl_80517AA0@sda21(r2)
	stfs     f0, 0x1d4(r31)
	stfs     f0, 0x1d8(r31)
	stfs     f0, 0x1dc(r31)
	lwz      r0, 0x10(r30)
	cmpwi    r0, 4
	bne      lbl_80117BF8
	mr       r3, r31
	lfs      f1, lbl_80517AB8@sda21(r2)
	lwz      r12, 0(r31)
	lwz      r12, 0x300(r12)
	mtctr    r12
	bctrl
	b        lbl_80117BF8

lbl_80117BE8:
	li       r0, 5
	mr       r3, r31
	stw      r0, 0x10(r30)
	bl       finishMotion__Q24Game9EnemyBaseFv

lbl_80117BF8:
	mr       r4, r31
	addi     r3, r1, 0x50
	lwz      r12, 0(r31)
	lfs      f24, 0x198(r31)
	lwz      r12, 8(r12)
	lfs      f25, 0x19c(r31)
	lfs      f26, 0x1a0(r31)
	mtctr    r12
	bctrl
	lfs      f0, 0x54(r1)
	lfs      f2, 0x50(r1)
	fsubs    f3, f0, f25
	lfs      f1, 0x58(r1)
	fsubs    f2, f2, f24
	lfs      f0, lbl_80517AA0@sda21(r2)
	fsubs    f1, f1, f26
	fmuls    f3, f3, f3
	fmuls    f4, f1, f1
	fmadds   f1, f2, f2, f3
	fadds    f1, f4, f1
	fcmpo    cr0, f1, f0
	ble      lbl_80117C60
	ble      lbl_80117C64
	frsqrte  f0, f1
	fmuls    f1, f0, f1
	b        lbl_80117C64

lbl_80117C60:
	fmr      f1, f0

lbl_80117C64:
	lwz      r3, 0xc0(r31)
	lfs      f0, 0x35c(r3)
	fcmpo    cr0, f1, f0
	ble      lbl_80117CB8
	li       r0, 5
	mr       r3, r31
	stw      r0, 0x10(r30)
	bl       finishMotion__Q24Game9EnemyBaseFv
	lfs      f0, lbl_80517AA0@sda21(r2)
	stfs     f0, 0x1d4(r31)
	stfs     f0, 0x1d8(r31)
	stfs     f0, 0x1dc(r31)
	lwz      r0, 0x10(r30)
	cmpwi    r0, 4
	bne      lbl_80117CB8
	mr       r3, r31
	lfs      f1, lbl_80517AB8@sda21(r2)
	lwz      r12, 0(r31)
	lwz      r12, 0x300(r12)
	mtctr    r12
	bctrl

lbl_80117CB8:
	mr       r3, r31
	li       r4, 1
	bl       isStartFlick__Q24Game9EnemyFuncFPQ24Game9EnemyBaseb
	clrlwi.  r0, r3, 0x18
	beq      lbl_80117D2C
	mr       r3, r30
	mr       r4, r31
	lwz      r12, 0(r30)
	li       r5, 2
	li       r6, 0
	lwz      r12, 0x1c(r12)
	mtctr    r12
	bctrl
	b        lbl_80117D2C

lbl_80117CF0:
	lwz      r3, 0x188(r31)
	lbz      r0, 0x24(r3)
	cmplwi   r0, 0
	beq      lbl_80117D2C
	lwz      r0, 0x1c(r3)
	cmplwi   r0, 0x3e8
	bne      lbl_80117D2C
	mr       r3, r30
	mr       r4, r31
	lwz      r12, 0(r30)
	li       r6, 0
	lwz      r5, 0x10(r30)
	lwz      r12, 0x1c(r12)
	mtctr    r12
	bctrl

lbl_80117D2C:
	lfs      f1, 0x200(r31)
	lfs      f0, lbl_80517AA0@sda21(r2)
	fcmpo    cr0, f1, f0
	cror     2, 0, 2
	bne      lbl_80117D60
	mr       r3, r30
	mr       r4, r31
	lwz      r12, 0(r30)
	li       r5, 1
	li       r6, 0
	lwz      r12, 0x1c(r12)
	mtctr    r12
	bctrl

lbl_80117D60:
	psq_l    f31, 360(r1), 0, qr0
	lfd      f31, 0x160(r1)
	psq_l    f30, 344(r1), 0, qr0
	lfd      f30, 0x150(r1)
	psq_l    f29, 328(r1), 0, qr0
	lfd      f29, 0x140(r1)
	psq_l    f28, 312(r1), 0, qr0
	lfd      f28, 0x130(r1)
	psq_l    f27, 296(r1), 0, qr0
	lfd      f27, 0x120(r1)
	psq_l    f26, 280(r1), 0, qr0
	lfd      f26, 0x110(r1)
	psq_l    f25, 264(r1), 0, qr0
	lfd      f25, 0x100(r1)
	psq_l    f24, 248(r1), 0, qr0
	lfd      f24, 0xf0(r1)
	lwz      r31, 0xec(r1)
	lwz      r30, 0xe8(r1)
	lwz      r29, 0xe4(r1)
	lwz      r0, 0x174(r1)
	lwz      r28, 0xe0(r1)
	mtlr     r0
	addi     r1, r1, 0x170
	blr
	*/
}

/*
 * --INFO--
 * Address:	80117DC0
 * Size:	000048
 */
void StateWalk::cleanup(EnemyBase* enemy)
{
	enemy->setEmotionCaution();
	enemy->resetAnimSpeed();
	enemy->mTargetVelocity = Vector3f(0.0f);
}

/*
 * --INFO--
 * Address:	80117E08
 * Size:	000054
 */
StateAttack::StateAttack(int stateID)
    : StateCautionBase(stateID)
{
	mName = "Attack";
}

/*
 * --INFO--
 * Address:	80117E5C
 * Size:	000048
 */
void StateAttack::init(EnemyBase* enemy, StateArg* stateArg)
{
	enemy->setEmotionExcitement();
	enemy->startMotion(0, nullptr);
	enemy->resetAnimSpeed();
}

/*
 * --INFO--
 * Address:	80117EA4
 * Size:	00033C
 */
void StateAttack::exec(EnemyBase* enemy)
{
	cautionProc(enemy);
	/*
	stwu     r1, -0x30(r1)
	mflr     r0
	stw      r0, 0x34(r1)
	stfd     f31, 0x20(r1)
	psq_st   f31, 40(r1), 0, qr0
	stw      r31, 0x1c(r1)
	stw      r30, 0x18(r1)
	stw      r29, 0x14(r1)
	mr       r31, r4
	mr       r30, r3
	mr       r3, r31
	lwz      r12, 0(r31)
	lwz      r12, 0x258(r12)
	mtctr    r12
	bctrl
	cmpwi    r3, 0x2a
	beq      lbl_80117EEC
	b        lbl_80117F5C

lbl_80117EEC:
	lwz      r5, 0xc0(r31)
	mr       r3, r31
	li       r4, 0
	lfs      f31, 0x870(r5)
	fmr      f1, f31
	bl
"isThereOlimar__Q24Game9EnemyFuncFPQ24Game8CreaturefP23Condition<Q24Game4Navi>"
	clrlwi.  r0, r3, 0x18
	beq      lbl_80117F14
	li       r3, 1
	b        lbl_80117F38

lbl_80117F14:
	fmr      f1, f31
	mr       r3, r31
	li       r4, 0
	bl
"isTherePikmin__Q24Game9EnemyFuncFPQ24Game8CreaturefP23Condition<Q24Game4Piki>"
	clrlwi.  r0, r3, 0x18
	beq      lbl_80117F34
	li       r3, 1
	b        lbl_80117F38

lbl_80117F34:
	li       r3, 0

lbl_80117F38:
	clrlwi.  r0, r3, 0x18
	bne      lbl_80117FC8
	lwz      r3, 0xc0(r31)
	lfs      f1, 0x200(r31)
	lfs      f0, 0x17c(r3)
	fcmpo    cr0, f1, f0
	mfcr     r0
	srwi     r3, r0, 0x1f
	b        lbl_80117FC8

lbl_80117F5C:
	lwz      r5, 0xc0(r31)
	mr       r3, r31
	li       r4, 0
	lfs      f31, 0x3ac(r5)
	fmr      f1, f31
	bl
"isThereOlimar__Q24Game9EnemyFuncFPQ24Game8CreaturefP23Condition<Q24Game4Navi>"
	clrlwi.  r0, r3, 0x18
	beq      lbl_80117F84
	li       r3, 1
	b        lbl_80117FA8

lbl_80117F84:
	fmr      f1, f31
	mr       r3, r31
	li       r4, 0
	bl
"isTherePikmin__Q24Game9EnemyFuncFPQ24Game8CreaturefP23Condition<Q24Game4Piki>"
	clrlwi.  r0, r3, 0x18
	beq      lbl_80117FA4
	li       r3, 1
	b        lbl_80117FA8

lbl_80117FA4:
	li       r3, 0

lbl_80117FA8:
	clrlwi.  r0, r3, 0x18
	bne      lbl_80117FC8
	lwz      r3, 0xc0(r31)
	lfs      f1, 0x200(r31)
	lfs      f0, 0x17c(r3)
	fcmpo    cr0, f1, f0
	mfcr     r0
	srwi     r3, r0, 0x1f

lbl_80117FC8:
	clrlwi.  r0, r3, 0x18
	beq      lbl_80117FD8
	lfs      f0, lbl_80517AA0@sda21(r2)
	stfs     f0, 0x2cc(r31)

lbl_80117FD8:
	lwz      r3, 0xc0(r31)
	lfs      f2, 0x2cc(r31)
	lfs      f0, 0x62c(r3)
	fcmpo    cr0, f2, f0
	bge      lbl_8011800C
	lwz      r3, sys@sda21(r13)
	lfs      f0, lbl_80517AA4@sda21(r2)
	lfs      f1, 0x54(r3)
	fadds    f1, f2, f1
	stfs     f1, 0x2cc(r31)
	stfs     f0, 0x2dc(r31)
	stfs     f0, 0x2e0(r31)
	b        lbl_80118020

lbl_8011800C:
	lfs      f0, 0x424(r3)
	stfs     f0, 0x2dc(r31)
	lwz      r3, 0xc0(r31)
	lfs      f0, 0x49c(r3)
	stfs     f0, 0x2e0(r31)

lbl_80118020:
	lwz      r3, 0x188(r31)
	lbz      r0, 0x24(r3)
	cmplwi   r0, 0
	beq      lbl_80118188
	mr       r3, r31
	bl       getCurrAnimIndex__Q24Game9EnemyBaseFv
	cmpwi    r3, 8
	beq      lbl_80118110
	bge      lbl_8011817C
	cmpwi    r3, 0
	beq      lbl_80118050
	b        lbl_8011817C

lbl_80118050:
	lwz      r3, 0x188(r31)
	lwz      r0, 0x1c(r3)
	cmpwi    r0, 4
	beq      lbl_80118100
	bge      lbl_80118074
	cmpwi    r0, 2
	beq      lbl_80118080
	bge      lbl_801180E8
	b        lbl_80118188

lbl_80118074:
	cmpwi    r0, 0x3e8
	beq      lbl_80118100
	b        lbl_80118188

lbl_80118080:
	lwz      r6, 0xc0(r31)
	mr       r3, r31
	li       r4, 0
	li       r5, 0
	lfs      f1, 0x5b4(r6)
	lfs      f2, 0x5dc(r6)
	lfs      f3, 0x604(r6)
	bl
"attackNavi__Q24Game9EnemyFuncFPQ24Game8CreaturefffP8CollPartP23Condition<Q24Game4Navi>"
	mr       r29, r3
	mr       r3, r31
	lwz      r12, 0(r31)
	lwz      r12, 0x310(r12)
	mtctr    r12
	bctrl
	add.     r29, r29, r3
	bne      lbl_801180D0
	mr       r3, r31
	li       r4, 8
	li       r5, 0
	bl       startMotion__Q24Game9EnemyBaseFiPQ28SysShape14MotionListener

lbl_801180D0:
	mr       r3, r31
	lwz      r12, 0(r31)
	lwz      r12, 0x304(r12)
	mtctr    r12
	bctrl
	b        lbl_80118188

lbl_801180E8:
	lwz      r5, 0xc0(r31)
	mr       r3, r31
	li       r4, 0
	lfs      f1, 0x848(r5)
	bl
"swallowPikmin__Q24Game9EnemyFuncFPQ24Game8CreaturefP23Condition<Q24Game4Piki>"
	b        lbl_80118188

lbl_80118100:
	mr       r3, r30
	mr       r4, r31
	bl       transitState__Q34Game10ChappyBase11StateAttackFPQ24Game9EnemyBase
	b        lbl_80118188

lbl_80118110:
	lwz      r3, 0x188(r31)
	lwz      r0, 0x1c(r3)
	cmpwi    r0, 3
	beq      lbl_80118154
	bge      lbl_80118130
	cmpwi    r0, 2
	bge      lbl_8011813C
	b        lbl_80118188

lbl_80118130:
	cmpwi    r0, 0x3e8
	beq      lbl_8011816C
	b        lbl_80118188

lbl_8011813C:
	mr       r3, r31
	lwz      r12, 0(r31)
	lwz      r12, 0x30c(r12)
	mtctr    r12
	bctrl
	b        lbl_80118188

lbl_80118154:
	mr       r3, r31
	lwz      r12, 0(r31)
	lwz      r12, 0x330(r12)
	mtctr    r12
	bctrl
	b        lbl_80118188

lbl_8011816C:
	mr       r3, r30
	mr       r4, r31
	bl       transitState__Q34Game10ChappyBase11StateAttackFPQ24Game9EnemyBase
	b        lbl_80118188

lbl_8011817C:
	mr       r3, r30
	mr       r4, r31
	bl       transitState__Q34Game10ChappyBase11StateAttackFPQ24Game9EnemyBase

lbl_80118188:
	lfs      f1, 0x200(r31)
	lfs      f0, lbl_80517AA0@sda21(r2)
	fcmpo    cr0, f1, f0
	cror     2, 0, 2
	bne      lbl_801181BC
	mr       r3, r30
	mr       r4, r31
	lwz      r12, 0(r30)
	li       r5, 1
	li       r6, 0
	lwz      r12, 0x1c(r12)
	mtctr    r12
	bctrl

lbl_801181BC:
	psq_l    f31, 40(r1), 0, qr0
	lwz      r0, 0x34(r1)
	lfd      f31, 0x20(r1)
	lwz      r31, 0x1c(r1)
	lwz      r30, 0x18(r1)
	lwz      r29, 0x14(r1)
	mtlr     r0
	addi     r1, r1, 0x30
	blr
	*/
}

/*
 * --INFO--
 * Address:	801181E0
 * Size:	0002F0
 */
void StateAttack::transitState(EnemyBase* enemy)
{
	/*
	stwu     r1, -0xf0(r1)
	mflr     r0
	stw      r0, 0xf4(r1)
	stfd     f31, 0xe0(r1)
	psq_st   f31, 232(r1), 0, qr0
	stfd     f30, 0xd0(r1)
	psq_st   f30, 216(r1), 0, qr0
	stfd     f29, 0xc0(r1)
	psq_st   f29, 200(r1), 0, qr0
	stfd     f28, 0xb0(r1)
	psq_st   f28, 184(r1), 0, qr0
	stfd     f27, 0xa0(r1)
	psq_st   f27, 168(r1), 0, qr0
	stfd     f26, 0x90(r1)
	psq_st   f26, 152(r1), 0, qr0
	stw      r31, 0x8c(r1)
	stw      r30, 0x88(r1)
	stw      r29, 0x84(r1)
	stw      r28, 0x80(r1)
	mr       r29, r4
	mr       r28, r3
	lwz      r5, 0xc0(r4)
	mr       r3, r29
	lfs      f1, 0x2e0(r4)
	li       r4, 0
	lfs      f2, 0x44c(r5)
	li       r5, 0
	li       r6, 0
	bl
"getNearestPikminOrNavi__Q24Game9EnemyFuncFPQ24Game8CreatureffPfP23Condition<Q24Game4Navi>P23Condition<Q24Game4Piki>"
	cmplwi   r3, 0
	beq      lbl_80118460
	stw      r3, 0x230(r29)
	addi     r3, r1, 0x68
	lwz      r4, 0x230(r29)
	lwz      r12, 0(r4)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	mr       r4, r29
	lfs      f2, 0x68(r1)
	lwz      r12, 0(r29)
	addi     r3, r1, 0x74
	lfs      f1, 0x6c(r1)
	lfs      f0, 0x70(r1)
	lwz      r12, 8(r12)
	stfs     f2, 0x50(r1)
	stfs     f1, 0x54(r1)
	stfs     f0, 0x58(r1)
	mtctr    r12
	bctrl
	lfs      f5, 0x74(r1)
	lis      r3, atanTable___5JMath@ha
	lfs      f3, 0x7c(r1)
	addi     r3, r3, atanTable___5JMath@l
	lfs      f1, 0x50(r1)
	lfs      f0, 0x58(r1)
	lfs      f4, 0x78(r1)
	fsubs    f1, f1, f5
	fsubs    f2, f0, f3
	stfs     f5, 0x5c(r1)
	stfs     f4, 0x60(r1)
	stfs     f3, 0x64(r1)
	bl       "atan2___Q25JMath18TAtanTable<1024,f>CFff"
	bl       roundAng__Ff
	lwz      r12, 0(r29)
	fmr      f26, f1
	mr       r3, r29
	lwz      r12, 0x64(r12)
	mtctr    r12
	bctrl
	fmr      f2, f1
	fmr      f1, f26
	bl       angDist__Fff
	mr       r4, r29
	lwz      r5, 0xc0(r29)
	lwz      r12, 0(r29)
	fmr      f30, f1
	addi     r3, r1, 0x14
	lfs      f28, 0x58c(r5)
	lwz      r12, 8(r12)
	li       r30, 0
	lfs      f29, 0x564(r5)
	lwz      r31, 0x230(r29)
	mtctr    r12
	bctrl
	mr       r4, r31
	addi     r3, r1, 8
	lwz      r12, 0(r31)
	lfs      f31, 0x14(r1)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	mr       r4, r29
	lfs      f0, 8(r1)
	lwz      r12, 0(r29)
	addi     r3, r1, 0x2c
	fsubs    f26, f0, f31
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	mr       r4, r31
	addi     r3, r1, 0x20
	lwz      r12, 0(r31)
	lfs      f31, 0x30(r1)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	mr       r4, r29
	lfs      f0, 0x24(r1)
	lwz      r12, 0(r29)
	addi     r3, r1, 0x44
	fsubs    f27, f0, f31
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	mr       r4, r31
	addi     r3, r1, 0x38
	lwz      r12, 0(r31)
	lfs      f31, 0x4c(r1)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	fmuls    f1, f27, f27
	lfs      f2, 0x40(r1)
	fmuls    f0, f29, f29
	fsubs    f2, f2, f31
	fmadds   f1, f26, f26, f1
	fmadds   f1, f2, f2, f1
	fcmpo    cr0, f1, f0
	bge      lbl_80118410
	lfs      f0, lbl_80517AD4@sda21(r2)
	fabs     f2, f30
	lfs      f1, lbl_80517AD0@sda21(r2)
	fmuls    f0, f0, f28
	frsp     f2, f2
	fmuls    f0, f1, f0
	fcmpo    cr0, f2, f0
	cror     2, 0, 2
	bne      lbl_80118410
	li       r30, 1

lbl_80118410:
	clrlwi.  r0, r30, 0x18
	beq      lbl_8011843C
	mr       r3, r28
	mr       r4, r29
	lwz      r12, 0(r28)
	li       r5, 4
	li       r6, 0
	lwz      r12, 0x1c(r12)
	mtctr    r12
	bctrl
	b        lbl_80118480

lbl_8011843C:
	mr       r3, r28
	mr       r4, r29
	lwz      r12, 0(r28)
	li       r5, 0
	li       r6, 0
	lwz      r12, 0x1c(r12)
	mtctr    r12
	bctrl
	b        lbl_80118480

lbl_80118460:
	mr       r3, r28
	mr       r4, r29
	lwz      r12, 0(r28)
	li       r5, 5
	li       r6, 0
	lwz      r12, 0x1c(r12)
	mtctr    r12
	bctrl

lbl_80118480:
	psq_l    f31, 232(r1), 0, qr0
	lfd      f31, 0xe0(r1)
	psq_l    f30, 216(r1), 0, qr0
	lfd      f30, 0xd0(r1)
	psq_l    f29, 200(r1), 0, qr0
	lfd      f29, 0xc0(r1)
	psq_l    f28, 184(r1), 0, qr0
	lfd      f28, 0xb0(r1)
	psq_l    f27, 168(r1), 0, qr0
	lfd      f27, 0xa0(r1)
	psq_l    f26, 152(r1), 0, qr0
	lfd      f26, 0x90(r1)
	lwz      r31, 0x8c(r1)
	lwz      r30, 0x88(r1)
	lwz      r29, 0x84(r1)
	lwz      r0, 0xf4(r1)
	lwz      r28, 0x80(r1)
	mtlr     r0
	addi     r1, r1, 0xf0
	blr
	*/
}

/*
 * --INFO--
 * Address:	801184D0
 * Size:	000024
 */
void StateAttack::cleanup(EnemyBase* enemy) { enemy->setEmotionCaution(); }

/*
 * --INFO--
 * Address:	801184F4
 * Size:	000004
 */
void StateAttack::doDirectDraw(EnemyBase* enemy, Graphics&) { }

/*
 * --INFO--
 * Address:	801184F8
 * Size:	000054
 */
StateFlick::StateFlick(int stateID)
    : StateCautionBase(stateID)
{
	mName = "Flick";
}

/*
 * --INFO--
 * Address:	8011854C
 * Size:	000078
 */
void StateFlick::init(EnemyBase* enemy, StateArg* stateArg)
{
	enemy->setEmotionExcitement();
	enemy->startMotion(2, nullptr);
	OBJ(enemy)->setAnimationSpeed(40.0f);
	enemy->disableEvent(0, EB_IsFlickEnabled);
	OBJ(enemy)->createFlickEffect();
}

/*
 * --INFO--
 * Address:	801185C4
 * Size:	00023C
 */
void StateFlick::exec(EnemyBase* enemy)
{
	cautionProc(enemy);
	/*
	stwu     r1, -0x20(r1)
	mflr     r0
	stw      r0, 0x24(r1)
	stfd     f31, 0x10(r1)
	psq_st   f31, 24(r1), 0, qr0
	stw      r31, 0xc(r1)
	stw      r30, 8(r1)
	mr       r31, r4
	mr       r30, r3
	mr       r3, r31
	lwz      r12, 0(r31)
	lwz      r12, 0x258(r12)
	mtctr    r12
	bctrl
	cmpwi    r3, 0x2a
	beq      lbl_80118608
	b        lbl_80118678

lbl_80118608:
	lwz      r5, 0xc0(r31)
	mr       r3, r31
	li       r4, 0
	lfs      f31, 0x870(r5)
	fmr      f1, f31
	bl
"isThereOlimar__Q24Game9EnemyFuncFPQ24Game8CreaturefP23Condition<Q24Game4Navi>"
	clrlwi.  r0, r3, 0x18
	beq      lbl_80118630
	li       r3, 1
	b        lbl_80118654

lbl_80118630:
	fmr      f1, f31
	mr       r3, r31
	li       r4, 0
	bl
"isTherePikmin__Q24Game9EnemyFuncFPQ24Game8CreaturefP23Condition<Q24Game4Piki>"
	clrlwi.  r0, r3, 0x18
	beq      lbl_80118650
	li       r3, 1
	b        lbl_80118654

lbl_80118650:
	li       r3, 0

lbl_80118654:
	clrlwi.  r0, r3, 0x18
	bne      lbl_801186E4
	lwz      r3, 0xc0(r31)
	lfs      f1, 0x200(r31)
	lfs      f0, 0x17c(r3)
	fcmpo    cr0, f1, f0
	mfcr     r0
	srwi     r3, r0, 0x1f
	b        lbl_801186E4

lbl_80118678:
	lwz      r5, 0xc0(r31)
	mr       r3, r31
	li       r4, 0
	lfs      f31, 0x3ac(r5)
	fmr      f1, f31
	bl
"isThereOlimar__Q24Game9EnemyFuncFPQ24Game8CreaturefP23Condition<Q24Game4Navi>"
	clrlwi.  r0, r3, 0x18
	beq      lbl_801186A0
	li       r3, 1
	b        lbl_801186C4

lbl_801186A0:
	fmr      f1, f31
	mr       r3, r31
	li       r4, 0
	bl
"isTherePikmin__Q24Game9EnemyFuncFPQ24Game8CreaturefP23Condition<Q24Game4Piki>"
	clrlwi.  r0, r3, 0x18
	beq      lbl_801186C0
	li       r3, 1
	b        lbl_801186C4

lbl_801186C0:
	li       r3, 0

lbl_801186C4:
	clrlwi.  r0, r3, 0x18
	bne      lbl_801186E4
	lwz      r3, 0xc0(r31)
	lfs      f1, 0x200(r31)
	lfs      f0, 0x17c(r3)
	fcmpo    cr0, f1, f0
	mfcr     r0
	srwi     r3, r0, 0x1f

lbl_801186E4:
	clrlwi.  r0, r3, 0x18
	beq      lbl_801186F4
	lfs      f0, lbl_80517AA0@sda21(r2)
	stfs     f0, 0x2cc(r31)

lbl_801186F4:
	lwz      r3, 0xc0(r31)
	lfs      f2, 0x2cc(r31)
	lfs      f0, 0x62c(r3)
	fcmpo    cr0, f2, f0
	bge      lbl_80118728
	lwz      r3, sys@sda21(r13)
	lfs      f0, lbl_80517AA4@sda21(r2)
	lfs      f1, 0x54(r3)
	fadds    f1, f2, f1
	stfs     f1, 0x2cc(r31)
	stfs     f0, 0x2dc(r31)
	stfs     f0, 0x2e0(r31)
	b        lbl_8011873C

lbl_80118728:
	lfs      f0, 0x424(r3)
	stfs     f0, 0x2dc(r31)
	lwz      r3, 0xc0(r31)
	lfs      f0, 0x49c(r3)
	stfs     f0, 0x2e0(r31)

lbl_8011873C:
	lwz      r3, 0x188(r31)
	lbz      r0, 0x24(r3)
	cmplwi   r0, 0
	beq      lbl_801187AC
	lwz      r0, 0x1c(r3)
	cmpwi    r0, 0x3e8
	beq      lbl_80118788
	bge      lbl_801187AC
	cmpwi    r0, 2
	beq      lbl_80118768
	b        lbl_801187AC

lbl_80118768:
	mr       r3, r31
	lwz      r12, 0(r31)
	lwz      r12, 0x308(r12)
	mtctr    r12
	bctrl
	lfs      f0, lbl_80517AA0@sda21(r2)
	stfs     f0, 0x20c(r31)
	b        lbl_801187AC

lbl_80118788:
	mr       r3, r30
	lwz      r5, 8(r30)
	lwz      r12, 0(r30)
	mr       r4, r31
	lwz      r5, 0x18(r5)
	li       r6, 0
	lwz      r12, 0x1c(r12)
	mtctr    r12
	bctrl

lbl_801187AC:
	lfs      f1, 0x200(r31)
	lfs      f0, lbl_80517AA0@sda21(r2)
	fcmpo    cr0, f1, f0
	cror     2, 0, 2
	bne      lbl_801187E0
	mr       r3, r30
	mr       r4, r31
	lwz      r12, 0(r30)
	li       r5, 1
	li       r6, 0
	lwz      r12, 0x1c(r12)
	mtctr    r12
	bctrl

lbl_801187E0:
	psq_l    f31, 24(r1), 0, qr0
	lwz      r0, 0x24(r1)
	lfd      f31, 0x10(r1)
	lwz      r31, 0xc(r1)
	lwz      r30, 8(r1)
	mtlr     r0
	addi     r1, r1, 0x20
	blr
	*/
}

/*
 * --INFO--
 * Address:	80118800
 * Size:	000054
 */
void StateFlick::cleanup(EnemyBase* enemy)
{
	enemy->setEmotionCaution();
	OBJ(enemy)->setAnimationSpeed(30.0f);
	enemy->enableEvent(0, EB_IsFlickEnabled);
}

/*
 * --INFO--
 * Address:	80118854
 * Size:	000064
 */
StateTurnToHome::StateTurnToHome(int stateID)
    : StateTurnBase(stateID)
{
	mName = "TurnToHome";
}

/*
 * --INFO--
 * Address:	801188B8
 * Size:	000150
 */
void StateTurnToHome::init(EnemyBase* enemy, StateArg* stateArg)
{
	/*
	stwu     r1, -0x50(r1)
	mflr     r0
	stw      r0, 0x54(r1)
	stfd     f31, 0x40(r1)
	psq_st   f31, 72(r1), 0, qr0
	stfd     f30, 0x30(r1)
	psq_st   f30, 56(r1), 0, qr0
	stfd     f29, 0x20(r1)
	psq_st   f29, 40(r1), 0, qr0
	stw      r31, 0x1c(r1)
	stw      r30, 0x18(r1)
	lfs      f0, lbl_80517AA0@sda21(r2)
	mr       r31, r4
	mr       r30, r3
	addi     r3, r1, 8
	stfs     f0, 0x1d4(r4)
	stfs     f0, 0x1d8(r4)
	stfs     f0, 0x1dc(r4)
	lwz      r12, 0(r4)
	lfs      f31, 0x198(r4)
	lwz      r12, 8(r12)
	lfs      f30, 0x19c(r4)
	lfs      f29, 0x1a0(r4)
	mtctr    r12
	bctrl
	lfs      f0, 0xc(r1)
	lfs      f2, 8(r1)
	fsubs    f3, f0, f30
	lfs      f1, 0x10(r1)
	fsubs    f2, f2, f31
	lfs      f0, lbl_80517AA0@sda21(r2)
	fsubs    f1, f1, f29
	fmuls    f3, f3, f3
	fmuls    f4, f1, f1
	fmadds   f1, f2, f2, f3
	fadds    f1, f4, f1
	fcmpo    cr0, f1, f0
	ble      lbl_80118960
	ble      lbl_80118964
	frsqrte  f0, f1
	fmuls    f1, f0, f1
	b        lbl_80118964

lbl_80118960:
	fmr      f1, f0

lbl_80118964:
	lwz      r3, 0xc0(r31)
	lfs      f0, 0x384(r3)
	fcmpo    cr0, f1, f0
	bge      lbl_80118998
	mr       r3, r30
	mr       r4, r31
	lwz      r12, 0(r30)
	li       r5, 7
	li       r6, 0
	lwz      r12, 0x1c(r12)
	mtctr    r12
	bctrl
	b        lbl_801189D8

lbl_80118998:
	lwz      r0, 0x1e0(r31)
	rlwinm.  r0, r0, 0, 0x1e, 0x1e
	beq      lbl_801189C8
	mr       r3, r30
	mr       r4, r31
	lwz      r12, 0(r30)
	li       r5, 0
	li       r6, 0
	lwz      r12, 0x1c(r12)
	mtctr    r12
	bctrl
	b        lbl_801189D8

lbl_801189C8:
	mr       r3, r31
	li       r4, 6
	li       r5, 0
	bl       startMotion__Q24Game9EnemyBaseFiPQ28SysShape14MotionListener

lbl_801189D8:
	psq_l    f31, 72(r1), 0, qr0
	lfd      f31, 0x40(r1)
	psq_l    f30, 56(r1), 0, qr0
	lfd      f30, 0x30(r1)
	psq_l    f29, 40(r1), 0, qr0
	lfd      f29, 0x20(r1)
	lwz      r31, 0x1c(r1)
	lwz      r0, 0x54(r1)
	lwz      r30, 0x18(r1)
	mtlr     r0
	addi     r1, r1, 0x50
	blr
	*/
}

/*
 * --INFO--
 * Address:	80118A08
 * Size:	0006AC
 */
void StateTurnToHome::exec(EnemyBase* enemy)
{
	cautionProc(enemy);
	/*
	stwu     r1, -0x110(r1)
	mflr     r0
	stw      r0, 0x114(r1)
	stfd     f31, 0x100(r1)
	psq_st   f31, 264(r1), 0, qr0
	stfd     f30, 0xf0(r1)
	psq_st   f30, 248(r1), 0, qr0
	stfd     f29, 0xe0(r1)
	psq_st   f29, 232(r1), 0, qr0
	stfd     f28, 0xd0(r1)
	psq_st   f28, 216(r1), 0, qr0
	stfd     f27, 0xc0(r1)
	psq_st   f27, 200(r1), 0, qr0
	stfd     f26, 0xb0(r1)
	psq_st   f26, 184(r1), 0, qr0
	stw      r31, 0xac(r1)
	stw      r30, 0xa8(r1)
	stw      r29, 0xa4(r1)
	stw      r28, 0xa0(r1)
	mr       r31, r4
	mr       r30, r3
	mr       r3, r31
	lwz      r12, 0(r31)
	lwz      r12, 0x258(r12)
	mtctr    r12
	bctrl
	cmpwi    r3, 0x2a
	beq      lbl_80118A7C
	b        lbl_80118AEC

lbl_80118A7C:
	lwz      r5, 0xc0(r31)
	mr       r3, r31
	li       r4, 0
	lfs      f28, 0x870(r5)
	fmr      f1, f28
	bl
"isThereOlimar__Q24Game9EnemyFuncFPQ24Game8CreaturefP23Condition<Q24Game4Navi>"
	clrlwi.  r0, r3, 0x18
	beq      lbl_80118AA4
	li       r3, 1
	b        lbl_80118AC8

lbl_80118AA4:
	fmr      f1, f28
	mr       r3, r31
	li       r4, 0
	bl
"isTherePikmin__Q24Game9EnemyFuncFPQ24Game8CreaturefP23Condition<Q24Game4Piki>"
	clrlwi.  r0, r3, 0x18
	beq      lbl_80118AC4
	li       r3, 1
	b        lbl_80118AC8

lbl_80118AC4:
	li       r3, 0

lbl_80118AC8:
	clrlwi.  r0, r3, 0x18
	bne      lbl_80118B58
	lwz      r3, 0xc0(r31)
	lfs      f1, 0x200(r31)
	lfs      f0, 0x17c(r3)
	fcmpo    cr0, f1, f0
	mfcr     r0
	srwi     r3, r0, 0x1f
	b        lbl_80118B58

lbl_80118AEC:
	lwz      r5, 0xc0(r31)
	mr       r3, r31
	li       r4, 0
	lfs      f28, 0x3ac(r5)
	fmr      f1, f28
	bl
"isThereOlimar__Q24Game9EnemyFuncFPQ24Game8CreaturefP23Condition<Q24Game4Navi>"
	clrlwi.  r0, r3, 0x18
	beq      lbl_80118B14
	li       r3, 1
	b        lbl_80118B38

lbl_80118B14:
	fmr      f1, f28
	mr       r3, r31
	li       r4, 0
	bl
"isTherePikmin__Q24Game9EnemyFuncFPQ24Game8CreaturefP23Condition<Q24Game4Piki>"
	clrlwi.  r0, r3, 0x18
	beq      lbl_80118B34
	li       r3, 1
	b        lbl_80118B38

lbl_80118B34:
	li       r3, 0

lbl_80118B38:
	clrlwi.  r0, r3, 0x18
	bne      lbl_80118B58
	lwz      r3, 0xc0(r31)
	lfs      f1, 0x200(r31)
	lfs      f0, 0x17c(r3)
	fcmpo    cr0, f1, f0
	mfcr     r0
	srwi     r3, r0, 0x1f

lbl_80118B58:
	clrlwi.  r0, r3, 0x18
	beq      lbl_80118B68
	lfs      f0, lbl_80517AA0@sda21(r2)
	stfs     f0, 0x2cc(r31)

lbl_80118B68:
	lwz      r3, 0xc0(r31)
	lfs      f2, 0x2cc(r31)
	lfs      f0, 0x62c(r3)
	fcmpo    cr0, f2, f0
	bge      lbl_80118B9C
	lwz      r3, sys@sda21(r13)
	lfs      f0, lbl_80517AA4@sda21(r2)
	lfs      f1, 0x54(r3)
	fadds    f1, f2, f1
	stfs     f1, 0x2cc(r31)
	stfs     f0, 0x2dc(r31)
	stfs     f0, 0x2e0(r31)
	b        lbl_80118BB0

lbl_80118B9C:
	lfs      f0, 0x424(r3)
	stfs     f0, 0x2dc(r31)
	lwz      r3, 0xc0(r31)
	lfs      f0, 0x49c(r3)
	stfs     f0, 0x2e0(r31)

lbl_80118BB0:
	mr       r3, r31
	bl       getCurrAnimIndex__Q24Game9EnemyBaseFv
	cmpwi    r3, 6
	bne      lbl_80118C20
	lwz      r3, 0x188(r31)
	lbz      r0, 0x24(r3)
	cmplwi   r0, 0
	beq      lbl_80119030
	lwz      r0, 0x1c(r3)
	cmplwi   r0, 0x3e8
	bne      lbl_80119030
	lwz      r0, 0x1e0(r31)
	rlwinm.  r0, r0, 0, 0x1e, 0x1e
	beq      lbl_80118C0C
	mr       r3, r30
	mr       r4, r31
	lwz      r12, 0(r30)
	li       r5, 0
	li       r6, 0
	lwz      r12, 0x1c(r12)
	mtctr    r12
	bctrl
	b        lbl_80119030

lbl_80118C0C:
	mr       r3, r31
	li       r4, 7
	li       r5, 0
	bl       startMotion__Q24Game9EnemyBaseFiPQ28SysShape14MotionListener
	b        lbl_80119030

lbl_80118C20:
	mr       r3, r31
	li       r4, 1
	bl       isStartFlick__Q24Game9EnemyFuncFPQ24Game9EnemyBaseb
	clrlwi.  r0, r3, 0x18
	beq      lbl_80118C48
	mr       r3, r31
	bl       finishMotion__Q24Game9EnemyBaseFv
	li       r0, 2
	stw      r0, 0x10(r30)
	b        lbl_80119030

lbl_80118C48:
	lwz      r5, 0xc0(r31)
	mr       r3, r31
	lfs      f26, 0x198(r31)
	li       r4, 0
	lfs      f27, 0x1a0(r31)
	lfs      f1, 0x820(r5)
	bl
"getSurroundPikminNum__Q24Game9EnemyFuncFPQ24Game8CreaturefP23Condition<Q24Game4Piki>"
	cmpwi    r3, 0xa
	ble      lbl_80118C70
	li       r3, 0xa

lbl_80118C70:
	xoris    r3, r3, 0x8000
	lis      r0, 0x4330
	stw      r3, 0x9c(r1)
	mr       r4, r31
	lwz      r5, 0xc0(r31)
	addi     r3, r1, 0x8c
	stw      r0, 0x98(r1)
	lfd      f1, lbl_80517AD8@sda21(r2)
	lfd      f0, 0x98(r1)
	lfs      f2, lbl_80517AC8@sda21(r2)
	fsubs    f0, f0, f1
	lwz      r12, 0(r31)
	lfs      f1, lbl_80517ACC@sda21(r2)
	lfs      f3, lbl_80517AC4@sda21(r2)
	fmuls    f2, f2, f0
	lfs      f0, 0x334(r5)
	lwz      r12, 8(r12)
	lfs      f30, 0x58c(r5)
	fdivs    f1, f2, f1
	lfs      f29, 0x30c(r5)
	fsubs    f1, f3, f1
	fmuls    f31, f1, f0
	mtctr    r12
	bctrl
	lfs      f4, 0x8c(r1)
	lis      r3, atanTable___5JMath@ha
	lfs      f0, 0x94(r1)
	addi     r3, r3, atanTable___5JMath@l
	lfs      f3, 0x90(r1)
	fsubs    f1, f26, f4
	fsubs    f2, f27, f0
	stfs     f4, 0x80(r1)
	stfs     f3, 0x84(r1)
	stfs     f0, 0x88(r1)
	bl       "atan2___Q25JMath18TAtanTable<1024,f>CFff"
	bl       roundAng__Ff
	lwz      r12, 0(r31)
	fmr      f26, f1
	mr       r3, r31
	lwz      r12, 0x64(r12)
	mtctr    r12
	bctrl
	fmr      f2, f1
	fmr      f1, f26
	bl       angDist__Fff
	fmr      f28, f1
	lfs      f0, lbl_80517AD4@sda21(r2)
	lfs      f1, lbl_80517AD0@sda21(r2)
	fmuls    f0, f0, f31
	fmuls    f29, f28, f29
	fmuls    f1, f1, f0
	fabs     f0, f29
	frsp     f0, f0
	fcmpo    cr0, f0, f1
	ble      lbl_80118D64
	lfs      f0, lbl_80517AA0@sda21(r2)
	fcmpo    cr0, f29, f0
	ble      lbl_80118D60
	fmr      f29, f1
	b        lbl_80118D64

lbl_80118D60:
	fneg     f29, f1

lbl_80118D64:
	mr       r3, r31
	lwz      r12, 0(r31)
	lwz      r12, 0x64(r12)
	mtctr    r12
	bctrl
	fadds    f1, f29, f1
	bl       roundAng__Ff
	lfs      f0, lbl_80517AD4@sda21(r2)
	fabs     f2, f28
	stfs     f1, 0x1fc(r31)
	fmuls    f0, f0, f30
	lfs      f1, lbl_80517AD0@sda21(r2)
	lfs      f3, 0x1fc(r31)
	frsp     f2, f2
	fmuls    f0, f1, f0
	stfs     f3, 0x1a8(r31)
	fcmpo    cr0, f2, f0
	cror     2, 0, 2
	bne      lbl_80118DC4
	mr       r3, r31
	bl       finishMotion__Q24Game9EnemyBaseFv
	li       r0, 6
	stw      r0, 0x10(r30)
	b        lbl_80118FF0

lbl_80118DC4:
	lwz      r5, 0xc0(r31)
	mr       r3, r31
	lfs      f1, 0x2e0(r31)
	li       r4, 0
	lfs      f2, 0x44c(r5)
	li       r5, 0
	li       r6, 0
	bl
"getNearestPikminOrNavi__Q24Game9EnemyFuncFPQ24Game8CreatureffPfP23Condition<Q24Game4Navi>P23Condition<Q24Game4Piki>"
	cmplwi   r3, 0
	beq      lbl_80118FD4
	stw      r3, 0x230(r31)
	addi     r3, r1, 0x68
	lwz      r29, 0x230(r31)
	lwz      r5, 0xc0(r31)
	mr       r4, r29
	lwz      r12, 0(r29)
	lfs      f30, 0x58c(r5)
	lwz      r12, 8(r12)
	lfs      f31, 0x564(r5)
	mtctr    r12
	bctrl
	mr       r4, r31
	lfs      f2, 0x68(r1)
	lwz      r12, 0(r31)
	addi     r3, r1, 0x74
	lfs      f1, 0x6c(r1)
	lfs      f0, 0x70(r1)
	lwz      r12, 8(r12)
	stfs     f2, 0x50(r1)
	stfs     f1, 0x54(r1)
	stfs     f0, 0x58(r1)
	mtctr    r12
	bctrl
	lfs      f5, 0x74(r1)
	lis      r3, atanTable___5JMath@ha
	lfs      f3, 0x7c(r1)
	addi     r3, r3, atanTable___5JMath@l
	lfs      f1, 0x50(r1)
	lfs      f0, 0x58(r1)
	lfs      f4, 0x78(r1)
	fsubs    f1, f1, f5
	fsubs    f2, f0, f3
	stfs     f5, 0x5c(r1)
	stfs     f4, 0x60(r1)
	stfs     f3, 0x64(r1)
	bl       "atan2___Q25JMath18TAtanTable<1024,f>CFff"
	bl       roundAng__Ff
	lwz      r12, 0(r31)
	fmr      f26, f1
	mr       r3, r31
	lwz      r12, 0x64(r12)
	mtctr    r12
	bctrl
	fmr      f2, f1
	fmr      f1, f26
	bl       angDist__Fff
	mr       r4, r31
	fmr      f28, f1
	lwz      r12, 0(r31)
	addi     r3, r1, 0x14
	li       r28, 0
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	mr       r4, r29
	addi     r3, r1, 8
	lwz      r12, 0(r29)
	lfs      f29, 0x14(r1)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	mr       r4, r31
	lfs      f0, 8(r1)
	lwz      r12, 0(r31)
	addi     r3, r1, 0x2c
	fsubs    f26, f0, f29
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	mr       r4, r29
	addi     r3, r1, 0x20
	lwz      r12, 0(r29)
	lfs      f29, 0x30(r1)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	mr       r4, r31
	lfs      f0, 0x24(r1)
	lwz      r12, 0(r31)
	addi     r3, r1, 0x44
	fsubs    f27, f0, f29
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	mr       r4, r29
	addi     r3, r1, 0x38
	lwz      r12, 0(r29)
	lfs      f29, 0x4c(r1)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	fmuls    f1, f27, f27
	lfs      f2, 0x40(r1)
	fmuls    f0, f31, f31
	fsubs    f2, f2, f29
	fmadds   f1, f26, f26, f1
	fmadds   f1, f2, f2, f1
	fcmpo    cr0, f1, f0
	bge      lbl_80118FA0
	lfs      f0, lbl_80517AD4@sda21(r2)
	fabs     f2, f28
	lfs      f1, lbl_80517AD0@sda21(r2)
	fmuls    f0, f0, f30
	frsp     f2, f2
	fmuls    f0, f1, f0
	fcmpo    cr0, f2, f0
	cror     2, 0, 2
	bne      lbl_80118FA0
	li       r28, 1

lbl_80118FA0:
	clrlwi.  r0, r28, 0x18
	beq      lbl_80118FF0
	mr       r3, r31
	bl       finishMotion__Q24Game9EnemyBaseFv
	mr       r3, r31
	lfs      f1, lbl_80517AB8@sda21(r2)
	lwz      r12, 0(r31)
	lwz      r12, 0x300(r12)
	mtctr    r12
	bctrl
	li       r0, 4
	stw      r0, 0x10(r30)
	b        lbl_80118FF0

lbl_80118FD4:
	lwz      r0, 0x1e0(r31)
	rlwinm.  r0, r0, 0, 0x1e, 0x1e
	beq      lbl_80118FF0
	mr       r3, r31
	bl       finishMotion__Q24Game9EnemyBaseFv
	li       r0, 0
	stw      r0, 0x10(r30)

lbl_80118FF0:
	lwz      r3, 0x188(r31)
	lbz      r0, 0x24(r3)
	cmplwi   r0, 0
	beq      lbl_80119030
	lwz      r0, 0x1c(r3)
	cmpwi    r0, 0x3e8
	beq      lbl_80119010
	b        lbl_80119030

lbl_80119010:
	mr       r3, r30
	mr       r4, r31
	lwz      r12, 0(r30)
	li       r6, 0
	lwz      r5, 0x10(r30)
	lwz      r12, 0x1c(r12)
	mtctr    r12
	bctrl

lbl_80119030:
	lfs      f1, 0x200(r31)
	lfs      f0, lbl_80517AA0@sda21(r2)
	fcmpo    cr0, f1, f0
	cror     2, 0, 2
	bne      lbl_80119064
	mr       r3, r30
	mr       r4, r31
	lwz      r12, 0(r30)
	li       r5, 1
	li       r6, 0
	lwz      r12, 0x1c(r12)
	mtctr    r12
	bctrl

lbl_80119064:
	psq_l    f31, 264(r1), 0, qr0
	lfd      f31, 0x100(r1)
	psq_l    f30, 248(r1), 0, qr0
	lfd      f30, 0xf0(r1)
	psq_l    f29, 232(r1), 0, qr0
	lfd      f29, 0xe0(r1)
	psq_l    f28, 216(r1), 0, qr0
	lfd      f28, 0xd0(r1)
	psq_l    f27, 200(r1), 0, qr0
	lfd      f27, 0xc0(r1)
	psq_l    f26, 184(r1), 0, qr0
	lfd      f26, 0xb0(r1)
	lwz      r31, 0xac(r1)
	lwz      r30, 0xa8(r1)
	lwz      r29, 0xa4(r1)
	lwz      r0, 0x114(r1)
	lwz      r28, 0xa0(r1)
	mtlr     r0
	addi     r1, r1, 0x110
	blr
	*/
}

/*
 * --INFO--
 * Address:	801190B4
 * Size:	000004
 */
void StateTurnToHome::cleanup(EnemyBase* enemy) { }

/*
 * --INFO--
 * Address:	801190B8
 * Size:	000054
 */
StateGoHome::StateGoHome(int stateID)
    : StateCautionBase(stateID)
{
	mName = "GoHome";
}

/*
 * --INFO--
 * Address:	8011910C
 * Size:	00002C
 */
void StateGoHome::init(EnemyBase* enemy, StateArg* stateArg) { enemy->startMotion(3, nullptr); }

/*
 * --INFO--
 * Address:	80119138
 * Size:	0005C4
 */
void StateGoHome::exec(EnemyBase* enemy)
{
	cautionProc(enemy);
	/*
	stwu     r1, -0x110(r1)
	mflr     r0
	stw      r0, 0x114(r1)
	stfd     f31, 0x100(r1)
	psq_st   f31, 264(r1), 0, qr0
	stfd     f30, 0xf0(r1)
	psq_st   f30, 248(r1), 0, qr0
	stfd     f29, 0xe0(r1)
	psq_st   f29, 232(r1), 0, qr0
	stfd     f28, 0xd0(r1)
	psq_st   f28, 216(r1), 0, qr0
	stfd     f27, 0xc0(r1)
	psq_st   f27, 200(r1), 0, qr0
	stfd     f26, 0xb0(r1)
	psq_st   f26, 184(r1), 0, qr0
	stw      r31, 0xac(r1)
	stw      r30, 0xa8(r1)
	stw      r29, 0xa4(r1)
	stw      r28, 0xa0(r1)
	mr       r31, r4
	mr       r30, r3
	mr       r3, r31
	lwz      r12, 0(r31)
	lwz      r12, 0x258(r12)
	mtctr    r12
	bctrl
	cmpwi    r3, 0x2a
	beq      lbl_801191AC
	b        lbl_8011921C

lbl_801191AC:
	lwz      r5, 0xc0(r31)
	mr       r3, r31
	li       r4, 0
	lfs      f28, 0x870(r5)
	fmr      f1, f28
	bl
"isThereOlimar__Q24Game9EnemyFuncFPQ24Game8CreaturefP23Condition<Q24Game4Navi>"
	clrlwi.  r0, r3, 0x18
	beq      lbl_801191D4
	li       r3, 1
	b        lbl_801191F8

lbl_801191D4:
	fmr      f1, f28
	mr       r3, r31
	li       r4, 0
	bl
"isTherePikmin__Q24Game9EnemyFuncFPQ24Game8CreaturefP23Condition<Q24Game4Piki>"
	clrlwi.  r0, r3, 0x18
	beq      lbl_801191F4
	li       r3, 1
	b        lbl_801191F8

lbl_801191F4:
	li       r3, 0

lbl_801191F8:
	clrlwi.  r0, r3, 0x18
	bne      lbl_80119288
	lwz      r3, 0xc0(r31)
	lfs      f1, 0x200(r31)
	lfs      f0, 0x17c(r3)
	fcmpo    cr0, f1, f0
	mfcr     r0
	srwi     r3, r0, 0x1f
	b        lbl_80119288

lbl_8011921C:
	lwz      r5, 0xc0(r31)
	mr       r3, r31
	li       r4, 0
	lfs      f28, 0x3ac(r5)
	fmr      f1, f28
	bl
"isThereOlimar__Q24Game9EnemyFuncFPQ24Game8CreaturefP23Condition<Q24Game4Navi>"
	clrlwi.  r0, r3, 0x18
	beq      lbl_80119244
	li       r3, 1
	b        lbl_80119268

lbl_80119244:
	fmr      f1, f28
	mr       r3, r31
	li       r4, 0
	bl
"isTherePikmin__Q24Game9EnemyFuncFPQ24Game8CreaturefP23Condition<Q24Game4Piki>"
	clrlwi.  r0, r3, 0x18
	beq      lbl_80119264
	li       r3, 1
	b        lbl_80119268

lbl_80119264:
	li       r3, 0

lbl_80119268:
	clrlwi.  r0, r3, 0x18
	bne      lbl_80119288
	lwz      r3, 0xc0(r31)
	lfs      f1, 0x200(r31)
	lfs      f0, 0x17c(r3)
	fcmpo    cr0, f1, f0
	mfcr     r0
	srwi     r3, r0, 0x1f

lbl_80119288:
	clrlwi.  r0, r3, 0x18
	beq      lbl_80119298
	lfs      f0, lbl_80517AA0@sda21(r2)
	stfs     f0, 0x2cc(r31)

lbl_80119298:
	lwz      r3, 0xc0(r31)
	lfs      f2, 0x2cc(r31)
	lfs      f0, 0x62c(r3)
	fcmpo    cr0, f2, f0
	bge      lbl_801192CC
	lwz      r3, sys@sda21(r13)
	lfs      f0, lbl_80517AA4@sda21(r2)
	lfs      f1, 0x54(r3)
	fadds    f1, f2, f1
	stfs     f1, 0x2cc(r31)
	stfs     f0, 0x2dc(r31)
	stfs     f0, 0x2e0(r31)
	b        lbl_801192E0

lbl_801192CC:
	lfs      f0, 0x424(r3)
	stfs     f0, 0x2dc(r31)
	lwz      r3, 0xc0(r31)
	lfs      f0, 0x49c(r3)
	stfs     f0, 0x2e0(r31)

lbl_801192E0:
	mr       r3, r31
	li       r4, 1
	bl       isStartFlick__Q24Game9EnemyFuncFPQ24Game9EnemyBaseb
	clrlwi.  r0, r3, 0x18
	beq      lbl_80119318
	mr       r3, r30
	mr       r4, r31
	lwz      r12, 0(r30)
	li       r5, 2
	li       r6, 0
	lwz      r12, 0x1c(r12)
	mtctr    r12
	bctrl
	b        lbl_80119678

lbl_80119318:
	lfs      f1, 0x19c(r31)
	mr       r3, r31
	lfs      f2, 0x1a0(r31)
	addi     r4, r1, 0x8c
	lfs      f0, 0x198(r31)
	stfs     f0, 0x8c(r1)
	stfs     f1, 0x90(r1)
	stfs     f2, 0x94(r1)
	lwz      r5, 0xc0(r31)
	lfs      f1, 0x2e4(r5)
	lfs      f2, 0x30c(r5)
	lfs      f3, 0x334(r5)
	bl "walkToTarget__Q24Game9EnemyFuncFPQ24Game9EnemyBaseR10Vector3<f>fff" mr
r4, r31 addi     r3, r1, 0x80 lwz      r12, 0(r31) lfs      f26, 0x198(r31) lwz
r12, 8(r12) lfs      f27, 0x19c(r31) lfs      f28, 0x1a0(r31) mtctr    r12 bctrl
	lfs      f0, 0x84(r1)
	lfs      f2, 0x80(r1)
	fsubs    f3, f0, f27
	lfs      f1, 0x88(r1)
	fsubs    f2, f2, f26
	lfs      f0, lbl_80517AA0@sda21(r2)
	fsubs    f1, f1, f28
	fmuls    f3, f3, f3
	fmuls    f4, f1, f1
	fmadds   f1, f2, f2, f3
	fadds    f1, f4, f1
	fcmpo    cr0, f1, f0
	ble      lbl_801193B4
	ble      lbl_801193B8
	frsqrte  f0, f1
	fmuls    f1, f0, f1
	b        lbl_801193B8

lbl_801193B4:
	fmr      f1, f0

lbl_801193B8:
	lwz      r3, 0xc0(r31)
	lfs      f0, 0x384(r3)
	fcmpo    cr0, f1, f0
	bge      lbl_801193E8
	mr       r3, r31
	bl       finishMotion__Q24Game9EnemyBaseFv
	lfs      f0, lbl_80517AA0@sda21(r2)
	li       r0, 7
	stfs     f0, 0x1d4(r31)
	stfs     f0, 0x1d8(r31)
	stfs     f0, 0x1dc(r31)
	stw      r0, 0x10(r30)

lbl_801193E8:
	lwz      r5, 0xc0(r31)
	mr       r3, r31
	lfs      f1, 0x2e0(r31)
	li       r4, 0
	lfs      f2, 0x44c(r5)
	li       r5, 0
	li       r6, 0
	bl
"getNearestPikminOrNavi__Q24Game9EnemyFuncFPQ24Game8CreatureffPfP23Condition<Q24Game4Navi>P23Condition<Q24Game4Piki>"
	cmplwi   r3, 0
	beq      lbl_8011961C
	stw      r3, 0x230(r31)
	addi     r3, r1, 0x68
	lwz      r29, 0x230(r31)
	lwz      r5, 0xc0(r31)
	mr       r4, r29
	lwz      r12, 0(r29)
	lfs      f30, 0x58c(r5)
	lwz      r12, 8(r12)
	lfs      f31, 0x564(r5)
	mtctr    r12
	bctrl
	mr       r4, r31
	lfs      f2, 0x68(r1)
	lwz      r12, 0(r31)
	addi     r3, r1, 0x74
	lfs      f1, 0x6c(r1)
	lfs      f0, 0x70(r1)
	lwz      r12, 8(r12)
	stfs     f2, 0x50(r1)
	stfs     f1, 0x54(r1)
	stfs     f0, 0x58(r1)
	mtctr    r12
	bctrl
	lfs      f5, 0x74(r1)
	lis      r3, atanTable___5JMath@ha
	lfs      f3, 0x7c(r1)
	addi     r3, r3, atanTable___5JMath@l
	lfs      f1, 0x50(r1)
	lfs      f0, 0x58(r1)
	lfs      f4, 0x78(r1)
	fsubs    f1, f1, f5
	fsubs    f2, f0, f3
	stfs     f5, 0x5c(r1)
	stfs     f4, 0x60(r1)
	stfs     f3, 0x64(r1)
	bl       "atan2___Q25JMath18TAtanTable<1024,f>CFff"
	bl       roundAng__Ff
	lwz      r12, 0(r31)
	fmr      f26, f1
	mr       r3, r31
	lwz      r12, 0x64(r12)
	mtctr    r12
	bctrl
	fmr      f2, f1
	fmr      f1, f26
	bl       angDist__Fff
	mr       r4, r31
	fmr      f28, f1
	lwz      r12, 0(r31)
	addi     r3, r1, 0x14
	li       r28, 0
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	mr       r4, r29
	addi     r3, r1, 8
	lwz      r12, 0(r29)
	lfs      f29, 0x14(r1)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	mr       r4, r31
	lfs      f0, 8(r1)
	lwz      r12, 0(r31)
	addi     r3, r1, 0x2c
	fsubs    f26, f0, f29
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	mr       r4, r29
	addi     r3, r1, 0x20
	lwz      r12, 0(r29)
	lfs      f29, 0x30(r1)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	mr       r4, r31
	lfs      f0, 0x24(r1)
	lwz      r12, 0(r31)
	addi     r3, r1, 0x44
	fsubs    f27, f0, f29
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	mr       r4, r29
	addi     r3, r1, 0x38
	lwz      r12, 0(r29)
	lfs      f29, 0x4c(r1)
	lwz      r12, 8(r12)
	mtctr    r12
	bctrl
	fmuls    f1, f27, f27
	lfs      f2, 0x40(r1)
	fmuls    f0, f31, f31
	fsubs    f2, f2, f29
	fmadds   f1, f26, f26, f1
	fmadds   f1, f2, f2, f1
	fcmpo    cr0, f1, f0
	bge      lbl_801195C4
	lfs      f0, lbl_80517AD4@sda21(r2)
	fabs     f2, f28
	lfs      f1, lbl_80517AD0@sda21(r2)
	fmuls    f0, f0, f30
	frsp     f2, f2
	fmuls    f0, f1, f0
	fcmpo    cr0, f2, f0
	cror     2, 0, 2
	bne      lbl_801195C4
	li       r28, 1

lbl_801195C4:
	clrlwi.  r0, r28, 0x18
	beq      lbl_80119608
	mr       r3, r31
	bl       finishMotion__Q24Game9EnemyBaseFv
	lfs      f0, lbl_80517AA0@sda21(r2)
	mr       r3, r31
	lfs      f1, lbl_80517AB8@sda21(r2)
	stfs     f0, 0x1d4(r31)
	stfs     f0, 0x1d8(r31)
	stfs     f0, 0x1dc(r31)
	lwz      r12, 0(r31)
	lwz      r12, 0x300(r12)
	mtctr    r12
	bctrl
	li       r0, 4
	stw      r0, 0x10(r30)
	b        lbl_80119638

lbl_80119608:
	mr       r3, r31
	bl       finishMotion__Q24Game9EnemyBaseFv
	li       r0, 3
	stw      r0, 0x10(r30)
	b        lbl_80119638

lbl_8011961C:
	lwz      r0, 0x1e0(r31)
	rlwinm.  r0, r0, 0, 0x1e, 0x1e
	beq      lbl_80119638
	mr       r3, r31
	bl       finishMotion__Q24Game9EnemyBaseFv
	li       r0, 0
	stw      r0, 0x10(r30)

lbl_80119638:
	lwz      r3, 0x188(r31)
	lbz      r0, 0x24(r3)
	cmplwi   r0, 0
	beq      lbl_80119678
	lwz      r0, 0x1c(r3)
	cmpwi    r0, 0x3e8
	beq      lbl_80119658
	b        lbl_80119678

lbl_80119658:
	mr       r3, r30
	mr       r4, r31
	lwz      r12, 0(r30)
	li       r6, 0
	lwz      r5, 0x10(r30)
	lwz      r12, 0x1c(r12)
	mtctr    r12
	bctrl

lbl_80119678:
	lfs      f1, 0x200(r31)
	lfs      f0, lbl_80517AA0@sda21(r2)
	fcmpo    cr0, f1, f0
	cror     2, 0, 2
	bne      lbl_801196AC
	mr       r3, r30
	mr       r4, r31
	lwz      r12, 0(r30)
	li       r5, 1
	li       r6, 0
	lwz      r12, 0x1c(r12)
	mtctr    r12
	bctrl

lbl_801196AC:
	psq_l    f31, 264(r1), 0, qr0
	lfd      f31, 0x100(r1)
	psq_l    f30, 248(r1), 0, qr0
	lfd      f30, 0xf0(r1)
	psq_l    f29, 232(r1), 0, qr0
	lfd      f29, 0xe0(r1)
	psq_l    f28, 216(r1), 0, qr0
	lfd      f28, 0xd0(r1)
	psq_l    f27, 200(r1), 0, qr0
	lfd      f27, 0xc0(r1)
	psq_l    f26, 184(r1), 0, qr0
	lfd      f26, 0xb0(r1)
	lwz      r31, 0xac(r1)
	lwz      r30, 0xa8(r1)
	lwz      r29, 0xa4(r1)
	lwz      r0, 0x114(r1)
	lwz      r28, 0xa0(r1)
	mtlr     r0
	addi     r1, r1, 0x110
	blr
	*/
}

/*
 * --INFO--
 * Address:	801196FC
 * Size:	000014
 */
void StateGoHome::cleanup(EnemyBase* enemy) { enemy->mTargetVelocity = Vector3f(0.0f); }
} // namespace ChappyBase
} // namespace Game
