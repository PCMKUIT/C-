#include <bits/stdc++.h>
#define MAXR 100
#define MAXC 100
void NhapMaTran(int a[MAXR][MAXC],int &n){
	std::cin>>n;
for (int i=0;i<n;i++){
for (int j=0;j<n;j++){std::cin>>a[i][j];}}
return;}
bool isMaTranDonVi(int a[MAXR][MAXC],int &n){
    if (n==0) return 0;
    for(int i=0; i<n; i++){
    if(a[i][i]!=1){return 0;}}
    for(int i=0; i<n; i++){
	for(int j=i+1; j<n; j++){
	if((a[i][j] !=0) || (a[j][i] !=0)){return false;}}}
	return 1;}

int main() {
    int a[MAXR][MAXC], n;
    NhapMaTran(a, n);
    std::cout <<  std::boolalpha << isMaTranDonVi(a, n);
    return 0;
}
