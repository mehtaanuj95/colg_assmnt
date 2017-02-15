#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[200];
char key[200][10];
int keycount[200] = {0};
int keyindex = 0;
int keylen;
char operatorarray[] = {',','=',';','+','/','*','-','^','%'};
int opcount[9] = {0};

int findoperator(char ch)
{
    int i;
    for(i = 0; i < 8;i++)
    {
        if(ch == operatorarray[i])
        {
            //printf("opcount - %d\n",opcount[i]);
            opcount[i]++;
            return 1;
        }
    }
    return 0;
}
int main(int argc, char* argv[])
{

    printf("---------------------------------\n");
    printf("Name: Anuj Bhai Mehta\n");
    printf("Enrollment No: 0801cs141013\n");
    printf("-------Program starts here-------\n\n\n");

    int i;
    printf("No. of arguments: %d\n",argc);

    for(i = 1; i < argc; i++)
    {
        printf("%d th argument: %s\n",i,argv[i]);
    }

    printf("\nKeyword Count:\n");
    if(argc == 3 || argc == 4)
    {
        printf("%s  -  1\n",argv[1]);
        if(argc == 4)
            printf("%s  -  1\n",argv[2]);
    }
    if(argc == 3)
    {
        strcpy(str,argv[2]);
    }
    else if(argc == 4)
    {
        strcpy(str,argv[3]);
    }
    keylen = strlen(str);
    str[keylen] = ';';
    str[keylen+1] = '\0';
    //printf("%s\n",str);
    keylen = strlen(str);
    //str[keylen] = ';';
    //str[keylen+1] = '\0';
    keylen = strlen(str);
    int opindex = -1,k;
    int counter=0;
    for(i = 0; i < keylen; i++)
    {
        if(findoperator(str[i]) == 1)
        {
            //printf("__%d ",findoperator(str[i]));
            for(k = opindex+1; k < i;k++)
            {
                key[keyindex][counter] = str[k];
                counter++;
            }
            key[keyindex][counter] = '\0';
            opindex = i;

            keycount[keyindex]++;
            keyindex++;
        }
        counter = 0;
    }
    for(i = 0; i < keyindex; i++)
    {
        //printf("%d ",keycount[i]);
    }
    printf("\n");
    for(i = 0; i < keyindex; i++)
    {
        //printf("%s  ",key[i]);
    }

    printf("Operator Count:\n");
    for(i = 0; i <9; i++ )
    {
        if(opcount[i] > 0)
        {
            printf("%c -> %d\n",operatorarray[i],opcount[i]);
        }
    }
    printf("\n");
    printf("Identifier Count:\n");
    for(i = 0; i <keyindex; i++ )
    {
        if(keycount[i] > 0)
        {
            printf("%s -> %d\n",key[i],keycount[i]);
        }
    }
    return 0;
}
