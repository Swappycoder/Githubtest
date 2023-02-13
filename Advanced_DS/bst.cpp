#include<iostream>
using namespace std;

class treenode
{
  int data;
  treenode *left;
  treenode *right;
  friend class bst;
};

//________________________________________________________________

class bst
  {
   treenode *root;
   public:
 		bst();
 	  	void create_nr();
 	  	void bft();
   		
  };
//_______________________________________________________________  

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
	if(front == rear)
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

//____________________________________

void bst::create_nr()
{
	treenode* curr ,*temp;
	int ch,flag = 0;
	if(root == NULL)
	{
		root = new treenode;
		cout<<"Enter root data"<<endl;
		cin>>root->data;
		root->left=NULL;
		root->right=NULL;
	
		do
		{
			temp = root;
			flag = 0;
			curr=new treenode;
			cout<<"enter next data: "<<endl;
			cin>>curr->data;
			curr->left=NULL;
			curr->right=NULL;
			while (flag ==0)
			{
				if(curr->data < temp->data)
				{
					if(temp->left == NULL)
						{
							temp->left = curr;
							flag = 1;
						}
					else
						{
							temp = temp->left;
						}
				}
				else if(curr->data == temp->data)
				{
					cout<<"Same value cannot be assingned."<<endl;
				}
				else
				{
					if(temp->right == NULL)
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
			cout<<"enter choice 1.yes 2.no"<<endl;
			cin>>ch;
		}while(ch == 1);
	}
}

//___________________________________________________________________________________________	

void bst::bft()
{
	treenode *temp;
	temp = root;
	queue q;
	q.addq(temp);
	while(q.empty() == 0)
	{
		temp = q.delq();
		cout<<temp->data<<" ";
		if(temp->left != NULL)
		{
			q.addq(temp->left);
		}
		if(temp->right != NULL)
		{
			q.addq(temp->right);
		}
	}
}
//___________________________________________________________________________________________	
	
bst::bst()
{
  root=NULL;  
}	
	
	
//___________________________________________________________________________________________
int main()
{
     bst b1;
     b1.create_nr();
     b1.bft();
     return 0;
}
