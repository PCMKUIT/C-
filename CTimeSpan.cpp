#include <bits/stdc++.h>
using namespace std;
class CTimeSpan{
	private: int Hour , Minute , Second;
	public:
	CTimeSpan(int h=0,int m=0,int s=0){Hour = h; Minute = m; Second = s;}
	~CTimeSpan(){}
	void Nhap(bool c){cout<<"\nNhap so gio: ";cin>>Hour;
					  cout<<"Nhap so phut: ";cin>>Minute;
					  cout<<"Nhap so giay: ";cin>>Second;
					  while(Time()<0){cout<<"Khoang thoi gian thu ";(c)?(cout<<"hai "):(cout<<"nhat ");
					  				  cout<<"khong hop le , vui long nhap lai: \n";
									  cout<<"Nhap so gio: ";cin>>Hour;
									  cout<<"Nhap so phut: ";cin>>Minute;
									  cout<<"Nhap so giay: ";cin>>Second;}}
	void Xuat(){int temp=Time();
				Hour=temp/3600;
				Minute=(temp-Hour*3600)/60;
				Second=temp-Hour*3600-Minute*60;
				if(Hour!=0) cout<<Hour<<" gio ";
				if(Minute!=0) cout<<Minute<<" phut ";
				if(Second!=0) cout<<Second<<" giay ";
				cout<<"\n";}
	int Time(){return (Hour*3600 + Minute*60 +Second);}
	CTimeSpan Cong(CTimeSpan a,CTimeSpan b){
		CTimeSpan c;
		c.Hour=a.Hour+b.Hour;
		c.Minute=a.Minute+b.Minute;
		c.Second=a.Second+b.Second;
		return c;}
	CTimeSpan Tru(CTimeSpan a,CTimeSpan b){
		CTimeSpan c;
		c.Hour=a.Hour-b.Hour;
		c.Minute=a.Minute-b.Minute;
		c.Second=a.Second-b.Second;
		return c;}
	bool Bang(CTimeSpan a,CTimeSpan b){if(a.Time()==b.Time()) return true; return false;}
	bool Khac(CTimeSpan a,CTimeSpan b){if(a.Time()!=b.Time()) return true; return false;}
	bool Lon_Hon(CTimeSpan a,CTimeSpan b){if(a.Time()>b.Time()) return true; return false;}
	bool Lon_Hon_Hoac_Bang(CTimeSpan a,CTimeSpan b){if(a.Time()>=b.Time()) return true; return false;}
	bool Be_Hon(CTimeSpan a,CTimeSpan b){if(a.Time()<b.Time()) return true; return false;}
	bool Be_Hon_Hoac_Bang(CTimeSpan a,CTimeSpan b){if(a.Time()<=b.Time()) return true; return false;}
};
int main (){
	CTimeSpan a,b,c,d;
	cout<<"Nhap du lieu cua khoang thoi gian thu nhat: "; a.Nhap(0);
	cout<<"Nhap du lieu cua khoang thoi gian thu hai: ";  b.Nhap(1);
	cout<<"Khoang thoi gian thu nhat: ";a.Xuat();cout<<"Khoang thoi gian thu hai: ";b.Xuat();
	cout<<"Tong cua hai khoang thoi gian la: ";c=c.Cong(a,b);c.Xuat();
	if(a.Lon_Hon(a,b)) {cout<<"Hieu cua khoang thoi gian thu nhat voi khoang thoi gian thu hai la: ";d=d.Tru(a,b);d.Xuat();}
	else if(a.Be_Hon(a,b)){cout<<"Hieu cua khoang thoi gian thu hai voi khoang thoi gian thu nhat la: ";d=d.Tru(b,a);d.Xuat();}
	else cout<<"Hieu cua hai khoang thoi gian la: 0 giay\n";
	cout<<"Khoang thoi gian thu nhat == Khoang thoi gian thu hai: "; (a.Bang(a,b))?(cout<<"TRUE"):(cout<<"FALSE");
	cout<<"\nKhoang thoi gian thu nhat != Khoang thoi gian thu hai: "; (a.Khac(a,b))?(cout<<"TRUE"):(cout<<"FALSE");
	cout<<"\nKhoang thoi gian thu nhat > Khoang thoi gian thu hai: "; (a.Lon_Hon(a,b))?(cout<<"TRUE"):(cout<<"FALSE");
	cout<<"\nKhoang thoi gian thu nhat >= Khoang thoi gian thu hai: "; (a.Lon_Hon_Hoac_Bang(a,b))?(cout<<"TRUE"):(cout<<"FALSE");
	cout<<"\nKhoang thoi gian thu nhat < Khoang thoi gian thu hai: "; (a.Be_Hon(a,b))?(cout<<"TRUE"):(cout<<"FALSE");
	cout<<"\nKhoang thoi gian thu nhat <= Khoang thoi gian thu hai: "; (a.Be_Hon_Hoac_Bang(a,b))?(cout<<"TRUE"):(cout<<"FALSE");
	return 0;
}