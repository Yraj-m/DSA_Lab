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

Node *sortList(Node *head)
{
    Node *prev = head;
    Node *cur = head;
    int swap =1;
    while(swap)
    {
        prev = head;
        cur = head;
        swap=0;
        while(cur->next!=NULL)
        {
            if(cur->data > cur->next->data){
                if(cur==head){
                    head = cur->next;
                    prev->next = head->next;
                    head->next = prev;
                    prev = head;
                }
                else{
                    prev->next = cur->next;
                    cur->next = prev->next->next;
                    prev->next->next = cur;
                    prev = prev->next;
                }
                swap = 1;
            }
            else{
                if(cur!=head)
                    prev=prev->next;
                cur=cur->next;
            }
        }
    }
    return head;
}
int main()
{
    Node *head = readList();
    Node *sorted = sortList(head);
    printList(sorted);
    freeList(head);
    freeList(sorted);
    return(0);
}




