#include <iostream>
#include <graphics.h>
using namespace std;
int gd = DETECT, gm;
class Elip {
	protected: float X,Y;
			   float BanTrucDai,BanTrucNgan; 
	public:
	Elip(float x=0, float y=0, float l=0, float s=0) {
		X=x; Y=y; BanTrucDai=l; BanTrucNgan=s;}
	~Elip(){}
	
	void error (bool control) const {
		cout<<"Do dai cua ban truc ";
		(control) ? (cout<<"dai") : (cout<<"ngan");
		cout<<" phai lon hon 0, vui long nhap lai: ";}
	
	virtual void Nhap(){
		cout<<"Nhap hoanh do tam cua ellipse: "; cin>>X;
		cout<<"Nhap tung do tam cua ellipse: ";  cin>>Y;
		cout<<"Nhap do dai ban truc dai cua ellipse: "; cin>>BanTrucDai;
		while(BanTrucDai<=0) {error(1); cin>>BanTrucDai;}
		cout<<"Nhap do dai ban truc ngan cua ellipse: "; cin>>BanTrucNgan;
		while(BanTrucNgan>BanTrucDai||BanTrucNgan<=0){
			if(BanTrucNgan<=0) {error(0); cin>>BanTrucNgan;}
			else{
			cout<<"Do dai cua ban truc ngan khong the lon hon do dai ";
			cout<<"cua ban truc dai, vui long nhap lai mot so nho hon: ";
			cin>>BanTrucNgan;}}}
	
	virtual void Xuat() const {
		cout<<"Ellipse co tam ("<<X<<","<<Y<<")";
		cout<<" voi do dai ban truc dai la "<<BanTrucDai;
		cout<<" va do dai ban truc ngan la "<<BanTrucNgan<<endl;}
	
	virtual void Ve() const {
		initgraph(&gd, &gm,"");
		fillellipse(X,Y,BanTrucDai,BanTrucNgan);
		system("pause");
		closegraph();}
};

class HinhTron : public Elip {
	private: float BanKinh;
	public:
	HinhTron(float x=0, float y=0, float r=0): 
	Elip(x,y,r,r){ BanKinh=r;}
	~HinhTron(){};
	
	void Nhap(){
		cout<<"Nhap hoanh do tam cua hinh tron: "; cin>>X;
		cout<<"Nhap tung do tam cua hinh tron: ";  cin>>Y;
		cout<<"Nhap do dai ban kinh cua hinh tron: "; cin>>BanKinh;
		while (BanKinh<=0){
			cout<<"Do dai cua ban kinh phai lon hon 0";
			cout<<", vui long nhap lai: "; cin>>BanKinh;}}
	
	void Xuat() const {
		cout<<"Hinh tron co tam ("<<X<<","<<Y<<")";
		cout<<" voi do dai ban kinh la "<<BanKinh<<endl;}
	
	void Ve() const {
		initgraph(&gd, &gm,"");
		circle(X,Y,BanKinh);
		floodfill(X,Y,WHITE);
		system("pause");
		closegraph();}
};

class XuLyThongTin{
	private: Elip *DuLieu;
	public:
	XuLyThongTin(){}
	~XuLyThongTin(){if(DuLieu!=NULL) {delete [] DuLieu; DuLieu = NULL;}}
	
	void Nhap(){
		int LoaiHinh;
		cout<<"Nhap 1 de nhap du lieu cho Ellipse";
		cout<<"\nNhap 2 de nhap du lieu cho hinh tron";
		cout<<"\nNhap mot so nguyen tuong ung voi hinh muon nhap: ";
		cin>>LoaiHinh;
		while(LoaiHinh!=1&&LoaiHinh!=2){
			cout<<"So nguyen khong hop le, vui long nhap lai: ";
			cin>>LoaiHinh;}
		if(LoaiHinh == 1) DuLieu = new Elip;
		else DuLieu = new HinhTron;
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