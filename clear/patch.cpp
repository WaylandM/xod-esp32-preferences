#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {

    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_UPD>(ctx))
            return;
        auto prefs = getValue<input_Prefs>(ctx);

        if (!prefs -> clear()) {
            raiseError(ctx);
            return;
        }

        emitValue<output_Done>(ctx, 1);
    }
}
