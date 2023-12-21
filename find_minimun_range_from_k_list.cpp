// problem link -> https://www.codingninjas.com/studio/problems/smallest-range-from-k-sorted-list_1069356?leftPanelTab=0&leftPanelTabValue=PROBLEM

#include<iostream>
#include<queue>
#include<limits.h>
using namespace std;

/*Approach -> 
            step 1 -> Make a user defined data type, as we need to move to the next element in the list and also keep record of which list we 
                        are incrementing the element.
                    push the first k element of the list into the minHeap
                    keep track of the maximum element while traversing.

            step 2 -> use start and end indexes for the ranges calcultion.
                    initialise the start with the top element of the heap and end with the maximum element.

            step 3 -> Now, iterate over the heap, till it not becomes empty
                        inside the loop do follwing things
                    1. update the start and end indexes of the range.

                    2 a. if and only if the size of next element is inside the range of the list then only push into the heap
                    2 b. push the next element of the minimum element and update the maximum element

                    ******** Reason why we are pushing the mini next element into the minHeap not the maxi next element or both ********
Till, here we get the range. But not the smallest range, to get the smallest range we do two things......
1. either we decrease the max element
2. or we increse the minimum element
then only our (range = maxi - mini) will decrease.
But, we can't decrese the maxi, as it is the first element of some array and if we decrease the maxi, then the element of that array will not include into the range as the data of the array is in sorted form. [use your pen and paper and do the thing, then get more understanding.]
Thus, we have to increase the mini only, thats why here we are pushing the next element of the mini not the maxi.
*/


class element{
    public:
        int data;
        int row;
        int col;

    element(int val, int row,int col)
    {
        this->data = val;
        this->row = row;
        this->col = col;
    }
};

class comparator{
    public:
        bool operator() (element* e1 , element* e2)
        {
            return e1->data > e2 -> data;
        }
};

int kSorted(vector<vector<int>> &a, int k, int n) {
    priority_queue<element*, vector<element*> , comparator > q;
    int maxi = INT_MIN;
    for(int i = 0; i<k; i++)
    {
        maxi = max(maxi, a[i][0]);
        element* temp = new element(a[i][0], i , 0);
        q.push(temp);
    }
    int mini = q.top()->data;
    int start = mini, end = maxi;
    // cout<<"start -> "<<start<<" end -> "<<end<<endl;
    while(q.size() > 0)
    {
        // update the range of start and end
        element* temp = q.top();
        q.pop();

        int row = temp->row;
        int col = temp->col;
        mini = temp->data;
        if(maxi-mini < end-start)
        {
            end = maxi;
            start = mini;
        }

        //push the element into the heap
        if(col + 1 < n)
        {
            maxi = max(maxi, a[row][col+1]);
            q.push(new element(a[row][col+1], row, col+1));
        }
        else
            break;
    }

    return end-start+1;
}
