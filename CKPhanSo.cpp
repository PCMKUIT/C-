#include <bits/stdc++.h>
using namespace std;
class PhanSo{
	private: int tu,mau;
	public:
		PhanSo(int ts=0,int ms=1){
			tu=ts; mau=ms;}
		~PhanSo(){}
		friend istream & operator >> (istream &In,PhanSo &PS){
			cout<<"Nhap tu so: ";  In>>PS.tu;
			cout<<"Nhap mau so: "; In>>PS.mau;
			return In;}
		PhanSo operator = (const PhanSo &PS){
			tu=PS.tu;
			mau=PS.mau;
			return *this;}
		PhanSo operator + (const PhanSo &PS){
			PhanSo ans(tu*PS.mau+PS.tu*mau,mau*PS.mau);
			return ans;}
		friend ostream &operator << (ostream &Out, PhanSo &PS){
			if(PS.mau<0){PS.mau=-PS.mau;PS.tu=-PS.tu;}
			int A=__gcd(abs(PS.tu),abs(PS.mau));
			PS.tu/=A; PS.mau/=A;
			if(PS.tu==0) {Out<<0<<endl;return Out;}
			if(PS.mau==1) {Out<<PS.tu<<endl;return Out;}
			Out<<PS.tu<<"/"<<PS.mau<<endl;return Out;}
		bool operator == (const PhanSo &PS){
			if(float(tu/mau)==float(PS.tu/PS.mau)) return true;
			return false;}			
};
int main(){
PhanSo a(5, 3);
PhanSo b, c, kq;
cin >> b >> c;
kq = a + b + 5 + c;
cout << "Ket qua la: " << kq;
if (a == b)
cout << "Phan so a bang phan so b" << endl;}