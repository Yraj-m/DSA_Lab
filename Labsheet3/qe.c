#include<stdio.h>
#include<stdlib.h>

struct Node_def
{
    int val;
    struct Node_def* next;
    struct Node_def* prev;
};

typedef struct Node_def Node;

Node *createNode(int x)
{
    Node *myNode = (Node*)malloc(sizeof(Node));
    myNode->val=x;
    myNode->next=NULL;
    myNode->prev=NULL;
    return myNode;
}

void freeList(Node *head)
{
    Node *cur,*next;
    cur=head;
    while(cur!=NULL){
        next = cur->next;
        free(cur);
        cur = next;
    }
}

void printList(Node *head)
{
    Node *temp = head;
    while(temp!=NULL)
    {
        printf("%d ",temp->val);
        temp=temp->next;
    }
    printf("\n");
}


Node *rotateList(Node *head, int ind)
{
    Node *cur = head;
    Node *temp =head;
    for(int i=0;i<ind;i++)
    {
        cur=cur->next;
    }
    head = cur;
    cur->prev->next = NULL;
    while(cur->next!=NULL)
    {
        cur=cur->next;
    }
    cur->next=temp;
    temp->prev=cur;
    return head;
}

int main()
{
    int n;
    scanf("%d",&n);
    int k;
    scanf("%d",&k);
    Node *head = NULL;
    Node *ptr = NULL;
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        Node *temp = createNode(x);
        if(head==NULL)
        {
            head = temp;
            ptr=head;
        }
        else
        {
            ptr->next = temp;
            temp->prev = ptr;
            ptr=temp;
        }
    }
    k = k%n;
    k = n-k;
    if(k!=n)
    {
        head = rotateList(head,k);
    }

    
    printList(head);
    freeList(head);
    return(0);
}