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

Node *addtoList(Node *head, int x)
{
    Node *myNode = createNode(x);
    if(head==NULL)
    {
        return myNode;
    }
    Node *temp = head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next = myNode;
    myNode->prev=temp;
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

void currentSong(Node *cur)
{
    printf("%d\n",cur->val);
}

void playPrev(Node **cur)
{
    if((*cur)->prev!=NULL)
    {
        (*cur) = (*cur)->prev;
    }
}
void playNext(Node **cur)
{
    if((*cur)->next!=NULL)
    {
        (*cur) = (*cur)->next;
    }
}

void printList(Node *head)
{
    Node *temp = head;
    while(temp!=NULL)
    {
        printf("%d->",temp->val);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    Node *head = readList();
    Node *cur = head;
    int cont =1;
    while(cont){
        int n;
        scanf("%d",&n);
        switch(n)
        {
            case 1:
            {
            int x;
            scanf("%d",&x);
            head = addtoList(head,x);
            break;
            }
            case 2:
            currentSong(cur);
            break;
            case 3:
            playNext(&cur);
            break;
            case 4:
            playPrev(&cur);
            break;
            case 5:
            cont=0;
            break;
        }
    }
    freeList(head);
    return(0);
}