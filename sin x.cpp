#include <bits/stdc++.h>
using namespace std;

double giaithua(float n){
    if (n == 1) return 1;
    else return n * giaithua(n - 1);}
int main(){
double x; cin>>x; float n=0;float S=0;
while (float(pow(x,2*n+1)/giaithua(2*n+1))>0.00001){S+=pow(-1,n)*(pow(x,2*n+1)/giaithua(2*n+1));n++;}
//if (S<0) S+=pow(-1,n)*(pow(x,2*n+1)/giaithua(2*n+1));
cout<<fixed<<setprecision(4)<<S;
return 0;
}