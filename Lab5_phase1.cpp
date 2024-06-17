#include <bits/stdc++.h>
using namespace std;
int main(){
	int x;
	cout<<"Enter value for v2[0]: ";
	cin>>x;
	while (x<9) {
		cout<<"BOMB!!!!\nThe bomb has blown up. Try again.";
		cout<<"\nEnter value for v2[0]: ";
		cin>>x;
	}
	cout<<"The answer string to find is: "<<x<<" "<<x+1<<" "<<x+3<<" "<<x+6<<" "<<x+10<<" "<<x+15;
	return 0;
}
