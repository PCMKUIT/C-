#include <iostream>
using namespace std;
struct TIME{
    int gio,phut,giay;
};
 
struct node {
	TIME info;
	node* next;
};

struct List{
	node* head;
	node* tail;
};
void CreateEmptyList(List &L){
	L.head=nullptr;
	L.tail=nullptr;}
	
void Insert(List &L,int h,int m,int s){
	node *temp=new node;
	temp->info.gio=h;
	temp->info.phut=m;
	temp->info.giay=s;
	temp->next=nullptr;
	if(!L.tail) L.tail=temp;
	else temp->next=L.head;
	L.head=temp;}
	
void CreateList(List &L){
	int n;cin>>n;
	if(n==0) return;
	CreateEmptyList(L);
	for(int i=0;i<n;i++){
		int hour,minute,second;
		cin>>hour>>minute>>second;
		Insert(L,hour,minute,second);}
	return;}
		
void Format(List &L){
	node* Node=L.head;
	while(Node){
		while(Node->info.giay>59||Node->info.phut>59||Node->info.gio>23){
			if(Node->info.giay>59) {Node->info.giay-=60;Node->info.phut+=1;}
			if(Node->info.phut>59) {Node->info.phut-=60;Node->info.gio+=1;}
			if(Node->info.gio>23) Node->info.gio-=24;}
			Node=Node->next;}
	return;}
		       
void PrintList(List L){
	if(!L.head) return;
	Format(L);
	node* Node=L.head;
	while(Node){
		cout<<Node->info.gio<<"h"<<Node->info.phut<<"p"<<Node->info.giay<<"s\n";
		Node=Node->next;}}
int main() {
    List L;
    CreateList(L);
    PrintList(L);
    return 0;
}