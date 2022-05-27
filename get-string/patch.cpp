#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {
    CStringView view;
    char* cString;
    size_t cap;

    void evaluate(Context ctx) {
        if (isSettingUp()) {
            cap = getValue<input_Size>(ctx) + 1;
            cString = new char[cap];
            view = CStringView(cString);
        }

        if (isInputDirty<input_UPD>(ctx)) {
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
            str.toCharArray(cString, strLen);
            emitValue<output_String>(ctx, XString(&view));
            emitValue<output_Done>(ctx, 1);
        }
    }
}
