/*
You have a binary tree where each node knows the number of nodes in its sub-tree (including itself).

Given a node n and an int k, write a function to return the kth node in an in order traversal.
Can you do this non recursively?

*/
#include <iostream>
using namespace std;

// Really it's a "node" class. Keeps track of children and size of subtree
class BTree {
   public:
	int value;
	int size;
	BTree *left;
	BTree *right;
	BTree(int value, int size, BTree *l, BTree *r): value( value ), size( size ), left( l ), right ( r ){}
};

BTree* returnkthr( BTree *t, int k ){
	// If you've recursed enough to now you're the only node left, you're done
	// Or, if you're literally the kth element in the subtree, you're done
	if( (t->left == NULL && t->right == NULL) || (t->left != NULL && k == t->size - t->left->size) ){
		return t;
	}
	// If k < size of left subtree, you'll find kth node there
	else if( t->left != NULL && t->left->size >= k ){
		returnkthr( t->left, k );
	}
	// Else it's in the right subtree
	else if( t->right != NULL && t->size - t->left->size - 1 < k ){
		returnkthr( t->right, k - t->size - t->left->size );
	}
	else{
		"I ran into this case"; // If you ever see this the program didn't work
	}
}

int main(){
	// Notice that I probably should have just made a BTree->insert function
	BTree *t1 = new BTree(1, 1, NULL, NULL);
	BTree *t2 = new BTree(4, 1, NULL, NULL);
	BTree *t3 = new BTree(3, 3, t1, t2);
	BTree *t5 = new BTree(8, 1, NULL, NULL);
	BTree *t6 = new BTree(9, 2, t5, NULL);
	BTree *t4 = new BTree(6, 6, t3, t6);
	
	cout << (returnkthr( t4, 5 ))->value << endl;
	return 0;
}
