#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {

    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_UPD>(ctx))
            return;
        auto prefs = getValue<input_Prefs>(ctx);
        auto xStringName = getValue<input_Name>(ctx);
        auto ro = getValue<input_RO>(ctx);

        int N=length(xStringName);
        if (N>15 || N<1) {
            raiseError(ctx);
            return;
        }
        N +=1;
        char cStringName[N];
        for(int i=0;i<N;i++)
            cStringName[i]=0;
        dump(xStringName, cStringName);

        if (!prefs -> begin(cStringName, ro)) {
            raiseError(ctx);
            return;
        }
        
        emitValue<output_Done>(ctx, 1);

    }
}
