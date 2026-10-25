#include <Geode/Geode.hpp>
#include <Geode/modify/PlayerObject.hpp>

using namespace geode::prelude;

static int g_bufferedTicks = 0;
static const int BUFFER_WINDOW_TICKS = 3;

class $modify(MyPlayerObject, PlayerObject) {
    void pushButton(PlayerButton p0) {
        g_bufferedTicks = BUFFER_WINDOW_TICKS;
        PlayerObject::pushButton(p0);
    }

    void destroyPlayer(PlayerObject* p0, GameObject* p1) {
        if (g_bufferedTicks > 0) {
            g_bufferedTicks--;
            return;
        }
        PlayerObject::destroyPlayer(p0, p1);
    }
};
