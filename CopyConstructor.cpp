#include <iostream>

using namespace std;

class Test
{
	int a;
public:
	int b;

	Test();
	Test(int, int);
	Test(const Test&);
};

Test::Test()
{
	a=b=0;
}

Test::Test(int a_,int b_)
{
	a=a_;
	b=b_;
}

Test::Test(const Test&x)
{
	a=x.a;
	b=x.b;

	cout<<"Inside Copy Constructor"<<endl;
}

void print(Test *a)
{
	cout<<a->b<<endl;
	cout<<"In print"<<endl;
}

Test abc()
{
	Test *b=new Test(55,65);
	return *b;
}

Test def()
{
	Test b(70,80);
	return *(&b);
}

int main()
{
	Test a;
	Test b(10,20);

	print(&a);
	print(&b);

	cout<<endl;

	Test c=b;
	print(&c);

	cout<<endl;

	Test f;
	f=b;
	print(&f);

	cout<<endl;

	Test d=abc();
	print(&d);

	cout<<endl;

	Test e;
	e=abc();
	print(&e);

	cout<<endl;

	Test g=def();
	print(&g);

	cout<<endl;

	Test h;
	h=def();
	print(&h);

	cout<<endl;

	return 0;
}