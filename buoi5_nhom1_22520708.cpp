#include <iostream>
using namespace std;
struct NODE {
int info;
NODE* next;
};
struct LIST {
NODE* head;
NODE* tail;
};
void CreateEmptyList(LIST &l) {
l.head = NULL;
l.tail = NULL;
}
NODE* CreateNode(int x) {
NODE* p = new NODE;
if (p == NULL)
exit(1);
p->info = x;
p->next = NULL;
return p;
}
void AddTail(LIST &L, NODE* p) {
if (L.head == NULL) {
L.head = p;
L.tail = L.head;
}
else {
L.tail->next = p;
L.tail = p;
}
}
void CreateList(LIST &l) {
    cout<<"Nhap so nguyen: "<<endl;
    while(true) {
        int x ; cin >> x ;
        if(x==-1) return;
        NODE* p = CreateNode(x);
        AddTail(l,p) ;
    }
}
int findmax(LIST l) {
    int max=INT_MIN ; 
    for(NODE* P=l.head ; P != NULL ;P=P->next) {
        if(P->info > max) max=P->info;
    }
    return max ;
}
void Print(LIST l) {
    int i=0 ;
    int max =findmax(l); cout<<"Vi tri cac phan tu co gia tri lon nhat trong danh sach lan luot la: ";
    for(NODE* P=l.head ; P != NULL ;P=P->next) {
        if(P->info == max) cout << i<<" ";
        i++;
    }
}
int main() {
LIST L;
CreateEmptyList(L);
CreateList(L);
Print(L);
return 0;
}