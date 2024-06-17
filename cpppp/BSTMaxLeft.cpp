#include <iostream> 
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE; 
TNODE* CreateNode (int x){
    TNODE* p=new TNODE();
    if (p==NULL) exit(1);
    p->key=x;
    p->pLeft=NULL;
    p->pRight=NULL;
    return p;}
    
void Insert(TREE &T,int x){
    if (T) {
        if (T->key==x) return ;
        if (T->key>x)
            return Insert(T->pLeft,x);
            return Insert(T->pRight,x); }
    T=CreateNode(x);
    return ;}

void CreateTree(TREE &T){
	T=NULL;
    int x;
    while (x!=-1) {
        cin>>x;
        if (x!=-1) Insert(T,x); }}
   
TNODE* SearchNode(TREE T,int x){
    if (T) {
        if(T->key==x)  return T;
        if (T->key>x)
            return SearchNode(T->pLeft,x);
        	return SearchNode(T->pRight,x);}
    return NULL;}  
    
int MaxLeft(TREE T,int max){
	max=T->key;
    if(T->pRight) {max=T->pRight->key; MaxLeft(T->pRight,max);}
	return  max;}
        
void Function(TREE T){
	int x;cin>>x; TNODE* Temp=SearchNode(T,x);
	if(!Temp){cout<<"No Find";return;}
	if(!(Temp->pLeft&&Temp->pRight)) {cout<<"No Node 2"; return;}
	int max=0;
	cout<<MaxLeft(Temp->pLeft,max);
	return;}
int main() {
	TREE T;  
	CreateTree(T); 
	Function(T);
	return 0;
}