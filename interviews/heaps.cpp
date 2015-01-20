#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/*
Problem: Implement heaps!
*/

// Used for extracting the min. The idea is that after deleting the top node, you've
// replaced it with the last node. You now need to do comparisons all the way down
// until it gets back to a place where it keeps the property of a heap
void bubbleDown( vector< int > &heap, int index ){
	// 
	for( int i = index; i < heap.size() / 2; ){// Keep going down heap and compare to children
		if( i * 2 + 2 == heap.size() ){// You've reached the bottom
			if( heap[i] > heap[i * 2 + 1] ){ // If it's bigger, swap
				int temp = heap[i];
				heap[i] = heap[i * 2 + 1];
				heap[i * 2 + 1] = temp;
			}
			break;
		}
		// You're bigger than one of your children
		if( heap[i] > heap[i * 2 + 1] || heap[i] > heap[i * 2 + 2] ){
			// If the left child is smaller, you must swap with him first
			if( heap[i * 2 + 1] < heap[i * 2 + 2] ){
				int temp = heap[i];
				heap[i] = heap[i * 2 + 1];
				heap[i * 2 + 1] = temp;
				i = i * 2 + 1; // Update i
			}
			else{ // else swap with right
				int temp = heap[i];
				heap[i] = heap[i * 2 + 2];
				heap[i * 2 + 2] = temp;
				i = i * 2 + 2; // Update i
			}
		}
		else{
			return;
		}
	}
}

// Used for inserting.
void bubbleUp( vector< int > &heap, int index ){
	for( int i = index; i > 0; i /= 2){
		if( heap[i] < heap[i / 2 - 1] ){
				int temp = heap[i];
				heap[i] = heap[i / 2];
				heap[i / 2] = temp;
		}
	}
}

// Turning the array into a heap
void heapify( vector< int > &heap ){
	for( int i = heap.size() / 2 - 1; i >= 0; i-- ){
		bubbleDown( heap, i );
	}
}

int extractMin( vector< int > &heap ){
	int temp;
	temp = heap[0];

	heap[0] = heap[ heap.size() - 1 ];

	// I'm thinking the next 2 lines should be flipped for order
	bubbleDown( heap, 0 );
	heap.erase( heap.begin() + heap.size() - 1 );

	return temp;
}

void insert( vector< int > &heap, int value ){
	heap.push_back( value );
	bubbleUp( heap, heap.size() - 1 );
}

int main(){
	vector< int > numbers;
	istream *infile = &cin;

	try{
		infile = new ifstream( "pleasesort.txt" );
	}
	catch( exception e ){
		cerr << "Error with file" << endl;
		return -1;
	}

	int temp;
	for( ;; ){
		*infile >> temp;
		if( infile->fail() ){
			break;
		}
		numbers.push_back( temp );
	}

	//heapify( numbers );
	//insert( numbers, -10 );
	// extractMin( numbers );

	return 0;
}
