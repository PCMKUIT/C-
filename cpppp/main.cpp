#include <iostream>
#include <graphics.h>
using namespace std;
int gd = DETECT, gm;
class Diem{
	public:
	float x,y;
	Diem(float a=0,float b=0){x=a;y=b;}
	~Diem(){}
	void Nhap(){cout<<"\nNhap hoanh do x: ";cin>>x;
				cout<<"Nhap tung do y: ";cin>>y;}
};

bool cmp(Diem a , Diem b) { 
	if(a.y!=b.y) return a.y>b.y;
	return a.x<b.x;}
	
void quickSort(Diem arr[] , int left, int right){
    int mid=left+right;
    mid/=2;
    Diem pivot = arr[mid];
    int l = left;
    int r = right;  
    do{ while((l <= right) && cmp(arr[l], pivot)) l++;
        while((r >= left) && cmp(pivot, arr[r]))  r--;
        if(l > r)  break;
        swap(arr[l], arr[r]); l++, r--;
	} while(l <= r);
    if(left < r) quickSort(arr, left, r);
    if(l < right)quickSort(arr, l, right);}
    
class HinhThang{
	protected: Diem A,B,C,D;
	public:
	HinhThang(){A.x=0;A.y=0;B.x=0;B.y=0;C.x=0;C.y=0;D.x=0;D.y=0;}
	HinhThang(float a[8]){A.x=a[0];A.y=a[1];B.x=a[2];B.y=a[3];
						  C.x=a[4];C.y=a[5];D.x=a[6];D.y=a[7];}
	~HinhThang(){}
	
	virtual void Nhap(){
		cout<<"Nhap dinh A cua hinh thang: "; A.Nhap();
		cout<<"Nhap dinh B cua hinh thang: "; B.Nhap();
		while(A.x==B.x&&A.y==B.y){
			cout<<"Dinh B khong hop le, vui long nhap lai ";
			cout<<"toa do khac toa do cua dinh A: ";
			B.Nhap();}
		cout<<"Nhap dinh C cua hinh thang: "; C.Nhap();
		while((A.y!=B.y&&C.y!=B.y&&C.y!=A.y)||(A.y==B.y&&A.y==C.y&&B.y==C.y)||(C.x==B.x&&C.y==B.y)||(C.x==A.x&&C.y==A.y)){
			if(A.y!=B.y&&C.y!=B.y&&C.y!=A.y){
			cout<<"Dinh C khong hop le, vui long nhap lai ";
			cout<<"toa do co tung do trung voi dinh A hoac dinh B: ";
			C.Nhap();}
			else if(A.y==B.y&&A.y==C.y&&B.y==C.y){
				 cout<<"Dinh C khong hop le, vui long nhap lai ";
				 cout<<"toa do co tung do khac voi dinh A va dinh B: ";
				 C.Nhap();}
			else {cout<<"Dinh C khong hop le, vui long nhap lai ";
				  cout<<"toa do khac toa do cua dinh A va dinh B: ";
				  C.Nhap();}}
		cout<<"Nhap dinh D cua hinh thang: "; D.Nhap();
		while((D.x==A.x&&D.y==A.y)||(D.x==B.x&&D.y==B.y)||(D.x==C.x&&D.y==C.y)){
			cout<<"Dinh D khong hop le, vui long nhap lai ";
			cout<<"toa do khac toa do cua dinh A, dinh B, dinh C: ";
			D.Nhap();}
		if(A.y==B.y){
			while((C.y!=D.y)||(D.x==A.x&&D.y==A.y)||(D.x==B.x&&D.y==B.y)||(D.x==C.x&&D.y==C.y)){
				if(C.y!=D.y){
				cout<<"Dinh D khong hop le, vui long nhap lai ";
				cout<<"toa do co tung do trung voi dinh C: ";
				D.Nhap();}
				else {cout<<"Dinh D khong hop le, vui long nhap lai ";
					  cout<<"toa do khac toa do cua dinh A, dinh B, dinh C: ";
					  D.Nhap();}}}
		else if(A.y==C.y){
			while((B.y!=D.y)||(D.x==A.x&&D.y==A.y)||(D.x==B.x&&D.y==B.y)||(D.x==C.x&&D.y==C.y)){
				if(B.y!=D.y){
				cout<<"Dinh D khong hop le, vui long nhap lai ";
				cout<<"toa do co tung do trung voi dinh B: ";
				D.Nhap();}
				else {cout<<"Dinh D khong hop le, vui long nhap lai ";
					  cout<<"toa do khac toa do cua dinh A, dinh B, dinh C: ";
					  D.Nhap();}}}
		else if(B.y==C.y){
			while((A.y!=D.y)||(D.x==A.x&&D.y==A.y)||(D.x==B.x&&D.y==B.y)||(D.x==C.x&&D.y==C.y)){
				if(A.y!=D.y){
				cout<<"Dinh D khong hop le, vui long nhap lai ";
				cout<<"toa do co tung do trung voi dinh A: ";
				D.Nhap();}
				else {cout<<"Dinh D khong hop le, vui long nhap lai ";
					  cout<<"toa do khac toa do cua dinh A, dinh B, dinh C: ";
					  D.Nhap();}}}}
	
	virtual void Xuat() const {
		cout<<"Hinh thang duoc tao boi 4 dinh: ";
		cout<<"A("<<A.x<<","<<A.y<<"),";
		cout<<"B("<<B.x<<","<<B.y<<"),";
		cout<<"C("<<C.x<<","<<C.y<<"),";
		cout<<"D("<<D.x<<","<<D.y<<")";}
	
	virtual void Ve() const {
		initgraph(&gd, &gm,"");
		Diem E[4];E[0]=A;E[1]=B;E[2]=C;E[3]=D;
		quickSort(E,0,3);
		line(E[0].x,E[0].y,E[1].x,E[1].y);
		line(E[1].x,E[1].y,E[3].x,E[3].y);
		line(E[2].x,E[2].y,E[3].x,E[3].y);
		line(E[2].x,E[2].y,E[0].x,E[0].y);
		system("pause");
		closegraph();
	}
};

int main (){
	HinhThang a;
	a.Nhap();
	a.Xuat();
	a.Ve();
	return 0;
}