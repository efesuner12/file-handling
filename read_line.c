#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>

int main()
{
    char ch;

	FILE *fp;
	fp = fopen("example.txt", "r");

	if(fp == NULL)
	{
		printf("Cannot open files\n");
		exit(-1);
	}

	//read commands line by line
    ch=getc(fp);
    while(ch != '\n')
    {
        printf("%c", ch);
        ch = getc(fp);

        if(ch == '\n')
        {
            ch = fseek(fp, 0, 1);
            printf("\n");
        }

        if(ch == EOF)
            break;
    }

    fclose(fp);

    return 0;
}