#include<stdio.h>
#define MAX_SIZE 100
void createList(int list[],int *size);
void insertElement(int list[],int *size,int element,int position);
void deleteElement(int list[],int *size,int element);
int searchElement(int list[],int size,int element);
void displayList(int list[],int size);

int main()
{
    int list[MAX_SIZE];
    int size=0;
    int choice,element,position,index;

    do
    {
        printf("1.Create List\n");
        printf("2.Insert Element\n");
        printf("3.Delete Element\n");
        printf("4.Search Element\n");
        printf("5.Display List\n");
        printf("6.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {

        case 1:
            createList(list,&size);
            break;
        case 2:
            printf("ENTER the element to insert:");
            scanf("%d",&element);
            printf("Enter the position to insert:");
            scanf("%d",&position);
            insertElement(list,&size,element,position);
            break;
        case 3:
            printf("Enter the position to delete:");
            scanf("%d",&position);
            deleteElement(list,&size,position);
            break;
        case 4:
            printf("Enter the element to search:");
            scanf("%d",&element);
            index=searchElement(list,size,element);
            if(index!=-1)
                printf("Element found at position %d\n",index);
            else
                printf("Element not found\n");
            break;
        case 5:
            displayList(list, size);
            break;
        case 6:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invlid choice!Please try again.\n");

        }
        printf("\n");

    }while(choice!=6);
        return 0;
}
void createList(int list[],int *size)
{
    int i,count;
    printf("Enter the number of elements:");
    scanf("%d",&count);
    printf("Enter the elements:\n");
    for(i=0;i<count;i++)
    {
      scanf("%d)",&list[i]);
    }
     *size=count;
     printf("List created successfully.\n");
}
void insertElement(int list[],int *size,int element,int position)
{

    int i;

    if(position < 0 || position > *size)
    {

        printf("invalid position! Insertion failed.\n");
        return;
    }
    for(i= *size;i > position; i--)
    {
        list[i]=list[i-1];

    }
        list[position]=element;
        (*size)++;
        printf("Element inserterd successfully.\n");
}
void deleteElement(int list[],int *size,int position)
{

    int i;
    if (position < 0 || position>=*size)
    {
        printf("Invalid position1 Deletion failed.\n");
        return;

    }
     for(i=position;i<*size-1;i++)
     {
         list[i]=list[i+1];
     }
      (*size)--;
      printf("Element deleted successfully.\n");
}
int searchElement(int list[],int size,int element)
{


    int i;
    for(i=0;i<size;i++)
    {
        if(list[i]==element)
        {
            return i;
        }


    }
     return -1;
}
void displayList(int list[],int size)
{
    int i;
    if(size==0)
    {
        printf("List is empty.\n");
        return;
    }
     printf("List elemnts:");
     for(i=0;i<size;i++)
     {
         printf("%d",list[i]);
     }
      printf("\n");
}
