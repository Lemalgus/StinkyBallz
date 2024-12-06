
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int global_i = 1;


	
void print_binary(int num) {
    int i;
    for (i = 10; i >= 0; i--) { // Assuming 32-bit integer
        int bit = (num >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");
}


void r_type(int instruction, int opcode) {
	char buffer[40];
    buffer[0] = '\0';
    int Rd = instruction & 0x1F;
    instruction = instruction >> 5;
    int Rn = instruction & 0x1F;
    instruction = instruction >> 5;
    int shamt = instruction & 0x3F;
    instruction = instruction >> 6;
    int Rm = instruction & 0x1F;


    char RdString[40]; //add a case specifically for BR which only uses the Rn field such as: BR X10
    RdString[0] = '\0';
    RdString[1] = 'X';
    sprintf(buffer, "%d", Rd); //also need a case for LSL and RSL where it uses Shamt in place of Rm
    strcat(RdString, buffer); //need a case for PRNT, PRNL, DUMP, HALT

    char RnString[40];
    RnString[0] = '\0';
    RnString[0] = ',';
    RnString[1] = ' ';
    RnString[2] = 'X';
    sprintf(buffer, "%d", Rn);
    strcat(RnString, buffer);

    char RmString[40];
    RmString[0] = '\0';
    RmString[0] = ',';
    RmString[1] = ' ';
    RmString[2] = 'X';
    sprintf(buffer, "%d", Rm);
    strcat(RmString, buffer);

    char ShamtString[40];
    ShamtString[0] = '\0';
    ShamtString[0] = 'X';
    sprintf(buffer, "%d", shamt);
    strcat(ShamtString, buffer);

    if (opcode == 0b11010110000) { //for BR
        printf(" X%s", RnString);
    } else if (opcode == 0b11010011011 || opcode == 0b11010011010) {
        printf("%s %s %s", RdString, RnString, ShamtString);
    } else {
        strcat(RdString, RnString);
        strcat(RdString, RmString);
        printf("%s\n", RdString);
    }
}

void i_type(int instruction, int opcode) {
	char buffer[40];
    buffer[0] = '\0';
    int Rd = instruction & 0x1F;
    instruction = instruction >> 5;
    int Rn = instruction & 0x1F;
    instruction = instruction >> 5;
    int ALUImm = instruction & 0xFFF; //come back, need to check that can work with more than 8 bits


    char RdString[40] = "X";
    sprintf(buffer, "%d", Rd);
    strcat(RdString, buffer);

    char RnString[40] = ", X";
    sprintf(buffer, "%d", Rn);
    strcat(RnString, buffer);

    char ALUString[40] = ", #";
    sprintf(buffer, "%d", ALUImm);
    strcat(ALUString, buffer);

    strcat(RdString, RnString);
    strcat(RdString, ALUString);

    printf("%s\n", RdString);
}

void d_type(int instruction, int opcode) {
	char buffer[40];
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

void b_type(int instruction, int opcode) {
	char buffer[40];
    int BRAdd = instruction & 0x3FFFFFF;
	
	if ((BRAdd >> 26) & 1) {
		BRAdd = ~BRAdd + 1;
	}
	
    BRAdd += global_i;


    char BRString[40] = "X";
    sprintf(buffer, "%d", BRAdd);
    strcat(BRString, buffer);

    printf("%s\n L", BRString);
}

void cb_type(int instruction, int opcode) {
	char buffer[40];
    buffer[0] = '\0';
    char ext[3];
    ext[0] = '\0';
    int Rt = instruction & 0x1F; //value that determines ge, lt, etc
    instruction = instruction >> 5;
    int COND_BR_ADD = instruction & 0x8FFFF;
	
	if ((COND_BR_ADD >> 18) & 1) {
		COND_BR_ADD = ~COND_BR_ADD + 1;
	}
	
		//handle if negative or psitive 
		//(twos to binary) -> (binary to decimal)
		
    COND_BR_ADD += global_i;

    if (Rt == 0) {
        ext[0] = 'E';
        ext[1] = 'Q';
    } else if (Rt == 1) {
        ext[0] = 'N';
        ext[1] = 'E';
    } else if (Rt == 2) {
        ext[0] = 'H';
        ext[1] = 'S';
    } else if(Rt == 3) {
        ext[0] = 'L';
        ext[1] = 'O';
    } else if (Rt == 4) {
        ext[0] = 'M';
        ext[1] = 'I';
    } else if (Rt == 5) {
        ext[0] = 'P';
        ext[1] = 'L';
    } else if (Rt == 6) {
        ext[0] = 'V';
        ext[1] = 'S';
    } else if (Rt == 7) {
        ext[0] = 'V';
        ext[1] = 'C';
    } else if (Rt == 8) {
        ext[0] = 'H';
        ext[1] = 'I';
    } else if (Rt == 9) {
        ext[0] = 'L';
        ext[1] = 'S';
    } else if (Rt == 10) {
        ext[0] = 'G';
        ext[1] = 'E';
    } else if (Rt == 11) {
        ext[0] = 'L';
        ext[1] = 'T';
    } else if (Rt == 12) {
        ext[0] = 'G';
        ext[1] = 'T';
    } else if (Rt == 13) {
        ext[0] = 'L';
        ext[1] = 'E';
    }


    char RtString[40];
    RtString[0] = '\0';
    RtString[0] = 'X';
    RtString[1] = '\0';
    sprintf(buffer, "%d", Rt);
    strcat(RtString, buffer);

    // sprintf(buffer, "%d", Rt);
    strcat(RtString, ext);
    char CONDString[40];
    CONDString[0] = '\0';
    sprintf(buffer, "%d", COND_BR_ADD);
    strcat(CONDString, buffer);

    strcat(RtString, ", ");
    strcat(RtString, CONDString);

    printf("%s\n", RtString);
}

void iw_type(int instruction, int opcode) {
	char buffer[40];

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


int main() {
	
	FILE* fptr = fopen("c_testing.legv8asm", "rb");

    if (fptr == NULL)
    {
        printf("ERR: File Not Found");
        exit(-1);
    }
	
	//index to find end of file
	int index = 0;
	int instruction;
	char buffer[40];
	
	//seek to end of file, compare to startinng pointer to find size, seek back to start
    fseek(fptr, 0, SEEK_END);
    int size = ftell(fptr);
    fseek(fptr, 0, SEEK_SET);
	
	
	
	
	
	
	//START OF BIG DADDY WHILE LOOP
	while(index < size){
	
	index += (fread(&instruction, sizeof(instruction), 1, fptr) * sizeof(instruction));
	
	//extract opcode
	int opcode = (instruction >> 21) & 0x7ff;
	
	//print binary representation for fun
	printf("Binary representation of %d: \n", opcode);
    print_binary(opcode);
	
	//B
	if(((opcode >> 5) & 0x05) == (opcode >> 5)){
		printf("B ");
		b_type(instruction, opcode);
		
		
	}//B.COND
	else if(((opcode >> 3) & 0x54) == (opcode >> 3)){
		printf("B.");
		cb_type(instruction, opcode);

	
	}//AND
	else if((opcode & 0x450) == opcode){
		printf("AND ");
		r_type(instruction, opcode);
	
	
	}//ADD command
	else if((opcode & 0x458) == opcode){
		printf("ADD ");
		r_type(instruction, opcode);
		
		
	}//ADDI
	else if(((opcode >> 1) & 0x244) == (opcode >> 1)){
		printf("ADDI ");
		i_type(instruction, opcode);
		
	
	}//ANDI
	else if(((opcode >> 1) & 0x248) == (opcode >> 1)){
		printf("ANDI ");
		i_type(instruction, opcode);
	

	}//BL  
	else if(((opcode >> 5) & 0x25) == (opcode >> 5)){
		printf("BL ");
		b_type(instruction, opcode);
		
		
	}//MUL
	else if((opcode & 0x4D8) == opcode){
		printf("MUL ");
		r_type(instruction, opcode);
		
		
	}//ORR
	else if((opcode & 0x150) == opcode){
		printf("ORR ");
		r_type(instruction, opcode);
		
		
	}//ORRI
	else if(((opcode >> 1) & 0x2C8) == (opcode >> 1)){
		printf("ORRI ");
		i_type(instruction, opcode);
		
		
	}//CBZ
	else if(((opcode >> 3) & 0xB4) == (opcode >> 3)){
		printf("CBZ ");
		cb_type(instruction, opcode);
	
	
	}//CBNZ
	else if(((opcode >> 3) & 0xB5) == (opcode >> 3)){
		printf("CBNZ ");
		cb_type(instruction, opcode);
		
		
	}//EOR
	else if((opcode & 0x650) == opcode){
		printf("EOR ");
		r_type(instruction, opcode);
		
		
	}//SUB
	else if((opcode & 0x658) == opcode){
		printf("SUB ");
		r_type(instruction, opcode);
	
	
	}//SUBI
	else if(((opcode >> 1) & 0x344) == (opcode >> 1)){
		printf("SUBI ");
		i_type(instruction, opcode);
		
		
	}//EORI
	else if(((opcode >> 1) & 0x348) == (opcode >> 1)){
		printf("EORI ");
		i_type(instruction, opcode);
		
		
	}//LSR
	else if((opcode & 0x69A) == opcode){
		printf("LSR ");
		r_type(instruction, opcode);
		
		
	}//LSL
	else if((opcode & 0x69B) == opcode){
		printf("LSL ");
		r_type(instruction, opcode);
		
		
	}//BR: branch target encoded in RN field
	else if((opcode & 0x6B0) == opcode){
		printf("BR ");
		r_type(instruction, opcode);
	
	
	}//SUBS
	else if((opcode & 0x758) == opcode){
		printf("SUBS ");
		r_type(instruction, opcode);
		
		
	}//SUBIS
	else if(((opcode >> 1) & 0x3C4) == (opcode >> 1)){
		printf("SUBIS ");
		i_type(instruction, opcode);
		
		
	}//STUR
	else if((opcode & 0x7C0) == opcode){
		printf("STUR ");
		d_type(instruction, opcode);
		
		
	}//LDUR
	else if((opcode & 0x7C2) == opcode){
		printf("LDUR ");
		d_type(instruction, opcode);
		
		
	}//PRNL
	else if((opcode & 0x7FC) == opcode){
		printf("PRNL\n");
		
		
	}//PRNT
	else if((opcode & 0x7FD) == opcode){
		printf("PRNT\n");
		
		
	}//DUMP
	else if((opcode & 0x7FE) == opcode){
		printf("DUMP\n");
		
		
	}//HALT
	else if((opcode & 0x7FF) == opcode){
		printf("HALT\n");
		
		
	}
	else{
		printf("invalid command\n");
		continue;
	}
	
	
	global_i++;
	}
}