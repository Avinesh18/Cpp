#include <iostream>

using namespace std;

inline int function(int x,int a,int b)
{
	return (1-(x/a)%2*2)*(b*x/a - (x+a)/(2*a)*b*2);
}

int main()
{
	cout<<"a: ";
	int a;
	cin>>a;

	cout<<"b: ";
	int b;
	cin>>b;

	cout<<"Range: ma - na"<<endl;
	cout<<"m: ";
	int m;
	cin>>m;
	cout<<"n: ";
	int n;
	cin>>n;

	for(int i=m*a;i<=n*a;i++)
	{
		cout<<i<<"\t"<<function(i,a,b)<<endl;
	}

	return 0;
}