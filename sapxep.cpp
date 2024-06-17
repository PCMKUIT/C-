#include <bits/stdc++.h>
using namespace std;
void NhapMang(long long a,long long ab[])
{
    for (int i=0;i<a;i++)
        cin>>ab[i];
}
void XuatMang(long long a,long long ab[])
{

    for (int i=0;i<a;i++)
        cout<<ab[i]<<" ";
}
void xuly(long long a[], long long b[], long long c[],long long A,long long B, long long K){
while((d<A)&&(e<B)){
if(a[d]<=b[e]){
c[cnt++]=a[d++];}
	else {c[cnt++]=b[e++];}}
while (d<A)c[cnt++]=a[d++];
while (e<B)c[cnt++]=b[e++];}
int main (){
long long A,B,a[A],b[B];cin>>A;long long c[A+B];int cnt =0;int d=0;int e=0;
NhapMang (A,a);
cin>>B;
NhapMang (B,b);
	//if (A>=B){for(int i=B+1;i<=A;i++){c[i]=a[i];}}
	//	else for(int i=A+1;i<=B;i++){c[i]=b[i];}
//for (int i=0;i<A+B;i++){
//cout<<c[i]<<" ";}
XuatMang(A,a);
XuatMang(B,b);
return 0;
}
/*long long sapxep (long long AA,long long BB,long long a[],long long b[]){
int cnt=0,i=0,j=0;long long A=0;long long B=0;long long c[AA+BB];
if(A<=B)A=AA;
else B=BB;
while(1>0){
if(i<=A){if(a[i]<=b[j]){
c[cnt]=a[i];cnt++;i++;}}
else {c[cnt]=b[j];cnt++;j++;}}
return c[AA+BB];}*/