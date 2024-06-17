#include <bits/stdc++.h>
using namespace std;
class CTime{
	private: int Gio , Phut , Giay;
	public:
	CTime(int h=0,int m=0,int s=0){Gio = h; Phut = m; Giay = s;}
	~CTime(){}
	void Nhap(){cout<<"\nNhap so gio: ";cin>>Gio;
				cout<<"Nhap so phut: ";cin>>Phut;
				cout<<"Nhap so giay: ";cin>>Giay;
				while(Time()<0){cout<<"Thoi gian nhap vao khong hop le , vui long nhap lai: \n";
								cout<<"Nhap so gio: ";cin>>Gio;
								cout<<"Nhap so phut: ";cin>>Phut;
								cout<<"Nhap so giay: ";cin>>Giay;}}
	void Xuat(bool a){while(Time()<0) Gio+=24;
					  int temp=Time();
					  Gio=temp/3600;
					  Phut=(temp-Gio*3600)/60;
					  Giay=temp-Gio*3600-Phut*60;
					  while(Gio>=24) Gio-=24;
					  if(!(a&&Gio==0)) cout<<Gio<<" gio ";
					  if(!(a&&Phut==0)) cout<<Phut<<" phut ";
					  if(!(a&&Giay==0)) cout<<Giay<<" giay ";
					  if(a&&Gio*3600+Phut*60+Giay==0) cout<<"0 giay ";}
				
	int Time(){return (Gio*3600 + Phut*60 +Giay);}
	CTime Cong(CTime a,int b){
		CTime c;
		c.Gio=a.Gio;
		c.Phut=a.Phut;
		c.Giay=a.Giay+b;
		return c;}
	CTime Tru(CTime a,int b){
		CTime c;
		c.Gio=a.Gio;
		c.Phut=a.Phut;
		c.Giay=a.Giay-b;
		return c;}
	CTime Tru(CTime a,CTime b){
		CTime c;
		c.Gio=a.Gio-b.Gio;
		c.Phut=a.Phut-b.Phut;
		c.Giay=a.Giay-b.Giay;
		return c;}
	void Cong_Cong (CTime &a){a.Giay++;return ;}
	void Tru_Tru(CTime &a){a.Giay--;return ;}
};
int main (){
	CTime a,b,c,d,e;int f,g;
	cout<<"Nhap vao du lieu thoi gian: "; a.Nhap();
	cout<<"Thoi gian ban dau: "; a.Xuat(0);
	cout<<"\nNhap vao mot so nguyen giay muon cong them: "; cin>>f;
	cout<<"Thoi gian sau khi cong them so giay nhap vao la: ";c=c.Cong(a,f); c.Xuat(0);
	cout<<"\nNhap vao mot so nguyen giay muon tru di: "; cin>>g;
	cout<<"Thoi gian sau khi tru di so giay nhap vao la: "; d=d.Tru(a,g); d.Xuat(0);
	cout<<"\nNhap vao thoi gian muon tru di: "; b.Nhap();
	cout<<"Thoi gian muon tru di: "; b.Xuat(0);
	cout<<"\n";
	if(a.Time()==b.Time()) cout<<"Hieu hai thoi gian la 0 giay"; 
	else if(a.Time()>b.Time()){cout<<"Thoi gian ban dau sau khi tru di thoi gian nhap vao la: ";e=e.Tru(a,b); e.Xuat(1);}
	else {cout<<"Thoi gian vua nhap sau khi tru di thoi gian ban dau la: ";e=e.Tru(b,a); e.Xuat(1);}
	cout<<"\nThoi gian sau khi them mot giay: "; a.Cong_Cong(a);a.Xuat(0);
    cout<<"\nThoi gian sau khi bot mot giay: "; a.Tru_Tru(a);a.Xuat(0);
    return 0;
}