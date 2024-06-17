#include <iostream>
#include <string.h>
using namespace std;

struct point {
    int x, y;
};

struct node {
	point info;
	node* next;
};

struct List {
	node* head;
	node* tail;
};
void CreateEmptyList(List &L){
	L.head=nullptr;
	L.tail=nullptr;}
	
void Insert(List &L,int x,int y){
	node *temp=new node;
	temp->info.x=x;
	temp->info.y=y;
	temp->next=nullptr;
	if(!L.head) L.head=temp;
	else L.tail->next=temp;
	L.tail=temp;}
	
void CreateList(List &L){
	int n;cin>>n;
	if(n==0) return;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		Insert(L,x,y);}}
		
void SortList(List &list){
	for(node *p=list.head;p!=NULL;p=p->next){
		for(node *q=p->next;q!=NULL;q=q->next){
    		if(p->info.x>q->info.x||(p->info.x==q->info.x&&p->info.y>q->info.y)) {
		       int tmp1=p->info.x; int tmp2=p->info.y;
		       p->info.x=q->info.x;
		       q->info.x=tmp1;
		       p->info.y=q->info.y;
		       q->info.y=tmp2;}}}}
		       
void PrintList(List L){
	if(!L.head) return;
	SortList(L);
	node* Node=L.head;
	while(Node){
		cout<<"("<<Node->info.x<<","<<Node->info.y<<")\n";
		Node=Node->next;}}
int main() {
    List L;
	CreateEmptyList(L);
	CreateList(L);
	PrintList(L);
    return 0;
}