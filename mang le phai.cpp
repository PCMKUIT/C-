#include <bits/stdc++.h>
using namespace std;
int main (){
int r,c;cin>>r>>c;string a[r][c];int max[10000];
for(int i=0;i<r;i++){
for(int j=0;j<c;j++){cin>>a[i][j];}}
for(int i=0;i<r;i++){
for(int j=0;j<c;j++){
if(a[j][i].size()>max[i]){max[i]=a[j][i].size();}}}
for(int i=0;i<r;i++){
for(int j=0;j<c;j++){a[j][i].insert(0,max[i]-a[j][i].size(),' ');}}
for(int i=0;i<r;i++){
for(int j=0;j<c;j++){cout<<a[i][j]<<" ";if(j==c-1)cout<<endl;}}
return 0;}