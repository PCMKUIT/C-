#include <iostream>
#include <bits/stdc++.h>

using namespace std;
bool IsPrime(int x)
{
    int a;
     if (x%2==0)
        return false;
 for(a=3;a<=sqrt(x);a+=2)
    if (x%a==0)
        return false;
return true;
}

int main()
{
    int n,dem=0;
    cin>>n;
    for (int i=3;i<n-2;i++,i++) if (IsPrime(i)&&(IsPrime(i+2)))
        {dem++;cout<<i<<","<<i+2<<endl;}
    cout<< "Tong:"<<dem<<" cap so sinh doi<"<<n;
        return 0;
}