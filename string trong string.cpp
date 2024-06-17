#include <bits/stdc++.h>
using namespace std;
int kt(string A, string B,int a){
    int b=0;
    for (int i=0; i<B.size();i++){if (A[a+i]!=B[i]) b=1;}
    if (b==0) return 1;
    else return 0;}
int main(){
    string A,B;int c=0;
    cin >>A>>B;
    for (int i=0;i<A.size();i++){
        if (A[i]==B[0]) {if (kt(A,B,i)==1) c++;}}
    cout<<c;
    return 0;}