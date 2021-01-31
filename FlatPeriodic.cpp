#include <iostream>
#include <math.h>

using namespace std;

int function(int x,int a,int b,int p)
{
	int start=x/2/a*2*a+p;
	int end=(x/2/a*2+2)*a-p;

	//Decides which function to execute
	int enable=(1+(x-start)/abs(x-start))/2*(1-(x-end)/abs(x-end))/2;

	cout<<start<<"\t"<<end<<"\t"<<enable<<"\t";

	return ((1 - x/a%2 *2)*(x%a)*b/p + x/a%2 * b*a/p)*(1-enable) + enable*b;
}

int main()
{
	cout<<"a: ";
	int a;
	cin>>a;

	cout<<"p: ";
	int p;
	cin>>p;

	cout<<"b: ";
	int b;
	cin>>b;

	cout<<"ma - na"<<endl;
	cout<<"m: ";
	int m;
	cin>>m;
	cout<<"n: ";
	int n;
	cin>>n;

	for(int i=m*a;i<=n*a;i++)
	{
		cout<<i<<"\t";
		cout<<function(i,a,b,p)<<endl;
	}

	return 0;
}