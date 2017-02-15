#include <stdio.h>
#include <string.h>

int main()
{
	FILE *fp;
	int status;
	char path[200];
	char srcfilename[100];
	char destfilename[100];

	printf("ENter source and destination files...\n");
	scanf("%s",srcfilename);
	scanf("%s",destfilename);
	char command[200];
	strcpy(command, "cp ");
	strcat(command, srcfilename);
	strcat(command, " ");
	strcat(command, destfilename);

	fp = popen(command, "r");
	if (fp == NULL)
	{
		printf("Could not open any pipe\n");
	}

	/*while (fgets(path, 200, fp) != NULL)
	    printf("%s", path);
*/
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