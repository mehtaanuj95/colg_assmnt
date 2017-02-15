#include <stdio.h>
#include <string.h>

int main()
{
	FILE *fp;
	int status;
	char path[200];
	char filename[100];

	printf("ENter a file name to display contents of...\n");
	scanf("%s",filename);
	char command[200];
	strcpy(command, "cat ");
	strcat(command, filename);

	fp = popen(command, "r");
	if (fp == NULL)
	{
		printf("Could not open any pipe\n");
	}

	while (fgets(path, 200, fp) != NULL)
	    printf("%s", path);

	status = pclose(fp);
	if (status == -1) 
	{
	    printf("Error is reported by pclose\n");
	} 
	else 
	{
	    printf("\n\nIt looks fine...\n");
	}
	return 0;
}