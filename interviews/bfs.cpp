#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

// Here I built a depth-first search algorithm. It's a slightly more powerful/expressive version
// as I've actually made a class "Vertex" as opposed to just using ints. This enables me discover
// things about the graph itself. 

// Note to self: make a breadth-first search after.
using namespace std;

enum Colour{
	White = 0,
	Grey,
	Black
};

class Vertex {
  public:
	int index;
	Colour colour;
	int discoveryTime;
};


// I keep track of the nodes themselves in a vector and neighbours in an adjacency list.
vector< Vertex > nodes;
vector< vector<int> > AdjacencyList;
stack<int> path; // For tracking the path taken to get to the node. Only useful for DFS.
queue< Vertex > toSearch; // For later use when making the BFS.

// edit this to build path
bool DFS( Vertex *start,int v ){
	path.push( start->index );
	if( start->index == v ){ // Found!
		return true;
	}
	start->colour = Grey;
	// I'm uncertain if this for loop is actually what DFS is supposed to do. I'm assuming it
	// checks all neighbours before continuing up the branch.
	for( int i = 0; i < AdjacencyList[start->index].size(); i++ ){
		if( nodes[AdjacencyList[start->index][i]].colour == White && AdjacencyList[start->index][i] == v ){ // Found! 
			path.push( v );
			return true;
		}
	}
	start->colour = Black;
	// Continue up each branch
	for( int i = 0; i < AdjacencyList[start->index].size(); i++ ){
		if( nodes[ AdjacencyList[start->index][i] ].colour == White ){
			return DFS( &nodes[AdjacencyList[start->index][i]], v );
		}
	}
	path.pop();
	return false;
}

int main(){
	istream *infile = &cin;
	try{
		infile = new ifstream( "graph.txt" );
	}
	catch( exception e ){
		cerr << "There was an error with the IO" << endl;
	}

	int numEdges;
	for( ;; ){
		// Make the vertex and push it onto the vector
		Vertex node;
		*infile >> node.index;
		node.colour = White;
		node.discoveryTime = 0;
		nodes.push_back( node );

		if( infile->fail() )
			break;

		// What are the neighbours?
		vector< int > neighbours;
		int temp;
		*infile >> numEdges;
		for( int i = 0; i < numEdges; i++ ){
			*infile >> temp;
			neighbours.push_back( temp );
		}
		AdjacencyList.push_back( neighbours );			
	}

	for( int i = 1; i < nodes.size(); i++ ){ // Search for the nodes that reachable by the first vertex inputted
		if( DFS( &(nodes[0]), i ) ){
			cout << "The node was found" << endl;
			int size = path.size();
			for( int j = 0; j < size; j++ ){
				cout << path.top() << " ";
				path.pop();
			}
			cout << endl;
		}
		else{
			cout << "The node was not found" << endl;
		}
		// Reset all the nodes
		for( int j = 0; j < nodes.size(); j++ ){
			nodes[j].colour = White;
		}
		// Empty the path stack
		for( int j = 0; j < path.size(); j++ ){
			path.pop();
		}
	}

	/*for( int i = 0; i < nodes.size(); i++ ){
		for( int j = 0; j < AdjacencyList[i].size(); j++ ){
			cout << AdjacencyList[i][j] << " ";
		}
		cout << endl;
	}*/
	return 0;
}
