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

    char RnString[40] = "X";
    sprintf(buffer, "%d", Rn);
    strcat(RnString, buffer);

    char RmString[40] = "X";
    sprintf(buffer, "%d", Rm);
    strcat(RmString, buffer);

    char ShamtString[40] = "X";
    sprintf(buffer, "%d", shamt);
    strcat(ShamtString, buffer);

    strcat(RmString, RnString);
    strcat(RmString, RdString);

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


    char RtString[40] = "X";
    sprintf(buffer, "%d", Rt);
    strcat(RtString, buffer);

    char RnString[40] = "[X";
    sprintf(buffer, "%d", Rn);
    strcat(RnString, buffer);

    char opString[40] = "X";
    sprintf(buffer, "%d", op);
    strcat(opString, buffer);

    char DTString[40] = "#";
    sprintf(buffer, "%d", DTAdd);
    strcat(DTString, buffer);

    strcat(RtString, RnString);
    strcat(RtString, DTString);
    strcat(RtString, "]");

    printf("%s\n", RtString);

}

else if (bType) {
    int BRAdd = instruction & 0x3FFFFFF;


    char BRString[40] = "X";
    sprintf(buffer, "%d", BRAdd);
    strcat(BRString, buffer);

    printf("%s\n", BRString);
}

else if (cbType) {
    int Rt = instruction & 0x1F;
    instruction = instruction >> 5;
    int COND_BR_ADD = instruction & 0x8FFFF;


    char RtString[40] = "X";
    sprintf(buffer, "%d", Rt);
    strcat(RtString, buffer);

    char CONDString[40] = "";
    sprintf(buffer, "%d", COND_BR_ADD);
    strcat(CONDString, buffer);

    strcat(RtString, ", ");

    printf("%s\n", RtString);
}

else if (iwType) {
    int Rd = instruction & 0x1F;
    instruction = instruction >> 5;
    int Mov_Imm = instruction & 0xFFFF;


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