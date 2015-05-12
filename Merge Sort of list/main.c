#include <stdio.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node * merge_sort(node *first);
node * merge(node *first,node *second);
node * split(node *first);

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

node * merge_sort(node *first)
{
    node *second=NULL;
    if(first==NULL || first->next==NULL)    
        return first;
        
    second=split(first);
    
    first=merge_sort(first);
    second=merge_sort(second);
    
    return merge(first,second);
}

node * merge(node *first,node *second)
{
    node *result=NULL;
    if(first==NULL)
        return second;
    else if(second==NULL)
        return first;
    else if(first->data<=second->data)
    {
        result=first;
        result->next=merge(first->next,second);
    }   
    else
    {
        result=second;
        result->next=merge(second->next,first);
    }
    return result;
}

node * split(node *first)
{
    node *second=NULL;
    node *slow=first;
    node *fast=first;
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    second=slow->next;
    slow->next=NULL;
    return second;
}


int main()
{
//    printf("Hello, World!\n");
    int i;
    node *head=NULL;
    
    push(&head, 15);
    push(&head, 10);
    push(&head, 5); 
    push(&head, 20);
    push(&head, 3);
    push(&head, 2);
    
    printf("Given list:");
    print_list(head);
    printf("Swapping..\n");
    head=merge_sort(head);
    printf("Result:\n");
    print_list(head);
    return 0;
}



