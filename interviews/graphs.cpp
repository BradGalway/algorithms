#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
Problem: https://www.hackerrank.com/challenges/even-tree
*/

// Made my own custom tree of "nodes". Every node knows the size of its subtree (number of nodes in
// children branches + itself).
class node{
    int val;
  public:
    int sizeOfSubtree;
    node( int v ):sizeOfSubtree( 1 ), val( v ){}
    int calculateSizeOfSubtree( node *vertices[], vector<int> adjacencyList[] ); // Used for calculating initial size of subtrees.
    int split( node *vertices[], vector<int> adjacencyList[]);
};

// Recursively call size function on all children adding sizes to your own.
int node::calculateSizeOfSubtree( node *vertices[], vector<int> adjacencyList[] ){
    sizeOfSubtree = 1;
    for( int i = 0; i < adjacencyList[val].size(); i++ ){
        sizeOfSubtree += vertices[adjacencyList[val][i]]->calculateSizeOfSubtree( vertices, adjacencyList );
    }
    return sizeOfSubtree;
}

int node::split( node *vertices[], vector<int> adjacencyList[] ){
	if( sizeOfSubtree == 1 ) return 0;
	int splits = 0;
	for( int i = 0; i < adjacencyList[val].size(); i++ ){ // Go through each neighbour
		// If neighbour subtree is an even size, break it off from me and recurse on it.
		if( vertices[adjacencyList[val][i]]->sizeOfSubtree % 2 == 0 ){
			splits += vertices[adjacencyList[val][i]]->split( vertices, adjacencyList );
			sizeOfSubtree -= vertices[adjacencyList[val][i]]->sizeOfSubtree;
			adjacencyList[val].erase(adjacencyList[val].begin() + i);
			i--;
			splits++;
		}
		// If not, just recurse on it.
		else{
			splits += vertices[adjacencyList[val][i]]->split( vertices, adjacencyList );
		}	
	}
	return splits;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int numVertices = 0, numEdges = 0;
    cin >> numVertices;
    cin >> numEdges;
    
    node *vertices[numVertices];
    vector<int> adjacencyList[numVertices];
    int vertex;
    int temp;

    for( int i = 0; i < numEdges; i++ ){
        cin >> vertex;
        cin >> temp;
        adjacencyList[temp - 1].push_back( vertex - 1 );
    }
    for( int i = 0; i < numVertices; i++ ){
        node *n = new node( i );
        vertices[i] = n;
    }
    int root = 0; // I'm gonna want to start on the root node.
    int max = -1;
    for( int i = 0; i < numVertices; i++ ){ // Find root by finding the node with the max subtree size
        temp = vertices[i]->calculateSizeOfSubtree( vertices, adjacencyList );
	if( temp > max ){
		max = temp;
		root = i;
        }
    }

    cout << vertices[root]->split( vertices, adjacencyList ) << endl; // Begin spit

    return 0;
}
