#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],c[N],b[N],n,vitri,kiso;
int main(){
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    c[1]=a[1];
    for(int i=2;i<=n;++i){
    c[i]=__gcd(c[i-1],a[i]);}
    b[n]=a[n];
    for(int i=n-1;i>=1;--i){
    b[i]=__gcd(b[i+1],a[i]);}
    kiso=b[2];
    vitri=1;
    for(int i=2;i<n;++i){
    if(__gcd(c[i-1],b[i+1])>kiso){
    kiso=__gcd(c[i-1],b[i+1]);
    vitri=i;}}
    if(c[n-1]>kiso) kiso=c[n-1], vitri=n;
    cout<<vitri<<" "<<kiso;
    return 0;}