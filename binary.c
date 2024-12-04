#include <stdio.h>
#include <stdlib.h>


void read(FILE* fptr)
{
    int index = 0;
    int value;

    //seek to end of file, compare to starting pointer to find size, seek back to start
    fseek(fptr, 0, SEEK_END);
    int size = ftell(fptr);
    fseek(fptr, 0, SEEK_SET);

    while(index < size)
    {
        index += (fread(&value, sizeof(value), 1, fptr) * sizeof(value));
        printf("%d\n", value);
    }

}

void write(FILE* fptr, int value)
{
    fwrite(&value, sizeof(value), 1, fptr);
}

int main()
{
    FILE* fptr = fopen("test.bin", "rb");

    if (fptr == NULL) 
    {
        printf("ERROR: File Not Found");
        exit(-1);
    }

    read(fptr);

    // write(fptr, 111);
    // write(fptr, 100);
    // write(fptr,250);
    // write(fptr,501);

    return 0;
}