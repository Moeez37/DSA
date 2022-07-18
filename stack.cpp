#include <iostream>
using namespace std;

class node;
node *head=NULL;
class node {
	public:
		string s;
		node *next;
		node() {
			s="";
			next=NULL;
		}
		void Display() {
			if(head==NULL) cout<<"Empty List"<<endl;
			else {
				if(head->next==NULL) {
					cout<<"stack contains data"<<endl;
					cout<<"         "<<head->s<<endl;
				} else {
					node *temp=head;
					cout<<"stack contains data"<<endl;
					while(temp!=NULL) {
						cout<<"         "<<temp->s<<endl;
						temp=temp->next;
					}
				}
			}
		}
		int lengthof() {
			if(head==NULL) {
				cout<<"nothing stack is empty"<<endl;
			} else if(head->next!=NULL) {
				int k=0;
				node *temp=head;
				while(temp!=NULL) {
					temp=temp->next;
					k++;
				}
				return k;
			} 
			else return 1;
		}
		void push(string s) {
			if(head==NULL) {
				head=new node();
				head->s=s;
			} else {
				node* temp=new node();
				temp->s=s;
				temp->next=head;
				head=temp;
			}
		}
		int pop() {
			if(head==NULL) {
				cout<<"Stack empty"<<endl;
				return 0;
			} else {
				node* temp=head;
				head=temp->next;
				cout<<temp->s<<"  is poped"<<endl;
				delete temp;
				return 1;
			}
		}
		string peek() {
			cout<<head->s<<" :is at peek"<<endl;
			return head->s;
		}
};

int main() {
	
	return 0 ;
}
