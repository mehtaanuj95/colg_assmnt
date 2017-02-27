#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#define BUF 1024

int main()
{
	char buffer[BUF];
	char filename[20];
	int length;
	int fd1;
	

	//reading the source filename	
	printf("\nEnter Source File Name : ");
	scanf("%s",filename);
	
	//Opens the filename and stores the file descriptor in fd1,if error, returns -1
	fd1 = open(filename,O_RDONLY);
	
	if(fd1 == -1)
		printf("\nFile not available.\n");

	else
	{
		printf("\nFile is available.\n\n\n");
		printf("\nDisplaying File.\n\n\n");


			//reads the contents of orignal file into buffer array,read returns the number of bytes read
			// -1 if any error occurs. Loop runs till it reads anything from the file		
		while ( (length = read (fd1, buffer, BUF)) >0)		
			     write (1, buffer, length);//first arguement of write is for the file descriptor, but if it
			     							// is equal to 1,it displays the contents on the terminal.
			     
		printf("\n\n\n\n");
	}
	close(fd1);
	
}
