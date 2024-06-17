#include <bits/stdc++.h>
#define loading; ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll= long long;
int cnt; vector <int> haha;ll n,m;

bool kt (ll n){
	ll j;
	for (int i=2;i<=sqrt(n);i++){j=pow(i,2);if(n%j==0) return false;}
	return true;
}

int main (){
	loading;
	cin>>n>>m;
	for (ll i=n;i<=m;i++){
	if (kt(i)) haha.push_back(i);}
	for (ll i=0;i<haha.size()-1;i++){
		for(ll j=i+1;j<haha.size();j++){
			if(__gcd(haha[i],haha[j])==1) cnt++;
		}
	}
	cout<<cnt;
	return 0;
}