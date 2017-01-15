#include <stdio.h>
#include <stdlib.h>

int atimecounter = 14;

struct linklist
{
    int cid;
    int atime;
    struct linklist *next;
};
typedef struct linklist Node;

Node *getNode()
{
    Node* create = malloc(sizeof(Node));
    create->next = NULL;
    return create;
}
Node* insertdata(Node* head, int cid, int atime)
{
    if(head == NULL)
    {
        Node* makenode = getNode();
        makenode->cid = cid;
        makenode->atime = atime;
        makenode->next = NULL;
        head = makenode;
    }
    else
    {
        Node* makenode = getNode();
        makenode->cid = cid;
        makenode->atime = atime;

        Node* temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        makenode->next = NULL;
        temp->next = makenode;
    }
    return head;
}
Node* display(Node* head)
{
    if(head == NULL)
    {
        printf("Queue is currently empty\n");
    }
    else
    {
        Node* temp = head;
        while(temp != NULL)
        {
            printf("%d ",temp->cid);
            temp = temp->next;
        }
    }
    printf("\n");
    return head;
}
Node* departure(Node* head, int cid)
{
    if(head == NULL)
    {
        printf("Sorry, The lane is already empty\n");
    }
    else
    {
        Node* temp = head;
        if(temp->cid == cid)
        {
            int tempdata = temp->next->cid;
            temp->next = temp->next->next;
            printf("Vehicle %d successfuly departed from lane\n",tempdata);
        }
        else
        {
            while(temp->next->cid != cid)
            {
                temp = temp->next;
            }
            int tempdata = temp->next->cid;
            temp->next = temp->next->next;
            printf("Vehicle %d successfuly departed from lane\n",tempdata);
        }
    }
    return head;
}
// Counts he number of cars in particular lane
int count(Node* head)
{
    int counter = 0;
    if(head == NULL)
    {
        return 0;
    }
    else
    {
        Node* temp = head;
        while(temp != NULL)
        {
            counter++;
            temp = temp->next;
        }
        return counter;
    }
}
// If space is available in any lane, it returns 1, else 0
int available(Node* head)
{
    if(count(head) >= 5)
    {
        return 0;
    }
    else if(count(head) < 5)
    {
        return 1;
    }
    return 0;
}
// Selects a lane which has the minimum number of cars parked and returns that lane number.
int selectLane(Node* head[])
{
/*
    printf("Count of Lane 1 : %d\n",count(head[0]));
    printf("Count of Lane 2 : %d\n",count(head[1]));
    printf("Count of Lane 3 : %d\n",count(head[2]));
    printf("Count of Lane 4 : %d\n",count(head[3]));
    printf("Count of Lane 5 : %d\n",count(head[4]));
*/
    int current_count[5];
    current_count[0] = count(head[0]);
    current_count[1] = count(head[1]);
    current_count[2] = count(head[2]);
    current_count[3] = count(head[3]);
    current_count[4] = count(head[4]);

    int min = current_count[0];
    int index = 0,i;
    for(i = 1; i <5; i++)
    {
        if(min > current_count[i])
        {
            min = current_count[i];
            index = i;
        }
    }
    return index;
}
void insertintolane(Node* head[], int cid, int atime)
{
    int lane = selectLane(head);
    printf("Lane selected is : %d\n",lane);
    if(available(head[lane]) == 1)
    {
        head[lane] = insertdata(head[lane], cid, atime);
    }
    else
    {
        printf("Sorry, But we could not park any more cars.\nAll the lanes are full.\n");
    }

}

void displayalllanes(Node* head[])
{
    printf("\nCurrent Statistics\nLane 0:\n");
    head[0] = display(head[0]);
    printf("Lane 1:\n");
    head[1] = display(head[1]);
    printf("Lane 2:\n");
    head[2] = display(head[2]);
    printf("Lane 3:\n");
    head[3] = display(head[3]);
    printf("Lane 4:\n");
    head[4] = display(head[4]);

}
int searchforcar(Node* head[], int cid)
{
    Node* temp1 = head[0];
    while(temp1 != NULL)
    {
        if(temp1->cid == cid)
            return 0;
        temp1 = temp1->next;
    }

    Node* temp2 = head[1];
    while(temp2 != NULL)
    {
        if(temp2->cid == cid)
            return 1;
        temp2 = temp2->next;
    }

    Node* temp3 = head[2];
    while(temp3 != NULL)
    {
        if(temp3->cid == cid)
            return 2;
        temp3 = temp3->next;
    }

    Node* temp4 = head[3];
    while(temp4 != NULL)
    {
        if(temp4->cid == cid)
            return 3;
        temp4 = temp4->next;
    }

    Node* temp5 = head[4];
    while(temp5 != NULL)
    {
        if(temp5->cid == cid)
            return 4;
        temp5 = temp5->next;
    }

    return -1;
}
// calls departure function from inside. First searches fro car in all the lanes, once the lane is found, it removes that car.
void departcar(Node* head[], int cid)
{
    int lane = searchforcar(head, cid);
    if(lane == -1)
    {
        printf("Sorry, Car is not present in any of the lane\n");
    }
    else
        head[lane] = departure(head[lane], cid);
}
int main()
{

    printf("---------------------------------\n");
    printf("Name: Anuj Bhai Mehta\n");
    printf("Enrollment No: 0801cs141013\n");
    printf("-------Program starts here-------\n\n\n");


    Node* head[5];
    int i;
    for(i = 0;i< 5;i++)
        head[i] = NULL;
    /*
    head[0] = display(head[0]);
    head[0] = insertdata(head[0], 2, 0);
    head[0] = insertdata(head[0], 3, 0);
    head[0] = insertdata(head[0], 4, 0);
    head[0] = display(head[0]);


    head[0] = departure(head[0], 3);
    head[0] = display(head[0]);
    printf("Count : %d\n",count(head[0]));
    printf("%d \n",available(head[0]));

    printf("%d \n",selectLane(head));

    for(i= 0; i < 26; i++)
    {
        insertintolane(head, i+1, 0);
    }
    displayalllanes(head);

    departcar(head, 21);
    departcar(head, 22);
    departcar(head, 23);
    displayalllanes(head);
    */

    int cars[50] = {0};
    int arrivaltime[50] = {0};
    int count_car = 0;

    FILE* fp;
    fp = fopen("arrival.txt","r");
    if(fp == NULL)
    {
        printf("Could not read input from Input File.\nExiting from Program...\n");
        exit(0);
    }
    else
    {

        int choise = 0;
        displayalllanes(head);



        int con = 1;
        while(con == 1)
        {
            printf("\nMenu :- (Choose any one option from below choises) \n");
            printf("1 : Read input dynamically from file\n");
            printf("2 : New Arrival of Car\n");
            printf("3 : Departure of first car in lane\n");
            printf("4 : Daparture of any thoer car\n");
            printf("5 : Show Current Statistics of Parking Lane\n");
            printf("6 : Exit\n");
            scanf("%d",&choise);
            switch(choise)
            {
                case 1:
                {

                    while(fscanf(fp, "%d %d\n",&cars[count_car], &arrivaltime[count_car]) != EOF)
                    {
                        count_car++;
                    }
                    fclose(fp);
                    /*
                    for(z = 0; z < count_car; z++)
                    {
                        printf("%d %d\n",cars[z],arrivaltime[z]);
                    }
                    printf("\n");
                    */
                    int m = 0,p;
                    for(m = 0; m < 15;m++)
                    {
                        for(p = 0; p < count_car; p++)
                        {
                            if(arrivaltime[p] == m)
                            {
                                insertintolane(head, cars[p], arrivaltime[p]);
                            }
                        }
                    }
                    printf("All the cars in the input file have been inserted to lanes\n");
                    displayalllanes(head);
                    break;
                }
                case 2:
                {
                    int carnumber;
                    printf("Enter the cid of your car\n");
                    scanf("%d",&carnumber);
                    insertintolane(head, carnumber, atimecounter);
                    atimecounter++;
                    displayalllanes(head);
                    break;
                }
                case 3:
                {
                    int departlane;
                    printf("Enter the lane whose first car you want to depart\n");
                    scanf("%d",&departlane);
                   // departlane = departlane - 1;
                    if(head[departlane] == NULL)
                    {
                        printf("This lane is already empty.\n");
                    }
                    else
                    {
                        printf("Car ID %d is departing fromlane %d\n",head[departlane]->cid, departlane);
                        head[departlane] = head[departlane]->next;
                    }
                    break;
                }
                case 4:
                {
                    int carnumber;
                    printf("Enter the cid of the car you want to take off the parking lane\n");
                    scanf("%d",&carnumber);
                    departcar(head, carnumber);
                    displayalllanes(head);
                    break;
                }
                case 5:
                {
                    displayalllanes(head);
                    break;
                }
                case 6:
                {
                    exit(0);
                    break;
                }

            }
            printf("Do you want to continue : 1 : yes or 0: no\n");
            scanf("%d",&con);
        }
    }


	printf("---------------------------------\n");
    printf("Author: Anuj Bhai Mehta\n");
    printf("Enrollment No: 0801cs141013\n");
    printf("-------Program ends here-------\n\n\n");


    return 0;
}
