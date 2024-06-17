#include <bits/stdc++.h>
using namespace std;
int reverse (int n){
int b=n;int j=0;
while(b!=0){b=b/10;j++;}
int a[j];int S=0;
for (int i=1;i<=j;i++){
a[i]=n%10;n/=10;
S+=a[i]*pow(10,j-i);}
return S;}

int main() {
    int n;
    cin >> n;
    cout << reverse(n);
}