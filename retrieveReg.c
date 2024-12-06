#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>



void main(){

bool rType = false;
bool iType = false;
bool dType = true;
bool bType = false;
bool cbType = false;
bool iwType = false;

int instruction = 0b11111000000001000000001000100001;
char buffer[40];



int i = 1;

if (rType) {
    int Rd = instruction & 0x1F;
    instruction = instruction >> 5;
    int Rn = instruction & 0x1F;
    instruction = instruction >> 5;
    int shamt = instruction & 0x3F;
    instruction = instruction >> 6;
    int Rm = instruction & 0x1F;


    char RdString[40] = "X";
    sprintf(buffer, "%d", Rd);
    strcat(RdString, buffer);

    char RnString[40] = ", X";
    sprintf(buffer, "%d", Rn);
    strcat(RnString, buffer);

    char RmString[40] = ", X";
    sprintf(buffer, "%d", Rm);
    strcat(RmString, buffer);

    char ShamtString[40] = "X";
    sprintf(buffer, "%d", shamt);
    strcat(ShamtString, buffer);

    strcat(RdString, RnString);
    strcat(RdString, RmString);

    printf("%s\n", RmString);
}

else if (iType) {
    int Rd = instruction & 0x1F;
    instruction = instruction >> 5;
    int Rn = instruction & 0x1F;
    instruction = instruction >> 5;
    int ALUImm = instruction & 0xFFF; //come back, need to check that can work with more than 8 bits


    char RdString[40] = "X";
    sprintf(buffer, "%d", Rd);
    strcat(RdString, buffer);

    char RnString[40] = "X";
    sprintf(buffer, "%d", Rn);
    strcat(RnString, buffer);

    char ALUString[40] = "#";
    sprintf(buffer, "%d", ALUImm);
    strcat(ALUString, buffer);

    strcat(RdString, RnString);
    strcat(RdString, ALUString);

    printf("%s\n", RdString);
}

else if (dType) {
    int Rt = instruction & 0x1F;
    instruction = instruction >> 5;
    int Rn = instruction & 0x1F;
    instruction = instruction >> 5;
    int op = instruction & 0x3;
    instruction = instruction >> 2;
    int DTAdd = instruction & 0x1FF;


    char RtString[40] = " X";
    sprintf(buffer, "%d", Rt);
    strcat(RtString, buffer);

    char RnString[40] = ", [X";
    sprintf(buffer, "%d", Rn);
    strcat(RnString, buffer);

    char opString[40] = "X";
    sprintf(buffer, "%d", op);
    strcat(opString, buffer);

    char DTString[40] = " ,#";
    sprintf(buffer, "%d", DTAdd);
    strcat(DTString, buffer);

    strcat(RtString, RnString);
    strcat(RtString, DTString);
    strcat(RtString, "]");

    printf("%s\n", RtString);

}

else if (bType) {
    int BRAdd = instruction & 0x3FFFFFF;
    BRAdd += i;
    i++;


    char BRString[40] = "X";
    sprintf(buffer, "%d", BRAdd);
    strcat(BRString, buffer);

    printf("%s\n L", BRString);
}

else if (cbType) {
    int Rt = instruction & 0x1F; //value that determines ge, lt, etc
    instruction = instruction >> 5;
    int COND_BR_ADD = instruction & 0x8FFFF;
    COND_BR_ADD += i;
    i++;
    char ext[5];

    if (Rt == 0) {
        ext[5] = "EQ";
    } else if (Rt == 1) {
        ext[5] = "NE";
    } else if (Rt == 2) {
        ext[5] = "HS";
    } else if (Rt == 3) {
        ext[5] = "LO";
    } else if (Rt == 4) {
        ext[5] = "MI";
    } else if (Rt == 5) {
        ext[5] = "PL";
    } else if (Rt == 6) {
        ext[5] = "VS";
    } else if (Rt == 7) {
        ext[5] = "VC";
    } else if (Rt == 8) {
        ext[5] = "HI";
    } else if (Rt == 9) {
        ext[5] = "LS";
    } else if (Rt == 10) {
        ext[5] = "GE";
    } else if (Rt == 11) {
        ext[5] = "LT";
    } else if (Rt == 12) {
        ext[5] = "GT";
    } else if (Rt == 13) {
        ext[5] = "LE";
    }


    char RtString[40];
    // sprintf(buffer, "%d", Rt);
    strcat(RtString, ext);

    char CONDString[40];
    sprintf(buffer, "%d", COND_BR_ADD);
    strcat(CONDString, buffer);

    strcat(RtString, ", ");
    strcat(RtString, CONDString);

    printf("%s\n", RtString);
}

else if (iwType) {
    int Rd = instruction & 0x1F;
    instruction = instruction >> 5;
    int Mov_Imm = instruction & 0xFFFF;
    // instruction = instruction >> 16;
    // int shift = instruction 


    char RdString[40] = "X";
    sprintf(buffer, "%d", Rd);
    strcat(RdString, buffer);

    char MOVString[40] = "#0x";
    sprintf(buffer, "%d", Mov_Imm);
    strcat(MOVString, buffer);

    strcat(RdString, ", ");
    strcat(RdString, MOVString);

    printf("%s\n", RdString);
}

}