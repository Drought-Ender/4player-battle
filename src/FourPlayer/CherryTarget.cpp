#include "CherryTarget.h"
#include "FourPlayer.h"
#include "sysMath.h"

namespace CherryTarget
{
    int GetControllerDirection(Controller* gamePad) {
        f32 x = gamePad->getSubStickX();
        f32 y = gamePad->getSubStickY();


        f32 radius = _sqrtf(x * x + y * y);
        f32 theta  = JMath::atanTable_.atan2_(x, y);

        if (radius < 0.5f) return -1;

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

    int GetTarget(Controller* gamePad) {
        int target = GetControllerDirection(gamePad);
        if (!gDrawNavi[target] || target >= Game::gNaviNum || Game::getVsPikiColor(gamePad->mPortNum) == Game::getVsPikiColor(target)) {
            return -1;
        }
        return target;
    }


    Vector2f GetXY(Controller* gamePad) {
        return Vector2f(gamePad->getSubStickX(), -gamePad->getSubStickY());
    }

} // namespace CherryTarget
