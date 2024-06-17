#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
if (a==0) return b;
else if (b==0) return a;
else return gcd(a%b, b%a);}
int main (){
int a,b,c,d,e,f;cin>>a>>b>>c>>d; int t=0;
if ((a==c*2-1)&&(b==1)&&(d==1)){t=1;cout<<t;}
else if(((a!=c)&&(b==d))||((a==c)&&(b!=d))){cout<<t;}
else if((float(a)/float(b)<1)&&(float(c)/float(d)>=1)){cout<<t;} 
else if((float(a)/float(b)>=1)&&(float(c)/float(d)<1)){cout<<t;}
else if((float(a)/float(b)>=1)&&(float(c)/float(d)>=1)){while ((a!=c)||(b!=d)){a++;b++;t++;e=a;f=b;a=a/gcd(e,f);b=b/gcd(e,f);if(float(a)/float(b)<float(c)/float(d)){t=0;break;}}}
else{
while ((a!=c)||(b!=d)){a++;b++;t++;e=a;f=b;a=a/gcd(e,f);b=b/gcd(e,f);if(float(a)/float(b)>float(c)/float(d)){t=0;break;}}
cout<<t;}
return 0;
}