#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e9+7;
int main (){
ios::sync_with_stdio(0), cin.tie(NULL),cout.tie(NULL);
long long n,l;cin>>n>>l;long long S=l,SS=0;
for (int i=0;i<=n;i++){
	S=l*l;
	for(int j=0;j<i;j++){
		S*=4; S=S%MAX;}
		SS+=S;}
		SS=SS%MAX;
		cout<<SS;
		return 0;}