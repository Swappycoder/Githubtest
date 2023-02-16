#include <iostream>
#include <string.h>

using namespace std;

class treenode
{
	char data[40];
	treenode *left;
	treenode *right;
	friend class bst;
};

//____________________________________________________________________________________

class bst
{
	treenode *root;

public:
	bst();
	void create_nr();
	void display();
	void search_nr(char k[30]);
	void mirror();
	void copy_r(bst t1);
	treenode *copy_r(treenode *root);
	void del(char d[30]);
};
//____________________________________________________________________________________

class queue
{
	int rear;
	int front;
	treenode *qdata[30];

public:
	queue()
	{
		front = -1;
		rear = -1;
	}
	int empty();
	void addq(treenode *temp);
	treenode *delq();
	friend class bst;
};

int queue::empty()
{
	if (front == rear)
		return 1;

	else
		return 0;
}

void queue::addq(treenode *temp)
{
	++rear;
	qdata[rear] = temp;
}

treenode *queue::delq()
{
	treenode *temp;
	++front;
	temp = qdata[front];
	return temp;
}

//_______________CREATION________________________________________________

void bst::create_nr()
{
	{
		treenode *temp, *curr;
		int flag, ch, c;
		if (root == NULL)
		{
			root = new treenode;
			cout << "Enter Value for root: " << endl;
			cin >> root->data;
			root->left = NULL;
			root->right = NULL;
		}
		cout << "Enter more values? (1 - Yes, 2 - No)" << endl;
		cin >> ch;
		if (ch == 1)
		{
			do
			{
				temp = root;
				flag = 0;
				curr = new treenode;
				cout << "Enter next value to be added: " << endl;
				cin >> curr->data;
				curr->left = NULL;
				curr->right = NULL;
				while (flag == 0)
				{
					c = strcmp(curr->data,temp->data);
					if (c == 0)
					{
						cout << "Same value cannot be entered twice!" << endl;
					}
					else
					{
						if (c < 0)
						{
							if (temp->left == NULL)
							{
								temp->left = curr;
								flag = 1;
							}
							else
							{
								temp = temp->left;
							}
						}
						else
						{
							if (temp->right == NULL)
							{
								temp->right = curr;
								flag = 1;
							}
							else
							{
								temp = temp->right;
							}
						}
					}
				}
				cout << "Enter more values? (1 - Yes, 2 - No)" << endl;
				cin >> ch;
			} while (ch == 1);
		}
	}
}
//_________________________DISPLAY_______________________________________________

void bst::display()
{
	treenode *temp;
	temp = root;
	queue q;
	q.addq(temp);
	while (q.empty() == 0)
	{
		temp = q.delq();
		cout << temp->data << " ";
		if (temp->left != NULL)
		{
			q.addq(temp->left);
		}
		if (temp->right != NULL)
		{
			q.addq(temp->right);
		}
	}
}


//________________________SEARCHING_______________________________________



void bst::search_nr(char key[10])
{
	treenode *curr;
	int flag = 0, c;
	curr = root;
	while (curr != NULL)
	{
		c = strcmp(key, curr->data);
		if (c==0)
		{
			flag = 1;
			break;
		}
		else
		{
			if (c<0)
			{
				curr = curr->left;
			}
			else
			{
				curr = curr->right;
			}
		}
	}
	if (flag == 1) cout<<"Found"<<endl;
	else cout<<"Not Found"<<endl;
}
//________________________MIRROR_______________________________________

void bst::mirror()
{
	treenode *temp;
	temp = root;
	queue q;
	q.addq(temp);
	while (q.empty() == 0)
	{
		temp = q.delq();
		treenode *n = temp->left;
		temp->left = temp->right;
		temp->right = n;

		if (temp->left != NULL)
		{
			q.addq(temp->left);
		}
		if (temp->right != NULL)
		{
			q.addq(temp->right);
		}
	}
}
//_________________________________________COPY_RECURSIVE______________________
//DRIVER CODE

void bst::copy_r(bst t1)
{
	root = copy_r(t1.root);
}


//WORKHORSE____________________________________________________________________

treenode* bst::copy_r(treenode* temp)
{
	treenode *curr = NULL;
	if(temp!=NULL)
	{
		curr = new treenode;
		strcpy(curr->data, temp->data);
		curr->left = copy_r(temp->left);
		curr->right = copy_r(temp->right);
	}
	
	return curr;
}

//__________________________DELETE_LEAF_NODE_____________________________________


void bst::del(char x[30])
{
	treenode *curr, *parent;
	int flag = 0, c, cs;
	curr = root;
	parent = root;
	while (curr != NULL)
	{
		c = strcmp(x, curr->data);
		if (c==0)
		{
			flag = 1;
			break;
		}
		else
		{
			if (c<0)
			{
				parent = curr;
				curr = curr->left;
			}
			else
			{
				parent = curr;
				curr = curr->right;
			}
		}
	}
	if (flag == 1)
	{
		if (curr->right == NULL && curr->left == NULL)
		{
			if(curr == parent->right)
			{
				parent->right = NULL;
				delete curr;
			}
			else
			{
				parent->left = NULL;
				delete curr;
			}
		}
		else if ((curr->right == NULL && curr->left != NULL) || (curr->right != NULL && curr->left == NULL))
		{
			if(curr == parent->right)
			{
				if(curr->right != NULL)
				{
					parent->right = curr->right;
					curr->right = NULL;
					delete curr;
				}
				else
				{
					parent->right = curr->left;
					curr->left = NULL;
					delete curr;
				}
			}
			else
			{
				if(curr->right != NULL)
				{
					parent->left = curr->right;
					curr->right = NULL;
					delete curr;
				}
				else
				{
					parent->left = curr->left;
					curr->left = NULL;
					delete curr;
				}
			}
		}
		else if (curr->right != NULL && curr->left != NULL)
		{
			cs = 3;
		}
	}
	else
	{
		cout<<"Value does not exist in tree!"<<endl;
	}
}

//__________________________CONSTRUCTOR__________________________________________


bst::bst()
{
	root = NULL;
}

//_______________________________________________________________________________

int main()
{
	bst b1, b2;
	char key[30];

	b1.create_nr();
	b1.display();
	cout<<"\n\n";

	cout<<"\nEnter value to be searched: ";
	cin>>key;
	b1.search_nr(key);
	cout<<"\n\n";

	cout << "\n After using mirror" << endl;
	b1.mirror();
	b1.display();
	cout<<"\n\n";

	cout << "\n After copy into new tree" << endl;
	b2.copy_r(b1);
	b2.display();
	cout<<"\n\n";

	cout<<"\nEnter value to be deleted: ";
	cin>>key;
	b1.del(key);
	b1.display();
	
	return 0;
}