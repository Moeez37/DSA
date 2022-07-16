#include <iostream>
using namespace std;

class doubly_list;
doubly_list* head;

class doubly_list {
	public:
		string data;
		doubly_list* next;
		doubly_list* prev;
		doubly_list() {
			data="";
			next=NULL;
			prev=NULL;
		}
		doubly_list(string data) {
			if(head==NULL) {
				head=new doubly_list();
				head->data=data;
			} else {
				doubly_list *temp=head;
				if(temp->next==NULL) {
					temp->next=new doubly_list();
					temp->next->prev=temp;
					temp->next->data=data;
				} else {
					temp=head;
					while(temp->next!=NULL) {
						temp=temp->next;
					}
					temp->next=new doubly_list();
					temp->next->prev=temp;
					temp->next->data=data;
				}

			}
		}

		void Display() {
			if(head==NULL) {
				cout<<"List is Empty!!"<<endl;
			} else {
				doubly_list* temp=head;
				while(temp!=NULL) {
					cout<< "data at node"	<<temp->data<<endl;
					temp=temp->next;
				}
			}
		}
		int lengthof() {
			doubly_list* temp=head;
			if(temp==NULL) {
				cout<<"Empty "<<endl;
				return 0;
			} else {
				int k=0;
				while(temp!=NULL) {
					k++;
					temp=temp->next;
				}
				return k;
			}
		}
		void AddFromFront(string data) {
			doubly_list* temp=new doubly_list();
			temp->data=data;
			head->prev=temp;
			temp->next=head;
			head=temp;
		}
		void AddAt(string data,int position) {
			if(this->lengthof()>position || position==0) { //checking position is not exceding the limit
				cout<<"Insertion at this position is not possible"<<endl;
			} else {
				if(position==1 ) {
					doubly_list* temp=new doubly_list();
					temp->data=data;
					temp->prev=NULL;
					temp->next=head;
					head=temp;
				} else {
					doubly_list* temp=head;
					doubly_list* prev=temp;
					while(position!=1) {
						prev=temp;
						temp=temp->next;
						position--;
					}
					doubly_list* temp1=new doubly_list();
					temp1->data=data;   //storing data
					temp1->next=temp;	//setting next node
					temp1->prev=prev;	//setting previous
					prev->next=temp1;	// adjusting it between prev and next node
					temp->prev=temp1;	//	//	//	//	//	//	//	//	//	//	//


				}

			}
		}
		void DeleteAt(int position) {
			if(this->lengthof()<position || position==0) { //checking position is not exceding the limit
				cout<<"Deletion at this position is not possible"<<endl;
			} else {
				if(position==1) {
					doubly_list* temp;
					temp=head;
					head=temp->next;
					delete temp;
					cout<<"Deleted !!!"<<endl;
				} else {
					doubly_list* temp=head;
					doubly_list* prev=temp;
					while(position!=1) {
						prev=temp;
						temp=temp->next;
						position--;
					}
					if(temp->next==NULL) {
						prev->next=NULL;
						delete temp;
					} else {
						prev->next=temp->next;
						temp->next->prev=prev;
						delete temp;
					}
				}
			}
		}
		void DeleteContent(string data) {
			doubly_list* temp=head;
			if(head==NULL) {
				cout<<"List is Empty"<<endl;
			} else {
				doubly_list* prev=temp;
				while(temp->next!=NULL) {

					if(temp->data==data) {
						prev->next=temp->next;
						prev=temp->next->prev;
						delete temp;
						return;
					}
					prev=temp;
					temp=temp->next;
				}
				if(temp->data==data) {
					prev->next=NULL;
					delete temp;
					if(head==temp) {
						head=NULL;
					}
					return;
				} else {
					cout<<"not found"<<endl;
				}
			}

		}
		void DeleteFromFront() {
			if(head==NULL) {
				cout<<"Empty List Deletion Unsuccessful"<<endl;
			} else {
				doubly_list* temp=head;
				head=head->next;
				head->prev=NULL;
				delete temp;
			}
		}
		void DeleteFromEnd() {
			if(head==NULL) {
				cout<<"Deletion Unsuccessfull Empty List"<<endl;
			} else if(head->next==NULL) {
				delete head;
				head=NULL;

			} else {
				doubly_list* temp=head;
				doubly_list* prev=temp;
				while(temp->next!=NULL) {
					prev=temp;
					temp=temp->next;
				}
				prev->next = NULL;
				delete temp;
			}
		}
};
int main() {
	doubly_list* list;
	list=new doubly_list("most");
	list=new doubly_list("people");
	list=new doubly_list("just ");
	list=new doubly_list("think");
	list->AddFromFront("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
////	list->DeleteContent("just ");
////	list->DeleteContent("most");
////	list->DeleteContent("people");
////	list->DeleteContent("think");
////	list->DeleteContent("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
////	list->AddAt("data",5);
////	list->DeleteFromEnd();
////	list->DeleteFromEnd();
////	list->DeleteAt(0);
	list->Display();
	cout<<list->lengthof()<<endl;
	return 0;
}