#include<stdio.h>
#include<stdlib.h>

struct Node_def
{
    int val;
    struct Node_def* ptr;
};

typedef struct Node_def node;



int main()
{
    int n,k;
    scanf("%d %d",&n,&k);

    if(k==1)
    {
        printf("%d",n);
        return(0);
    }

    node *head = NULL;
    node *cur = NULL;

    for(int i=0;i<n;i++)
    {
        node *mynode = (node*)malloc(sizeof(node));
        mynode->ptr = NULL;
        mynode->val = i+1;

        if(head==NULL)
        {
            head = mynode;
        }
        else
        {
            cur->ptr = mynode;
        }
        cur = mynode;
    }
    cur->ptr = head;

    node *temp = head;

    for(int i = 0 ; i<n ; i++)
    {
        for(int j = 1; j<(k-1) ; j++)
        {
            temp = temp->ptr;
        }
        temp->ptr = temp->ptr->ptr;
        temp=temp->ptr;
    }
    printf("%d",temp->val);
    return(0);
}