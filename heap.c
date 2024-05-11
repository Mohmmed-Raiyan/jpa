#include<stdio.h>
#include<stdlib.h>
int array[100],n;
void display();
void insert(int,int);
int main()
{
    int choice,num;
    n=0;
    while(1)
    {
        printf("1.Insert the element \n");
        printf("2.Display all elements \n");
        printf("3.Quit \n");
        printf("Enter your choice :");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the element to be inserted to the list:");
            scanf("%d",&num);
            insert(num,n);
             n = n+1;
            break;
        case 2:
            display();
            break;
        case 3:
            printf("Exiting...\n");
            exit(0);;
        deafault:
            printf("Invalid choice\n");
       }
    }
}
void display()

{
    int i;
    if (n == 0)
    {
        printf("Heap is empty\n");
        return;
    }
    for(i=0;i<n;i++)
     printf("%d", array[i]);
     printf("\n");
}
void insert(int num,int location)
{
    int parentnode;
    while(location > 0)
    {
        parentnode =(location - 1)/2;
        if(num <= array[parentnode])
        {

           array[location] = num;
           return;
        }
        array[location] = array[parentnode];
        location = parentnode;

    }
    array[0] = num;

}
