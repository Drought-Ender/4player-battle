#ifndef _PSSYSTEM_PSGAME_H
#define _PSSYSTEM_PSGAME_H

#include "JSystem/JUtility/JUTException.h"
#include "PSSystem/PSScene.h"
#include "PSSystem/SingletonBase.h"
#include "PSGame/SeMgr.h"

#include "PSSystem/PSScene.h"
#include "PSSystem/Seq.h"
#include "PSGame/SeMgr.h"
#include "PSGame/SoundTable.h"
#include "PSGame/PikScene.h"


// idk what else goes in this file (if anything? maybe this is in the PSGame folder??)
// but these use the file name in the exception check so :shrug:
namespace PSSystem {
inline SceneMgr* getSceneMgr()
{

	P2ASSERTLINE(467, spSceneMgr);

	return spSceneMgr;
}

inline void checkSceneMgr(SceneMgr* mgr) { P2ASSERTLINE(476, mgr); }

inline PSGame::SeMgr* getSeMgrInstance()
{
	P2ASSERTLINE(567, SingletonBase<PSGame::SeMgr>::sInstance);
	return SingletonBase<PSGame::SeMgr>::sInstance;
}

inline Scene* getChildScene(SceneMgr* mgr)
{
	Scene* scene = mgr->mScenes->mChild;
	P2ASSERTLINE(485, scene);
	return scene;
}

inline SeqBase* getSeqFromScene(Scene* scene, u32 id)
{
	SeqBase* seq = scene->mSeqMgr.getSeq(id);
	P2ASSERTLINE(487, seq);
	return seq;
}


inline SeqBase* getSeqData(SceneMgr* mgr, int id) { return getSeqFromScene(getChildScene(mgr), id); }


}; // namespace PSSystem

namespace PSGame
{
u16 seqCpuSync(JASTrack* track, u16 command);
} // namespace PsGame


#endif
