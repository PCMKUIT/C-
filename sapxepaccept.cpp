#include <bits/stdc++.h>
using namespace std;
int main (){
int n,m;cin>>n;int a[n];int i=0, j=0,cnt=0;
for (int i=0;i<n;i++){cin>>a[i];}
cin>>m;int b[m];
for (int i=0;i<m;i++){cin>>b[i];}
int c[n+m];
while (i<n && j<m){
if(a[i]<=b[j]){c[cnt++]=a[i++];}
else {c[cnt++]=b[j];++j;}}
while (i<n){c[cnt++]=a[i++];}
while (j<m){c[cnt++]=b[j++];}
for (int i=0;i<n+m;i++){cout<<c[i]<<" ";}
return 0;
}