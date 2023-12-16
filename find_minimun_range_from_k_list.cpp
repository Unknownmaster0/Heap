// problem link -> https://www.codingninjas.com/studio/problems/smallest-range-from-k-sorted-list_1069356?leftPanelTab=0&leftPanelTabValue=PROBLEM

#include<iostream>
#include<queue>
#include<limits.h>
using namespace std;

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
    while(!q.empty())
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
