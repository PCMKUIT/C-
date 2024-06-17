#include<bits/stdc++.h>
using namespace std;
string a;bool Bool[10] ;int A[10];

void kt(long long k) {
 if (k == a.size()+1) {
 for (int i = 1; i < k; i++){
 cout << A[i];}
 cout<<'\n';
 return;}
 for (int i = a.size()-1; i >= 0; i--) {
 if (!Bool[a[i]-'0']) {Bool[a[i]-'0'] = 1; A[k] = a[i]-'0'; 
  kt(k + 1); Bool[a[i]-'0'] = 0;}}
  return;}
 
signed main() {
 ios::sync_with_stdio(0), cin.tie(NULL),cout.tie(NULL);
 cin >> a;
 kt(1);
 return 0;}