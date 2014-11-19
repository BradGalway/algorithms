#include <iostream>

using namespace std;

int main(){
	int array[7] = { 13, 4, 8, 29, 21, 19, 25 };

	int smaller[7];
	int bigger[7];

	smaller[0] = -1;
	bigger[6] = -1;

	int smallest = 0;
	int biggest = 6;

	for( int i = 0; i < 7; i++ ){
		if( array[i] < array[smallest] || i == smallest ){
			smaller[i] = -1;
			smallest = i;
		}
		else{
			smaller[i] = smallest;
		}
	}
	for( int i = 6; i >= 0; i-- ){
		if( array[i] > array[biggest] || i == biggest ){
			bigger[i] = -1;
			biggest = i;
		}
		else{
			bigger[i] = biggest;
		}
	}

	for( int i = 0; i < 7; i++ ){
		if( smaller[i] != -1 && bigger[i] != -1 ){
			cout << array[ smaller[i] ] << ", " << array[i] << ", " << array[ bigger[i] ] << endl;
			return 0;
		}
	}
	cout << "No such subsequence" << endl;
	return 0;
}
