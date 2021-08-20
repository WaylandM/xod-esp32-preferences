node {

    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_UPD>(ctx))
            return;
        auto prefs = getValue<input_Prefs>(ctx);
        auto xStringKey = getValue<input_Key>(ctx);
        float number = getValue<input_Num>(ctx);

        int N=length(xStringKey) + 1;
        char cStringKey[N];
        for(int i=0;i<N;i++)
            cStringKey[i]=0;
        dump(xStringKey, cStringKey);

        prefs -> putUChar(cStringKey, float);

        emitValue<output_Done>(ctx, 1);
    }
}
