#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct Node_t
{
    int data;
    struct Node_t* next;
};

typedef struct Node_t Node;

Node* createNode(int value)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    assert(newNode!=NULL);
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

Node* addToList(Node * head, int val)
{
    Node *newNode = createNode(val);
    if(head==NULL)
    {
        return newNode;
    }
    Node *cur = head;
    while(cur->next !=NULL)
    {
        cur = cur->next;
    }
    cur->next = newNode;
    return newNode;
}

Node *readList(){
    int n;
    scanf("%d",&n);

    Node *head = NULL;
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);

        if(head==NULL)
        {
            head = addToList(head,x);
        }
        else{
            addToList(head,x);
        }

    }
    return head;
}


void printList(Node *head)
{
    Node *cur = head;
    while(cur!=NULL){
        printf("%d ",cur->data);
        cur = cur->next;
    }
    printf("\n");
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

int findMedian(Node *head)
{
    Node *cur = head;
    int n=0;
    while(cur!=NULL)
    {
        n++;
        cur = cur->next;
    }
    cur = head;
    if(n%2!=0)
    {
        n=(n+1)/2;
        for(int i=0;i<n-1;i++)
        {
           cur=cur->next;
        }
        return cur->data;
    }
    else
    {
        int temp1;
        n=n/2;
        for(int i=0;i<n-1;i++)
        {
            cur=cur->next;
        }
        temp1 = cur->data;
        cur=cur->next;
        return ((temp1 + cur->data)/2);
    }
}




int main (void)
{
    Node *head = readList();
    int median = findMedian(head);
    printf("%d\n",median);
    freeList(head);
    return(0);
}