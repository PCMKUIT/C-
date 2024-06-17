#include <bits/stdc++.h>
using namespace std;
class CDate{
	private: int Ngay, Thang, Nam;
	public:
	CDate(int d=0,int m=0,int y=0){Ngay = d; Thang = m; Nam = y;}
	~CDate(){}
	bool Leap(int y){return ((y%4==0&&y%100!=0)||y%400==0);}
	int Max_Day(int m,int y){
  		switch(m){
    		case 1:case 3:case 5:case 7:case 8:case 10:case 12:{return 31;}
    		case 2:{if(Leap(y)){return 29;}return 28;}
    		case 4:case 6:case 9:case 11:{return 30;}}}
	void Nhap(){cout<<"Nhap nam: "; cin>>Nam;
				while(Nam<1) {cout<<"Nam khong hop le , vui long nhap lai: ";cin>>Nam;}
				cout<<"Nhap thang: "; cin>>Thang;
				while(Thang<1||Thang>12) 
				{cout<<"Thang khong hop le , vui long nhap lai: ";cin>>Thang;}
    			cout<<"Nhap ngay: "; cin>>Ngay;
				while(Ngay<1||Ngay>31||(Ngay>(Max_Day(Thang,Nam)))) 
				{cout<<"Ngay khong hop le , vui long nhap lai: ";cin>>Ngay;}}
    void Xuat(){cout<<"ngay "<<Ngay<<" thang "<<Thang<<" nam "<<Nam<<"\n";}
    CDate Cong(CDate a,int b){
    	CDate c;
    	c.Ngay=a.Ngay+b;
    	c.Thang=a.Thang;
    	c.Nam=a.Nam;
    	while(c.Ngay>Max_Day(c.Thang,c.Nam)) {c.Ngay-=Max_Day(c.Thang,c.Nam);c.Thang++;
												 if(c.Thang>12) {c.Thang-=12;c.Nam++;}}
    	while(c.Ngay<=0) {c.Thang--;if(c.Thang==0) {c.Thang=12;c.Nam--;} 
						  c.Ngay+=Max_Day(c.Thang,c.Nam);}
    	return c;}
	CDate Tru(CDate a,int b){
    	CDate c;
    	c.Ngay=a.Ngay-b;
    	c.Thang=a.Thang;
    	c.Nam=a.Nam;
    	while(c.Ngay<=0) {c.Thang--;if(c.Thang==0) {c.Thang=12;c.Nam--;} 
						  c.Ngay+=Max_Day(c.Thang,c.Nam);}
    	while(c.Ngay>Max_Day(c.Thang,c.Nam)) {c.Ngay-=Max_Day(c.Thang,c.Nam);c.Thang++;
											  if(c.Thang>12) {c.Thang-=12;c.Nam++;}}
    	return c;}
	void Cong_Cong(CDate &a){	
		if(a.Thang!=12&&a.Ngay==Max_Day(a.Thang,a.Nam)){a.Ngay=1;a.Thang++;}
		else if(a.Thang==12&&a.Ngay==Max_Day(a.Thang,a.Nam)){a.Ngay=1;a.Thang=1;a.Nam++;}
		else a.Ngay++;}
	void Tru_Tru(CDate &a){
		if(a.Thang!=1&&a.Ngay==1){a.Thang--;a.Ngay=Max_Day(a.Thang,a.Nam);}
		else if(a.Thang==1&&a.Ngay==1){a.Ngay=31;a.Thang=12;a.Nam--;}
		else a.Ngay--;}
	int Tru(CDate a,CDate b){	
		bool cmp;int cnt=0;
		CDate c,d;
		c.Ngay=a.Ngay;c.Thang=a.Thang;c.Nam=a.Nam;
		d.Ngay=b.Ngay;d.Thang=b.Thang;d.Nam=b.Nam;
		if(c.Nam>d.Nam) cmp=1;
		else if(c.Nam<d.Nam) cmp=0;
		else {if(c.Thang>d.Thang) cmp=1;
			  else if(c.Thang<d.Thang) cmp=0;
			  else {if(c.Ngay>d.Ngay) cmp=1;
					else if(c.Ngay<d.Ngay) cmp=0;
					else return 0;}}
		if(cmp) {while (c.Nam!=d.Nam||c.Thang!=d.Thang||c.Ngay!=d.Ngay) {
				 if(d.Ngay!=31||d.Thang!=12){Cong_Cong(d);cnt++;continue;}
				 while(c.Nam>d.Nam+1) {d.Nam++;(Leap(d.Nam))?(cnt+=366):(cnt+=365);}
				 Cong_Cong(d);cnt++;}}
		else {while (c.Nam!=d.Nam||c.Thang!=d.Thang||c.Ngay!=d.Ngay){
			  if(c.Ngay!=31||c.Thang!=12){Cong_Cong(c);cnt++;continue;}
			  while(d.Nam>c.Nam+1) {c.Nam++;(Leap(c.Nam))?(cnt+=366):(cnt+=365);}
			  Cong_Cong(c);cnt++;}}
		if(cmp) return cnt; else return -cnt;}
};
int main (){
	CDate a,b,c,d; int e,f,g;
	cout<<"Nhap vao du lieu ngay, thang, nam:\n"; a.Nhap();
	cout<<"Ngay nhap vao: "; a.Xuat();
	cout<<"Nhap vao so ngay muon cong them: "; cin>>e;
	cout<<e<<" ngay sau cua ngay nhap vao se la ngay: "; b=b.Cong(a,e); b.Xuat();
	cout<<"Nhap vao so ngay muon tru di: "; cin>>f;
	cout<<f<<" ngay truoc cua ngay nhap vao se la ngay: "; c=c.Tru(a,f); c.Xuat();
	cout<<"Nhap vao du lieu ngay, thang, nam muon tru:\n"; d.Nhap();
	cout<<"Du lieu ngay vua nhap la: "; d.Xuat(); g=d.Tru(a,d);
	if(g>0) cout<<"Ngay nhap vao ban dau lon hon du lieu ngay vua nhap la: "<<g<<" ngay";
	else if(g<0) cout<<"Ngay nhap vao ban dau be hon du lieu ngay vua nhap la: "<<-g<<" ngay";
	else cout<<"Khoang cach giua hai ngay nhap vao la: 0 ngay";
	cout<<"\nNgay nhap vao ban dau sau khi them 1 ngay la: "; a.Cong_Cong(a); a.Xuat();
	cout<<"Ngay nhap vao ban dau sau khi bot 1 ngay la: "; a.Tru_Tru(a); a.Xuat();
	return 0;
}