#include<stdio.h>
#include<stdlib.h>

struct Node
{

    int data;
    struct Node *previous;
    struct Node *next;

};
struct Node *head=NULL;
void insertAtBeginning(int value)
{
    struct Node *newNode;
    newNode=malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->previous=NULL;
    if(head==NULL)
    {
        newNode->next=NULL;
        head=newNode;
    }
    else
    {
        newNode->next=head;
        head->previous=newNode;
        head=newNode;
    }
    printf("\n Insertion successful");
    display();
}
void insertAtEnd(int value)
{
    struct Node *newNode;
    newNode=malloc(sizeof(struct Node));
    newNode-> data=value;
    newNode->next=NULL;
    if(head==NULL)
    {
        newNode->previous=NULL;
        head = newNode;
    }
    else
    {
        struct Node *temp = head;
        while(temp->next!=NULL)
            temp = temp -> next;
        newNode->previous=temp;
        temp->next=newNode;
    }
    printf("\n Insertion successful at End");
    display();
}
void insertAfter(int value,int pos)

{
    int i,flag=1;
    struct Node *newNode;
    struct Node *temp=head;
    newNode=malloc(sizeof(struct Node));
    newNode->data = value;
    if(head == NULL)
    {
        newNode->previous=NULL;
        newNode->next=NULL;
        head = newNode;
    }
    else
    {
         for(i=0;i<pos-1;i++)
         {
               temp=temp->next;
               if(temp->next == NULL)
               {
                    flag=0;
                    break;
               }
         }

         if(flag)
         {
              newNode->next = temp->next;
              temp->next->previous=newNode;
              temp->next=newNode;
              newNode->previous=temp;
              printf("\n Insertion succesful at position");
         }
         else
                    printf("Number of elements is less than position enterd");

    }
    display();
}

void deleteBeginning()
{
    if(head == NULL)
        printf("List is Empty");
    else
    {
        struct Node *temp=head;
        if(temp->previous==temp->next)
        {
            head=NULL;
            free(temp);
        }
        else
        {
            head=temp->next;
            head->previous=NULL;
            free(temp);
        }
        printf("\n Delettion successful");
    }
    display();
}

void deleteEnd()
{
    if(head == NULL)
        printf("List is Empty");
    else
    {
        struct Node *temp=head;
        if(temp->previous==temp->next)
        {
            head=NULL;
            free(temp);
        }
        else
        {
             while(temp->next!=NULL)
                temp = temp -> next;
             temp->previous->next=NULL;
        }
        printf("\n Deletion succesful at End");
    }
    display();
}

void deleteSpecific(int delvalue)
{
    if(head == NULL)
        printf("List is Empty");
    else
    {
         struct Node *temp = head;
         while(temp->data!=delvalue)
         {
             if(temp->next==NULL)
             {
                                 printf("\n Given node is not found in the list");
                                 return;
             }

             else
                temp=temp->next;
         }
         if(temp==head)
         {
             head=NULL;
             free(temp);
         }
         else
         {
              temp->previous->next=temp->next;
              temp->next->previous=temp->previous;
              free(temp);
         }
         printf("\n Deletion successful at specific");

    }
    display();
}

void display()
{
     if(head == NULL)
        printf("\n List is Empty");
     else
     {
         struct Node *temp = head;
         printf("\n List elements are:\n");
         printf("START<---");
         while(temp->next!=NULL)
         {
             printf("%d<----->",temp->data);
             temp = temp -> next;
         }
         printf("%d--->NULL\n",temp->data);
     }
}

int main()
{
    int choice,value,pos;
    while(1)
    {
        printf("\n Doubly Linked List Operations\n");
        printf("1. Insert at Beginning\n");
         printf("2.Insert at End\n");
         printf("3.Insert at position\n");
         printf("4.Delete at beginning\n");
         printf("5.Delete at End\n");
         printf("6.Delete at position\n");
         printf("7.Display\n");
         printf("8.Exit\n");
         printf("\n Enter your choice:");
         scanf("%d",&choice);
         switch(choice)
         {
             case 1:printf("ENTER THE VALUE TO BE INSERT:");
                    scanf("%d",&value);
                    insertAtBeginning(value);
                    break;
             case 2:printf("Enter the value to be insert:");
                    scanf("%d",&value);
                    insertAtEnd(value);
                    break;
             case 3:printf("Enter the value to be insert:");
                    scanf("%d",&value);
                    printf("Enter the postion after which you want to insert:");
                    scanf("%d",&pos);
                    insertAfter(value,pos);
                    break;
             case 4:deleteBeginning();
                    break;
             case 5:deleteEnd();
                    break;
             case 6:printf("Enter the value you want to delete:");
                    scanf("%d",&value);
                    deleteSpecific(value);
                    break;
             case 7:display();
                    break;

             case 8:exit(0);
             default:printf("\n Invalid Choice\n");
         }
    }
}