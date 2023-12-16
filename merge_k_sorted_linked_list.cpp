#include<iostream>
#include<vector>

using namespace std;

// question link -> https://www.codingninjas.com/studio/problems/merge-k-sorted-lists_992772?leftPanelTab=0&leftPanelTabValue=SUBMISSION

// Method 1 -> 
Node* mergeKLists(vector<Node*> &list)
{
    vector<int>ans;
    for(int i = 0; i<list.size(); i++)
    {
        Node* temp = list[i];
        while(temp)
        {
            ans.push_back(temp -> data);
            temp = temp -> next;
        }
    }

    sort(ans.begin(),ans.end());

    Node* head = list[0];
    Node* temp = head;
    temp->data = ans[0];
    int j = 1;
    for(int i = 0; i<list.size(); i++)
    {
        while(temp -> next)
        {
            temp = temp -> next;
            temp -> data = ans[j++];
        }

        if(i+1 < list.size())
            temp -> next = list[i+1];
    }
    return head;
}


// Method 2 -> 
class comparator{
    public:
        bool operator()(Node* r1, Node* r2)
        {
            return r1->data > r2 -> data;
        }
};

Node* mergeKLists(vector<Node*> &listArray)
{
    priority_queue<Node*, vector<Node*>, comparator > minheap;

    Node* head = NULL;
    Node* tail = head;

    // pushing the first k nodes in the queue
    // Time complexity -> O(k * logk)
    for(int i = 0; i<listArray.size(); i++)
    {
        // Time complexity -> O(log k)
        minheap.push(listArray[i]);
    }

    // pushing the element from minHeap to the list and also pushing the element of the same linked list to the queue
    // Time complexity -> O(n*k * log k)
    while(!minheap.empty())
    {
        // we came to push our first node
        if(head == NULL)
        {
            head = minheap.top();
            minheap.pop();
            tail = head;

            // pushing the next element of the same list to the minheap
            if(tail->next != NULL)
                minheap.push(tail->next);
        }
        else
        {
            tail->next = minheap.top();
            minheap.pop();
            tail = tail->next;

            if(tail ->next != NULL)
                minheap.push(tail->next);
        }
    }
    return head;
}
