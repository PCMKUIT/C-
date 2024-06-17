
#include <iostream>
using namespace std;
#define MAX 300

int Fibo(int);

int main()
{
	int x;
	cin >> x;
	if (x < 1 || x>30)
		cout << "So " << x << " khong nam trong khoang [1,30]." << endl;
	else
	{
		cout << Fibo(x) << endl;
	}
	return 0;
}

int Fibo(int x)
{int S[x-1]; S[0]=1;S[1]=1;int a=0;
for (int i=2;i<=x;i++){S[i]=S[i-1]+S[i-2];}
return S[x-1];}