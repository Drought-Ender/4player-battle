#include "Game/VsGame.h"
#include "PSSystem/PSSystemIF.h"
#include "Game/Entities/ItemOnyon.h"
#include "efx/TNaviEffect.h"
#include "Game/Stickers.h"
#include "Dolphin/rand.h"
#include "Game/GameConfig.h"

namespace Game {
namespace VsGame {
bool CardMgr::usePlayerCardNew(int user, TekiMgr* tekiMgr) {

    tekiMgr = m_tekiMgr;
    int slotID = m_slotMachines[user].m_slotID;
    
    bool used = true;
    
    if (m_slotMachines[user]._18) {
        return false;
    }
    
    // The switch cases have curly braces on them to prevent 
    // awkward varible naming due to conflicts
    
    switch (slotID) {
        case UNRESOLVED: {
            PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_ERROR, 0);
            used = false;
            break;
        }
        case PIKMIN_5: {
            Onyon* onyon = ItemOnyon::mgr->getOnyon(1 - user);
            if (onyon) {
                for (int i = 0; i < 5; i++) {
                    onyon->vsChargePikmin();
                }
            }
            break;
        }
        case PIKMIN_10: {
            Onyon* onyon = ItemOnyon::mgr->getOnyon(1 - user);
            if (onyon) {
                for (int i = 0; i < 10; i++) {
                    onyon->vsChargePikmin();
                }
            }
            break;
        }
        case DOPE_BLACK: {
            Navi* navi = naviMgr->getAt(user);
            if (navi) {
                navi->incDopeCount(DOPE_TYPE_BITTER);
            }
            break;
        }
        case DOPE_RED: {
            Navi* navi = naviMgr->getAt(user);
            if (navi) {
                navi->incDopeCount(DOPE_TYPE_SPICY);
            }
            break;
        }
        case PIKMIN_XLU: {
            Navi* navi = naviMgr->getAt(user);
            if (navi && m_section->m_obakeTimer[user] <= 0.0f) {
                efx::TNaviEffect* naviEffect = navi->m_effectsObj;
                if (!naviEffect->isFlag(efx::NAVIFX_Unk32)) { // is Hidden?
                    naviEffect->_04 = naviEffect->m_flags;
                    naviEffect->m_flags.clear();
                    naviEffect->setFlag(efx::NAVIFX_Unk32);
                }
                naviEffect->m_light.forceKill();
                naviEffect->m_lightAct.forceKill();
                naviEffect->m_damage.forceKill();
                naviEffect->killHamonA_();
                naviEffect->killHamonB_();
                naviEffect->killLight_();
                naviEffect->killLightAct_();
                naviEffect->killCursor_();
                naviEffect->killFueact_();
            }
            m_section->m_obakeTimer[user] = 60.0f;
            break;
        }
        case ALL_FLOWER: {
            Iterator<Piki> IPiki = pikiMgr;
            CI_LOOP(IPiki) {
                Piki* piki = *IPiki;
                if (piki->m_pikiKind == 1 - user && piki->isAlive() && piki->m_happaKind != Flower) {
                    piki->changeHappa(Flower);
                    Vector3f vec = piki->_25C;
                    efx::TPkGlow2 particle;
                    efx::Arg arg = vec;
                    particle.create(&arg);
                    piki->startSound(PSSE_PK_FLOWER_VOICE, true);
                }
            }
            break;
        }
        case RESET_BEDAMA: {
            int color = 1 - user;
            Onyon* onyon = ItemOnyon::mgr->getOnyon(color);
            Pellet* bedama = nullptr;
            PelletIterator IPellet;
            
            CI_LOOP(IPellet) {
                Pellet* pellet = *IPellet;
                if (color == pellet->getBedamaColor()) {
                    bedama = pellet;
                    break;
                }
                
            }
            if (bedama && bedama->isAlive()) {
                { // needed for stickers to call dtor
                    Stickers stickers = bedama;
                    Iterator<Creature> ICreature = &stickers;
                    CI_LOOP(ICreature) {
                        (*ICreature)->endStick();
                    }
                }
                Vector3f onyonPos = onyon->getFlagSetPos();
                Vector3f bedamaPos = bedama->getPosition();
                if (_distanceXZflag(bedamaPos, onyonPos) > 30.0f) {
                    onyonPos.y += bedama->getCylinderHeight() * 0.5f;
                    PelletReturnArg end = onyonPos;
                    
                    bedama->m_pelletSM->transit(bedama, Pellet::PS_RETURN, &end);
                }
            }
            break;
        }
        case TEKI_HANACHIRASHI:
        case TEKI_SARAI: {
            int tekiID = slotID - 7;
            Onyon* onyon = ItemOnyon::mgr->getOnyon(user);
            Vector3f onyonPos;
            if (onyon) {
                onyonPos = onyon->getPosition();
                
                float faceDir = onyon->getFaceDir();
                
                float radius = randFloat() * 150.0f + 50.0f;
                float angle  = randFloat() * TAU;
                float height = 0.0f;
            
                Vector3f spawnOffset = Vector3f(
                    radius * pikmin2_sinf(angle), 
                    height, 
                    radius * pikmin2_cosf(angle)
                );

                onyonPos += spawnOffset;
            }
            tekiMgr->birth(tekiID, onyonPos, true);
            break;
        }
        case TEKI_ROCK:
        case TEKI_BOMBOTAKRA: {
            
            float radiusVariance = 90.0f;
            float enemyHeight = 0.0f;
            int num;
            if (slotID == TEKI_ROCK) {
                num = 8;
            }
            else {
                num = 1;
                radiusVariance = 0.0f;
                enemyHeight = 1.0f;
            }

            int tekiID = slotID - 7;
            Navi* navi = naviMgr->getAt(1 - user);
            for (int i = 0; i < num; i++) {
                Vector3f spawnNaviPos;
                if (navi) {
                    spawnNaviPos = navi->getPosition();
                    
                    float faceDir = navi->getFaceDir();
                    float radius = randFloat() * 150.0f * radiusVariance;
                    
                    float angle  = randFloat() * TAU;
                    float height = enemyHeight;
                    
                
                    Vector3f spawnOffset = Vector3f(
                        radius * pikmin2_sinf(angle), 
                        height, 
                        radius * pikmin2_cosf(angle)
                    );

                    spawnNaviPos += spawnOffset;
                }
                tekiMgr->birth(tekiID, spawnNaviPos, true);
            }
            break;
        }
        case TEKI_TANK: {
            u32 TekiID = (!user) ? 4 : 5;
            
            Onyon* onyon = ItemOnyon::mgr->getOnyon(user);
            Vector3f onyonPos;
            if (onyon) {
                
                onyonPos = onyon->getPosition();
                
                float faceDir = onyon->getFaceDir();
                
                float radius = randFloat() * 150.0f + 50.0f;
                float angle  = randFloat() * TAU;
                float height = 0.0f;

                angle = faceDir;
                
                Vector3f spawnOffset = Vector3f(
                    radius * pikmin2_sinf(angle), 
                    height, 
                    radius * pikmin2_cosf(angle)
                );

                onyonPos += spawnOffset;
            }
            tekiMgr->birth(TekiID, onyonPos, true);
            break;   
        }
    }

    if (used) {
        PSSystem::spSysIF->playSystemSe(PSSE_SY_2PSLOT_GO, 0);
        if (m_slotMachines[user].m_cherryStock > 0) {
            m_slotMachines[user].m_cherryStock--;
            m_slotMachines[user].start();
            m_slotMachines[user]._18 = 0;
        }
        else {
            m_slotMachines[user].m_spinSpeed = 0.0f;
            m_slotMachines[user].m_spinAcceleration = 0.0f;
            m_slotMachines[user]._30 = 2;
            m_slotMachines[user].m_slotID = UNRESOLVED;
            m_slotMachines[user].startZoomUse();
            m_slotMachines[user]._18 = 1;
        }
    }
    
    return used;
}


inline int Game::VsGame::CardMgr::SlotMachine::getNextCard(int card) {
    return (CARD_ID_COUNT + card + 1) % CARD_ID_COUNT;
}

inline int Game::VsGame::CardMgr::SlotMachine::getPreviousCard(int card) {
    return (CARD_ID_COUNT + card - 1) % CARD_ID_COUNT;
}

inline bool Game::VsGame::CardMgr::SlotMachine::canJumpToCard(int card) { 

    int nextCardBottom = getNextCard(card);

    float distanceToBottom = FABS(nextCardBottom - m_projectedProgress);
    
    int nextCardTop = nextCardBottom + CARD_ID_COUNT;
    
    float distanceToTop = FABS(nextCardTop - m_projectedProgress);

    float distance = distanceToBottom;
    if (distanceToTop < distanceToBottom) {
        distance = distanceToTop;
    }

    
    return (distance < 0.07f && distance >= 0.0f);
    return true;
}




void CardMgr::SlotMachine::updateNew() {
    updateAppear();
    float deltaTime = sys->m_deltaTime;
    switch(m_spinningState) { // await spin stop
        case SPIN_WAIT_START:
            m_spinAcceleration = -TAU;
            if (m_spinSpeed < 0.0f) {
                m_spinningState = SPIN_START;
                m_spinTimer = 1.0f;
            }
            break;
        case SPIN_START:
            if (m_cherryStock >= 1) { // start spin
                m_spinAcceleration = -TAU;
            }
            else {
                m_spinAcceleration = -TAU;
            }
            if (gGameConfig.m_parms.m_vsY.m_data == 1) {
                m_spinAcceleration *= 3.0f;
            }
            if (m_spinSpeed < -TAU) {
                m_spinSpeed = -TAU;
                m_spinningState = SPIN_WAIT_MAX_SPEED;
                if (gGameConfig.m_parms.m_vsY.m_data == 0) {
                    m_spinTimer = randFloat() * 0.4f + 0.7f;
                    if (m_cherryStock >= 1) {
                        m_spinTimer = 0.0f;
                    }
                }
                else if (m_spinTimer > 0.0f) {
                    m_spinTimer = randFloat() * 0.4f + 0.7f;
                }
            }
            break;
        case SPIN_WAIT_MAX_SPEED: // await spining max speed
            m_spinSpeed = -TAU;
            m_spinAcceleration = 0.0f;
            m_spinTimer -= deltaTime;
            if (m_spinTimer <= 0.0f) {
                if (getNextCard(m_predeterminedSlotID) == m_projectedCardIndex) {
                    m_spinningState = SPIN_DECELERATE;
                    m_spinAcceleration = TAU; // nice
                }
            }
            break;
        case SPIN_DECELERATE: // begin decelerate
            m_spinAcceleration = TAU;
            if (m_cherryStock >= 1) {
                if (m_spinSpeed > -0.44f * PI) { 
                    m_spinAcceleration = 0.0f;
                    m_spinningState = SPIN_DECELERATE_END;
                    _2C = 0.0f;
                }
            }
            else {
                if (m_spinSpeed > -0.44f * PI) { 
                    m_spinAcceleration = 0.0f;
                    m_spinningState = SPIN_DECELERATE_END;
                    _2C = 0.0f;
                }
            }
            break;
        case SPIN_DECELERATE_END: // on decelerate end
            _2C += deltaTime; // wait 3 seconds
            if (_2C >= 3.0f && FABS(m_projectedProgress - m_projectedCardIndex) < 0.07f) { // can jump to previous card
                _6C = 0.0f;
                _68 = 0.0f;
                m_predeterminedSlotID = (CardID)getPreviousCard(m_projectedCardIndex);
                _2C = 0.0f;
                m_spinAcceleration = 0.0f;
                m_spinSpeed = 0.0f;
                m_spinningState = SPIN_END;
                _4C = m_predeterminedSlotID;
                m_spinTimer = 0.8f;
                startZoomIn();
                PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_DECIDE,0);
            }
            else if (canJumpToCard(m_predeterminedSlotID)) { // can jump to this card
                _6C = 0.0f;
                _68 = 0.0f;
                m_spinSpeed = 0.0f;
                m_spinAcceleration = 0.0f;
                m_spinningState = SPIN_END;
                _4C = m_predeterminedSlotID;
                m_spinTimer = 0.8f;
                startZoomIn();
                PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_DECIDE,0);
            }
            break;
        case SPIN_DOWN_TO_CARD: 
            m_spinTimer -= deltaTime;
            if (m_spinTimer <= 0.0f) {
                m_spinSpeed = 0.0f;
                m_spinAcceleration = -TAU;
                m_spinningState = SPIN_WAIT_CARD_ROLL;
            }
            break;
        case SPIN_WAIT_CARD_STOP:
            if (canJumpToCard(m_predeterminedSlotID)) {
                m_spinSpeed = 0.0f;
                m_spinAcceleration = 0.0f;
                m_spinningState = SPIN_END;
                PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_DECIDE,0);
            }
            break;
        case SPIN_UP_TO_CARD: 
            m_spinTimer -= deltaTime;
            if (m_spinTimer <= 0.0f) {
                m_spinSpeed = 0.0f;
                m_spinAcceleration = TAU;
                m_spinningState = SPIN_WAIT_CARD_STOP;
            }
            break;
        case SPIN_WAIT_CARD_ROLL: 
            if (canJumpToCard(m_predeterminedSlotID)) {
                m_spinSpeed = 0.0f;
                m_spinAcceleration = 0.0f;
                m_spinningState = SPIN_END;
                m_spinTimer = 1.2f;
                PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_DECIDE,0);
            }
            break;
        case SPIN_END: // on roll end
            _51 = true;
            m_slotID = m_predeterminedSlotID;
            m_spinSpeed = 0.0f;
            m_spinAcceleration = 0.0f;
            if (gGameConfig.m_parms.m_vsY.m_data == 1) {
                m_spinTimer -= sys->m_deltaTime;
                if (m_spinTimer <= 0.0f) {
                    m_cardMgr->usePlayerCard(m_playerIndex, nullptr); // nice tekimgr dumbass
                }
            }
            break;
    }
    m_spinAngle += m_spinSpeed * deltaTime;
    if (m_spinAngle > TAU)  {
        m_spinAngle -= TAU;
    }
    if (m_spinAngle < 0.0f) {
        m_spinAngle += TAU;
    }
    m_spinSpeed += m_spinAcceleration * deltaTime;
    CardID previousValue = m_projectedCardIndex;
    m_previousCardIndex = m_projectedCardIndex;
    float loopValue = TAU / CARD_ID_COUNT;
    m_projectedProgress = roundAng(m_spinAngle + loopValue) / loopValue;
    m_projectedCardIndex = (CardID)m_projectedProgress;
    if (m_spinningState != 10 && m_spinningState != 0) {
        if (m_spinSpeed > m_cardMgr->_104) {
            PSSystem::spSysIF->playSystemSe(PSSE_SY_2PSLOT_ROLL, 0);
        }
        else if (previousValue != m_projectedCardIndex) {
            PSSystem::spSysIF->playSystemSe(PSSE_SY_MENU_CURSOR, 0);
        }
    }   
}




}
}