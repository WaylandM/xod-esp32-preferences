
node {

    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_UPD>(ctx))
            return;
        auto prefs = getValue<input_Prefs>(ctx);

        prefs -> end();
        emitValue<output_Done>(ctx, 1);

    }
}
