#include <iostream>
using namespace std;

// Heapify function to build the MAX heap
void heapify(int *arr, int size, int idx)
{
    int curr = idx;
    int leftChild = 2 * idx;
    int rightChild = 2 * idx + 1;

    // compare from the left and right child
    if (leftChild <= size && arr[curr] < arr[leftChild])
        curr = leftChild;
    if (rightChild <= size && arr[curr] < arr[rightChild])
        curr = rightChild;

    if (curr != idx)
    {
        swap(arr[curr], arr[idx]);
        heapify(arr, size, curr);
    }
}

int main()
{
    int arr[7] = {-1, 7, 6, 8, 10, 2, 13};
    int n = 6;
    for (int i = n / 2; i > 0; i--)
        heapify(arr, n, i);

    cout << "array after buildinig the max heap" << endl;
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << endl;
    // now my max heap is ready
    // now apply the heap sort on the array
    int size = n;
    while (size > 1)
    {
        swap(arr[1], arr[size]);
        size--;
        heapify(arr, size, 1);
    }

    cout << "array after final heap sort" << endl;
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}