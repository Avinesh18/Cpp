#include <iostream>
using namespace std;

typedef struct Node
{
	int val;
	struct Node *left;
	struct Node *right;

	Node(int value): val(value),left(NULL),right(NULL){}
}Node;

int *seq;
int n;
int i;
Node* root;

void getInput()
{
	cout << "No. of nodes" << endl;
	cin >> n;

	seq=new int[n];
	cout << "Enter the postorder sequence" << endl;
	for(int i=0;i<n;i++)
		cin >> seq[i];
	cout << "Got the nodes" << endl;
	i=n-1;
}

void generate(Node *current,int min,int max)
{
	Node *temp=new Node(seq[i--]);
	if(temp->val > current->val)
		current->right=temp;
	else
		current->left = temp;

	if(seq[i] > temp->val && seq[i] <= max)
		generate(temp,temp->val+1,max);
	if(seq[i] >= min && seq[i] < temp->val)
		generate(temp,min,temp->val-1);
}

void generate()
{
	root=new Node(seq[i--]);

	if(seq[i] > root->val)
		generate(root,root->val+1,INT_MAX);
	if(seq[i] < root->val)
		generate(root,INT_MIN,root->val-1);
}

void postorder(Node *root)
{
	if(root==NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	cout << root->val << " ";
}

void BFS(Node *root)
{
	Node** queue=new Node*[n];
	queue[0]=root;
	int front=0;
	int rear=0;

	Node *current;
	while(front!=-1)
	{
		current=queue[front++];
		cout << current->val << " ";

		front = front > rear ? -1 : front;
		rear = front==-1 ? -1 : rear;

		if(current->left!=NULL)
		{
			queue[++rear]=current->left;
			front = front==-1 ? 0 : front;
		}
		if(current->right!=NULL)
		{
			queue[++rear]=current->right;
			front = front==-1 ? 0 : front;
		}
	}
}

int main()
{
	getInput();
	generate();
	BFS(root);

	return 0;
}