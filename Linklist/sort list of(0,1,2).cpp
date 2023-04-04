//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        map <int,int>mp;
        Node* temp=head;
        while(temp!=NULL)
        {
            mp[temp->data]++;
            temp=temp->next;
        }
        temp=head;
        for(auto i:mp)
        {
            int count=i.second;
            while(count>0 && temp !=NULL)
            {
                temp->data=i.first;
                
                temp=temp->next;
                count--;
                
            }
        }
        
    return head;    
    }
};
// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}


int main() {

    return 0;
}

