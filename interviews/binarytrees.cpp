/*
You have a binary tree where each node knows the number of nodes in its sub-tree (including itself).

Given a node n and an int k, write a function to return the kth node in an in order traversal.
Can you do this non recursively

*/
#include <iostream>
using namespace std;

class BTree {
   public:
	int value;
	int size;
	BTree *left;
	BTree *right;
	BTree(int value, int size, BTree *l, BTree *r): value( value ), size( size ), left( l ), right ( r ){}
};

BTree* returnkthr( BTree *t, int k ){
	if( (t->left == NULL && t->right == NULL) || (t->left != NULL && k == t->size - t->left->size) ){
		return t;
	}
	else if( t->left != NULL && t->left->size >= k ){
		returnkthr( t->left, k );
	}
	else if( t->right != NULL && t->size - t->left->size - 1 < k ){
		returnkthr( t->right, k - t->size - t->left->size );
	}
	else{
		"I ran into this case";
	}
}

int main(){
	BTree *t1 = new BTree(1, 1, NULL, NULL);
	BTree *t2 = new BTree(4, 1, NULL, NULL);
	BTree *t3 = new BTree(3, 3, t1, t2);
	BTree *t5 = new BTree(8, 1, NULL, NULL);
	BTree *t6 = new BTree(9, 2, t5, NULL);
	BTree *t4 = new BTree(6, 6, t3, t6);
	
	cout << (returnkthr( t4, 5 ))->value << endl;
	return 0;
}
