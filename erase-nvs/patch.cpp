#include <nvs_flash.h>
#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {

    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_Erase>(ctx))
            return;

        nvs_flash_erase();
        nvs_flash_init();
        emitValue<output_Done>(ctx, 1);
    }
}
