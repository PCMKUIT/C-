#include <bits/stdc++.h>
using namespace std;
using ll =long long;
double S1,S2,S3;string s1,s2;
ll gt(ll n){
	 if (n == 0) return 1;
    return n * gt(n - 1);
}
ll solve (ll n){
	 if (n==0) return 0;
	 return n + solve(n - 1);
}

int main (){
	ll n;cin>>n;
	for (ll i=1;i<=n;i++){
		S1+=pow(i,i);
		S2+=gt(i);
		S3+=1/double(solve(i));
	}
	cout<<S1<<endl<<S2<<endl<<S3;
	return 0;
}