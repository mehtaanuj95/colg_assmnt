#include <stdio.h>
#include <string.h>

int main()
{
	char str[1000];
	char tokens[1000][100];
	printf("& ");
	gets(str);
	printf("\nThe original commans is :  %s\n",  str);
	const char ch[2] = " ";
	char *token;
   	int count = 0;
   	token = strtok(str, ch);
   	while( token != NULL ) 
   	{
      	strcpy(tokens[count], token);
      	token = strtok(NULL, ch);
      	count++;
   	}
   	printf("%d\n", count);
   	int i;
   	/*
   	for(i = 0; i < count; i++)
   	{
   		printf("---%s\n", tokens[i]);
   	}
   	*/
   	char base_path[]= "/bin/";
   	strcat(base_path, tokens[0]);
   	printf("%s\n",base_path);
   	int m = fork();
   	if(m == 0)
   	{
   	execl(base_path, "", NULL);
   	}
   	else
   	{
   		wait();
   	}
	return 0;
}
