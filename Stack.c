#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *ptr;
};
struct node *top,*top1,*temp;

int count = 0;

void create()
{
    top = NULL;

}

void stack_count()
{
    printf("\n No. of elements in stack : %d", count);

}

void push(int data)
{
    if(top == NULL)
    {
         top =malloc(sizeof(struct node));
         top->ptr= NULL;
         top->info = data;
    }
    else
    {
       temp =malloc(sizeof(struct node));
       temp->ptr = top;
       temp->info = data;
       top=temp;
    }
    count++;
    display();
}

void display()
{
    top1=top;

    if (top1 == NULL)
    {
        printf("Stack is empty");
        return;
    }
    printf("\n Elements in the stack are:");
    while(top1 != NULL)
    {
        printf("\t %d",top1 -> info);
        top1 = top1 -> ptr;
    }
}
void pop()
{
    top1 = top;

    if(top1 ==NULL)
    {
        printf("\n Error : Typing to pop from empty stack");
        return;
    }
    else
         top1 = top1->ptr;
    printf("\n Popped value : %d", top->info);
    free(top);
    top = top1;
    count--;
    display();
}

int topelement()
{
    return(top->info);
}

void empty()
{
    if (top == NULL)
        printf("\n Stack is Empty");
    else
        printf("\n Stack is not Empty with %d elements",count);
}

void destroy()
{
    top1 = top;

    while(top1 != NULL)
    {
        top1 = top->ptr;
        free(top);
        top = top1;
        top1 = top1 -> ptr;
    }
    free(top1);
    top = NULL;

    printf("\n All stack elements destroyed");
    count = 0;
}
void main()
{
    int no,ch,val;
    printf("\n 1.Push");
    printf("\n 2.Pop");
    printf("\n 3.Top");
    printf("\n 4. Empty");
    printf("\n 5.Display");
    printf("\n 6.Stack Count");
    printf("\n 7.Destroy stack");
    printf("\n 8.Exit");
    create();
    while (1)
    {
        printf("\n Enter choice :");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
             printf("Enter data :");
             scanf("%d", &no);
             push(no);
             break;
        case 2:
             pop();
             break;
        case 3:
             if (top == NULL)
                printf("No elements in stack");
             else
             {
                 val = topelement();
                 printf("\n Top element : %d",val);
             }
             break;
        case 4:
             empty();
             break;
        case 5:
             display();
             break;
        case 6:
             stack_count();
             break;
        case 7:
             destroy();
             break;
        case 8:
             exit(0);
        default:
              printf("Invalid choice ");
              break;
        }
    }
}
