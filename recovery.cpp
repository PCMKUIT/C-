#include <bits/stdc++.h>
#define N 100001
using namespace std;
int n,c,k; long long sum[N] , source[N], solve[N], ans= LLONG_MAX;
int main (){
	cin >>n >>c>>k;
	for (int i=0; i < n; i++){
		cin>>source[i];
		solve[i]=source[i]+1;
	}
	solve[n]=1;
	solve[n+1]=c-k+1;
	sort(solve,solve+n+2);
	sort(source,source+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+source[i-1];
	}
	for(int i=0;i<n+2;i++){
		int l = solve[i];
		int r = solve[i] +k -1;// solve[i] is left
		if (r>c) break;
		int a =upper_bound(source,source+n,r)-source;
		int b =lower_bound(source,source+n,l)-source;

		ans=min(sum[a]-sum[b],ans);
	}
	cout<<ans;
}