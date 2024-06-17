#include<graphics.h>
#include<bits/stdc++.h>
using namespace std;
const float pi=3.1415926535897;
int gd = DETECT, gm;
class Diem{
	private: float hoanhdo,tungdo;
	public:
	Diem(){}
	Diem(float a,float b){hoanhdo=a;tungdo=b;}
	~Diem(){}
	void nhap(){cout<<"\nHoanh do x=";cin>>hoanhdo;
				cout<<"Tung do y=";cin>>tungdo;}
	void xuat(){cout<<"Toa do cua diem la: "<<"("<<hoanhdo<<","<<tungdo<<")";vediem();} 
	float getx(){return hoanhdo;}
	float gety(){return tungdo;}
	void setxy(float a,float b){hoanhdo=a;tungdo=b;}
	void tinhtien(float a,float b){hoanhdo+=a;tungdo+=b;}
	void vediem(){initgraph(&gd, &gm,"");
            	  putpixel(hoanhdo,tungdo,RED);
				  cout<<endl;
				  system("pause");} 
	
};
int main(){
float x,y,alpha,k;cout<<"Nhap toa do cua diem:\n"; 
Diem a;a.nhap(); a.xuat();
cout<<"\nNhap vector v(x,y):\nx=";cin>>x;cout<<"y=";cin>>y;
cout<<"Sau khi tinh tien theo vector v("<<x<<","<<y<<").";a.tinhtien(x,y);a.xuat();
closegraph();
return 0;}