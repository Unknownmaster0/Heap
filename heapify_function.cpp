#include<iostream>
using namespace std;

/*heapify -> The function which tells the correct postion of the node. */

// Heapify function to build the MAX heap
void heapify(int *arr,int size, int idx)
{
    int curr = idx;
    int leftChild = 2 * idx;
    int rightChild = 2 * idx + 1;

    // compare from the left and right child
    if(leftChild <= size && arr[curr] < arr[leftChild])
        curr = leftChild;
    if(rightChild <= size && arr[curr] < arr[rightChild])
        curr = rightChild;

    if(curr != idx)
    {
        swap(arr[curr],arr[idx]);
        heapify(arr,size,curr);
    }
}

// heapify function to build the min Heap
void heapifyMin(int *arr, int n, int idx)
{
    int curr = idx;
    int leftChild = 2 * idx;
    int rightChild = 2 * idx + 1;

    if(leftChild <= n && arr[leftChild] < arr[curr])
        curr = leftChild;

    if(rightChild <= n && arr[rightChild] < arr[curr])
        curr = rightChild;

    if(curr != idx)
    {
        swap(arr[curr],arr[idx]);
        heapifyMin(arr,n,curr);
    }
}


int main()
{
    // int arr[6] = {-1,2,3,4,5,6};
    int arr[6] = {-1,6,5,4,3,2};
    // n -> the size of the array.
    int n = 5;

    for(int i = n/2; i > 0; i--)
    {
        heapifyMin(arr,n,i);
    }
    for(int i = 1; i<=n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}