#include "CherryTarget.h"
#include "FourPlayer.h"
#include "sysMath.h"
#include "Dolphin/rand.h"

namespace CherryTarget {
int GetControllerDirection(Controller* gamePad)
{
	f32 x = gamePad->getSubStickX();
	f32 y = gamePad->getSubStickY();

	f32 radius = _sqrtf(x * x + y * y);
	f32 theta  = JMath::atanTable_.atan2_(x, y);

	DebugReport("radius %f\n", radius);

	if (radius < 0.5f)
		return 4;

	if (theta < -PI / 2) {
		return 2;
	} else if (theta < 0.0f) {
		return 0;
	} else if (theta < PI / 2) {
		return 1;
	} else if (theta < PI) {
		return 3;
	} else {
		return 2;
	}

	return -1;
}

int GetTarget(Controller* gamePad)
{
	int target = GetControllerDirection(gamePad);
	if (target == 4) {
		int count = 0;
		int array[4];
		for (int i = 0; i < ARRAY_SIZE(gDrawNavi); i++) {
			if (gDrawNavi[i] && i < Game::gNaviNum && Game::getVsPikiColor(gamePad->mPortNum) != Game::getVsPikiColor(i)) {
				array[count++] = i;
			}
		}
		return array[(int)(randFloat() * count)];
	}
	if (!gDrawNavi[target] || target >= Game::gNaviNum
	    || (Game::getVsPikiColor(gamePad->mPortNum) == Game::getVsPikiColor(target)
	        && gConfig[FRIENDLY_FIRE] == ConfigEnums::FRIENDCHERRY_OFF)) {
		return -1;
	}
	return target;
}

Vector2f GetXY(Controller* gamePad) { return Vector2f(gamePad->getSubStickX(), -gamePad->getSubStickY()); }

} // namespace CherryTarget
