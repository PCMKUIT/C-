#include<bits/stdc++.h>
using namespace std;
int y,m,d;
int leap(int y){return ((y%4==0&&y%100!=0)||y%400==0);}

int dayinmonth(int m,int y){
  switch(m){
    case 1:case 3:case 5:case 7:case 8:case 10:case 12:{return 31;break;}
    case 2:{if(leap(y)){return 29;}return 28;}
    case 4:case 6:case 9:case 11:{return 30;}}}

void nextday(int y,int m,int d){
	if(m!=12&&d==dayinmonth(m,y)){d=1;m++;}
	else if(m==12&&d==dayinmonth(m,y)){d=1;m=1;y++;}
	else d++;
	cout<<"Ngay ke tiep la: "<<d<<"/"<<m<<"/"<<y;}
int main(){
	cout<<"Nhap nam: ";cin>>y;
	cout<<"Nhap thang: ";cin>>m;while(m<1||m>12) {cout<<"Thang khong hop le , vui long nhap lai: ";cin>>m;}
    cout<<"Nhap ngay: ";cin>>d; while(d<1||d>31||(d>(dayinmonth(m,y)))) {cout<<"Ngay khong hop le , vui long nhap lai: ";cin>>d;}
    nextday(y,m,d);
    return 0;
}