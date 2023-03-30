/* Iterative program to print levels line by line */
#include <iostream>
#include <queue>
using namespace std;

// A Binary Tree Node
struct node {
	struct node* left;
	int data;
	struct node* right;
};

// Iterative method to do level order traversal
// line by line
void printLevelOrder(node* root)
{
	// Base Case
	if (root == NULL)
		return;
	
	
	// Create an empty queue for level order traversal
	queue<node*> q;
	q.push(root);
	bool indicator=true;
	while(q.empty()==false)
	{
		
		
		int count=q.size();
		//true for zig and false for zag
		while(count>0)
		{		node* temp=q.front();q.pop();
			cout<<temp->data<<" ";
			if(indicator){
			
			if(temp->left!=NULL)q.push(temp->left);
			if(temp->right!=NULL)q.push(temp->right);
			count--;
			indicator=false;
		}
		else{
			
			if(temp->right!=NULL)q.push(temp->right);
			if(temp->left!=NULL)q.push(temp->left);
			count--;
			indicator=true;
		}
		}
		cout<<endl;
		
	}
}

// Utility function to create a new tree node
node* newNode(int data)
{
	node* temp = new node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

// Driver program to test above functions
int main()
{
	// Let us create binary tree shown above
	node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	printLevelOrder(root);
	return 0;
}

