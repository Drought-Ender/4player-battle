#include "Game/Entities/Tank.h"

namespace Game {
namespace Qtank {

/*
 * --INFO--
 * Address:	8029E484
 * Size:	0000A4
 */
Obj::Obj() { createEffect(); }

/*
 * --INFO--
 * Address:	8029E528
 * Size:	0001A4
 */
void Obj::changeMaterial()
{
	J3DModelData* modelData;
	J3DModel* j3dModel = m_model->m_j3dModel;
	modelData          = j3dModel->m_modelData;
	ResTIMG* texture   = static_cast<Mgr*>(m_mgr)->getChangeTexture();

	j3dModel->calcMaterial();

	ResTIMG* newTexture;
	J3DTexture* j3dTexture = m_model->m_j3dModel->m_modelData->m_materialTable.m_texture;
	newTexture             = j3dTexture->_04;

	texture->copyTo(newTexture);

	j3dTexture->setImageOffset((u32)texture);
	j3dTexture->setPaletteOffset((u32)texture);

	for (u16 i = 0; i < modelData->m_materialTable.m_count1; i++) {
		J3DMatPacket* packet  = &j3dModel->m_matPackets[i];
		j3dSys.m_matPacket    = packet;
		J3DMaterial* material = modelData->m_materialTable.m_materials1[i];
		material->diff(packet->_2C->_34);
	}
}

/*
 * --INFO--
 * Address:	8029E6CC
 * Size:	000048
 */
void Obj::createEffect() { m_tankEffect = new efx::TQtankEffect(nullptr); }

/*
 * --INFO--
 * Address:	8029EAF0
 * Size:	000054
 */
void Obj::setupEffect()
{
	efx::TQtankEffect* effect;
	Matrixf* mtx = m_joint->getWorldMatrix();
	effect       = m_tankEffect;

	effect->m_efxQue.setMtxptr(mtx->m_matrix.mtxView);
	//effect->m_efxFire.m_efxIND.m_mtx = mtx;
	effect->m_efxQueYodare.m_mtx    = mtx;
}

/*
 * --INFO--
 * Address:	8029EB44
 * Size:	000034
 */
void Obj::startEffect() { m_tankEffect->m_efxQue.create(nullptr); }

/*
 * --INFO--
 * Address:	8029EB78
 * Size:	000054
 */
void Obj::startYodare()
{
	efx::TQtankEffect* tankEffect = m_tankEffect;
	tankEffect->m_efxQue.fade();
	tankEffect->m_efxQueYodare.create(nullptr);
}

/*
 * --INFO--
 * Address:	8029EC64
 * Size:	000050
 */
void Obj::finishEffect()
{
	efx::TQtankEffect* effect = m_tankEffect;
	effect->m_efxQue.fade();
	effect->m_efxQueYodare.fade();
}

/*
 * --INFO--
 * Address:	8029ECB4
 * Size:	000064
 */
void Obj::effectDrawOn()
{
	efx::TQtankEffect* effect = m_tankEffect;
	effect->m_efxQue.endDemoDrawOn();
	effect->m_efxQueYodare.endDemoDrawOn();
}

/*
 * --INFO--
 * Address:	8029ED58
 * Size:	000064
 */
void Obj::effectDrawOff()
{
	efx::TQtankEffect* effect = m_tankEffect;
	effect->m_efxQue.startDemoDrawOff();
	effect->m_efxQueYodare.startDemoDrawOff();
}

/*
 * --INFO--
 * Address:	8029EDFC
 * Size:	000060
 */
void Obj::interactCreature(Creature* creature)
{
	InteractFire que(this, static_cast<EnemyParmsBase*>(m_parms)->m_general.m_attackDamage.m_value);
	creature->stimulate(que);
}

/*
 * --INFO--
 * Address:	8029EE5C
 * Size:	000010
 */
void Obj::stopEffectRadius(f32 radius)
{
	efx::TQtankEffect* effect               = m_tankEffect;
	effect->m_efxQue.m_particleCallBack._04 = radius;
}

/*
 * --INFO--
 * Address:	8029EE6C
 * Size:	000044
 */
void Obj::createChargeSE() { getJAIObject()->startSound(PSSE_EN_TANK_BREATH, 0); }

/*
 * --INFO--
 * Address:	8029EEB0
 * Size:	000044
 */
void Obj::createDisChargeSE() { getJAIObject()->startSound(PSSE_EN_TANK_FIRE, 0); }

} // namespace Gtank
} // namespace Game
