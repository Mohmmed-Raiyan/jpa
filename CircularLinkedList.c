#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct  Node *head=NULL;

void insertAtBeginning(int value)
{
    struct Node *newNode;
    newNode=malloc(sizeof(struct Node));
    newNode->data=value;
    if(head==NULL)
    {
        head=newNode;
        newNode->next=head;
    }
    else
    {
        struct Node *temp=head;
        while(temp->next!=head)
            temp=temp->next;
        newNode->next=head;
        head=newNode;
        temp->next=head;
    }
    printf("\n Insertion successful\n");
    display();
}
void insertAtEnd(int value)
{
    struct Node *newNode;
    newNode=malloc(sizeof(struct Node));
    newNode->data=value;
    if(head==NULL)
    {
        head=newNode;
        newNode->next=head;

    }
    else
    {
        struct Node *temp=head;
        while(temp->next!=head)
            temp=temp->next;
        temp->next=newNode;
        newNode->next=head;
    }
    printf("\n insertion Successful\n");
    display();
}
void insertAfter(int value,int location)
{
    struct Node *newNode;
    int i;

    newNode=malloc(sizeof(struct Node));
    newNode->data=value;
    if(head==NULL)
    {
        head=newNode;
        newNode->next=head;
    }
    else
    {
        struct Node *temp=head;
        for(i=1;i<location-1;i++)
        {
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
        printf("\n Insertion Successful");
    }
    display();
}
void deleteBeginning()
{
    if(head==NULL)
        printf("List is Empty");
    else
    {
        struct Node *temp=head;
        struct Node *last=NULL;
        if(temp->next==head)
        {
            head=NULL;
            free(temp);
        }
        else
        {
            while(temp->next!=head)
                temp=temp->next;
            last=temp;
            temp=head;
            head=head->next;
            free(temp);
            last->next=head;
        }
        printf("\n Deletion Successful");
    }
    display();
}
void deleteEnd()
{

    if(head==NULL)
        printf("List is Empty");
    else
    {
        struct Node *temp1=head;
        struct Node *temp2;
        if(temp1->next==head)
        {
            head=NULL;
            free(temp1);

        }
        else
        {
            while(temp1->next!=head)
            {
                temp2=temp1;
                temp1=temp1->next;
            }
            temp2->next=head;
            free(temp1);
        }

        printf("\n Deletion Successful");
    }
    display();
}
void deleteSpecific(int location)
{
    int i;
    if(head == NULL)
        printf("List is Empty");
    else
    {
        struct Node *temp1=head;
        struct Node *temp2;
        for(i=1;i<location-1;i++)
        {
            if(temp1->next==head)
                printf("\n Element is not found in the list");
            else
            {
                temp2=temp1;
                temp1=temp1->next;
            }
        }
        if(temp1->next==head)
        {
            head = NULL;
            free(temp1);
        }
        else
        {
            if(temp1==head)
            {
                temp2=head;
                while(temp2->next!=head)
                    temp2= temp2 -> next;
                head = head -> next;
                temp2->next=head;
            }
            else
            {
                if(temp1->next==head)
                    temp2->next=head;
                else
                    temp2->next=temp1->next;
                free(temp1);
            }

        }
        printf("\n Deletion Successful");
    }
    display();
}
void display()
{
    if(head == NULL)
        printf("\nList is Empty");
    else
    {
        struct Node *temp = head;
        printf("\n List elements are:\n");
        while(temp -> next != head)
        {
            printf("%d-------->",temp->data);
            temp = temp -> next;
        }
        printf("%d------>%d",temp->data,head->data);
    }
}
int main()
{
    int choice,value,pos;
    while(1)
    {
        printf("\n\nCircular Linked List operation\n");
        printf("1.Insert at Beginning\n");
        printf("2.Insert at End\n");
        printf("3.Insert at location\n");
        printf("4.Delete at Beginning\n");
        printf("5.Delete at End\n");
        printf("6.Delete at location\n");
        printf("7.Display\n");
        printf("8.Exit\n\n");
        printf("Enter the chioce:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter the value to insert:");
                   scanf("%d",&value);
                   insertAtBeginning(value);
                   break;
           case 2:printf("Enter the value to insert:");
                  scanf("%d",&value);
                  insertAtEnd(value);
                  break;
           case 3:printf("Enter the value to insert:");
                  scanf("%d",&value);
                  printf("Enter the position to insert the value:");
                  scanf("%d",&pos);
                  insertAfter(value,pos);
                  break;
           case 4:deleteBeginning();
                  break;
           case 5:deleteEnd();
                  break;
           case 6:printf("Enter the location to delete:");
                  scanf("%d",&pos);
                  deleteSpecific(pos);
                  break;
           case 7:display();
                  break;
           case 8:exit(0);
           default:printf("\nInvalid choice\n\n");
        }
    }
}