#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


void bubbleDown( vector< int > &heap, int index ){
	for( int i = index; i < heap.size() / 2; ){
		if( i * 2 + 2 == heap.size() ){
			if( heap[i] > heap[i * 2 + 1] ){
				int temp = heap[i];
				heap[i] = heap[i * 2 + 1];
				heap[i * 2 + 1] = temp;
			}
			break;
		}
		if( heap[i] > heap[i * 2 + 1] || heap[i] > heap[i * 2 + 2] ){
			if( heap[i * 2 + 1] < heap[i * 2 + 2] ){
				int temp = heap[i];
				heap[i] = heap[i * 2 + 1];
				heap[i * 2 + 1] = temp;
				i = i * 2 + 1;
			}
			else{
				int temp = heap[i];
				heap[i] = heap[i * 2 + 2];
				heap[i * 2 + 2] = temp;
				i = i * 2 + 2;
			}
		}
		else{
			return;
		}
	}
}

void bubbleUp( vector< int > &heap, int index ){
	for( int i = index; i > 0; i /= 2){
		if( heap[i] < heap[i / 2 - 1] ){
				int temp = heap[i];
				heap[i] = heap[i / 2];
				heap[i / 2] = temp;
		}
	}
}

void heapify( vector< int > &heap ){
	for( int i = heap.size() / 2 - 1; i >= 0; i-- ){
		bubbleDown( heap, i );
	}
}

int extractMin( vector< int > &heap ){
	int temp;
	temp = heap[0];

	heap[0] = heap[ heap.size() - 1 ];
	bubbleDown( heap, 0 );

	heap.erase( heap.begin() + heap.size() - 1 );
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
	cout << endl;

	//heapify( numbers );
	//insert( numbers, -10 );
	// extractMin( numbers );

	return 0;
}
