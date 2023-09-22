#include <bits/stdc++.h>
using namespace std;
int main(){
int b,n,c,d,max;cin>>n;long long a[n];
for (int i=0;i<n;i++)cin>>a[i];
for (int i=0;i<n;i++){
for (int j=0;j<n;j++){if (i!=j){
c=a[j];d=a[j+1];
while (c!=d){
if (c>d){c-=d;}
else{d-=c;}} if (max<c){max=c;b=i;}
}}}
cout<<b+1<<" ";
cout<<max;
return 0;}