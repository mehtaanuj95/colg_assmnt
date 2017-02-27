//dest file ko del karke wapas save kar dete hai.
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
	strcpy(command, "cat ");
	strcat(command, destfilename);
	strcat(command, " ");
	strcat(command, srcfilename);
	strcat(command, " > ");
	strcat(command, "hello1.txt");

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
		strcpy(command, "rm ");
		strcat(command, destfilename);
		fp = popen(command, "r");
		if (fp == NULL)
		{
			printf("Could not open any pipe\n");
		}
		else
		{
			status = pclose(fp);
			strcpy(command, "cp ");
			strcat(command, "hello1.txt");
			strcat(command, " ");
			strcat(command, destfilename);
			fp = popen(command, "r");
			if (fp == NULL)
			{
				printf("Could not open any pipe\n");
			}
		    status = pclose(fp);
		    if (status == -1) 
			{
		    	printf("Error is reported by pclose\n");
			}
			else
			{
				printf("Eberything looks fine\n");
				return 0;
			} 
		}
	}
	return 0;
}