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

bool SearchNode(int A[],TREE T,int x,int &cnt){
    if (T!=NULL) {
        if(T->key==x) return true;
        A[cnt++]=T->key;
        if (T->key>x)
            return SearchNode(A,T->pLeft,x,cnt);
        	return SearchNode(A,T->pRight,x,cnt);}
    return false;}

void Function(TREE T){
	int x; cin>>x; int ans[500]={0}; int cnt=ans[0];
	if(x==T->key) {cout<<"Root no ancestor";return;}
	if(!SearchNode(ans,T,x,cnt)){cout<<"No Find";return;}
	for(int i=0;i<500;i++) {
		if(ans[i]==0) return;
		cout<<ans[i]<<" ";}
	return;}
int main() {
	TREE T;  
	CreateTree(T); 
	Function(T);
	return 0;
}