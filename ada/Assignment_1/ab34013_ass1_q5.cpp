/*
@author : Anuj Bhai Mehta
Description : factorial of a large number.
Date: Saturday, 21 January 2017
Usage: g++ ass1_q5.cpp
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int prod,carry = 0;

struct linklist
{
    int info;
    struct linklist *next;
    struct linklist *prev;
};
typedef struct linklist Node;
//Function to create a new node
Node* getNode()
{
    Node* create = (Node* )malloc(sizeof(Node));
    create->next = NULL;
    create->prev = NULL;
    return create;
}
//Function to insert a new node
Node* insert(Node* head,int data)
{
    if(head == NULL)
    {
        Node* makenode = getNode();
        head = makenode;
        makenode->info =data;
    }
    else
    {
        Node* makenode = getNode();
        makenode->next = head;
        head->prev = makenode;
        head = makenode;
        makenode->info = data;
    }
    return head;
}
//Function to display information of link list
Node* display(Node* head)
{
    if(head == NULL)
    {
        printf(" List Empty..!!\n");
        exit(0);
    }
    else
    {
        Node* temp = head;
        while(temp!=NULL)
        {   
            printf("%d",temp->info);
            temp = temp->next;
        }
    }
    return head;
}
//Function to multiply two link lists
Node* multiply(Node* head,int data)
{
    Node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    while(temp != head)
    {
        prod = ( temp->info)*data + carry;
        //head = insert(head,prod % 10);
        temp->info = prod%10;
        carry = prod / 10;   
        temp = temp->prev;     
    }
    prod = (head->info)*data + carry;
    head->info = prod%10;
   // head = insert(head,prod%10);
    carry = prod / 10;
    while(carry>0)
    {
        head = insert(head,carry%10);
        carry = carry/10;
    }
    return head;
}
int main()
{
    Node* head = NULL;
    int num,i;
    printf(" Enter a number to find Factoriasal for \n");
    scanf("%d",&num);
    head = insert(head,1);
    for(i=2;i<=num;i++)
    {
        head = multiply(head,i);
    }
    head = display(head);
    printf("\n");
    return 0;
}
