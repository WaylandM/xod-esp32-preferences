
node {
    CStringView view;
    //char cString[4] = {'K', 'o', 'i', '\0'};
    char* cString;

    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_UPD>(ctx))
            return;
  
        //cString[4] = {'K', 'o', 'i', '\0'};
        //cString = new char[4];
        //cString[0] = 'K';
        //cString[1] = 'o';
        //cString[2] = 'i';
        //cString[3] = '\0';

        String str = "Echinorhynchus";
        int strLen = str.length() + 1;
        cString = new char[strLen];
        
        str.toCharArray(cString, strLen);

        view=CStringView(cString);
        //view=CStringView("sausage");
        emitValue<output_String>(ctx, XString(&view));
        
    }
}
