#include <bits/stdc++.h>
using namespace std;
string sodu(string a, string b)
{
    int     du  = 0;
    int     mid = 0;
    string  res = "";
    a.insert(0, max(0, (int) (b.length() - a.length())), '0');
    b.insert(0, max(0, (int) (a.length() - b.length())), '0');
    for (int i = a.length()-1; i >= 0; --i)
    {
        mid = ((int) a[i] - 48) - ((int) b[i] - 48) - du;
        if(mid<0){mid=mid+10;du=1;} else du=0;
        //du  = mid / 10;
        res = (char) (mid % 10 + 48) +res;
    }
   // if (du > 0) res = "1" + res;
    return res;
    return a;
}
int main(){
//string a,b; cin>>a>>b;cout<< sodu (a,b);
int n,l;cin>>n>>l;long long S=0;
for (int i=0;i<=n;i++){
	S+=(l*pow(2,i))*(l*pow(2,i));
	while(S-pow(10,9)-7>=0)S-=pow(10,9)+7;}
	cout<<S;
	return 0;
}