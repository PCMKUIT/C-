#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
using namespace std;
char big[500][500], kid[400][400], cop[400][400];// cop viết tắt từ copy, *ko can cop
void xoay(int n) {
    char w[n][n];
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++)
            w[i][j] = kid[n-j-1][i];}//xoay 90
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++)
           kid[i][j] = w[i][j];}}//gán lại thành biến mới để quay lại tiếp tục vòng lặp
           
int kt(int n, int m) {
    int ans = 0, i, j, a, b;//ans là answer thay cho kiso
    for(i = 0; i <= n-m; i++) {
    for(j = 0; j <= n-m; j++) {
    	int cnt=0;int d=0;
            for(a = 0; a < m; a++) {
            for(b = 0; b < m; b++) {
               if(big[i+a][j+b] != kid[a][b]) {d=1;break;}}}
                if(d==0) ans++;}}  
			//	if(big[i+a][j+b] == kid[a][b]) cnt++;}} cách khẳng định
            //    if(cnt == m*m) ans++;}}
    return ans;}

int main() {
    int n, m, i, j;// ko can j
    while(n != 0 || m != 0) {
        cin>>n>>m;
        for(i = 0; i < n; i++) cin >> big[i];
        for(i = 0; i < m; i++) {cin >> kid[i];}
        for(i = 0; i < 4; i++) {
            if(i!=0)//hoặc if(i)
              cout<<" "; // putchar(' ');
            if(n != 0 || m != 0) cout<< kt(n, m);
            xoay(m);}
        cout<<endl;//có thể dùng puts("");
	   }
    return 0;}