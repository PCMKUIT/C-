#include<bits/stdc++.h>
#define MAX 40
using namespace std;
 
string a;
int Bool[MAX] = {0};//Đánh dấu chưa có phần tử nào sử dụng hết
string A[MAX];//Lưu hoán vị vào mảng A

void xuat() {

 for (int i = 0; i < a.size(); i++)
 cout << A[i] ;
 cout << endl;}
 
void Try(int k) {
 for (int i = 0; i < a.size(); i++) {
 //Kiểm tra nếu phần tử chưa được chọn thì sẽ đánh dấu
 if (!Bool[i]) {
 A[k] = a[i]; // Lưu một phần tử vào hoán vị
 Bool[i] = 1;//Đánh dấu đã dùng
 
 if (k+1 == a.size())//Kiểm tra nếu đã chứa một hoán vị thì xuất
 xuat();
 else
 Try(k + 1);
 Bool[i] = 0;}}}
 
int main() {
 cout << "Mhap a: ";
 cin >> a;reverse(a.begin(), a.end());
 Try(0);}