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
void twoTeams(Node *head)
{
    Node *left=head;
    Node *right=head;
    while(right->next!=NULL)
    {
        right=right->next;
    }
    int sum1 = left->val;
    int sum2 = right->val;
    while(left->next!=right)
    {
        if(sum1<=sum2)
        {
            left=left->next;
            sum1+=left->val;
        }
        else 
        {
            right=right->prev;
            sum2+=right->val;
        }
    }
    while(sum1!=sum2)
    {
        if(sum1>sum2)
        {
            sum1-=left->val;
            left=left->prev;
        }
        else{
            sum2-=right->val;
            right=right->next;
        }
    }
    int val1=0;
    int val2=0;
    while(left!=NULL)
    {
        val1++;
        left=left->prev;
    }
    while(right!=NULL)
    {
        val2++;
        right=right->next;
    }
    printf("%d %d",val1,val2);
}

int main()
{
    Node *head = readList();
    twoTeams(head);
    freeList(head);
    return(0);
}