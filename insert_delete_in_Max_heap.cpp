#include <iostream>
using namespace std;

class heap
{
public:
    int *arr;
    int curr;
    int size;

    heap(int size)
    {
        this->size = size;
        arr = new int[size];
        curr = 0;
    }

    void insert(int val);
    void deleteRoot();

    void print()
    {
        int itr = 1;
        while (itr <= curr)
        {
            cout << arr[itr] << " ";
            itr++;
        }
        cout << endl;
        return;
    }
};

// Time complexity -> O(log N) -> As we are traversing the half part of the tree.
void heap::insert(int val)
{
    curr ++;
    int idx = curr;
    arr[idx] = val;

    while (idx > 1)
    {
        // find the parent and check if the child is smaller then the parent node, then only it will become the max heap
        int parent = idx / 2;
        if (arr[idx] > arr[parent])
        {
            swap(arr[idx], arr[parent]);
            idx = parent;
        }
        else
            break;
    }
    return;
}

// Time complexity -> O(log N) -> As we are traversing the half part of the tree.
void heap::deleteRoot()
{
    if(curr == 0)
    {
        cout<<"nothing to print."<<endl;
        return;
    }

    // step 1 -> put the last index at the first index
    arr[1] = arr[curr];
    // step 2 -> delete the last element.
    curr--;

    //step3 ->  make the curr node at its correct position
    int idx = 1;
    while(idx <= curr)
    {
        int i = idx;
        // find the child node.
        int leftChild = 2*idx;
        int rightChild = 2 *idx + 1;

        if(leftChild <= curr && arr[idx] < arr[leftChild])
        {
            swap(arr[idx],arr[leftChild]);
            idx = leftChild;
        }

        else if(rightChild <= curr && arr[idx] < arr[rightChild])
        {
            swap(arr[idx],arr[rightChild]);
            idx = rightChild;
        }
/*
        if(idx != i)
        {
            swap(arr[idx],arr[i]);
        }
*/
        else    
            break;
    }
    return;
}

int main()
{
    int size;
    cout<<"size of heap -> ";cin>>size;
    heap h(size);
    int itr = 1;
    int num;
    while (itr <= size)
    {
        cout << "enter data -> ";
        cin >> num;
        h.insert(num);
        itr++;
    }
    h.print();
    h.deleteRoot();
    h.print();
    return 0;
}