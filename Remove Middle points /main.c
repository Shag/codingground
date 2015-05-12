#include <stdio.h>

typedef struct node
{
    int x;
    int y;
    struct node * next;
}point;

void push(point **head,int x,int y)
{
    point *new_point=(point *)malloc(sizeof(point));
    new_point->x=x;
    new_point->y=y;
    new_point->next=*head;
    *head=new_point;
}

void print_lines(point *head)
{
    while(head!=NULL)
    {
        if(head->next!=NULL)
            printf("(%d,%d) -> ",head->x,head->y);
        else
            printf("(%d,%d)\n",head->x,head->y);
        head=head->next;
    }
}

void delete_node(point *head,point *Next)
{
    head->next = Next->next;
    Next->next = NULL;
    free(Next);
}

void delete_middle_points(point* head){
    point * Next,*NextNext;
    
    if(head==NULL || head->next == NULL || head->next->next == NULL)
        return;
         
    Next=head->next;
    NextNext=Next->next;
    
    if (head->x == Next->x)
    {
        // Find middle nodes with same x value, and delete them
        while (NextNext !=NULL && Next->x==NextNext->x)
        {
            delete_node(head, Next);
 
            // Update Next and NextNext for next iteration
            Next = NextNext;
            NextNext = NextNext->next;
        }
    }
    else if (head->y==Next->y) // If horizontal line
    {
        // Find middle nodes with same y value, and delete them
        while (NextNext !=NULL && Next->y==NextNext->y)
        {
            delete_node(head, Next);
 
            // Update Next and NextNext for next iteration
            Next = NextNext;
            NextNext = NextNext->next;
        }
    }
    delete_middle_points(head->next);
}

int main()
{
    point *head=NULL;
    
    push(&head, 40,5);
    push(&head, 20,5);
    push(&head, 10,5);
    push(&head, 10,8);
    push(&head, 10,10);
    push(&head, 3,10);
    push(&head, 1,10);
    push(&head, 0,10);
    
    printf("Given set of line segments: \n");
    print_lines(head);
    
    delete_middle_points(head);
    
    if(head!=NULL)
    {
        printf("\nResult:\n");
        print_lines(head);
    }
    return 0;
}



