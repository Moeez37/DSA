////				circular linked list with following functions
////				AddAt(),AddFromFront(),DeleteAt(),DeleteContent(),DeleteFromFront(),DeleteFromEnd(),
////				Display(),lengthof();
////				*****************************coding can be improved so provide others with ease by your extra ordinary coding skills*****************  
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
				head->next=head;
				head->prev=head;
			} else {
				doubly_list *temp=head;
				if(temp->next==head) {
					temp->next=new doubly_list();
					temp->next->prev=temp;
					temp->next->data=data;
					temp->prev=temp->next;
					temp->next->next=head;
				} else {
					temp=head;
					while(temp->next!=head) {
						temp=temp->next;
					}
					temp->next=new doubly_list();
					temp->next->data=data;
					temp->next->prev=temp;
					temp->next->next=head;
					head->prev=temp->next;


				}
			}
		}
		void Display() {
			if(head==NULL) {
				cout<<"List is Empty!!"<<endl;
			} else {
				doubly_list* temp=head;
				cout<<"data at node :: "<<temp->data<<endl;
				temp=temp->next;
				while(temp!=head) {
					cout<<"data at node :: "<<temp->data<<endl;
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
				int k=1;
				temp=temp->next;
				while(temp!=head) {
					temp=temp->next;
					k++;
				}
				return k;
			}
		}
		void AddFromFront(string data) {
			if(this->lengthof()==0) {
				head =new doubly_list(data);
			} else {
				doubly_list* temp=new doubly_list();
				temp->data=data;
				temp->next=head;
				temp->prev=head->prev;
				head->prev->next=temp;
				head=temp;
			}
		}
		void AddAt(string data,int position) {
			
			if(this->lengthof()<position || position==0) { //checking position is not exceding the limit
				cout<<"Insertion at this position is not possible"<<endl;
			} else {
				if(position==1 ) {
					this->AddFromFront(data);

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
					//setting previous
					if(!(position==this->lengthof())) {
						temp1->next=temp;	//setting next node
						temp1->prev=prev;
						prev->next=temp1;
						temp->prev=temp1;
					} else {
						prev->next=temp1;
						temp1->prev=prev;
						temp1->next=head;
						head->prev=temp1;
					}
				}

			}
		}
		void DeleteAt(int position) {
		
			if(this->lengthof()<position || position==0) { //checking position is not exceding the limit
				cout<<"Deletion at this position is not possible"<<endl;
			} else {
				if(position==1){
				
				this->DeleteFromFront();
				}
				 else {
					doubly_list* temp=head;
					doubly_list* prev=temp;
					while(position!=1) {
						prev=temp;
						temp=temp->next;
						position--;
					}
					if(temp->next==head) {
						temp=prev->next;
						prev->next=head;
						head->prev=prev;
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
			} else if (head->data==data) {
				this->DeleteAt(1);
			} else {
				doubly_list* prev=temp;
				while(temp->next!=head) {

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
					prev->next=head;
					head->prev=prev;
					delete temp;
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
					head->next->prev=head->prev;
					head->prev->next=head->next;
					doubly_list* temp=head;
					head=head->next;
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
				this->DeleteAt((this->lengthof()));
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
	list->AddAt("data",5);
	
	list->DeleteContent("think");
	list->Display();
	cout<<list->lengthof()<<endl;
	return 0;
}