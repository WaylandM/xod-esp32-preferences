
node {

    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_UPD>(ctx))
            return;
        ESP.restart();
    }
}
