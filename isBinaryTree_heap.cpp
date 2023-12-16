#include<iostream>
using namespace std;

// question link -> https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1

int countNodes(Node* root)
{
    if(root == NULL)
        return 0;
        
    int left = countNodes(root->left);
    int right = countNodes(root->right);
    return left + right + 1;
}

bool isCBT(Node* root, int currIdx, int totalNodes)
{
    if(root == NULL)
        return true;
        
    if(currIdx >= totalNodes)
        return false;
        
    bool left = isCBT(root->left, 2 * currIdx + 1, totalNodes);
    bool right = isCBT(root->right, 2 * currIdx + 2, totalNodes);
    
    return left && right;
}

bool isMaxOrder(Node* root)
{
    if(root -> left == NULL && root -> right == NULL)
        return true;
        
    else if(root -> right == NULL)
        return root->data > root -> left -> data;
    
    bool left = isMaxOrder(root->left);
    bool right = isMaxOrder(root->right);
    
    return left && right && (root->data > root->left->data && root->data > root -> right -> data);
}

// here the heap -> MAX HEAP
bool isHeap(struct Node* tree) {
    
    int totalNodes = countNodes(tree);
    
    // the current index of the node which is root.
    int idx = 0;
    return isCBT(tree,idx,totalNodes) && isMaxOrder(tree);
}

int main()
{
    // create a binary tree and send it to the isHeap function, it will return true if the tree is Heap else return false;
    return 0;
}