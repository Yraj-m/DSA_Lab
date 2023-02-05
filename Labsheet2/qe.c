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


int isPalindrome(Node *head)
{
    Node *cur = head;
    int n=0;
    while(cur!=NULL){
        n++;
        cur=cur->next;
    }
    int token=1;
    cur = head;
    for(int i=0;i<n/2;i++){
        int temp = cur->data;
        Node *ptr = cur;
        for(int j=0;j<(n-2*i-1);j++){
            ptr=ptr->next;
        }
        if (temp!=ptr->data){
            token=0;
        }
        cur=cur->next;
    }
    return token;
}

int main()
{
    Node *head = readList();
    printf("%d ",isPalindrome(head));
    freeList(head);
    return(0);
}