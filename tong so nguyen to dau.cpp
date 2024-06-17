#include <bits/stdc++.h> 
using namespace std ;
bool kt ( long long n) {
    if(n==1) return false ;
    else {
        for (int i=2; i<=sqrt(n);i++)
            if(n%i==0) return false ;}
    return true ;}
int main() {
    int n ; 
    cin >> n ;long long S=0,i=1,cnt=0;
    while (n<=0||n>50){
        cout<< "Gia tri vua nhap la "<<n<<", khong hop le. Vui long nhap lai."<<endl;cin>>n;}
        for(cnt=0;cnt<n;){
            if(kt(i)==true) {S+=i;cnt++;}
            i++;}
    cout <<"Tong "<<n<<" so nguyen to dau tien la: "<<S ;
    return 0;}