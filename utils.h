#include <stdio.h>

void dump(char* d, int size)
{
    for (int i=0; i<size; i++)
    {
	printf("%02X", d[i]);
    }
    printf("\n");
    return;
}

char* find(char* d, const char* key)
{
    return strstr(d, key);
}
#include <stdio.h>
#include <string.h>
#include "utils.h"

int main()
{
    printf("utils\n");

    char filename[] = "./test.bin";
    
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL)
    {
	printf("cannot open %s\n", filename);
	return 0;
    }
    
    fseek(fp, 0 , SEEK_END);
    int filesize = ftell(fp);
    printf("size %d\n", filesize);

    fseek(fp,  0L, SEEK_SET);
    
    char data[1024*100] = {0};
    fread(data, sizeof(char), filesize, fp);

    dump(data, filesize);
    
    //const char key[] = {0x0a, 0x0a};
    const char key[] = {0x69, 0x61};
    //dump((char*)key, sizeof(key));
    
    char* sp = find(data, key);
    printf("%s", sp);
    
    fclose(fp);
    return 0;
}
