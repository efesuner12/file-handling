#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

static int index = 0;
char array[1000];
char *p = &array[0];

int main()
{
    printf("%d\n\n", index);

    char ch;
    
    FILE *fp;
    fp = fopen("example.txt", "r");

    if(fp == NULL)
	{
		printf("Cannot open files\n");
		exit(-1);
	}

    ch = getc(fp); //get first char
    while(ch != EOF)
    {
        printf("%c", ch); //print on scene
        array[index] = ch; //add to array by index num
        index++; //increment index
        ch = getc(fp); //continue to get char
    }

    printf("\n\n");
    printf("%d", index);

    return 0;
}