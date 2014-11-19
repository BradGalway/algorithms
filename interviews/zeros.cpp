#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

void makeZeros( vector< vector< int > > &matrix, int row, int column ){
	for( int i = 0; i < matrix.size(); i++ ){
		matrix[i][column] = 0;
	}
	for( int i = 0; i < matrix[row].size(); i++ ){
		matrix[row][i] = 0;
	}
}

int main(){
	vector< vector< int > > matrix;
	string input;
	istream *infile = &cin;
	try{
		infile = new ifstream( "intmatrix.txt" );
	}
	catch( exception e ){
		cerr << "error" << endl;
	}

	while( getline( *infile, input ) ){
		vector< int > row;
		stringstream ls( input );
		string word;
		while( ls >> word ){
			row.push_back( atoi( word.c_str() ) );
		}
		matrix.push_back( row );
	}

	cout << "Size: " << matrix.size() << endl;

	vector< vector< int > > temp = matrix;

	for( int i = 0; i < temp.size(); i++ ){
		for( int j = 0; j < temp[i].size(); j++ ){
			if( temp[i][j] == 0 ){
				makeZeros( matrix, i, j );
			}
		}
	}
	
	for( int i = 0; i < matrix.size(); i++ ){
		for( int j = 0; j < matrix[i].size(); j++ ){
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}
