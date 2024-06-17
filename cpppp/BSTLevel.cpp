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

int Height(TREE T) {
	if(!T) return -1;
	int a = Height(T->pLeft);
	int b = Height(T->pRight);
	return (a > b ? a : b) +1;}

void Level(TREE T,int k,int cnt){
	if(!T) return;
	if(cnt==k) cout<<T->key<<" ";
	Level(T->pLeft,k,cnt+1);
	Level(T->pRight,k,cnt+1);}
         
void Function(TREE T){
	int k;cin>>k;
	if(!T) {cout<<"Empty Tree.";return;}
	if(k<0||k>Height(T)) {cout<<"Khong co node o muc "<<k; return;}
	cout<<"Xuat cac node o muc "<<k<<":\n";
	Level(T,k,0);
	return;}
int main() {
	TREE T;  
	CreateTree(T); 
	Function(T);
	return 0;
}