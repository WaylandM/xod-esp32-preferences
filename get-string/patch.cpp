node {
    CStringView view;
    char* cString;

    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_UPD>(ctx))
            return;
        auto prefs = getValue<input_Prefs>(ctx);
        auto xStringKey = getValue<input_Key>(ctx);
        
        int N=length(xStringKey);
        if (N>15 || N<1) {
            raiseError(ctx); 
            return;
        }
        N +=1;
        char cStringKey[N];
        for(int i=0;i<N;i++)
            cStringKey[i]=0;
        dump(xStringKey, cStringKey);

        String str = prefs -> getString(cStringKey, "NA");
        int strLen = str.length() + 1;
        cString = new char[strLen];
        
        str.toCharArray(cString, strLen);

        view=CStringView(cString);

        emitValue<output_String>(ctx, XString(&view));
        emitValue<output_Done>(ctx, 1);
    }
}
