#include "efx/Container.h"
#include "Game/Entities/ItemOnyon.h"

namespace efx {

bool Container::create(efx::Arg* arg)
{
	bool argCheck = strcmp("ArgType", arg->getName()) == 0;
	P2ASSERTLINE(301, argCheck);

	ArgType* argtype = static_cast<ArgType*>(arg);

	switch (argtype->mType) {
	case ONYON_TYPE_BLUE:
		mEffectID = PID_Container_Blue;
		break;
	case ONYON_TYPE_RED:
		mEffectID = PID_Container_Red;
		break;
	case ONYON_TYPE_YELLOW:
		mEffectID = PID_Container_Yellow;
		break;
    case ONYON_TYPE_PURPLE:
        mEffectID = PID_Container_Purple;
        break;
    case ONYON_TYPE_WHITE:
        mEffectID = PID_Container_White;
        break;
	}
	return TSync::create(arg);
}

/*
 * --INFO--
 * Address:	803B62C8
 * Size:	0000E8
 */
bool ContainerAct::create(efx::Arg* arg)
{
	bool argCheck = strcmp("ArgType", arg->getName()) == 0;
	P2ASSERTLINE(322, argCheck);

	ArgType* argtype = static_cast<ArgType*>(arg);

	switch (argtype->mType) {
	case ONYON_TYPE_BLUE:
		mItems[0].mEffectID = PID_ContainerAct_Blue_1;
		mItems[1].mEffectID = PID_ContainerAct_Blue_2;
		break;
	case ONYON_TYPE_RED:
		mItems[0].mEffectID = PID_ContainerAct_Red_1;
		mItems[1].mEffectID = PID_ContainerAct_Red_2;
		break;
	case ONYON_TYPE_YELLOW:
		mItems[0].mEffectID = PID_ContainerAct_Yellow_1;
		mItems[1].mEffectID = PID_ContainerAct_Yellow_2;
		break;
	case ONYON_TYPE_PURPLE:
		mItems[0].mEffectID = PID_ContainerAct_Purple_1;
		mItems[1].mEffectID = PID_ContainerAct_Purple_2;
		break;
	case ONYON_TYPE_WHITE:
		mItems[0].mEffectID = PID_ContainerAct_White_1;
		mItems[1].mEffectID = PID_ContainerAct_White_2;
		break;
	}
	return TSyncGroup2<TForever>::create(arg);
}

} // namespace efx