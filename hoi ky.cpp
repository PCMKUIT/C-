#include <bits/stdc++.h>
#define ll long long 
#define MAX 100000
using namespace std;
ll n,k,a[MAX],l=0,m,r = 0,ans;

ll kt(ll m){
    int cnt=1;ll S=0;
    for(int i=0;i<n;i++) {
        if(a[i]>m) return k+1;
        if(S+a[i]>m) {S=0;cnt++;}
        S += a[i];}
    return cnt;}
    
int main() {
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> a[i];
        l = max(l, a[i]);
        r += a[i];}
    while(l <= r) {
        m = (l + r)>>1;
        if(kt(m) <= k) {
        	ans=m;
            r = m-1 ;}
        else l = m + 1;}
    cout << ans;
	return 0;}