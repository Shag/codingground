#include <stdio.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

void push(node **head_ref,int data){
    node *new_node=(node *)malloc(sizeof(node));
    new_node->data=data;
    new_node->next=*head_ref;
    *head_ref=new_node;
}

void print_list(node * head)
{
    while(head!=NULL)
    {
        printf(" %d ",head->data);
        head=head->next;
    }
}

void pairwise_swap(node ** head_ref)
{
    node *prev=NULL; node * curr= *head_ref; node *next=NULL;
    
    while(curr!=NULL && curr->next!=NULL){
        if(prev!=NULL)
            prev->next=curr->next;
        else
            *head_ref=curr->next;
            
        next=curr->next;
        curr->next=next->next;
        next->next=curr;
        prev=curr;
        curr=curr->next;
        
    }
    
}

int main()
{
//    printf("Hello, World!\n");
    int i;
    node *head=NULL;
    for(i=60;i>0;i-=10)
    {
        push(&head,i);
        printf("Pushed %d\n",i);
    }
    printf("Given list:");
    print_list(head);
    printf("Swapping..\n");
    pairwise_swap(&head);
    printf("Result:\n");
    print_list(head);
    return 0;
}


