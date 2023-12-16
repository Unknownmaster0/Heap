/*
condition to convert -> all the values in the left subtree of a node should be less than all the values in the right subtree of the node. This condition is applied to all the nodes, in the resultant converted Min Heap. 
*/
#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
        int data;
        Node* left, *right;
        Node(int val)
        {
            this -> data = val;
            this -> left = NULL;
            this -> right = NULL;
        }
};

int main()
{
    
    return 0;
}