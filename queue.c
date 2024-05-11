#include<stdio.h>
#include<stdlib.h>
int count=0;
struct node
{

    int info;
    struct node *ptr;

};
struct node *front,*rear,*temp,*front1;
void create()
{
    front=rear=NULL;
}
void queuesize()

{
    printf("\n Queue size:%d",count);
}
int frontelement()

{
    if((front!=NULL)&&(rear!=NULL))
      return (front->info);
      else
         return 0;
}
void  empty()
{
    if((front==NULL)&&(rear==NULL))
        printf("\n Queue empty");
}
void enq(int data)
{
    if(rear==NULL)
    {
        rear=(struct node*)malloc(1*sizeof(struct node));
        rear->ptr=NULL;
        rear->info=data;
        front=rear;
    }
    else
    {
        temp=(struct node*)malloc(1*sizeof(struct node));
        rear->ptr=temp;
        temp->info=data;
        temp->ptr=NULL;
        rear=temp;
    }
    count++;
    printf("\n List of elements in the enqueue\n");
    display();
}
void deq()
{
    front1 = front;
    if(front1 == NULL)
    {
        printf("\n Error:Trying to display elements from empty queue");
        return;
    }
    else
            if(front1->ptr!=NULL)
            {
                front1=front1->ptr;
                printf("\n Dequeue value:%d",front->info);
                free(front);
                front=front1;
            }
            else
            {
                printf("\n Dequeue value:%d",front->info);
                free(front);
                front=NULL;
                rear=NULL;
            }
            count--;
            printf("\n List of Elements in the queue:\n");
            display();

}
void display()
{
    front1=front;
    if((front1==NULL)&&(rear==NULL))
    {
        printf("Queue is empty");
        return;
    }
    while(front1!=rear)
    {
        printf("%d\n",front1->info);
        front1=front1->ptr;
    }
    if(front1==rear)
        printf("%d",front1->info);
}
void main()
{
    int ch,value;
    printf("\n 1:Enqueue");
    printf("\n 2:Dequeue");
    printf("\n 3:front element");
    printf("\n 4:empty");
    printf("\n 5:Display");
    printf("\n 6:Queue");
    printf("\n 7:Exit");
    create();
    while(1)
    {

        printf("\n Enter choice:");
        scanf("%d",&ch);
         switch(ch)
         {
           case 1:
              printf("ENTER DATA:");
              scanf("%d",&value);
              enq(value);
              break;
          case 2:
              deq();
              break;
          case 3:
               value=frontelement();
               if(value!=0)
                printf("Front element:%d",value);
               else
                 printf("\n Queue is empty");
                 break;
          case 4:
              empty();
              break;
          case 5:
              display();
              break;
          case 6:
              queuesize();
              break;
          case 7:
               exit(0);
          default:
                printf("Invalid choice:");
                break;
        }
    }
}
