#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class node{
    int val;
  public:
    int sizeOfSubtree;
    node( int v ):sizeOfSubtree( 1 ), val( v ){}
    int calculateSizeOfSubtree( node *vertices[], vector<int> adjacencyList[] );
    int split( node *vertices[], vector<int> adjacencyList[]);
};

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
	for( int i = 0; i < adjacencyList[val].size(); i++ ){
		if( vertices[adjacencyList[val][i]]->sizeOfSubtree % 2 == 0 ){
			splits += vertices[adjacencyList[val][i]]->split( vertices, adjacencyList );
			sizeOfSubtree -= vertices[adjacencyList[val][i]]->sizeOfSubtree;
			adjacencyList[val].erase(adjacencyList[val].begin() + i);
			i--;
			splits++;
		}
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
    int root = 0;
    int max = -1;
    for( int i = 0; i < numVertices; i++ ){
        temp = vertices[i]->calculateSizeOfSubtree( vertices, adjacencyList );
	if( temp > max ){
		max = temp;
		root = i;
        }
    }

    cout << vertices[root]->split( vertices, adjacencyList ) << endl;

    return 0;
}
