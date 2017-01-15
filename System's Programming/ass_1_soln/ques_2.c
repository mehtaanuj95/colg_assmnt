#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{

    printf("---------------------------------\n");
    printf("Name: Anuj Bhai Mehta\n");
    printf("Enrollment No: 0801cs141013\n");
    printf("-------Program starts here-------\n\n\n");

    if(argc == 1)
    {
        printf("Input has been taken by text file.\n");
        FILE *fp;
        char ch;

        // Counting number of characters
        int count = 0;
        char str[100];
        fp = fopen("one.txt", "r");
        while((ch = fgetc(fp))!= EOF)
        {
           count++;
        }
        fclose(fp);
        printf("Number of characters :- %d\n",count);

        //Counting number of words
        int count_line = 0;
        fp = fopen("one.txt", "r");
        while(fscanf(fp, "%s", str) != EOF)
        {
           count_line++;
        }
        fclose(fp);
        printf("Number of Words :- %d\n",count_line);

        //Counting number of lines
        int count_l = 0;
        fp = fopen("one.txt", "r");
        while((ch = fgetc(fp))!= EOF)
        {
           if(ch == '\n')
                count_l++;
        }
        fclose(fp);
        printf("Number of lines :- %d\n",count_l);
    }
    else
    {
        printf("Input has been given via command line.\n");
        printf("Number of Lines : 1\n");
        printf("Number of words :%d\n",argc - 1);
        int i,count = 0;
        for(i = 1; i < argc;i++)
        {
            count = count + strlen(argv[i]);
        }
        printf("Number of characters : %d\n",count);
    }
    return 0;
}
