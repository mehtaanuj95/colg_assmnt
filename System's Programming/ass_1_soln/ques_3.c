#include <stdio.h>
#include <stdlib.h>
int replaced_line[1000] = {0};
int index = 0;

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}


int line_matches(int line)
{
    int i;
    for(i = 0; i < index; i++)
    {
        if(line == replaced_line[i])
        {
            return 1;
            break;
        }
    }
    return 0;
}
void display(int a[], int limit)
{
    int i = 0;
    printf("\nReplaced_Line:\n");
    for(i = 0; i < limit; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void compare(int a[], int b[], int line, int position)
{
    int flag = 1;
    int i = position;
    for(i = position; i < position+10; i++)
    {
        if(a[i] != b[i])
        {
            flag = 0;
            break;
        }
    }
    if(!flag)
    {
        printf("Line %d in numbes3.txt\n",line);
        for(i = position; i < position+10; i++)
        {
           printf("%d ",b[i]);
        }
        printf("\n");

        printf("Line %d in numbes2.txt\n",line);
        for(i = position; i < position+10; i++)
        {
           printf("%d ",a[i]);
        }
        printf("\n");
    }



}
int main()
{
    printf("---------------------------------\n");
    printf("Name: Anuj Bhai Mehta\n");
    printf("Enrollment No: 0801cs141013\n");
    printf("-------Program starts here-------\n\n\n");

    char newline = '\n';
    int data, count = 0, num;
    FILE *fr, *fw;
    fr = fopen("numbers.txt","r");
    if(fr == NULL)
    {
        printf("File cannot be opened");
    }

    fw = fopen("numbers_2.txt", "w");
    if(fw == NULL)
    {
        printf("File cannot be opened");
    }
    //printf("Both files opened successfully\n");
    while(fscanf(fr,"%d  ", &data) != EOF)
    {

        if(count != 10)
        {
            fprintf(fw, "%d ", data);
            count++;
        }
        else
        {
            count = 0;
            fputc((int)newline, fw);
            fprintf(fw, "%d ", data);
        }
    }
    fclose(fw);
    fclose(fr);
    printf("Data copied successfully in numbers_1.txt\n");
//-------------------- PART 1 ends here --------------------------------------------------------//

    printf("Enter a number to be searched");
    scanf("%d", &num);
    fr = fopen("numbers_2.txt", "r");
    if(fr == NULL)
    {
        printf("File cannot be opened");
    }

    fw = fopen("numbers_1.txt", "w");
    if(fw == NULL)
    {
        printf("File cannot be opened");
    }

    count = 0;
    int flag = 0;
    //int count_line = 0;
    index = 0;
    int counter = 0;
    while(fscanf(fr, "%d",&data) != EOF)
    {
        count++;
        //printf("%d ",data);
        if(data == num)
        {
            fscanf(fr, " hello");
            printf("Match Found...!!\n");
            printf("Word Count - %d\n",count);
            printf("Line Count - %d\n",count/10);
            replaced_line[index] = count/10;
            index++;
            flag = 1;
            if(counter != 10)
            {
                fprintf(fw, "%d ", data+1);
                counter++;
            }
            else
            {
                counter = 0;
                fputc((int)newline, fw);
                fprintf(fw, "%d ", data+1);
            }
        }
        else
        {
                if(counter != 10)
                {
                    fprintf(fw, "%d ", data);
                    counter++;
                }
                else
                {
                    counter = 0;
                    fputc((int)newline, fw);
                    fprintf(fw, "%d ", data);
                }
        }
    }
    if(!flag)
        printf("Number does not exists in the file.\n");

    fclose(fr);
    fclose(fw);
//----------------------Part 2 and 3 ends here --------------------------------------------------------------------------------//

    fr = fopen("numbers_1.txt", "r");
    if(fr == NULL)
    {
        printf("File cannot be opened");
    }
    fw = fopen("numbers_3.txt", "w");
    if(fw == NULL)
    {
        printf("File cannot be opened");
    }
    count = 0;


    if(flag)
    {
        counter = 0;
        while(fscanf(fr,"%d",&data) != EOF)
        {
            count++;
            //printf("%d ",line_matches(count/10));
            if(line_matches(count/10) == 0)
            {
                if(counter != 10)
                {
                    fprintf(fw, "%d ", data);
                    counter++;
                }
                else
                {
                    counter = 0;
                    fputc((int)newline, fw);
                    fprintf(fw, "%d ", data);
                    counter++;
                }
            }
        }
    }
    else
    {
        printf("There are no occurences. Hence line cannot be deleted.");
    }
    display(replaced_line, index);
    printf("\nLines successfully deleted\n");
    fclose(fr);
    fclose(fw);

//-------------------------------REPLACED LINES DELETED-------------------Part 4 ends here-----------------------------------//
    int buff[1000] = {0};
    counter = 0;
    fr = fopen("numbers_3.txt", "r");
    if(fr == NULL)
    {
        printf("File cannot be opened");
    }

    while(fscanf(fr, "%d", &data) != EOF)
    {
        buff[counter] = data;
        counter++;
    }

    //display(buff, counter);
    mergeSort(buff, 0, counter - 1);
    //display(buff, counter);
    fclose(fr);


    fw = fopen("numbers_2.txt", "w");
    if(fw == NULL)
    {
        printf("File cannot be opened");
    }
    int i;
    for(i = 0; i < counter; i++)
    {
        if(i % 10 == 0 && i != 0)
        {
            fputc((int)newline, fw);
            fprintf(fw, "%d ", buff[i]);
        }
        else
        {
            fprintf(fw, "%d ", buff[i]);
        }
    }
    fclose(fw);
    printf("Data Successfully sorted using merge sort and saved in numbers_2.txt\n");

//------------------------------------------Part 5 ends here-----------------------------------------------------------------------------//

    int buff3[1000] = {0};
    counter = 0;
    fr = fopen("numbers_3.txt", "r");
    if(fr == NULL)
    {
        printf("File cannot be opened");
    }

    while(fscanf(fr, "%d", &data) != EOF)
    {
        buff3[counter] = data;
        counter++;
    }

    int buff2[1000] = {0};
    counter = 0;
    fr = fopen("numbers_2.txt", "r");
    if(fr == NULL)
    {
        printf("File cannot be opened");
    }

    while(fscanf(fr, "%d", &data) != EOF)
    {
        buff2[counter] = data;
        counter++;
    }
    fclose(fr);
    fclose(fw);
    printf("Comparing Different Lines and printing them\n");
    for(i = 0; i < counter; i= i+10)
    {
        compare(buff2, buff3, i/10, i);
    }

    return 0;
}

