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

Node* readList()
{
    int n;
    scanf("%d",&n);
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
    return head;
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
int hasDyad(Node *head, int k)
{
    int found=0;
    Node *left=head;
    Node *right=head;
    while(right->next!=NULL)
    {
        right=right->next;
    }
    while(left->val<right->val)
    {
        int val1 = left->val;
        int val2 = right->val;
        if(val1+val2==k)
        {
            found=1;
            break;
        }
        else if(val1+val2>k)
        {
            right=right->prev;
        }
        else
        {
            left=left->next;
        }
    }
    return found;
}

int main()
{
    int k;
    scanf("%d",&k);
    Node *head = readList();
    printf("%d",hasDyad(head,k));
    freeList(head);
    return(0);
}