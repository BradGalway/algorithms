#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

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

vector< Vertex> nodes;
vector< vector<int> > AdjacencyList;
stack<int> path;

// edit this to build path
bool BFS( Vertex *start,int v ){
	path.push( start->index );
	if( start->index == v ){
		return true;
	}
	start->colour = Grey;
	for( int i = 0; i < AdjacencyList[start->index].size(); i++ ){
		if( nodes[AdjacencyList[start->index][i]].colour == White && AdjacencyList[start->index][i] == v ){
			path.push( v );
			return true;
		}
	}
	start->colour = Black;
	for( int i = 0; i < AdjacencyList[start->index].size(); i++ ){
		if( nodes[ AdjacencyList[start->index][i] ].colour == White ){
			return BFS( &nodes[AdjacencyList[start->index][i]], v );
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
		Vertex node;
		*infile >> node.index;
		node.colour = White;
		node.discoveryTime = 0;
		nodes.push_back( node );

		if( infile->fail() )
			break;

		vector< int > neighbours;
		int temp;
		*infile >> numEdges;
		for( int i = 0; i < numEdges; i++ ){
			*infile >> temp;
			neighbours.push_back( temp );
		}
		AdjacencyList.push_back( neighbours );			
	}

	for( int i = 1; i < nodes.size(); i++ ){
		if( BFS( &(nodes[0]), i ) ){
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
		for( int j = 0; j < nodes.size(); j++ ){
			nodes[j].colour = White;
		}
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
