#include<bits/stdc++.h>
#define loading; ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
#define loop(i, j, k, in)  for (int i = (j); i <= (k); i += (in))
#define pb push_back
#define ll long long

using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef pair<ll,ll> pll;

const int N = 1000;

ll n,m,d; pll ans,a[N]; vi b[N];
bool c[N];
int s[N];

ll solve(pll a,pll b){return 1ll * (pow((a.first - b.first),2)  + pow((a.second - b.second),2)) ;}

void process(int x);
int main(){
    loading;
    cin >> n >> m >> d;
    loop(i,1,n,1) cin>>a[i].first>>a[i].second;
    loop(i,1,n,1){
        loop(j,1,n,1){
            if(i == j) continue;
            if(solve(a[i],a[j]) < d*d){
                b[i].pb(j);
                b[j].pb(i);}}}
    c[m]=1;
    process(m);
    loop(i,1,n,1){
        if(s[i] == 1) ans.first++;
        else if(s[i] == 2) ans.second++;}
    cout<< ans.first << " " << ans.second;
    return 0;
}
void process(int x){
    queue<int> q;
    q.push(x);
    s[x] = 0; c[x] = 1;
    while(q.size()){
        int f = q.front(); q.pop();
        for(auto v : b[f]){
            if(!c[v]){  c[v] = 1;
              			s[v] = s[f] + 1;
               			q.push(v);}}}
    return ;
}