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
    printf("\n...\n");
    while(head!=NULL)
    {
        printf(" %d ",head->data);
        head=head->next;
    }
}

int isPresent(node *list,int data){
    while(list!=NULL)
    {
        if(list->data==data)
            return 1;
        list=list->next;
            
    }
    return 0;
}

node * find_union(node *head1,node *head2)
{
    node *curr=head1;
    node *result=NULL;
    
    while(curr!=NULL)
    {
        push(&result,curr->data);
        curr=curr->next;
    }
   
    curr=head2;
    while(curr!=NULL)
    {
        if(isPresent(head1,curr->data)==0)
        {
            push(&result,curr->data);
        }
        curr=curr->next;
    }
    return result;
}

node * find_intersection(node *head1,node *head2)
{
    
    node *result=NULL;
    
   
    node *curr=head2;
    while(curr!=NULL)
    {
        if(isPresent(head1,curr->data)==1)
        {
            push(&result,curr->data);
        }
        curr=curr->next;
    }
    return result;
}

void fun(node *head1,node *head2,node **union_head,node **int_head)
{
    node *curr=head1;
    node *uTemp=NULL;
    node *iTemp=NULL;
    
    while(curr!=NULL)
    {
        push(&uTemp,curr->data);
        curr=curr->next;
    }
   
    curr=head2;
    while(curr!=NULL)
    {
        if(isPresent(head1,curr->data)==0)
        {
            push(&uTemp,curr->data);
        }else
        {
            push(&iTemp,curr->data);
        }
        curr=curr->next;
    }
    *union_head=uTemp;
    *int_head=iTemp;
}

int main()
{
//    printf("Hello, World!\n");
    int i,j;
    node *head1=NULL;
    node *head2=NULL;
    node *union1=NULL;
    node *intersection1=NULL;
    
    
    for(i=60;i>0;i-=10)
    {
        push(&head1,i);
        printf("Pushed %d on list1\n",i);
    }
    
    for(j=120;j>0;j-=20)
    {
        push(&head2,j);
        printf("Pushed %d on list2\n",j);
    }
      
    printf("\nlist1:\n");
    print_list(head1);
    printf("\nlist2:\n");
    print_list(head2);
    
    
     
    
    /*union1=find_union(head1,head2);
    intersection1=find_intersection(head1,head2);
    */
    printf("\nCalculating union and intersection...");
    fun(head1,head2,&union1,&intersection1);
    
    printf("\nUnion:\n");
    print_list(union1);
    
    printf("\nIntersection:\n");
    print_list(intersection1);
    
    return 0;
}










