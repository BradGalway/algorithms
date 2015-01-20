#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

// Unfinished. The problem was, given a unique board of snakes and ladders, if you had complete control of the dice, what's the fastest way you could get from 1 to 100?

int stringToInt( string s ){
    int num = 0;
    for( int i = s.length() - 1, base = 1; i >= 0; i--, base *= 10 ){
        if( s[i] >= 48 && s[i] <= 57 ){
            num += (s[i] - 48) * base;
        }
        else{
            cerr << "Invalid int" << endl;
            return 0;
        }
    }
    return num;
}

void getSandL( string s, int &numLadders, int &numSnakes ){
    for( int i = 0; ; i++ ){
        if( s[i] != ',' ) continue;
        numLadders = stringToInt( s.substr(0, i) );
        numSnakes = stringToInt( s.substr(i+1, s.length() - i - 1));
        return;
    }
}

enum Colour{
    White = 0,
    Grey,
    Black
};

class node{
    int value;
  public:
    static int min;
    Colour colour;
    bool BFS( node *vertices[], vector<int> adjancencyList[], queue<int> &toSearch );
    bool DFS( node *vertices[], vector<int> adjacencyList[], stack<int> &path );
    node( int val ): value( val ){}
};

bool checkNeighbours( int vertex, node *vertices[], vector<int> adjacencyList[] ){
    for( int i = 0; i < adjacencyList[vertex].size(); i++ ){
        if( adjacencyList[vertex][i] == 100 ) return true;
    }
    return false;
}

bool node::BFS( node *vertices[], vector<int> adjacencyList[], queue<int> &toSearch ){
    if( value == 99 || checkNeighbours(value, vertices, adjacencyList) ) return 1;
    vertices[value]->colour = Black;
    for( int i = 0; i < adjacencyList[value].size(); i++ ){
        if( vertices[adjacencyList[value][i]]->colour == White ){
	    vertices[adjacencyList[value][i]]->colour = Grey;
	    toSearch.push( adjacencyList[value][i] );
	}
    }
    toSearch.pop();
    if( !toSearch.empty() ) vertices[toSearch.front()]->BFS( vertices, adjacencyList, toSearch );
    return 1;
}

bool within( stack<int> path, int v ){
	for( ; !path.empty() ; path.pop() ){
		if( path.top() == v ){
			return true;
		}
	}
	return false;
}

// this is really nothing like DFS now that I think about it. It keeps searching, even if it's
// already seen the node before. As long as it's not in the previous path it'll go there.
bool node::DFS( node *vertices[], vector<int> adjacencyList[], stack<int> &path ){
        path.push( value );
	//cout << "value: " << value << ", size: " << path.size() << endl;
        if( value >= 93 && value <= 98 ){
		if( path.size() + 1 < min ) min = path.size() + 1;
		path.pop();
		return true;
	}
	
        for( int i = 0; i < adjacencyList[value].size(); i++ ){
                if( !within( path, adjacencyList[value][i] ) ){
                        vertices[adjacencyList[value][i]]->DFS( vertices, adjacencyList, path );
                }
        }
        path.pop();
        return false;
}


int node::min = 100;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int numTests;
    cin >> numTests;
    int numSnakes;
    int numLadders;
    string input;


    for( int test = 0; test < numTests; test++ ){
        node *vertices[100];
	vector<int> adjacencyList[100];
        for( int i = 0; i < 100; i++ ){
	    vertices[i] = new node(i);
	} 
	for( int i = 0; i < 100; i++ ){
	    for( int j = i + 1; j <= i + 6 && j < 100; j++ ){
		adjacencyList[i].push_back( j );
	    }
	}
        cin >> input;
        getSandL(input, numLadders, numSnakes);
	for( int ladder = 0, begin = 0, end = 0; ladder < numLadders; ladder++ ){
		cin >> input;
		getSandL(input, begin, end);
		adjacencyList[begin-1].push_back( end - 1 );
	}
	for( int snake = 0, begin = 0, end = 0; snake < numSnakes; snake++ ){
		cin >> input;
		getSandL(input, begin, end);
		adjacencyList[begin-1].clear();
		adjacencyList[begin-1].push_back( end - 1 );
	}
	stack<int> path;
	vertices[0]->DFS( vertices, adjacencyList, path );
        cout << node::min << endl;
    }
    return 0;
}

