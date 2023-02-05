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


Node *removeRepeatedNodes(Node *head)
{
    Node *prev = head;
    Node *curr = prev->next;
    while(prev->next->next!=NULL){
        if(prev->data == curr->data)
        {
            while(prev->data == curr->next->data){
                curr = curr->next;
            }
            if(prev==head){
                head=curr->next;
            }
            else{
                prev->next = curr->next;
            }
        }
        prev=prev->next;
        curr=prev->next;
    }
    return head;
}

int main(){
    Node *head = readList();
Node *newList = removeRepeatedNodes(head);
printList(newList);
freeList(head);
freeList(newList);
}