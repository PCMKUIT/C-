#include <bits/stdc++.h>
#define For(i, a, b) for(int i = a; i <= b; i ++)
#define Fod(j, a, b) for(int j = a; j >= b; j --)
using namespace std;

struct node {
    int val = 0;
    vector<int> v;};

int main(){
    int n, x; cin >> n >> x;
    vector<int> a(n + 1);
    vector<vector<node>> dp(n + 1);
    For(i, 1, n) {
        cin >> a[i];
        dp[i].resize(x + 1);}
	if (n<4||x<4) {cout <<"Impossible"; return 0;}
    a[0] = 0;
    dp[0].resize(x + 1);
    For(i, 0, n)   dp[i][0].val = 0;
    For(i, 0, x)   dp[0][i].val = 0;
    vector<int> res;
    int ans = 0;
    For(i, 1, n) {
        For(j, 1, x) {
            if(j >= a[i] && dp[i - 1][j].val < dp[i - 1][j - a[i]].val + a[i] && dp[i - 1][j - a[i]].v.size() < 4) {
                dp[i][j].val = dp[i - 1][j - a[i]].val + a[i];
                dp[i][j].v = dp[i - 1][j - a[i]].v;
                dp[i][j].v.push_back(i);
            } else if(j >= a[i] && dp[i - 1][j].val == dp[i - 1][j - a[i]].val + a[i] && dp[i - 1][j - a[i]].v.size() < 4) {
                dp[i][j].val = dp[i - 1][j - a[i]].val + a[i];
                if(dp[i - 1][j].v.size() < dp[i - 1][j - a[i]].v.size() + 1) {
                    dp[i][j].v = dp[i - 1][j - a[i]].v;
                    dp[i][j].v.push_back(i);
                } else dp[i][j].v = dp[i - 1][j].v;              
            } else if(dp[i - 1][j].v.size() < 4){
                dp[i][j].val = dp[i - 1][j].val;
                dp[i][j].v = dp[i - 1][j].v;}
            if(ans < dp[i][j].val && dp[i][j].v.size() == 4) {
                ans = dp[i][j].val;
                res = dp[i][j].v;}}}
    if(ans == 0) {
        cout << "Impossible";
        return 0;}
    cout << ans << endl;
    for(auto x:res)  cout << x << " "; 
	return 0;}