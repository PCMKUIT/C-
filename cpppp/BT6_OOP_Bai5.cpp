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
	void Xuat(){cout<<"("<<x<<","<<y<<")";}
};

bool Compare(Diem a , Diem b) { 
	if(a.y!=b.y) return a.y>b.y;
	return a.x<b.x;}
	
void QuickSort(Diem arr[] , int left, int right){
    int mid=left+right;
    mid/=2;
    Diem pivot = arr[mid];
    int l = left;
    int r = right;  
    do{ while((l <= right) && Compare(arr[l], pivot)) l++;
        while((r >= left) && Compare(pivot, arr[r]))  r--;
        if(l > r)  break;
        swap(arr[l], arr[r]); l++, r--;
	} while(l <= r);
    if(left < r) QuickSort(arr, left, r);
    if(l < right)QuickSort(arr, l, right);}

class TuGiac{
	protected: Diem A,B,C,D;
	public:
	TuGiac(){A.x=0;A.y=0;B.x=0;B.y=0;C.x=0;C.y=0;D.x=0;D.y=0;}
	TuGiac(float a[8]){A.x=a[0];A.y=a[1];B.x=a[2];B.y=a[3];
					   C.x=a[4];C.y=a[5];D.x=a[6];D.y=a[7];}
	~TuGiac(){}
	virtual void Nhap() = 0;
	
	virtual void Xuat() const {
		cout<<" duoc tao boi 4 dinh: ";
		cout<<"A("<<A.x<<","<<A.y<<"),";
		cout<<"B("<<B.x<<","<<B.y<<"),";
		cout<<"C("<<C.x<<","<<C.y<<"),";
		cout<<"D("<<D.x<<","<<D.y<<")\n";}

	void error () const {
		cout<<" khong hop le, vui long nhap lai toa do ";}
		
	void duplicate (int a) {
		switch(a){
			case 1:cout<<"Dinh B"; error();
				   cout<<"khac toa do cua dinh A";
				   A.Xuat();cout<<": ";
			       B.Nhap(); break;
			case 2:cout<<"Dinh C";error();
				   cout<<"khac toa do cua dinh A";
				   A.Xuat();cout<<" va dinh B";B.Xuat();
				   cout<<": "; C.Nhap(); break;
			case 3:cout<<"Dinh D";error();
				   cout<<"khac toa do cua dinh A";
				   A.Xuat();cout<<", dinh B";B.Xuat();
				   cout<<", dinh C";C.Xuat();
				   cout<<": "; D.Nhap(); break;}}
				   
	void sample (int a, bool b, bool c, int d){
		switch(a){
			case 1: cout<<"Dinh A"; error(); break;
			case 2: cout<<"Dinh B"; error(); break;
			case 3: cout<<"Dinh C"; error(); break;
			case 4: cout<<"Dinh D"; error(); break;}
		cout<<"co";
		(b) ? (cout<<" tung do ") : (cout<<" hoanh do ");
		(c) ? (cout<<"trung voi") : (cout<<"khac voi");
		(b) ? (cout<<" tung do ") : (cout<<" hoanh do ");
		cout<<"cua dinh ";
		switch(d){
			case 1: cout<<"A"; A.Xuat(); break;
			case 2: cout<<"B"; B.Xuat(); break;
			case 3: cout<<"C"; C.Xuat(); break;
			case 4: cout<<"D"; D.Xuat(); break;}}		

	void Ve() const {
		initgraph(&gd, &gm,"");
		Diem E[4];E[0]=A;E[1]=B;E[2]=C;E[3]=D;
		QuickSort(E,0,3);
		line(E[0].x,E[0].y,E[1].x,E[1].y);
		line(E[1].x,E[1].y,E[3].x,E[3].y);
		line(E[2].x,E[2].y,E[3].x,E[3].y);
		line(E[2].x,E[2].y,E[0].x,E[0].y);
		system("pause");
		closegraph();}				
};

class HinhThang : public TuGiac {
	public:
	HinhThang(){}
	~HinhThang(){}
				   
	void Nhap(){
		cout<<"Nhap dinh A cua hinh thang: "; A.Nhap();
		cout<<"Nhap dinh B cua hinh thang: "; B.Nhap();
		while(A.x==B.x&&A.y==B.y) duplicate(1);
		cout<<"Nhap dinh C cua hinh thang: "; C.Nhap();
		while((A.y!=B.y&&C.y!=B.y&&C.y!=A.y)||(A.y==C.y&&B.y==C.y)||(C.x==B.x&&C.y==B.y)||(C.x==A.x&&C.y==A.y)){
			if(A.y!=B.y&&C.y!=B.y&&C.y!=A.y){
				sample(3,1,1,1);
				cout<<" hoac dinh B";B.Xuat();cout<<": ";
				C.Nhap();}
			else if(A.y==C.y&&B.y==C.y){
				sample(3,1,0,1);
				cout<<" va dinh B";B.Xuat();cout<<": ";
				C.Nhap();}
			else duplicate(2);}
		cout<<"Nhap dinh D cua hinh thang: "; D.Nhap();
		if(A.y==B.y){
			while((C.y!=D.y)||(D.x==A.x&&D.y==A.y)||(D.x==B.x&&D.y==B.y)||(D.x==C.x&&D.y==C.y)){
				if(C.y!=D.y){
					sample(4,1,1,3);
					cout<<": ";	D.Nhap();}
				else duplicate(3);}}
		else if(A.y==C.y){
			while((B.y!=D.y)||(D.x==A.x&&D.y==A.y)||(D.x==B.x&&D.y==B.y)||(D.x==C.x&&D.y==C.y)){
				if(B.y!=D.y){
					sample(4,1,1,2);
					cout<<": ";	D.Nhap();}
				else duplicate(3);}}
		else if(B.y==C.y){
			while((A.y!=D.y)||(D.x==A.x&&D.y==A.y)||(D.x==B.x&&D.y==B.y)||(D.x==C.x&&D.y==C.y)){
				if(A.y!=D.y){
					sample(4,1,1,1);
					cout<<": ";	D.Nhap();}
				else duplicate(3);}}}
	
	void Xuat() const { cout<<"Hinh thang"; TuGiac::Xuat(); }
};

class HinhBinhHanh : public TuGiac {
	public:
	HinhBinhHanh(){}
	~HinhBinhHanh(){}
	
	void Nhap(){
		cout<<"Nhap dinh A cua hinh binh hanh: "; A.Nhap();
		cout<<"Nhap dinh B cua hinh binh hanh: "; B.Nhap();
		while(A.x==B.x&&A.y==B.y) duplicate(1);
		cout<<"Nhap dinh C cua hinh binh hanh: "; C.Nhap();
		while((A.y!=B.y&&C.y!=B.y&&C.y!=A.y)||(A.y==C.y&&B.y==C.y)||(C.x==B.x&&C.y==B.y)||(C.x==A.x&&C.y==A.y)){
			if(A.y!=B.y&&C.y!=B.y&&C.y!=A.y){
				sample(3,1,1,1);
				cout<<" hoac dinh B";B.Xuat();
				cout<<": "; C.Nhap();}
			else if(A.y==C.y&&B.y==C.y){
				sample(3,1,0,1);
				cout<<" va dinh B";B.Xuat();
				cout<<": ";	C.Nhap();}
			else duplicate(2);}
		cout<<"Nhap dinh D cua hinh binh hanh: "; D.Nhap();
		float ans1 = B.x - A.x + C.x;
		float ans2 = A.x - B.x + C.x;
		float ans3 = C.x - A.x + B.x;
		float ans4 = A.x - C.x + B.x;
		float ans5 = C.x - B.x + A.x;
		float ans6 = B.x - C.x + A.x;
		if(A.y==B.y){
			while((C.y!=D.y)||(D.x!=ans1&&D.x!=ans2)){
				cout<<"Dinh D";error();cout<<"voi hoanh do co gia tri bang "<<ans1<<" hoac ";
				cout<<ans2<<" va tung do trung voi tung do cua dinh C";C.Xuat();cout<<": ";
				D.Nhap();}}
		else if(A.y==C.y){
			while((B.y!=D.y)||(D.x!=ans3&&D.x!=ans4)){
				cout<<"Dinh D";error();cout<<"voi hoanh do co gia tri bang "<<ans3<<" hoac ";
				cout<<ans4<<" va tung do trung voi tung do cua dinh B";B.Xuat();cout<<": ";
				D.Nhap();}}
		else if(B.y==C.y){
			while((A.y!=D.y)||(D.x!=ans5&&D.x!=ans6)){
				cout<<"Dinh D";error();cout<<"voi hoanh do co gia tri bang "<<ans5<<" hoac ";
				cout<<ans6<<" va tung do trung voi tung do cua dinh A";A.Xuat();cout<<": ";
				D.Nhap();}}}
					  
	void Xuat() const {	cout<<"Hinh binh hanh"; TuGiac::Xuat(); }
};

class HinhChuNhat : public TuGiac {
	public:
	HinhChuNhat(){}
	~HinhChuNhat(){}
	
	void Nhap(){
		cout<<"Nhap dinh A cua hinh chu nhat: "; A.Nhap();
		cout<<"Nhap dinh B cua hinh chu nhat: "; B.Nhap();
		while(A.x==B.x&&A.y==B.y) duplicate(1);
		cout<<"Nhap dinh C cua hinh chu nhat: "; C.Nhap();	
		if(A.y!=B.y&&A.x!=B.x){
			while(!((C.x==A.x&&C.y==B.y)||(C.x==B.x&&C.y==A.y))){
				sample(3,0,1,1);
				cout<<" hoac dinh B";B.Xuat();cout<<" va tung do";
				cout<<" trung voi tung do cua dinh con lai: ";
				C.Nhap();}
			cout<<"Nhap dinh D cua hinh chu nhat: "; D.Nhap();
			if(C.x==A.x){
				while(D.x!=B.x||D.y!=A.y){
					sample(4,0,1,2);
					cout<<" va tung do trung voi tung do cua dinh A";
					A.Xuat();cout<<": "; D.Nhap();}}
			else {  while(D.x!=A.x||D.y!=B.y){
					sample(4,0,1,1);
					cout<<" va tung do trung voi tung do cua dinh B";
					B.Xuat();cout<<": "; D.Nhap();}}}				   
		else if(A.y!=B.y&&A.x==B.x){	
			while((A.y!=B.y&&C.y!=B.y&&C.y!=A.y)||(C.x==B.x&&C.y==B.y)||(C.x==A.x&&C.y==A.y)){
				if(A.y!=B.y&&C.y!=B.y&&C.y!=A.y){
					sample(3,1,1,1);
					cout<<" hoac dinh B";B.Xuat();cout<<": ";
					C.Nhap();}
				else duplicate(2);}
			cout<<"Nhap dinh D cua hinh chu nhat: "; D.Nhap();
			if(C.y==A.y){
				while(D.x!=C.x||D.y!=B.y){
					sample(4,0,1,3);
					cout<<" va tung do trung voi tung do cua dinh B";
					B.Xuat();cout<<": "; D.Nhap();}}
			else {	while(D.x!=C.x||D.y!=A.y){
					sample(4,0,1,3);
					cout<<" va tung do trung voi tung do cua dinh A";
					A.Xuat();cout<<": "; D.Nhap();}}}
		else {while((A.x!=B.x&&C.x!=B.x&&C.x!=A.x)||(C.x==B.x&&C.y==B.y)||(C.x==A.x&&C.y==A.y)){
				if(A.x!=B.x&&C.x!=B.x&&C.x!=A.x){
					sample(3,0,1,1);
					cout<<" hoac dinh B";B.Xuat();
					cout<<": ";	C.Nhap();}
				else duplicate(2);}
			cout<<"Nhap dinh D cua hinh chu nhat: "; D.Nhap();
			if(C.x==A.x){
				while(D.y!=C.y||D.x!=B.x){
					sample(4,0,1,2);
					cout<<" va tung do trung voi tung do cua dinh C";
					C.Xuat();cout<<": "; D.Nhap();}}
			else {	while(D.y!=C.y||D.x!=A.x){
					sample(4,0,1,1);
					cout<<" va tung do trung voi tung do cua dinh C";
					C.Xuat();cout<<": "; D.Nhap();}}}}
	
	void Xuat() const { cout<<"Hinh chu nhat"; TuGiac::Xuat(); }
};

class HinhVuong : public TuGiac {
	public:
	HinhVuong(){}
	~HinhVuong(){}
	
	void Nhap(){
		cout<<"Nhap dinh A cua hinh vuong: "; A.Nhap();
		cout<<"Nhap dinh B cua hinh vuong: "; B.Nhap();
		while((abs(A.x-B.x)!=abs(A.y-B.y)&&(A.x!=B.x&&A.y!=B.y))||(A.x==B.x&&A.y==B.y)){
			if(A.x==B.x&&A.y==B.y) duplicate(1);
			else{
				cout<<"Dinh B";error();cout<<"moi sao cho vector AB";
				cout<<" co dang (k,k) hoac (k,-k) hoac (-k,k) voi k thuoc tap so thuc hoac";
				cout<<" co the nhap mot toa do co hoanh do hoac tung do trung voi dinh A";
				A.Xuat(); cout<<": "; B.Nhap();}}
		cout<<"Nhap dinh C cua hinh vuong: "; C.Nhap();
		if(A.x!=B.x&&A.y!=B.y){
			while(!((C.x==A.x&&C.y==B.y)||(C.x==B.x&&C.y==A.y))){
				sample(3,0,1,1);
				cout<<" hoac dinh B";B.Xuat();
				cout<<" va tung do do trung voi tung do cua dinh con lai: ";
				C.Nhap();}
			cout<<"Nhap dinh D cua hinh vuong: "; D.Nhap();
			if(C.x==A.x){
				while(D.x!=B.x||D.y!=A.y){
					sample(4,0,1,2);
					cout<<" va tung do trung voi tung do cua dinh A";A.Xuat();
					cout<<": "; D.Nhap();}}
			else {  while(D.x!=A.x||D.y!=B.y){
					sample(4,0,1,1);
					cout<<" va tung do trung voi tung do cua dinh B";B.Xuat();
					cout<<": "; D.Nhap();}}}
		else if(A.x!=B.x&&A.y==B.y){
			float ans1=A.y+B.x-A.x, ans2=A.y-B.x+A.x;
			while(!(C.x==A.x||C.x==B.x||C.y==ans1||C.y==ans2)
				|| (C.x==B.x&&C.y==B.y)||(C.x==A.x&&C.y==A.y)){
				if((C.x==B.x&&C.y==B.y)||(C.x==A.x&&C.y==A.y)) duplicate(2);
				else{sample(3,0,1,1);
					 cout<<" hoac dinh B"; B.Xuat();
					 cout<<" va tung do co gia tri bang "<<ans1<<" hoac "<<ans2;
					 C.Nhap();}}
			cout<<"Nhap dinh D cua hinh vuong: "; D.Nhap();
			if(C.x==A.x){
				while(D.y!=C.y||D.x!=B.x){
					sample(4,0,1,2);
					cout<<" va tung do trung voi tung do cua dinh C";
					C.Xuat();cout<<": "; D.Nhap();}}
			else {	while(D.y!=C.y||D.x!=A.x){
					sample(4,0,1,1);
					cout<<" va tung do trung voi tung do cua dinh C";
					C.Xuat();cout<<": "; D.Nhap();}}}
		else {
			float ans1=A.x+B.y-A.y,ans2=A.x-B.y+A.y;
			while(!(C.y==A.y||C.y==B.y||C.x==ans1||C.x==ans2)
				|| (C.x==B.x&&C.y==B.y)||(C.x==A.x&&C.y==A.y)){
				if((C.x==B.x&&C.y==B.y)||(C.x==A.x&&C.y==A.y)) duplicate(2);
				else{
				cout<<"Dinh C";error();cout<<"voi hoanh do co gia tri bang "<<ans1;
				cout<<" hoac "<<ans2<<" va tung do trung voi tung do cua dinh A";
				A.Xuat(); cout<<" hoac dinh B";B.Xuat();cout<<": ";	C.Nhap();}}
			cout<<"Nhap dinh D cua hinh vuong: "; D.Nhap();
			if(C.y==A.y){
				while(D.x!=C.x||D.y!=B.y){
					sample(4,0,1,3);
					cout<<" va tung do trung voi tung do cua dinh B";
					B.Xuat();cout<<": "; D.Nhap();}}
			else {	while(D.x!=C.x||D.y!=A.y){
					sample(4,0,1,3);
					cout<<" va tung do trung voi tung do cua dinh A";
					A.Xuat();cout<<": "; D.Nhap();}}}}
	
	void Xuat() const { cout<<"Hinh vuong"; TuGiac::Xuat();	}
};

class XuLyThongTin{
	private: TuGiac *DuLieu;
	public:
	XuLyThongTin(){}
	~XuLyThongTin(){if(DuLieu!=NULL) {delete [] DuLieu; DuLieu = NULL;}}
	
	void Nhap(){
		int LoaiHinh;
		cout<<"Nhap 1 de nhap du lieu cho hinh thang";
		cout<<"\nNhap 2 de nhap du lieu cho hinh binh hanh";
		cout<<"\nNhap 3 de nhap du lieu cho hinh chu nhat";
		cout<<"\nNhap 4 de nhap du lieu cho hinh vuong";
		cout<<"\nNhap mot so nguyen tu 1 den 4 tuong ung voi hinh muon nhap: ";
		cin>>LoaiHinh;
		while(LoaiHinh!=1&&LoaiHinh!=2&&LoaiHinh!=3&&LoaiHinh!=4){
			cout<<"Cau lenh khong hop le, vui long nhap lai mot so nguyen tu 1 den 4: ";
			cin>>LoaiHinh;}
		switch (LoaiHinh){
			case 1: DuLieu = new HinhThang; break;
			case 2: DuLieu = new HinhBinhHanh; break;
			case 3: DuLieu = new HinhChuNhat; break;
			case 4: DuLieu = new HinhVuong; break;}
		DuLieu->Nhap();}
		
	void Xuat() const { DuLieu->Xuat();	}
	void Ve() const { DuLieu->Ve();	}		
};

int main (){
	XuLyThongTin Hinh;
	Hinh.Nhap();
	Hinh.Xuat();
	Hinh.Ve();
	return 0;}