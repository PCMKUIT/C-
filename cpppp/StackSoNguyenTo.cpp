#include <iostream>
#include <string.h>
using namespace std;
// Cấu trúc của một node
struct node {
	int info;
	node* next;
};
// Cấu trúc của một Stack 
struct Stack {
	node* head;
	node* tail;
};
void CreateEmptyStack(Stack &l)
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
void Input(Stack &L,int x){
	node *temp=CreateNode(x);
	if(!L.tail) L.tail=temp;
	else temp->next=L.head;
	L.head=temp;}
	
void Insert(Stack &L,int x){
	node *temp=CreateNode(x);
	if(!L.head) L.head=temp;
	else L.tail->next=temp;
	L.tail=temp;}
	
void CreateStack(Stack &L){
	int x;
	while(true){
		cin>>x;
		if(x==-1) return;
		Input(L,x);}}

bool Check(int x){
	if(x==2) return true;
    if (x%2==0||x==1)  return false;
 	for(int i=3;i<x;i+=2)
    if (x%i==0)  return false;
	return true;}

void Process(Stack &L,Stack &T){
	node *Node=L.head;
	bool block[1000]={0};
	while(Node){
		if(Check(Node->info)&&!block[Node->info]) {
			Insert(T,Node->info);
			block[Node->info]=1;}
		Node=Node->next;}}
		
void PrintStack(Stack L){
	Stack T;
	CreateEmptyStack(T);
	Process(L,T);
	if(!T.head) {
		cout<<"No SNT";return;}
	node *Node=T.head;
	while(Node){
		cout<<Node->info<<" ";
		Node=Node->next;}
	return;}
int main() {
    Stack L;
    CreateEmptyStack(L);
    CreateStack(L);
    PrintStack(L);
    return 0;
}