#include <bits/stdc++.h>
using namespace std;
class Date{
	private: int d,m,y;
	public:
		Date(int year=1,int month=1,int day=1){
			y=year; m=month, d=day;}
		~Date(){}
		int Max_Day(int m,int y){
			switch(m){
				case 1:case 3:case 5:case 7:case 8:case 10:case 12:return 31;
				case 2:if((y&4==0&&y%100!=0)||(y%400==0)) return 29; return 28;
				case 4:case 6:case 9:case 11:return 30;}}
		friend istream &operator >>(istream &In,Date &D){
			cout<<"Nhap ngay: "; In>>D.d;
			cout<<"Nhap thang: "; In>>D.m;
			cout<<"Nhap nam: "; In>>D.y;
			return In;}
		Date operator ++ (int){
			if(d==Max_Day(m,y)&&m<12) {d=1;m++;return *this;}
			if(d==Max_Day(m,y)&&m==12) {d=1;m=1;y++;return *this;}
			d++; return *this;}
		friend ostream &operator <<(ostream &Out,Date &D){
			Out<<"ngay "<<D.d<<" thang "<<D.m<<" nam "<<D.y;
			return Out;}
		bool operator < (const Date &D){
			if(y<D.y) return 1;
			if(y>D.y) return 0;
			if(m<D.m) return 1;
			if(m>D.m) return 0;
			if(d<D.d) return 1;
			return 0;}
};
int main() {
Date ng1; // ng1 sẽ có giá trị là ngày 1 tháng 1 năm 1
Date ng2(2017, 1); // ng2 sẽ có giá trị là ngày 1 tháng 1 năm 2017
Date ng3(2017, 1, 7); // ng3 sẽ có giá trị là ngày 7 tháng 1 năm 2017
cin >> ng1;
ng1++;
cout << ng1;
if (ng1 < ng2)
cout << "Ngay 1 truoc ngay 2" << endl;
else
cout << "Ngay 1 khong truoc ngay 2" << endl;
return 0;}