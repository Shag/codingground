#include <stdio.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}node;

void push(node **head,int data)
{
   
    
    node *new_node=(node *)malloc(sizeof(node));
     
    new_node->data=data;
    new_node->prev=NULL;
    new_node->next=(*head);
   
    if((*head)!=NULL)
        (*head)->prev=new_node;
   
    (*head)=new_node;
  
}

/*void push(struct node** head_ref, int new_data)
{
   
    struct node* new_node =
            (struct node*) malloc(sizeof(struct node));
  
  
    new_node->data  = new_data;
     
   
    new_node->prev = NULL;
  
      
    new_node->next = (*head_ref);    
 
   
    if((*head_ref) !=  NULL)
      (*head_ref)->prev = new_node ;    
  
   
    (*head_ref)    = new_node;
}*/

void print_list(node *head)
{
    while(head!=NULL)
    {
         printf("\n %d ",head->data);
         head=head->next;
    }
}

void reverse(node **head){
    node *curr=*head;
    node *tmp=NULL;
    while(curr!=NULL)
    {
        tmp=curr->prev;
        curr->prev=curr->next;
        curr->next=tmp;
        curr=curr->prev;
        
    }
      if(tmp!=NULL)
        (*head)=tmp->prev;
}

int main()
{
    
    node *head=NULL;
    push(&head, 2);
      push(&head, 4);
      push(&head, 8);
      push(&head, 10);
      
      printf("\n Original Linked list ");
      print_list(head);
      
     
      reverse(&head);
      
      printf("\n Reversed Linked list ");
      print_list(head);           
    return 0;
}






