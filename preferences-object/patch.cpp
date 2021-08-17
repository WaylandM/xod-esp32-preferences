#include <Preferences.h>

node {
    meta {
        using Type = Preferences*;
    }

    Preferences prefs = Preferences();

    void evaluate(Context ctx) {
        // It should be evaluated only once on the first (setup) transaction
        if (!isSettingUp())
            return;
        emitValue<output_PREF>(ctx, &prefs);
    }

}
