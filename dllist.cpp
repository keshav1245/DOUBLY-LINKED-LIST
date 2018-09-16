#include<iostream>
#include<stdlib.h>
using namespace std;

class Node{
public:
Node* prev;
Node* next;
int data;
};

class dll{
public:
Node * head;
dll(){
head=NULL;
}
Node* createnode(int val);
void addeleatbeg(int val);
void display();
void reverse();
void addeleatlast(int val);
void addafternode(int val);
void addbeforenode(int val);
void deleteatbeg();
void deleteatlast();
void deleteafternode();
void deletebeforenode();
};

int main(){
int value,i;
dll obj;
while(1){
cout<<"\n1.ADD AT BEGINNING\n2.ADD AT LAST\n3.ADD AFTER NODE\n4.ADD BEFORE A NODE\n5.DELETE AT BEGINNING\n6.DELETE AT LAST\n7.DELETE AFTER NODE\n8.DELETE BEFORE NODE\n9.DISPLAY\n10.REVERSE THE LIST\n11.EXIT\nChoose your option : ";
cin>>i;
switch(i){
case 1:
cout<<"Enter value you want to add : ";
cin>>value;
obj.addeleatbeg(value);
break;
case 2:
cout<<"Enter value you want to add : ";
cin>>value;
obj.addeleatlast(value);
break;
case 3:
cout<<"Enter value you want to add : ";
cin>>value;
obj.addafternode(value);
break;
case 4:
cout<<"Enter value you want to add : ";
cin>>value;
obj.addbeforenode(value);
break;
case 5:
obj.deleteatbeg();
break;
case 6:
obj.deleteatlast();
break;
case 7:
obj.deleteafternode();
break;
case 8:
obj.deletebeforenode();
break;
case 9:
obj.display();
break;
case 10:
obj.reverse();
break;
case 11:
exit(0);
break;
}
}
return 0;
}
//create node
Node* dll::createnode(int val){
Node* temp = new Node;
temp->data = val;
return temp;
}
//add at beg
void dll::addeleatbeg(int val){
if(head==NULL){
Node* temp = createnode(val);
temp->prev =NULL;
temp->next=head;
head = temp;
cout<<"\n\nELEMENT ADDED !\n\n";
}else{
Node* temp = createnode(val);
Node*ptr =head;
ptr->prev = temp;
temp->prev =NULL;
temp->next=ptr;
head = temp;
cout<<"\n\nELEMENT ADDED !\n\n";
}
}
//display function
void dll::display(){
if(head==NULL){
cout<<"\n\nEMPTY LIST !\n\n";
return;
}
Node* ptr=head;
cout<<"\n\n";
while(ptr!=NULL){
cout<<ptr->data<<" ";
ptr=ptr->next;
}
cout<<"\n\n";
}
//print reverse
void dll::reverse(){
if(head==NULL){
cout<<"\n\nEMPTY LIST\n\n";
return;
}
Node*ptr=head;
Node* prevp;
while(ptr!=NULL){
prevp=ptr;
ptr=ptr->next;
Node* t = prevp->next;
prevp->next=prevp->prev;
prevp->prev = t;
}
head = prevp;
cout<<"\n\nLIST REVERSED\n\n";
}
//add ele at last
void dll::addeleatlast(int val){
if(head==NULL){
addeleatbeg(val);
return;
}else{
Node* temp = createnode(val);
Node* ptr=head;
while(ptr->next!=NULL){
ptr=ptr->next;
}
ptr->next = temp;
temp->next = NULL;
temp->prev = ptr;
cout<<"\n\nELEMENT ADDED\n\n";
}
}
//add after node
void dll::addafternode(int val){
if(head==NULL){
addeleatbeg(val);
cout<<"AT FIRST POSITION !\n\n";
return;
}else{
int vrepl;
cout<<"Enter value after you want the node to be inserted : ";
cin>>vrepl;
Node* temp = createnode(val);
Node* ptr=head;
while(ptr->data!=vrepl){
ptr=ptr->next;
if(ptr==NULL){
cout<<"\n\nVALUE NOT FOUND !\n\n";
return;
}
}
if(ptr->next==NULL){
temp->next = NULL;
ptr->next = temp;
temp->prev = ptr;
}else{
temp->next = ptr->next;
ptr->next->prev=temp;
ptr->next = temp;
temp->prev = ptr;
}

cout<<"\n\nELEMENT ADDED !\n\n";
}
}
//add before node
void dll::addbeforenode(int val){
if(head==NULL){
addeleatbeg(val);
cout<<"AT FIRST POSITION !\n\n";
return;
}else{
int vrepl;
cout<<"Enter value before you want the node to be inserted : ";
cin>>vrepl;
if(head->data==vrepl){
addeleatbeg(val);
return;
}
Node* temp = createnode(val);
Node* ptr=head;
Node* prevp;
while(ptr->data!=vrepl){
prevp = ptr;
ptr=ptr->next;
if(ptr==NULL){
cout<<"\n\nVALUE NOT FOUND !\n\n";
return;
}
}
temp->next = ptr;
ptr->prev = temp;
temp->prev = prevp;
prevp->next = temp;
cout<<"\n\nELEMENT ADDED !\n\n";
}
}
//delete at beg
void dll::deleteatbeg(){
if(head==NULL){
cout<<"\n\nUnderFlow !\n\n";
return;
}
Node* ptr =head;
head = ptr->next;
if(head==NULL){
cout<<"\n\nELEMENT DELETED\n\n";
delete ptr;
}else{
delete ptr;
head->prev =NULL;
cout<<"\n\nELEMENT DELETED\n\n";
}
}
//delete at last
void dll::deleteatlast(){
if(head==NULL){
cout<<"\n\nUNDERFLOW !\n\n";
return;
}else if(head->next == NULL){
Node* ptr =head;
head= NULL;
delete ptr;
cout<<"\n\nELEMENT DELETED !\n\n";
}else{
Node* ptr = head;
while(ptr->next!=NULL){
ptr=ptr->next;
}
ptr->prev->next = ptr->next;
delete ptr;
cout<<"\n\nELEMENT DELETED !\n\n";
}
}
//delete after node
void dll::deleteafternode(){
if(head==NULL){
cout<<"\n\nUNDERFLOW !\n\n";
return;
}
int value;
cout<<"Enter value after which you want to delete : ";
cin>>value;
Node* ptr = head;
while(ptr->data!=value){
ptr=ptr->next;
}
if(ptr==NULL){
cout<<"\n\nVALUE NOT FOUND !\n\n";
return;
}else if(ptr->next==NULL){
cout<<"\n\nEND OF LIST REACHED !\n\n";
return;
}
Node* delnext =ptr->next;
if(delnext->next==NULL){
ptr->next = delnext->next;
delete delnext;
cout<<"\n\nELEMENT DELETED !\n\n";
}else{
ptr->next = delnext->next;
delnext->next->prev = ptr;
delete delnext;
cout<<"\n\nELEMENT DELETED !\n\n";
}
}
//delete before node
void dll::deletebeforenode(){
if(head==NULL){
cout<<"\n\nUNDERFLOW !\n\n";
return;
}
int value;
cout<<"Enter value before which you want to delete : ";
cin>>value;
Node * ptr=head;
while(ptr->data!=value){
ptr=ptr->next;
}
if(ptr ==NULL){
cout<<"\n\nVALUE NOT FOUND !\n\n";
return;
}else if(ptr->prev==NULL){
cout<<"\n\nLIST AT BEGINNING !\n\n";
return;
}
if(ptr->prev ==head){
ptr->prev = NULL;
delete head;
head = ptr;
cout<<"\n\nELEMENT DELETED !\n\n";
}else{
Node* delpre = ptr->prev;
delpre->prev->next = ptr;
ptr->prev = delpre->prev;
delete delpre;
cout<<"\n\nELEMENT DELETED !\n\n";
}
}
