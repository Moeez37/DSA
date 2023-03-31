// C++ program to convert a binary tree
// to its mirror
#include <bits/stdc++.h>
#include <queue>
using namespace std;

/* A binary tree node has data, pointer
to left child and a pointer to right child */
struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

/* Helper function that allocates a new node with
the given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
	struct Node* node
		= (struct Node*)malloc(sizeof(struct Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}
void insert(struct Node* node,int key)
{
	if(!node){
		node=newNode(key);
	}
	else{
		struct Node* temp=node;
		while(true)
		{
			if(key>temp->data && temp->right==NULL)
			{
				temp->right=newNode(key);
				break;
			}
			else if(key<temp->data && temp->left ==NULL)
			{
				temp->left=newNode(key);
				break;
			}
		    if(key>temp->data && temp->right!=NULL)
			{
				temp=temp->right;
			}
			else if(key<temp->data && temp->left !=NULL)
			{
				temp=temp->left;
			}
		}
	}
}
/*Inorder traversal.*/
void inOrder(struct Node* node)
{
	if (node == NULL)
		return;

	inOrder(node->left);
	cout << node->data << " ";
	inOrder(node->right);
}
bool mineisbst(struct Node* node)
{
	if(!node)return true;
	else
	{
		queue<Node*> q;
		q.push(node);
		while(q.empty()==false)
		{
			int count=q.size();
			while(count>0)
			{
				Node* temp=q.front();
				q.pop();
				if(temp->right!=NULL && temp->left!=NULL){
				if(!(temp->data<temp->right->data && temp->data>temp->left->data))
				{
					return false;
				}
			}
				if(temp->left)q.push(temp->left);
				if(temp->right)q.push(temp->right);
				count--;
			}
		}
	}
	return true;
}
bool isbst(Node* node, int minVal, int maxVal) {
    if (node == NULL) {
        return true;
    }
    if (node->data < minVal || node->data > maxVal) {
        return false;
    }
    return isbst(node->left, minVal, node->data - 1) && isbst(node->right, node->data + 1, maxVal);
}

bool isBST(Node* node) {
    return isbst(node, INT_MIN, INT_MAX);
}

int main()
{
	struct Node* root = NULL;
	insert(root,10);
	insert(root,14);
	insert(root,12);
	//insert(root,10);
	insert(root,13);
	insert(root,1);
	insert(root,16);
	//insert(root,)
	
	/* Print inorder traversal of the input tree */
	cout << "Inorder traversal of the constructed"
		<< " tree is" << endl;
	inOrder(root);

	/* Convert tree to its mirror */
//	mirror(root);

	/* Print inorder traversal of the mirror tree */
	cout << "\nInorder traversal of the mirror tree"
		<< " is \n";
	inOrder(root);
isBST(root)? cout<<"\n its binary tree \n": cout<<"\n its not binary tree\n";
mineisbst(root)? cout<<"\n its binary tree \n": cout<<"\n its not binary tree\n";

	return 0;
}

// This code is contributed by Akanksha Rai

