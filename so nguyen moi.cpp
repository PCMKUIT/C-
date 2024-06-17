#include <iostream>
using namespace std;
int main(){
	string n,a;
	int t,p,l,d;
	cin>>n;a=n;p=t=0;
	l=n.size();
	while (p<l){t+=n[p],p++;}d=t%3;
	for (p=0;(p<l)&&(n[p]+3-d>'9');p++);
    n[p]=n[p]+3-d;
    while (n[p]<'7'){n[p]=n[p]+3;}
	if (a==n){if(d==0){n[l-1]=n[l-1]-3;
	}else {n[l-1]=n[l-1]-d;}}
    cout<<n;
	return 0;
}

