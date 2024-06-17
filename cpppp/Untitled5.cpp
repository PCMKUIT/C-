#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
map<ll, vector<pll> > m;
int n;
ll a[1007], x;
int main(){
    cin >> n >> x;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        for(int j = 1; j < i; ++j){
            ll sum = a[i] + a[j];
            if(m.find(x - sum) != m.end()){
                for(auto p : m[x - sum]){
                    if(p.fi != i && p.fi != j && p.se != i && p.se != j){
                    	cout<<a[i]+a[j]+a[p.fi]+a[p.se]<<"\n";
                        cout << i << ' ' << j << ' ' << p.fi << ' ' << p.se;
                        return 0;}}}
	    m[sum].pb(mp(i, j));}}
    cout << "Impossible"; return 0;}