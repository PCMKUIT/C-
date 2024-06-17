#include <bits/stdc++.h>
using namespace std;
class IntArr {
private:
int count; // tổng số lượng phần tử có trong values
int* values; // mảng các số nguyên đang có trong đối tượng hiện tại
public:
	IntArr(){count=0;values=nullptr;}
	IntArr(int cnt,int val=0){
		count=cnt;
		values=new int [count];
		for (int i=0;i<count;i++) values[i]=val;}
	IntArr(const IntArr &IA){
		count=IA.count;
		values=new int [count];
		for(int i=0;i<count;i++) values[i]=IA.values[i];}
	~IntArr(){if(values) {delete [] values; values=nullptr;}}
	IntArr operator = (const IntArr &IA){
		if(this==&IA) return *this;
		if(values) {delete [] values; values=nullptr;}
		count=IA.count;
		values=new int [count];
		for(int i=0;i<count;i++) values[i]=IA.values[i];
		return *this;}
	IntArr concat (const IntArr &IA){
		IntArr ans(count+IA.count);
		int cnt=0;
		for(int i=0;i<count;i++)    ans.values[cnt++]=values[i];
		for(int i=0;i<IA.count;i++) ans.values[cnt++]=IA.values[i];
		return ans;}
	void push(int val){
		IntArr temp(1,val);
		*this=this->concat(temp);}
	friend istream & operator >> (istream &In,IntArr &IA){
		if(IA.values) {delete [] IA.values; IA.values=nullptr;}
		cout<<"Nhap so luong phan tu: "; In>>IA.count;
		IA.values=new int [IA.count];
		cout<<"Nhap gia tri cho tung phan tu:\n";
		for(int i=0;i<IA.count;i++){
			cout<<"Nhap gia tri cho phan tu thu "<<i+1<<": ";
			In>>IA.values[i];}
		return In;}
	friend ostream & operator << (ostream & Out, IntArr &IA){
		for(int i=0;i<IA.count;i++) {
			Out<<"Phan tu thu "<<i+1<<": ";
			Out<<IA.values[i]<<endl;}
			return Out;}
/* Sinh viên bổ sung đầy đủ các thành phần cần thiết để hàm main hoạt động
như mong đợi */
};
int main() {
IntArr l1; // tạo mảng không chứa bất kì phần tử nào
IntArr l2(3, 2); /* tạo một mảng với 3 phần tử, tất cả phần tử đều có giá trị
là 2 */
IntArr l3(2);//tạo một mảng với 2 phần tử, tất cả phần tử đều có giá trị là 0
IntArr l4 = l2.concat(l3); /* tạo ra một IntArr mới có nội dung là kết quả
của việc nối các phần tử l3 vào cuối các phần tử của l2 theo thứ tự */
l2.push(3); // thêm số 3 vào cuối danh sách trong đối tượng l2
cin >> l2; /* Xoá các giá trị hiện có trong l2 và cho phép người dùng nhập
số lượng phần tử mới và giá trị các phần tử mới vào l2 (cần xoá các vùng nhớ
không sử dụng nếu có) */
cout << l2; // in ra các số nguyên có trong danh sách
/* Khi vượt quá phạm vi sử dụng cần huỷ tất cả các vùng nhớ được cấp phát cho
các values của IntArr */
cout<<l4;
return 0;
}