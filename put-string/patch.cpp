node {

    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_UPD>(ctx))
            return;
        auto prefs = getValue<input_Prefs>(ctx);
        auto xStringKey = getValue<input_Key>(ctx);
        auto xString = getValue<input_String>(ctx);

        int N=length(xStringKey) + 1;
        char cStringKey[N];
        for(int i=0;i<N;i++)
            cStringKey[i]=0;
        dump(xStringKey, cStringKey);

        N=length(xString) + 1;
        char cString[N];
        for(int i=0;i<N;i++)
            cString[i]=0;
        dump(xString, cString);

        prefs -> putString(cStringKey, cString);

        emitValue<output_Done>(ctx, 1);
    }
}
