#include <iostream>
#include <vector>

using namespace std;

typedef struct RegEx
{
	bool all;
	char ch;
	bool repeat;

	RegEx(char ch_, bool repeat_):all(false), ch(ch_), repeat(repeat_)
	{}

	RegEx(bool all_, bool repeat_):all(all_), ch('\0'), repeat(repeat_)
	{}
}RegEx;

string expr;
string txt;
int len;
vector<RegEx> expression;
int regExpLen;
int endState;

void parseExpression()
{
    expression.emplace_back('\0',false);

    int expr_len=expr.length();
    char ch1;
    char ch2;
    bool all=false;
    bool repeat=false;
    int i=-1;
    for(i=0;i<expr_len-1;i++)
    {
        repeat=all=false;
        ch1=expr[i];
        ch2=expr[i+1];

        if(ch1=='.')
            all=true;
        if(ch2=='*')
            repeat=true;

        if(all && repeat)
        {
            expression.emplace_back(true,true);
        }
        else if(all)
        {
            expression.emplace_back(true,repeat);
        }
        else
        {
            expression.emplace_back(ch1,repeat);
        }

        if(repeat)
            i++;
        else
            endState=expression.size()-1;

    }
    if(i==expr_len-1)
    {
        if(expr[i]=='.')
            expression.emplace_back(true,false);
        else
            expression.emplace_back(expr[i],false);
        endState=expression.size()-1;
    }
    regExpLen=expression.size();

    /*vector<RegEx>::iterator it=expression.begin();
    for(;it!=expression.end();it++)
        cout << (*it).all << "  " << (*it).ch << "  " << (*it).repeat << endl;*/

    vector<RegEx>::iterator it=expression.begin();
    RegEx &temp=(*it);
    for(;it!=expression.end();it++)
    {
        temp=(*it);
        cout << (temp.repeat ? ( temp.all ? "." : string(1,temp.ch)) + "*" : (temp.all ? ". " : string(1,temp.ch) + " " ) ) << "  ";
    }
    cout << endl;
}

void getInput()
{
	cout << "Regular Expression: ";
	cin >> expr;

	cout << "String: "; 
	cin >> txt;
	len=txt.length();

	parseExpression();
}

bool parseString()
{
    vector<vector<int> >mem=vector<vector<int> >(2,vector<int>(regExpLen,0));
    mem[0][0]=1;
    int pre_last=0;
    int i=1;
    int last=-1;
    int ptr=0;
    int first=-1;
    int mem_row=1;

    for(int k=0;k<regExpLen;k++)
        cout << mem[0][k] << "   ";
    cout << endl;

    while(i<regExpLen && ptr<len)
    {
        char ch=txt[ptr++];
        bool placed=false;
        int j=i;

        mem[mem_row%2]=vector<int>(regExpLen,0);
        while(j<=pre_last+1 && j<regExpLen)
        {
            bool a=mem[(mem_row-1)%2][j-1]==1;
            bool b=mem[(mem_row-1)%2][j]==1;
            bool c=expression[j].repeat;
            if(!(mem[(mem_row-1)%2][j-1]==1 || mem[(mem_row-1)%2][j]==1 && expression[j].repeat))
            {
                j++;
                continue;
            }

            do
            {
                if(expression[j].all || expression[j].ch==ch)
                {
                    placed=placed || (first=j);
                    mem[mem_row %2][j]=1;
                    last=j;
                }
                j++;
            }while(j<regExpLen && expression[j-1].repeat);
        }

        for(int k=0;k<regExpLen;k++)
            cout << mem[mem_row %2][k] << "   ";
        cout << ch << endl;
        if(!placed)
            return false;

        if(expression[first].repeat)
            i=first;
        else
            i=first+1;

        pre_last=last;
        mem_row++;
    }

    if(ptr==len && pre_last>=endState)
        return true;
    return false;
}

int main()
{
	getInput();
	cout << parseString() << endl;

	return 0;
}