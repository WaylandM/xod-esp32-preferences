#include <nvs_flash.h>

node {

    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_UPD>(ctx))
            return;
        nvs_flash_erase();
        nvs_flash-init();
    }
}
