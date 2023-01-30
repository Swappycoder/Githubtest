#include <iostream>
using namespace std;

class treenode
{
    int data;
    treenode *lc;
    treenode *rc;
    friend class tree;
};

class tree
{
    treenode *root;

public:
    tree();
    void create();
    void create(treenode *);

    void inorder();
    void inorder(treenode *);

    void preorder();
    void preorder(treenode *);

    void postorder();
    void postorder(treenode *);
};

// CONSTRUCTOR.
//..................................................................................................

tree::tree()
{
    root = NULL;
}

//........................................................................................................
//CREATION.

void tree::create()
{
    if (root == NULL)
    {
        root = new treenode;
        cout << "Enter data for root: " << endl;
        cin >> root->data;
        root->lc = NULL;
        root->rc = NULL;
    }
    create(root);
}

void tree::create(treenode *temp)
{
    int ch;
    treenode *curr;
    cout << "to add left child for " << temp->data << " "
         << " (press 1) " << endl;
    cin >> ch;
    if (ch == 1)
    {
        curr = new treenode;
        cout << "Enter lc data: " << endl;
        cin >> curr->data;
        curr->lc = NULL;
        curr->rc = NULL;
        temp->lc = curr;
        create(curr);
    }

    cout << "to add right child to " << temp->data << " "
         << " (press 1) ." << endl;
    cin >> ch;
    if (ch == 1)
    {
        curr = new treenode;
        cout << "Enter rc data: " << endl;
        cin >> curr->data;
        curr->lc = NULL;
        curr->rc = NULL;
        temp->rc = curr;
        create(curr);
    }
}

//..................................................................................................

void tree::inorder()
{
    inorder(root);
}

void tree::inorder(treenode *trav)
{
    if (trav != NULL)
    {
        inorder(trav->lc);
        cout << trav->data << " " << endl;
        inorder(trav->rc);
    }
}

//........................................................................................................

void tree::preorder()
{
    preorder(root);
}

void tree::preorder(treenode *trav)
{
    if (trav != NULL)
    {
        cout << trav->data << endl;
        preorder(trav->lc);
        preorder(trav->rc);
    }
}

//........................................................................................................

void tree::postorder()
{
    postorder(root);
}

void tree::postorder(treenode *trav)
{
    if (trav != NULL)
    {
        postorder(trav->lc);
        postorder(trav->rc);
        cout << trav->data << endl;
    }
}

//........................................................................................................
int main()
{
    tree bt;
    bt.create();
    int trav;
    cout << "Enter choice from Menu for display:\n1)Inorder\n2)Preorder\n3)Postorder" << endl;
    cin >> trav;
    cout << endl;
    switch (trav)
    {
    case 1:
        bt.inorder();
        break;
    case 2:
        bt.preorder();
        break;
    case 3:
        bt.postorder();
        break;
    default:
        cout << "Invalid choice..." << endl;
        break;
    }
    return 0;
}