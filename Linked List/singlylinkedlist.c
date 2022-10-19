
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int info;
    struct node *link;
}NODE;

typedef struct list{
    NODE *head;
}LLIST;

int init(LLIST *p){
    p->head=NULL;
    return 1;
}

int display(LLIST *p){
    if(p->head==NULL) return 0;

    NODE *temp;
    temp=p->head;

    while(temp->link != NULL){
        printf("%d\n", temp->info);
        temp=temp->link;
    }
    printf("%d\n", temp->info);
    return 1;
}

int insertfront(LLIST *p, int e)
{
    NODE *temp=(NODE*)malloc(sizeof(NODE));
    if(sizeof(temp)==0) return 0;

    temp->info = e;
    temp->link = p->head;
    p->head=temp;
    return 1;
}


int insertback(LLIST *p, int e){
    NODE *temp;
    NODE *temp1=(NODE*)malloc(sizeof(NODE));
    if(sizeof(temp)==0) return 0;

    temp1->info=e;
    temp1->link=NULL;

    temp=p->head;

    while(temp->link != NULL){
        temp=temp->link;
    }

    temp->link=temp1;
    return 1;
}


int deletefront(LLIST *p){
    NODE *temp;
    temp=p->head;
    if(temp==NULL) return 0;
    p->head=temp->link;
    free(temp);
    return 1;
}

int deleteback(LLIST *p){
    NODE *temp=p->head;
    NODE *pre;
    if(temp==NULL) return 0;
    while(temp->link!=NULL){
        pre=temp;
        temp=temp->link;
    }
    pre->link=NULL;
    free(temp);
    return 1;
}

// int insertatposition(LLIST *p, int pos, int e)        //using two temp pointers
// {
//     NODE *temp=p->head;
//     NODE *newnode=(NODE*)malloc(sizeof(NODE));
//     NODE *temp2;

//     newnode->info=e;

//     if(sizeof(temp)==0) return 0;

//     if(pos==1 || p->head==NULL)
//     {
//         newnode->link=p->head;
//         p->head=newnode;
//         return 1;
//     }
//     else
//     {
//         int count=1;

//         while(count<pos && temp->link!=NULL){
//             temp2=temp;
//             temp=temp->link;
//             count++;
//         }

//         newnode->link=temp2->link;
//         temp2->link=newnode;

//         return 1;
    // }
// }

int insertatposition(LLIST *p, int pos, int e)        //using one temp pointer
{
    NODE *temp=p->head;
    NODE *newnode=(NODE*)malloc(sizeof(NODE));

    newnode->info=e;

    if(sizeof(temp)==0) return 0;

    if(pos==1 || p->head==NULL)
    {
        newnode->link=p->head;
        p->head=newnode;
        return 1;
    }
    else
    {
        int count=2;

        while(count<pos && temp->link!=NULL){
            temp=temp->link;
            count++;
        }

        if(temp->link==NULL) return 0; 

        newnode->link=temp->link;
        temp->link=newnode;

        return 1;
    }
}

int deleteatposition(LLIST *p, int pos){
    NODE *temp=p->head;
    NODE *newnode;

    if(sizeof(temp)==0) return 0;

    if(pos==1)
    {
        p->head = temp->link;
        free(temp);
        return 1;
    }
    else
    {
        int count=1;

        while(count<pos && temp->link!=NULL){
            newnode=temp;
            temp=temp->link;
            count++;
        }

        if(temp->link==NULL){
            newnode->link=NULL;
            free(temp);
            return 1;
        }

        newnode->link=temp->link;
        free(temp);

        return 1;
    }

}

int reverselist(LLIST *p){
    
{
    NODE *prev = NULL;
    NODE *current = p->head;
    NODE *next = NULL;

    while (current != NULL) {
        // Store next
        next = current->link;
 
        // Reverse current node's pointer
        current->link = prev;
 
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    p->head = prev;
}

    return 1;
}


int main(){

    printf("\n###SINGLY LINKED LIST IN C###\n\n");

    LLIST list;
    int k, choice, ele=1, pos;

    k=init(&list);
    if(k==1) printf("INITIALZATION SUCCESSFUL\n\n");

    printf("1 -> DISPLAY\n2 -> INSERT IN FRONT\n3 -> DELETE IN FRONT\n4 -> INSERT IN LAST\n5 -> DELETE IN LAST\n6 -> INSERT AT POSITION\n7 -> DELETE AT POSITION\n8 -> REVERSE LIST\n0 -> EXIT\n\n");

    printf("ENTER CHOICE: ");
    scanf("%d", &choice);

    
    // insertfront(&list, ele++);
    // insertfront(&list, ele++);
    // insertfront(&list, ele++);
    // insertfront(&list, ele++);
    // insertfront(&list, ele++);
    // insertfront(&list, ele++);
    // insertfront(&list, ele++);
    // insertfront(&list, ele++);
    // insertfront(&list, ele++);


    do{
        switch(choice){
            case 1:{
                k=display(&list);
                if(k==0) printf("LIST EMPTY...\n\n");
                else printf("DISPLAY SUCCESSFUL...\n\n");
                break;
            }

            case 2:{
                printf("ENTER ELEMENT TO BE INSERTED: ");
                scanf("%d", &ele);
                k=insertfront(&list, ele);
                if(k==0) printf("INSERTION UNSUCCESSFUL...\n\n");
                else printf("INSERTION SUCCESSFUL...\n\n");
                break;
            }

            case 3:{
                k=deletefront(&list);
                if(k==0) printf("DELETION UNSUCCESSFUL...\n\n");
                else printf("DELETION SUCCESSFUL...\n\n");
                break;
            }

            case 4:{
                printf("ENTER ELEMENT TO BE INSERTED: ");
                scanf("%d", &ele);
                k=insertback(&list, ele);
                if(k==0) printf("INSERTION UNSUCCESSFUL...\n\n");
                else printf("INSERTION SUCCESSFUL...\n\n");
                break;
            }

            case 5:{
                k=deleteback(&list);
                if(k==0) printf("DELETION UNSUCCESSFUL...\n\n");
                else printf("DELETION SUCCESSFUL...\n\n");
                break;
            }

            case 6:{
                printf("ENTER ELEMENT TO BE INSERTED: ");
                scanf("%d", &ele);
                printf("ENTER POSITION: ");
                scanf("%d", &pos);
                k=insertatposition(&list, pos, ele);
                if(k==0) printf("INSERTION UNSUCCESSFUL...\n\n");
                else printf("INSERTION SUCCESSFUL...\n\n");
                break;
            }            

            case 7:{
                printf("ENTER POSITION: ");
                scanf("%d", &pos);
                k=deleteatposition(&list, pos);
                if(k==0) printf("DELETION UNSUCCESSFUL...\n\n");
                else printf("DELETION SUCCESSFUL...\n\n");
                break;
            }

            case 8:{
                k=reverselist(&list);
                if(k==0) printf("REVERSAL UNSUCCESSFUL...\n\n");
                else printf("REVERSAL SUCCESSFUL...\n\n");
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