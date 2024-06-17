#include <bits/stdc++.h>
#define MAXR 500
#define MAXC 500
using namespace std;
void NhapMaTran(double a[MAXR][MAXC],int &b,int &c){
	cin>>b>>c;
for (int i=1;i<=b;i++){
for (int j=1;j<=c;j++){cin>>a[i][j];}}
return;}
double maxtrix(double a[MAXR][MAXC],int b,int c){
double S=0;
for (int i=1;i<=b;i++){
S+=a[i][i];}
return S;}
	
int main(){
    double a[MAXR][MAXC]; int b,c;
    NhapMaTran(a,b,c);
    cout << maxtrix (a,b,c);
    return 0;
}