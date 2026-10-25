#include <Geode/Geode.hpp>
#include <Geode/modify/PlayerObject.hpp>

using namespace geode::prelude;

// Track ticks for input forgiveness
static int g_bufferedTicks = 0;
static const int BUFFER_WINDOW_TICKS = 3; // Change to 4 or 5 if you want a wider window

class $modify(MyPlayerObject, PlayerObject) {
    // 1. When you touch/click the screen, grant a 3-tick window
    void pushButton(PlayerButton button) {
        g_bufferedTicks = BUFFER_WINDOW_TICKS;
        PlayerObject::pushButton(button);
    }

    // 2. Intercept death execution
    void destroyPlayer() {
        if (g_bufferedTicks > 0) {
            g_bufferedTicks--;
            // Returning early skips calling the real destroyPlayer(), preventing death!
            return; 
        }

        // Standard death execution if no ticks remain
        PlayerObject::destroyPlayer();
    }
};
