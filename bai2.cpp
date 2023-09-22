#include <iostream>
using namespace std;
int main(){
int a,c,d,e,f;cin>>a;
if (a>=1000) {c=a/100;d=a-c*100;}else {c=a/10;d=a-c*10;} 
if((c>=10)&&(d>=10)){e=(d-9)*1000+909+(c-9)*10;}
else if((c>=10)&&(d<10)&&(d>=1)){e=1000+(d-1)*100+(c-9)*10+9;} else if ((c>=10)&&(d<10)&&(d==0)){e=(c-9)*1000+900;}
else if((c<10)&&(d<10)&&(d>=1)){e=1000+(d-1)*100+c;} else{e=1000+(c-1)*100+d;}
cout<<e;
return 0;
}

