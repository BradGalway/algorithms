#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

printVector( vector< int > numbers ){
	for( int i = 0; i < numbers.size(); i++ ){
		cout << numbers[i] << " ";
	}
	cout << endl;
}

void merge( vector< int > &numbers, int begin, int end ){
	vector< int > newList;
	int temp = begin, temp2 = begin + ((end - begin) / 2) + 1;
	cout << "begin: " << begin << ", end: " << end << endl;
	while( temp < begin + ((end - begin) / 2) + 1 || temp2 <= end ){
		cout << "comparing: " << numbers[temp] << " and: " << numbers[temp2] << endl;
		if( temp == begin + ((end - begin) / 2) + 1 ){
			newList.push_back( numbers[temp2] );
			temp2++;
		}
		else if( temp2 == end + 1 ){
			newList.push_back( numbers[temp] );
			temp++;
		}
		else if( numbers[temp] > numbers[temp2] ){
			newList.push_back( numbers[temp2] );
			temp2++;
		}
		else{
			newList.push_back( numbers[temp] );
			temp++;
		}
	}
	for( int i = 0; i < newList.size(); i++ ){
		numbers[begin + i] = newList[i];
	}
}

void partition( vector< int > &numbers, int begin, int end ){
	srand( time(NULL) );
	int pivot = rand() % end + begin;
	int i = begin + 1, j = end, temp;
	temp = numbers[pivot];
	numbers[pivot] = numbers[begin];
	numbers[begin] = temp;
	for( ;; ){
		cout << numbers[i] << " vs " << numbers[j] << " with pivot: " << numbers[begin] << endl;
		for(; i <= end && numbers[i] <= numbers[begin]; i++ ){}
		for(; j > begin && numbers[j] > numbers[begin]; j-- ){}
		if( j < i ) break;
		cout << "i: " << i << " and j: " << j << endl;
		temp = numbers[i];
		numbers[i] = numbers[j];
		numbers[j] = temp;
	}
	cout << "i: " << i << " and j: " << j << " and begin: " << begin << endl;
	temp = numbers[begin];
	numbers[begin] = numbers[j];
	numbers[j] = temp;
	return;
}

void mergeSort( vector< int > &numbers, int begin, int end ){
	if( end - begin == 0 ){
		return;
	}

	mergeSort( numbers, begin, begin + ((end - begin) / 2 ));
	mergeSort( numbers, begin + ((end - begin) / 2) + 1, end );

	merge( numbers, begin, end );

	return;
}

void quickSort( vector< int > numbers, int begin, int end ){
	if( end - begin == 0 ){
		return;
	}

	quickSort( numbers, begin, begin + ((end - begin) / 2 ));
	quickSort( numbers, begin + ((end - begin) / 2) + 1, end );

	partition( numbers, begin, end );

	return;
}

int main(){
	istream *infile = &cin;
	vector<int> numbers;
	vector<int> numbersCopy;
	try{
		infile = new ifstream( "pleasesort.txt" );
	}
	catch( exception e ){
		cerr << "IO error" << endl;
	}

	int input;
	for( ;; ){
		*infile >> input;
		if( infile->fail() ){
			break;
		}
		numbers.push_back( input );
		numbersCopy.push_back( input );
	}


	mergeSort( numbers, 0, numbers.size() - 1 );
	for(int i = 0; i < numbers.size(); i++ ){
		cout << numbers[i] << " ";
	}
	cout << endl;

	quickSort( numbersCopy, 0, numbersCopy.size() - 1 );
	for(int i = 0; i < numbersCopy.size(); i++ ){
		cout << numbersCopy[i] << " ";
	}
	cout << endl;
	return 0;
}
