#include <iostream>
#include <string.h>
using namespace std;
// Cấu trúc của một node
struct node {
	int info;
	node* next;
};
// Cấu trúc của một Queue
struct Queue{
	node* head;
	node* tail;
};
void CreateEmptyQueue(Queue &l)
{
    l.head=NULL;
    l.tail=NULL;
}
node* CreateNode(int x)
{
    node* p = new node();
    if(p==NULL) exit(1);
    p->info=x;
    p->next=NULL;
    return p;
}
void Insert(Queue &L,int x){
	node *temp=CreateNode(x);
	if(!L.head) L.head=temp;
	else L.tail->next=temp;
	L.tail=temp;}
	
int Size(int num){
	int len=0;
	while(num){
		num/=10;len++;}
	return len;}
	
int Pow(int a,int b){
	b--;
	while(b--) a*=10;
	return a;}
		
void CreateQueue(Queue &L){
	string x; cin>>x;
	for(int i=0;i<x.size();i++){
		int Temp,cnt=1;
		while(x[i]==x[i+1]){
			cnt++;i++;}
		Temp=int(x[i])*Pow(10,Size(cnt))+cnt;
		Insert(L,Temp);}
	return;}
void PrintQueue(Queue l)
{
     for(node*p=l.head; p!=NULL; p=p->next)
        cout<<p->info;
}
int main() {
    Queue L;
    CreateEmptyQueue(L);
    CreateQueue(L);
    PrintQueue(L);
    return 0;
}