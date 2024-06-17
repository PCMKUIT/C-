#include <bits/stdc++.h>
using namespace std;
class Time{
	private: int h,m,s;
	public:
		Time(int hour=0,int minute=0,int second=0){
			h=hour; m=minute; s=second;}
		~Time(){}
		friend istream &operator >>(istream &In,Time &T){
			cout<<"Nhap gio: "; In>>T.h;
			cout<<"Nhap phut: "; In>>T.m;
			cout<<"Nhap giay: "; In>>T.s;
			return In;}
		int Total(){return (h*3600+m*60+s);}
		void Format(){
			int temp=Total();
			h=temp/3600;
			m=(temp%3600)/60;
			s=temp%60;}
		friend ostream &operator << (ostream &Out, Time &T){
			T.Format();
			Out<<T.h<<" gio "<<T.m<<" phut "<<T.s<<" giay";
			return Out;}
		Time operator ++ (int){
			s++;
			return *this;}
		Time operator + (const Time &T){
			Time ans;
			ans.h=h+T.h;
			ans.m=m+T.m;
			ans.s=s+T.s;
			return ans;}
};
int main (){
	Time a,b,c,d;
	cin>>a>>b>>c;
	a++;
	d=b+c;
	cout<<a<<endl<<d;
}