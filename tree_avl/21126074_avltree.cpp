#include<iostream>
#include<queue>
#include <math.h>
#define RH 1 
#define EH 0 
#define LH -1 
using namespace std;

struct Node
{
	int data;
	Node *pLeft;
	Node *pRight;
	int height;
};
typedef Node* AVLTree;

void init(AVLTree& T)
{
	T = NULL;
}

Node *createNode(int data)
{
	Node *node = new Node;
	node->data = data;
	node->pLeft = node->pRight = NULL;
	node->height = EH;
	return node;
}

void rotateLeftLeft(AVLTree &T)
{
	Node* T1 = T->pLeft;
	T->pLeft = T1->pRight;
	T1->pRight = T;
	switch(T1->height)
	{
	case LH:
		T->height = EH;
		T1->height = EH;
		break;
	case EH:
		T->height = LH;
		T1->height = RH;
		break;
	}
	T = T1;
}

void rotateRightRight(AVLTree &T)
{
	Node* T1 = T->pRight;
	T->pRight = T1->pLeft;
	T1->pLeft = T;
	switch(T1->height)
	{
	case RH:
		T->height = EH;
		T1->height = EH;
		break;
	case EH:
		T->height = RH;
		T1->height = LH; //EH
		break;
	}
	T = T1;
}

void rorateLeftRight(AVLTree &T)
{
	Node* T1 = T->pLeft;
	Node* T2 = T1->pRight;
	T->pLeft = T2->pRight;
	T2->pRight = T;
	T1->pRight = T2->pLeft;
	T2->pLeft = T1;
	switch(T2->height)
	{
	case LH:
		T->height = RH;
		T1->height = EH;
		break;
	case EH:
		T->height = EH;
		T1->height = EH;
		break;
	case RH:
		T->height = EH;
		T1->height = LH;
		break;
	}
	T2->height = EH;
	T = T2;
}

void rorateRightLeft(AVLTree &T)
{
	Node* T1 = T->pRight;
	Node* T2 = T1->pLeft;
	T->pRight = T2->pLeft;
	T2->pLeft = T;
	T1->pLeft = T2->pRight;
	T2->pRight = T1;
	switch(T2->height)
	{
	case RH:
		T->height = LH;
		T1->height = EH;
		break;
	case EH:
		T->height = EH;
		T1->height = EH;
		break;
	case LH:
		T->height = EH;
		T1->height = RH;
		break;
	}
	T2->height = EH;
	T = T2;
}

int balanceLeft(AVLTree& T)
{
	Node* T1 = T->pLeft;
	switch(T1->height)
	{
	case LH:
		rotateLeftLeft(T);
		return 2;
	case EH:
		rotateLeftLeft(T);
		return 1;
	case RH:
		rorateLeftRight(T);
		return 2;
	}
	return 0;
}

int balanceRight(AVLTree& T)
{
	Node* T1 = T->pRight;
	switch(T1->height)
	{
	case LH:
		rorateRightLeft(T);
		return 2;
	case EH:
		rotateRightRight(T);
		return 1;
	case RH:
		rotateRightRight(T);
		return 2;
	}
	return 0;
}

int insert(AVLTree& T, int x)
{
	int result;
	if(T)
	{
		if(T->data == x) return 0;
		if(T->data > x)
		{
			result = insert(T->pLeft, x);
			if(result < 2) return result;
			switch(T->height)
			{
			case RH:
				T->height = EH;
				return 1;
			case EH:
				T->height = LH;
				return 2;
			case LH:
				balanceLeft(T);
				return 1;
			}
		}
		else
		{
			result = insert(T->pRight, x);
			if(result < 2) return result;
			switch(T->height)
			{
			case LH:
				T->height = EH;
				return 1;
			case EH:
				T->height = RH;
				return 2;
			case RH:
				balanceRight(T);
				return 1;
			}
		}
	}
	T = createNode(x);
	return 2; //height of tree increase 2
}

void levelOrder(AVLTree T)
{
	queue<AVLTree> q;
	AVLTree p;
	if (T == NULL) return;
	p = T;
    q.push(p);
    while (!q.empty())
	{
    	p = q.front();
        q.pop();
        cout << p->data << " ";
        if (p->pLeft) q.push(p->pLeft);
        if (p->pRight) q.push(p->pRight);
	}
}

void NLR(AVLTree t)
{
    if(t != NULL)
    {
        cout << t->data << " ";
        NLR(t->pLeft);
        NLR(t->pRight);
    }
}

void LNR(AVLTree t)
{
    if(t != NULL)
    {
        LNR(t->pLeft);
        cout << t->data << " ";
        LNR(t->pRight);
    }
}

void LRN(AVLTree t)
{
    if(t != NULL)
    {
        LRN(t->pLeft);
        LRN(t->pRight);
        cout << t->data << " ";
    }
}

int max(int x, int y)
{
	return (x >= y)? x: y;
}

int height(AVLTree T)
{
	if(T == NULL) return 0;
	return 1 + max(height(T->pLeft), height(T->pRight));
}

bool isAVL(AVLTree T)
{
	if(T == NULL) return 1;
	int leftHeight = height(T->pLeft);
	int rightHeight = height(T->pRight);
	if(abs(leftHeight - rightHeight) <= 1 && isAVL(T->pLeft) && isAVL(T->pRight)) return 1;
	return 0;
}

int findTemporaryElement(AVLTree &root, Node *&p)
{
	int result;
	if(p->pLeft)
	{
		result = findTemporaryElement(root, p->pLeft);
		if(result < 2) return result;
		switch(p->height)
		{
		case LH:
			p->height = EH;
			return 1;
		case EH:
			p->height = RH;
			return 2;
		case RH:
			return balanceRight(root);
		}
	}
	root->data = p->data;
	root = p;
	p = p->pRight;
	return 2;
}

int Remove(AVLTree &root, int x)
{
	int result;
	if(!root) return 0;
	if(root->data > x)
	{
		result = Remove(root->pLeft, x);
		if(result < 2) return result;
		switch(root->height)
		{
		case LH:
			root->height = EH;
			return 2;
		case EH:
			root->height = RH;
			return 1;
		case RH:
			return balanceRight(root);
		}
	}
	if(root->data < x)
	{
		result = Remove(root->pRight, x);
		if(result < 2) return result;
		switch(root->height)
		{
		case LH:
			return balanceLeft(root);
		case EH:
			root->height = LH;
			return 1;
		case RH:
			root->height = EH;
			return 2;
		}
	}
	else //root->data = x
	{
		Node *p1 = root;
		if(root->pLeft == NULL)
		{
			root = root->pRight;
			result = 2;
		}
		else
		{
			if(root->pRight == NULL)
			{
				root = root->pLeft;
				result = 2;
			}
			else
			{
				result = findTemporaryElement(p1, root->pRight);
				if(result < 2) return result;
				switch(root->height)
				{
				case RH:
					root->height = EH;
					return 2;
				case EH:
					root->height = LH;
					return 1;
				case LH:
					return balanceRight(root);
				}
			}
			delete p1;
			return result;
		}
	}
}



int main()
{
	AVLTree root;

	init(root);
	insert(root, 9);  
    insert(root, 5);  
    insert(root, 10);  
    insert(root, 0);  
    insert(root, 6);  
    insert(root, 11);  
    insert(root, -1);  
    insert(root, 1);  
    insert(root, 2);
	Remove(root, 10);
	cout << "Level-order traversal after removing node: ";
	levelOrder(root);
	cout << "\nNLR after removing node: ";
	NLR(root);
	cout << "\nLNR after removing node: ";
	LNR(root);
	cout << "\nLRN after removing node: ";
	LRN(root);
	if(isAVL(root)) cout << "\nAVL tree";
	else cout << "Not AVL tree";

	// AVLTree root;
	// OperateAVL(root);
    
	return 0;
}
