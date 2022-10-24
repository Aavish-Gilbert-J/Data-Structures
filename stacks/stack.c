#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int info;
    struct node *next;
}NODE;


typedef struct stack{
    NODE *head;
}STACK;

void init(STACK *pl){
    pl->head=NULL;
}

int push(STACK *pl, int e){
    NODE *st = (NODE*)malloc(sizeof(NODE));
    st->info=e;
    st->next=pl->head;
    pl->head=st;
}

int pop(STACK *pl)
{
    NODE *st;
    st=pl->head;
    printf("The popped element is: %d", st->info);
    pl->head = st->next;
    free(st);
}

int peek(STACK *pl)
{
    NODE *st;
    st=pl->head;
    printf("The peek element is: %d\n", st->info);

}

void display(STACK *pl){
    NODE *st;
    st=pl->head;

    if(st==NULL) printf("Empty list\n");
    else
    {
        while(st!=NULL){
            printf("%d\n", st->info);
            st=st->next;
        }
    }
}




int main()
{
    STACK s;
    init(&s);
    push(&s, 5);
    push(&s, 4);
    push(&s, 3);
    push(&s, 2);
    //pop(&s);
    push(&s, 1);
    push(&s, 10);
    push(&s, 100);
    //display(&s);
    //pop(&s);
    //printf("\n-----------\n");

   
    peek(&s);

    //push(&s, 10000);

    display(&s);
}















