#include <bits/stdc++.h>
using namespace std;
int main(){
long long a,k,b,m,n,x,y,z,t,g,l,s;
cin>>a>>k>>b>>m>>n;
x=n/(a+b);
t=a+b;
g=t*x-a*int(x/k)-b*int(x/m);
z=x;y=0;z++;l=2;
while ((y<n-g)&&(z!=k*m))
{if(z%k==0){y-=a;} 
 if(z%m==0){y-=b;}
 y+=t;z++;} z--;s=y+g;
 while (y<n-g)
{s*=l;z*=l;l++;} z++;
while (y<n-g)
{if(z%k==0){y-=a;} 
 if(z%m==0){y-=b;}
 y+=t;z++;}
cout<<z-1;
return 0;}