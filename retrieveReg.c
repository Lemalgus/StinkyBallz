
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>



void main(){

bool rType = false;
bool iType = false;
bool dType = false;
bool bType = false;
bool cbType = false;
bool iwType = false;

int instruction = 0x0;
char buffer[40];


if (rType) {
    int Rd = instruction & 0x1F;
    instruction = instruction >> 5;
    int Rn = instruction & 0x1F;
    instruction = instruction >> 5;
    int shamt = instruction & 0x3F;
    instruction = instruction >> 6;
    int Rm = instruction & 0x1F;


    char RdString[40] = "X";
    itoa(Rd, buffer, 10);
    strcat(RdString, buffer);

    char RnString[40] = "X";
    itoa(Rn, buffer, 10);
    strcat(RnString, buffer);

    char RmString[40] = "X";
    itoa(Rm, buffer, 10);
    strcat(RmString, buffer);

    char ShamtString[40] = "X";
    itoa(shamt, buffer, 10);
    strcat(ShamtString, buffer);

    strcat(RmString, RnString);
    strcat(RmString, RdString);
}

else if (iType) {
    int Rd = instruction & 0x1F;
    instruction = instruction >> 5;
    int Rn = instruction & 0x1F;
    instruction = instruction >> 5;
    int ALUImm = instruction & 0xFFF; //come back, need to check that can work with more than 8 bits


    char RdString[40] = "X";
    itoa(Rd, buffer, 10);
    strcat(RdString, buffer);

    char RnString[40] = "X";
    itoa(Rn, buffer, 10);
    strcat(RnString, buffer);

    char ALUString[40] = "#";
    itoa(ALUImm, buffer, 10);
    strcat(ALUString, buffer);

    strcat(RdString, RnString);
    strcat(RdString, ALUString);
}

else if (dType) {
    int Rt = instruction & 0x1F;
    instruction = instruction >> 5;
    int Rn = instruction & 0x1F;
    instruction = instruction >> 5;
    int op = instruction & 0x3;
    instruction = instruction >> 2;
    int DTAdd = instruction & 0x1FF;


    char RtString[40] = "X";
    itoa(Rt, buffer, 10);
    strcat(RtString, buffer);

    char RnString[40] = "[X";
    itoa(Rn, buffer, 10);
    strcat(RnString, buffer);

    char opString[40] = "X";
    itoa(op, buffer, 10);
    strcat(opString, buffer);

    char DTString[40] = "#";
    itoa(DTAdd, buffer, 10);
    strcat(DTString, buffer);

    strcat(RtString, RnString);
    strcat(RtString, DTString);
    strcat(RtString, "]");

}

else if (bType) {
    int BRAdd = instruction & 0x3FFFFFF;


    char BRString[40] = "X";
    itoa(BRAdd, buffer, 10);
    strcat(BRString, buffer);
}

else if (cbType) {
    int Rt = instruction & 0x1F;
    instruction = instruction >> 5;
    int COND_BR_Add = instruction & 0x8FFFF;


    char RtString[40] = "X";
    itoa(Rt, buffer, 10);
    strcat(RtString, buffer);

    char CONDString[40] = "";
    itoa(COND_BR_Add, buffer, 10);
    strcat(CONDString, buffer);

    strcat(RtString, ", ");
}

else if (iwType) {
    int Rd = instruction & 0x1F;
    instruction = instruction >> 5;
    int Mov_Imm = instruction & 0xFFFF;


    char RdString[40] = "X";
    itoa(Rd, buffer, 10);
    strcat(RdString, buffer);

    char MOVString[40] = "#0x";
    itoa(Mov_Imm, buffer, 10);
    strcat(MOVString, buffer);

    strcat(RdString, ", ");
    strcat(RdString, MOVString);
}

}