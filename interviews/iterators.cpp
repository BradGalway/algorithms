#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <sstream>
#include <stdlib.h>
using namespace std;

/*
Problem: Make an iterator class that will go through a vector of vectors of ints and always return the
next value. Example { {2, 3}, {4}, {}, {5, 6, 7} }
iterator.next();
iterator.next();
iterator.next();
iterator.next();
iterator.next();
iterator.next();
-> 2 3 4 5 6 7
*/

class Iterator{
	const vector< vector< int > > array;
	int currentVector;
	int currentIndex;
  public:
	Iterator( const vector< vector< int > > &array ): array( array ), currentVector( 0 ), currentIndex( 0 ){}
	bool next( int *a );
};

// Should put the value of the next integer in a. Returns 0 if there is no next and 1 if there is. 
bool Iterator::next( int *a ){
	while( currentVector < array.size() ){
		if( currentIndex >= array[currentVector].size() ){
			currentVector++;
			currentIndex = 0;
			continue;
		}
		*a = array[currentVector][currentIndex];
		currentIndex++;
		return 1;
	}
	return 0;
}

int main(){
	vector< vector< int > > collection;
	istream *infile = &cin;
	try{
		infile = new fstream( "collection.txt" );
	}
	catch( exception e ){
		cerr << "Error with IO" << endl;
	}

	string input;
	while( getline( *infile, input ) ){
		stringstream ls( input );
		string word;
		vector< int > vec;
		while( ls >> word ){
			vec.push_back( atoi( word.c_str() ) );
		}
		collection.push_back( vec );
	}

	int *a = new int;
	Iterator iterator( collection );
	
	while( iterator.next( a ) ){
		cout << *a;
	}
	cout << endl;
	
	return 0;
}
