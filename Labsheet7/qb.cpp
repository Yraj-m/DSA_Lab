#include<iostream>
#include<vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *right;
    TreeNode *left;
    TreeNode(int x): val(x),left(nullptr),right(nullptr){}
};

void printGivenLevel(TreeNode *root, int level){
    if (root == nullptr){
        cout <<"-1 ";
        return;
    }
    if (level == 1){
        cout << root->val << " ";
    }
    else if (level > 1) {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}

int height(TreeNode *root){
    if(root == nullptr){
        return 0;
    }

    int lheight = height(root->left);
    int rheight = height(root->right);
    if(lheight > rheight){
        return lheight+1;
    }
    return rheight+1;
}

void printLevel(TreeNode *root){
    int h = height(root);
    for(int i=1;i<=h;++i){
        printGivenLevel(root,i);
    }
}

TreeNode* createTree(int n, int pre[], int in[], int lb, int ub)
{
    TreeNode *mynode = new TreeNode(pre[lb]);

    if(lb==ub)
    {
        return mynode;
    }
    int i=lb;
    for(i=0;i<n;i++)
    {
        if(pre[lb] == in[i])
            break;
    }

    mynode->left = createTree(n,pre,in,lb+1,i);
    mynode->right = createTree(n,pre,in,i+1,ub);

    return mynode;
}

int main()
{
    int n;
    cin>>n;

    int *pre = new int[n];
    int *in = new int[n];

    for(int i=0;i<n;i++)
    {
        cin>>pre[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>in[i];
    }

    TreeNode *root = createTree(n,pre,in,0,n-1);

    printLevel(root);

    return(0);




}