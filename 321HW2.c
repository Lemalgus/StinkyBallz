#include <stdlib.h>
#include <stdio.h>
#include <endian.h>
	
void print_binary(int num) {
    int i;
    for (i = 10; i >= 0; i--) { // Assuming 32-bit integer
        int bit = (num >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");
}

int main() {

	FILE* fptr = fopen("test.legv8asm", "rb");

    if (fptr == NULL) 
    {
        printf("ERROR: File Not Found");
        exit(-1);
    }

	int index = 0;
	int bitstring; 

	//seek to end of file, compare to startinng pointer to find size, seek back to start
    fseek(fptr, 0, SEEK_END);
    int size = ftell(fptr);
    fseek(fptr, 0, SEEK_SET);

    while(index < size)
    {
        index += (fread(&bitstring, sizeof(bitstring), 1, fptr) * sizeof(bitstring));
        //printf("%d\n", bitstring);]

		bitstring = be32toh(bitstring);
    
	
	//extract opcode
	int opcode = (bitstring >> 21) & 0x7ff;
	
	printf("Binary representation of %d: ", opcode);
    print_binary(opcode);
	
	
	
	
	//go in order of opcode
	
	
	
	
	//B (is only 6 bits, so we need to include the not B.COND because B.COND has similar start as B
	if(((opcode >> 5) & 0x05) == (opcode >> 5)){
		printf("\nB COMMAND");
		
		
	}//B.COND
	else if(((opcode >> 3) & 0x54) == (opcode >> 3)){
		printf("\nB.COND COMMAND... CHECKING CONDITION");
		
	//TODO: do RT (end register) if->else if chain for all of the different
	//B.COND cases you could have


	
	}//AND
	else if((opcode & 0x450) == opcode){
		printf("\nAND COMMAND");
	
	
	}//ADD command
	else if((opcode & 0x458) == opcode){
		printf("\nADD COMMAND");
		
		
	}//ADDI
	else if(((opcode >> 1) & 0x244) == (opcode >> 1)){
		printf("\nADDI COMMAND");
		
	
	}//ANDI
	else if(((opcode >> 1) & 0x248) == (opcode >> 1)){
		printf("\nANDI COMMAND");
	

	}//BL  
	else if(((opcode >> 5) & 0x25) == (opcode >> 5)){
		printf("\nBL COMMAND");
		
		
	}//MUL
	else if((opcode & 0x4D8) == opcode){
		printf("\nMUL COMMAND");
		
		
	}//ORR
	else if((opcode & 0x150) == opcode){
		printf("\nORR COMMAND");
		
		
	}//ORRI
	else if(((opcode >> 1) & 0x2C8) == (opcode >> 1)){
		printf("\nORRI COMMAND");
		
		
	}//CBZ
	else if(((opcode >> 3) & 0xB4) == (opcode >> 3)){
		printf("\nCBZ COMMAND");
	
	
	}//CBNZ
	else if(((opcode >> 3) & 0xB5) == (opcode >> 3)){
		printf("\nCBNZ COMMAND");
		
		
	}//EOR
	else if((opcode & 0x650) == opcode){
		printf("\nEOR COMMAND");
		
		
	}//SUB
	else if((opcode & 0x658) == opcode){
		printf("\nSUB COMMAND");
	
	
	}//SUBI
	else if(((opcode >> 1) & 0x344) == (opcode >> 1)){
		printf("\nSUBI COMMAND");
		
		
	}//EORI
	else if(((opcode >> 1) & 0x348) == (opcode >> 1)){
		printf("\nEORI COMMAND");
		
		
	}//LSR
	else if((opcode & 0x69A) == opcode){
		printf("\nLSR COMMAND");
		
		
	}//LSL
	else if((opcode & 0x69B) == opcode){
		printf("\nLSL COMMAND");
		
		
	}//BR: branch target encoded in RN field
	else if((opcode & 0x6B0) == opcode){
		printf("\nBR COMMAND");
	
	
	}//SUBS
	else if((opcode & 0x758) == opcode){
		printf("\nSUBS COMMAND");
		
		
	}//SUBIS
	else if(((opcode >> 1) & 0x3C4) == (opcode >> 1)){
		printf("\nSUBIS COMMAND");
		
		
	}//STUR
	else if((opcode & 0x7C0) == opcode){
		printf("\nSTUR COMMAND");
		
		
	}//LDUR
	else if((opcode & 0x7C2) == opcode){
		printf("\nLDUR COMMAND");
		
		
	}//PRNL
	else if((opcode & 0x7FC) == opcode){
		printf("\nPRNL COMMAND");
		
		
	}//PRNT
	else if((opcode & 0x7FD) == opcode){
		printf("\nPRNT COMMAND");
		
		
	}//DUMP
	else if((opcode & 0x7FE) == opcode){
		printf("\nDUMP COMMAND");
		
		
	}//HALT
	else if((opcode & 0x7FF) == opcode){
		printf("\nHALT COMMAND");
		
		
	}
	else{
		printf("invalid command");
	}
	
	}
	
	

}

