#include <iostream>
#include <vector>

using namespace std;

int vertices;
int edges;
vector<int> source;
vector<int> destination;

void getInput()
{
	cout << "Vertices: ";
	cin >> vertices;
	cout << "Edges: ";
	cin >> edges;

	source = vector<int>(edges);
	destination=vector<int>(edges);

	cout << "Enter the lists" << endl;
	for(int i=0;i<edges;i++)
		cin >> source[i];
	for(int i=0;i<edges;i++)
		cin >> destination[i];
}

int compute()
{
	int label_val=1;
	int *temp=NULL;
	temp=new int(label_val++);

	int **label=new int*[vertices]();
	int count=0;

	label[source[0]-1]=temp;
	/*cout << endl;
	for(int i=0;i<vertices;i++)
		cout << (label[i]==0 ? 0 : *label[i]) << "  ";
	cout << endl;*/
	for(int i=0;i<edges;i++)
	{
		if(label[source[i]-1]==0 && label[destination[i]-1]==0)
		{
			temp=new int(label_val++);
			label[source[i]-1]=label[destination[i]-1]=temp;
		}
		else if(label[source[i]-1]==0)
		{
			label[source[i]-1]=label[destination[i]-1];
		}
		else if(label[destination[i]-1]==0)
		{
			label[destination[i]-1]=label[source[i]-1];
		}
		else
		{
			if(*label[source[i]-1]==*label[destination[i]-1])
				count++;
			else
				*label[source[i]-1]=*label[destination[i]-1];
		}

	/*for(int i=0;i<vertices;i++)
		cout << (label[i]==0 ? 0 : *label[i]) << "  ";
	cout <<"   " << source[i] << "->" << destination[i];
	cout << endl;
	}*/

	return count;
}

int main()
{
	getInput();

	cout << compute() << endl;

	return 0;
}