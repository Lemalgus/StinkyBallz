if (opcode is R type) {
    int Rd = instruction & 0x1F
    instruction >> 5
    int Rn = instruction & 0x1F
    instruction >> 5
    int shamt = instruction & 0x3F
    instruction >> 6
    int Rm = instruction & 0x1F


    char RdString[40] = "X";
    char buffer[40];
    itoa(Rd, buffer, 10);
    strcat(RdString, buffer);

    char RnString[40] = "X";
    char buffer[40];
    itoa(Rn, buffer, 10);
    strcat(RnString, buffer);

    char RmString[40] = "X";
    char buffer[40];
    itoa(Rm, buffer, 10);
    strcat(RmString, buffer);

    char ShamtString[40] = "X";
    char buffer[40];
    itoa(shamt, buffer, 10);
    strcat(ShamtString, buffer);

    strcat(RmString, RnString);
    strcat(RmString, RdString);
}

else if (opcode is I type) {
    int Rd = instruction & 0x1F
    instruction >> 5
    int Rn = instruction & 0x1F
    instruction >> 5
    int ALUImm = instruction & 0xFFF //come back, need to check that can work with more than 8 bits


    char RdString[40] = "X";
    char buffer[40];
    itoa(Rd, buffer, 10);
    strcat(RdString, buffer);

    char RnString[40] = "X";
    char buffer[40];
    itoa(Rn, buffer, 10);
    strcat(RnString, buffer);

    char ALUString[40] = "#";
    char buffer[40];
    itoa(ALUImm, buffer, 10);
    strcat(ALUString, buffer);

    strcat(RdString, RnString);
    strcat(RdString, ALUString);
}

else if (opcode is D type) {
    int Rt = instruction & 0x1F
    instruction >> 5
    int Rn = instruction & 0x1F
    instruction >> 5
    int op = instruction & 0x3
    instruction >> 2
    int DTAdd = instruction & 0x1FF


    char RtString[40] = "X";
    char buffer[40];
    itoa(Rt, buffer, 10);
    strcat(RtString, buffer);

    char RnString[40] = "[X";
    char buffer[40];
    itoa(Rn, buffer, 10);
    strcat(RnString, buffer);

    char opString[40] = "X";
    char buffer[40];
    itoa(op, buffer, 10);
    strcat(opString, buffer);

    char DTString[40] = "#";
    char buffer[40];
    itoa(DTAdd, buffer, 10);
    strcat(DTString, buffer);

    strcat(RtString, RnString);
    strcat(RtString, DTString);
    strcat(RtString, "]");

}

else if (opcode is B type) {
    int BRAdd = instruction & 0x3FFFFFF


    char BRString[40] = "X";
    char buffer[40];
    itoa(BRAdd, buffer, 10);
    strcat(BRString, buffer);
}

else if (opcode is CB type) {
    int Rt = instruction & 0x1F
    instruction >> 5
    int COND_BR_Add = instruction & 0x8FFFF


    char RtString[40] = "X";
    char buffer[40];
    itoa(Rt, buffer, 10);
    strcat(RtString, buffer);

    char CONDString[40] = "";
    char buffer[40];
    itoa(COND_BR_Add, buffer, 10);
    strcat(CONDString, buffer);

    strcat(RtString, ", ");
}

else if (opcode is IW type) {
    int Rd = instruction & 0x1F
    instruction >> 5
    int Mov_Imm = instruction & 0xFFFF


    char RdString[40] = "X";
    char buffer[40];
    itoa(Rd, buffer, 10);
    strcat(RdString, buffer);

    char MOVString[40] = "#0x";
    char buffer[40];
    itoa(Mov_Imm, buffer, 10);
    strcat(MOVString, buffer);

    strcat(RdString, ", ");
    strcat(RdString, MOVString);
}