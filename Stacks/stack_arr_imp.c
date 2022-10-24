/*
    THIS IS THE ARRAY IMPLEMENTATION OF STACK
*/

#include<stdio.h>
#include<stdlib.h>
#define STACKSIZE 100

typedef struct stack  //stack
{
  int top;
  int items[STACKSIZE];
}STACK;

void init(STACK *p)
{
    p->top=-1;
}

/* 
ps is pointer to the structure representing stack
x is integer to be inserted
top is integer that indicates the position of the current stack top within the array 
items is an integer array that represents stack
STACK_SIZE is the maximum size of the stack 
*/
int push(STACK *ps, int x)
{
    if (ps->top == STACKSIZE -1) //check if the stack is full
        return 0;
    else
    {
       ++(ps->top); //increment top
       ps->items[ps->top]=x; //insert the element at a location top
    }
    return 1;
}


/*
ps is pointer to the structure representing stack
top is integer that indicates the position of the current stack top within the array 
items is an integer array that represents stack
STACK_SIZE is the maximum size of the stack 
*/
int pop(STACK *ps )
{
    if (ps->top == -1) // check if the stack is the empty
    {
        return 0;
    }
  else
    {
        int x=ps->items[ps->top]; //delete the element
        --(ps->top); //decrement top
    }
        return 1;
}


/*
ps is pointer to the structure representing stack, 
top is integer that indicates the position of the current stack top within the array 
*/
int peep(STACK *ps )
{
    if (ps->top == -1)
        return 0;
    else
    {
       int x=ps->items[ps->top]; //get the element
       printf("%d\n", x);
    }
    return 1;
}


/*
checks if the stack is empty
*/
int empty(STACK *ps )
{
    if (ps->top == -1)
        return 1;
   return 0;
}


/*
checks for the overflow condition of the stack
*/
int overflow(STACK *ps)
{
    if (ps->top==STACKSIZE-1)
      return 1;
    return 0;
}  


/*
ps is pointer to the structure representing stack, 
top is integer that indicates the position of the current stack top within the array , 
items is an integer array that represents stack, 
STACK_SIZE is the maximum size of the stack 
*/
int display(STACK *ps )
{
    if (ps->top == -1) // check if the stack is the empty
        return 0;
    else
    {
       for (int i=ps->top;i>=0;i--) // displays the elements from top
           printf("%d\n",ps->items[i]);
    }
    return 1;
}


int main()
{

    printf("\n###ARRAY IMPLEMENTAION OF STACKS IN C###\n\n");

    STACK stack;
    int k, choice, ele=1;

    init(&stack);

    printf("INITIALZATION SUCCESSFUL...\n\n");

    printf("1 -> DISPLAY\n2 -> PUSH\n3 -> POP\n4 -> PEEP\n5 -> EMPTY\n6 -> OVERFLOW\n0 -> EXIT\n\n");

    printf("ENTER CHOICE: ");
    scanf("%d", &choice);

    do{
        switch(choice){
            case 1:{
                k=display(&stack);
                if(k==0) printf("LIST EMPTY...\n\n");
                else printf("DISPLAY SUCCESSFUL...\n\n");
                break;
            }

            case 2:{
                printf("ENTER ELEMENT TO BE INSERTED: ");
                scanf("%d", &ele);
                k=push(&stack, ele);
                if(k==0) printf("STACK OVERFLOW CANNOT INSERT...\n\n");
                else printf("INSERTION SUCCESSFUL...\n\n");
                break;
            }

            case 3:{
                k=pop(&stack);
                if(k==0) printf("STACK EMPTY CANNOT POP...\n\n");
                else printf("POP SUCCESSFUL...\n\n");
                break;
            }

            case 4:{
                k=peep(&stack);
                if(k==0) printf("STACK EMPTY...\n\n");
                else printf("PEEP SUCCESSFUL...\n\n");
                break;
            }

            case 5:{
                k=empty(&stack);
                if(k==0) printf("STACK NOT EMPTY...\n\n");
                else printf("STACK EMPTY...\n\n");
                break;
            }

            case 6:{
                k=overflow(&stack);
                if(k==0) printf("NO OVERFLOW...\n\n");
                else printf("OVERFLOW ALERT...\n\n");
                break;
            }

            default:{
                printf("INVALID CHOICE...\n\n");
            }

        }

        printf("ENTER CHOICE: ");
        scanf("%d", &choice);
        if(choice==0) printf("EXITED...\n\n");

    }while(choice!=0);
}


