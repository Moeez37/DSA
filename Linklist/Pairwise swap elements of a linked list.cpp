//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
  Pairwise swap a linked list
  The input list will have at least one element
  node is defined as

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}*head;
*/
class Solution
{
    public:
        Node* pairWiseSwap(struct Node* head) 
    {
        
        if(!head || !head->next) return head;
        else{
                    Node *dummy=new Node(-1);
                    dummy->next=head;
                    Node *prev=dummy;
                    while(head && head->next)
                    { 
                        Node* first=head;
                        Node* second=head->next;
                       
                       prev->next=second;
                       first->next=second->next;
                       second->next=first;
                       
                       prev=first;
                       head=first->next;
                    }
                        return dummy->next;
            }
    
    }
};

//{ Driver Code Starts.

void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
}

int main() 
{ 
	return 0; 
}

// } Driver Code Ends
