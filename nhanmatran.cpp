#include <bits/stdc++.h>
using namespace std;
const int MAXR=400, MAXC=400;
void input (float a[MAXR][MAXC],int &n, int &m){
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
        cin>>a[i][j];}

int main(){
    int m,n,k,l,z;float a[MAXR][MAXC],b[MAXR][MAXC],c[MAXR][MAXC];
    cin>>m>>n;
   input(a,m,n);
    cin>>l>>k;
    input(b,l,k);
    for(int i=0;i<m;++i){
    for(int j=0;j<k;j++){
        for(z=0;z<n;z++){
		c[i][j]=c[i][j]+(a[i][z]*b[z][j]);}
        cout<<c[i][j]<<" ";}
        cout<<endl;}
    return 0;}