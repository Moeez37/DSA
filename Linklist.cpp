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
		node(string ss) {
			if(head==NULL) {
				head=new node();
				head->s=ss;
			} else if (head->next==NULL) {
				head->next=new node();
				head->next->s=ss;
			} else {
				node* temp=head;
				while(temp->next!=NULL) {
					temp=temp->next;
				}
				temp->next=new node();
				temp->next->s=ss;
			}
		}
//                                 Member Functons
		void AddAt(string s,int position);
		void AddAtFornt(string s);
		void DeleteAt(int position);
		void DeleteContent(string s);
		void DeleteFromFront();
		void Display();
		int lengthof();
};

int main() {
	/* implement your own code using given functions  */
	return 0 ;
}
void node::Display() {
	if(head==NULL) cout<<"Empty List"<<endl;
	else {
		if(head->next==NULL) {
			cout<<"List contains data"<<endl;
			cout<<"         "<<head->s<<endl;
		} else {
			node *temp=head;
			cout<<"List contains data"<<endl;
			while(temp!=NULL) {
				cout<<"         "<<temp->s<<endl;
				temp=temp->next;
			}
		}
	}
}
void node::AddAtFornt(string s) {
	node* first=head;
	head=new node();
	head->next=first;
	head->s=s;
};
int node::lengthof() {
	if(head->next!=NULL) {
		int k=0;
		node *temp=head;
		while(temp!=NULL) {
			temp=temp->next;
			k++;
		}
		return k;
	} else return 1;
}
void node::AddAt(string s,int position) {
	if(!(position<=this->lengthof())|| position==0) {
		cout<<"insertion at this position is not possible"<<endl;
	} else {
		node* temp=head;
		node* prev;
		if(position==1) {
			node* new_node=new node();
			new_node->s=s;
			new_node->next=temp;
			head=new_node;
			cout<<"Added Sucessfully"<<endl;
		} else {
			while(position != 1) {
				position--;
				prev=temp;
				temp=temp->next;

			}
			node* new_node=new node();
			new_node->s=s;
			new_node->next=temp;
			prev->next=new_node;
			cout<<"Added Sucessfully"<<endl;
		}
	}
}

void node::DeleteContent(string s) {
	bool b=false;
	if(head==NULL) {
		cout<<"Empty List"<<endl;
	} else {
		node* temp=head;
		node* prev;
		while(temp!=NULL) {
			if(temp->s==s) {
				prev->next=temp->next;
				delete temp;
				b=true;
			}
			prev=temp;
			temp=temp->next;
		}
	}
	if(b==true) {
		cout<<"Deleted!!!"<<endl;
	} else {
		cout<<"No match"<<endl;
	}
}
void node::DeleteAt(int position) {
	if(!(position<=this->lengthof())|| position==0) {
		cout<<"Deletion at this position is not possible"<<endl;
	} else {
		node* temp=head;
		node* prev;
		if(position==1) {
			head=temp->next;
			delete temp;
		} else {
			while(position!=1) {
				prev=temp;
				temp=temp->next;
				position--;
			}
			prev->next=temp->next;
			delete temp;
			cout<<"Deleted !!!"<<endl;
		}
	}
}
void node::DeleteFromFront() {
	node* temp=head->next;
	delete head;
	head=temp;
}

