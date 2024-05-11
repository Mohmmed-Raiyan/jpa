#include<stdio.h>
#include<stdlib.h>

struct Node
{

    int data;
    struct Node *next;
};
struct Node *head=NULL;
void insertAtBeginning(int value)
{
    struct Node *newNode;
    newNode=malloc(sizeof(struct Node));
    newNode->data=value;
    if (head==NULL)
    {
       newNode->next=NULL;
       head=newNode;
    }
    else
    {
        newNode->next=head;
        head=newNode;
    }
    printf("\n Node insertion successfully at beginning\n");
}
void insertAtEnd(int value)
{
        struct Node *newNode;
        newNode=malloc(sizeof(struct Node));
        newNode->data=value;
        newNode->next=NULL;
        if(head==NULL)
            head=newNode;
        else
        {
            struct Node *temp = head;
            while(temp->next!=NULL)
                temp = temp->next;
            temp->next=newNode;
        }
        printf("\n Node inserted successfully at end\n");
}
void insertPosition(int value,int pos)
{
    int i=0;
    struct Node *newNode;
    newNode=malloc(sizeof(struct Node));
    newNode->data = value;
    if(head==NULL)
    {
        newNode->next=NULL;
        head = newNode;
    }
   else
   {
       struct Node *temp=head;
       for(i=0;i<pos-1;i++)
          temp = te mp->next;
       newNode->next=temp->next;
       temp->next = newNode;
   }
   printf("\n Node inserted successfully\n");
}
void removeBeginning()
{
    if(head == NULL)
        printf("\n\n List is empty");
    else
    {
        struct Node *temp=head;
        if(head->next == NULL)
        {
            head=NULL;
            free(temp);
        }
       else
       {
           head=temp->next;
           free(temp);
           printf("\n Node deleted at the beginning \n\n");
       }
    }

}
void removeEnd()
{
    if(head == NULL)
    {
        printf("\n List is empty\n");
    }
    else
    {
        struct Node *temp1=head;
        struct Node *temp2;
        if(head->next == NULL)
            head=NULL;
        else
        {
            while(temp1->next!=NULL)
            {
                temp2 = temp1;
                temp1 =temp1->next;
            }
            temp2->next=NULL;
        }
        free(temp1);
        printf("\n Node deleted at the end\n\n");
    }

}
void removePosition(int pos)
{
    int i,flag=1;
    if (head==NULL)
        printf("List is empty");
    else
    {
        struct Node *temp1=head;
        struct Node *temp2;
        if (pos == 1)
        {
            head = temp1->next;
            free(temp1);
            printf("\n Node deleted\n\n");
        }
        else
        {
            for(i=0;i<pos-1;i++)
            {
                if(temp1->next!=NULL)
                {
                    temp2 = temp1;
                    temp1=temp1->next;
                }
                else
                {
                    flag=0;
                    break;
                }
            }
            if(flag)
            {
              temp2->next=temp1->next;
              free(temp1);
              printf("\n Node deleted\n\n");
            }
           else
             printf("Position exceeds number of elements.");
        }

    }
}
void display()
{
    if(head==NULL)
         printf("\nList is empty\n");

    else
    {
        struct Node *temp= head;
        printf("\n\n List elements are\n");
        while(temp->next!=NULL)
        {
            printf("data:%d\n",temp->data);
            temp = temp->next;
        }
        printf("data:%d\n",temp->data);

    }
}
int main()
{
     int choice,value,pos;
     while(1)
     {
         printf("\n\nsingly Linked list operatin\n");
         printf("1.Insert at Beginning\n");
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
                    insertPosition(value,pos);
                    break;
             case 4:removeBeginning();
                    break;
             case 5:removeEnd();
                    break;
             case 6:printf("Enter the position which you want to delete:");
                    scanf("%d",&pos);
                    removePosition(pos);
                    break;
             case 7:display();
                    break;

             case 8:exit(0);
             default:printf("\n Invalid Choice\n\n");
         }
     }
}
