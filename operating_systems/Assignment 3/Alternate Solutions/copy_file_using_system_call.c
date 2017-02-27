#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h> //contains the values of variables like O_RDONLY,O_WRONLY 
#define BUF 1024 //setting the buffer size

int main()
{
	char buffer[BUF];
	char filename[20];
	int length;
	int fd1,fd2;
	
	//reading the source filename	
	printf("\nEnter Source File Name : ");
	scanf("%s",filename);
	
	//Opens the filename and stores the file descriptor in fd1,if error, returns -1
	fd1 = open(filename,O_RDONLY);
	
	if(fd1 == -1)
		printf("\nFile not available.\n");

	else
	{
		printf("\nFile available.\n\n\n");


		//Taking input for new filename
		printf("\nEnter New File Name : ");
		scanf("%s",filename);

		//creating a new file with all permissions to everyone,returns -1 on error
		fd2=creat(filename,0777);
		
		if(fd2==-1)
		{
			printf("\nError creating file.\n");
			close(fd2);
			exit(0);
		}
		
		else
		{
			//opens the newly created file
			fd2 = open(filename,O_WRONLY);			
		
			//reads the contents of orignal file into buffer array,read returns the number of bytes read
			// -1 if any error occurs. Loop runs till it reads anything from the file
			while ( (length = read (fd1, buffer, BUF)) >0)		
			     write (fd2, buffer, length);//Writes the content read from orignal file to the new file 
			     							//whose location is stored in fd2;
			     
			printf("\n\n\n\n FIle Copied. :)");
			     
		}		
	}
	
	//closes the opened file
	close(fd2);
	close(fd1);
	
}
