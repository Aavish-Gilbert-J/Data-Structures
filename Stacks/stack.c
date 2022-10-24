/*
    THIS IS THE LINKED LIST IMPLEMENTATION OF STACK
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node     //One stack level
{
    int info;
    struct node *next;
}NODE;

typedef struct stack{         //stack
    NODE *head;
}STACK;

void init(STACK *pl){          //this is to initialize the first stack level
    pl->head=NULL;
}

int push(STACK *pl, int e)               //this function pushes the element e onto the stack
{         
    NODE *st = (NODE*)malloc(sizeof(NODE));

    if(st==NULL) return 0;

    st->info=e;
    st->next=pl->head;
    pl->head=st;
    return 1;
}

int pop(STACK *pl)               //this function is to pop the element from the stack
{
    NODE *st;
    st=pl->head;
    if(st==NULL) return 0;
    pl->head = st->next;
    free(st);
    return 1;
}

int peek(STACK *pl)             //this function is to view the upper most element of the stack
{
    NODE *st;
    st=pl->head;
    printf("%d\n", st->info);
    return 1;
}

int display(STACK *pl)         //this function is used to display the elements in the stack
{
    NODE *st;
    st=pl->head;

    if(st==NULL) return 0;
    else
    {
        while(st!=NULL){
            printf("%d\n", st->info);
            st=st->next;
        }
    }
    return 1;
}


int main(){
    
    printf("\n###LINKED LIST IMPLEMENTAION OF STACKS IN C###\n\n");

    STACK stack;
    int k, choice, ele=1;

    init(&stack);

    printf("INITIALZATION SUCCESSFUL...\n\n");

    printf("1 -> DISPLAY\n2 -> PUSH\n3 -> POP\n4 -> PEEK\n0 -> EXIT\n\n");

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
                k=peek(&stack);
                if(k==0) printf("PEEK FAILED...\n\n");
                else printf("PEEK SUCCESSFUL...\n\n");
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

