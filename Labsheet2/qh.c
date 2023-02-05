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


Node *removeSlide(Node* head,int k)
{
    int n=0;
    Node *cur = head;
    while(cur!=NULL){
        n++;
        cur=cur->next;
    }
    if(k==n){
        head = head->next;
        return head;
    }
    cur=head;
    n=n-k-1;
    while(n--){
        cur=cur->next;
    }
    cur->next=cur->next->next;
    return head;
}

int main()
{
    int k;
    scanf("%d",&k);
    Node *head = readList();
    Node *corrected = removeSlide(head,k);
    printList(corrected);
    freeList(corrected);
    freeList(head);
    return(0);
}