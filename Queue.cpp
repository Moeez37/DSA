////Enqueue, Dequeue , Front, Rear
#include <iostream>
using namespace std;

class node;
node* head=NULL;
class node {
	public:
		string data;
		node* next;
		node() {
			this->data="";
			next=NULL;
		}

		void Enqueue(string ss) {
			if(head==NULL) {
				head=new node();
				head->data=ss;
			} else if (head->next==NULL) {
				head->next=new node();
				head->next->data=ss;
			} else {
				node* temp=head;
				while(temp->next!=NULL) {
					temp=temp->next;
				}
				temp->next=new node();
				temp->next->data=ss;
			}
		}
		void Dequeue()  {
			if(head==NULL) {
				cout<<"Queue empty"<<endl;
			
			} else {
				node* temp=head;
				head=temp->next;
				cout<<temp->data<<" : is Dequeue"<<endl;
				delete temp;
				
			}
		}
		void parchi_person(string s){
			
	bool b=false;
	if(head==NULL) {
		cout<<"Person"<<endl;
	} else {
		node* temp=head;
		node* prev=temp;
		while(temp!=NULL) {
			if(temp->data==s) {
				prev->next=temp->next;
				cout<<temp->data<<" :"<<endl;
				delete temp;
				b=true;
			}
			prev=temp;
			temp=temp->next;
		}
	}
	if(b==true) {
		cout<<"Bacha to aja phla Abu ko salam kahna mara"<<endl;
}
		else {cout<<"No match"<<endl;}
	
}

		int lengthof() {
			if(head==NULL)
			{
				cout<<"Queue is empty"<<endl;
				return 0;
			}
		else if(head->next!=NULL) {
				int k=0;
				node *temp=head;
				while(temp!=NULL) {
					temp=temp->next;
					k++;
				}
				return k;
			} else return 1;
		}
		void Display() {
			if(head==NULL) cout<<"Empty Queue"<<endl;
			else {
				if(head->next==NULL) {
					cout<<"Queue contains data"<<endl;
					cout<<"         "<<head->data<<endl;
				} else {
					node *temp=head;
					cout<<"Queue contains data"<<endl;
					while(temp!=NULL) {
						cout<<"         "<<temp->data<<endl;
						temp=temp->next;
					}
				}
			}
		}

};
int main()
{	
}