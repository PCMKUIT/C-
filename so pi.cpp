#include <bits/stdc++.h>
using namespace std;
int main (){
double n;cin>>n; double S=0;
for( int i=0;i<=n;i++){
S+=pow(-1,i)/(2*i+1);}
S=4*S;
cout<<S;
return 0;}