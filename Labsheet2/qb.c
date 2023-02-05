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


Node *mergedLists(Node *head1, Node *head2)
{
    Node *cur1 = head1;
    Node *cur2 = head2;

    Node *head = NULL;

    while(cur1 != NULL || cur2 != NULL)
    {
        if(cur1==NULL){
             if(head==NULL)
                {
                    head = addToList(head,cur2->data);
                }
                else{
                    addToList(head,cur2->data);
                }
                cur2=cur2->next;
        }
        else if(cur2==NULL){
             if(head==NULL)
                {
                    head = addToList(head,cur1->data);
                }
                else{
                    addToList(head,cur1->data);
                }
                cur2=cur2->next;
        }
        else if(cur1->data<=cur2->data )
        {
                if(head==NULL)
                {
                    head = addToList(head,cur1->data);
                }
                else{
                    addToList(head,cur1->data);
                }
                cur1=cur1->next;
        }
        else
        {
            if(head==NULL)
                {
                    head = addToList(head,cur2->data);
                }
                else{
                    addToList(head,cur2->data);
                }
                cur2=cur2->next;
        }

    }
    return head;
}

int main()
{
    Node *head1 = readList();
    Node *head2 = readList();
    Node * merged = mergedLists(head1,head2);
    printList(merged);
    freeList(head1);
    freeList(head2);
    freeList(merged);

    return(0);

}