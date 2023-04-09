#include<stdio.h>
#include<stdlib.h>


struct Node_def
{
        int val;
        struct Node_def* ptr ;
};

typedef struct Node_def node;

node* push_front(node *head, int x)
{
    node* mynode = (node*)malloc(sizeof(node));
    mynode->ptr = NULL;
    mynode->val = x;
    if(head==NULL)
        return mynode;
    else
    {
        mynode->ptr = head;
        head = mynode;
        return head;
    }
}
node* push_back(node **tail, int x)
{
    node* mynode = (node*)malloc(sizeof(node));
    mynode->ptr = NULL;
    mynode->val = x;

    (*tail)->ptr = mynode;
    return mynode;
}


int main()
{
    int n;
    scanf("%d",&n);
    
    int *arr = (int*)malloc(n*sizeof(int));

    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    node *head = NULL;
    node *tail = NULL;

    head = push_front(head,arr[0]);
    tail = head;

    for(int i=1;i<n;i++)
    {
        if(arr[i]<head->val)
        {
            head = push_front(head,arr[i]);
        }
        else
        {
            tail = push_back(&tail , arr[i]);
        }
    }
    node *cur = head;
    while(cur!=NULL)
    {
        printf("%d ",cur->val);
        cur=cur->ptr;
    }
    free(arr);


}