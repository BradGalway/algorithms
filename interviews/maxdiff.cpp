#include <iostream>
#include <vector>
using namespace std;

// Find the max difference between any two points such that the bigger number follows the smaller in terms of index in the array. Pretty simple, just keep track of the smallest preceeding number and compare to current index.

int maxDifference(vector< int > arr) {
    int curMin = arr[0];
    int curMaxDifference = arr[1] - curMin;
    for( int index = 1; index < arr.size(); index++ ){
	cout << "comparing: " << arr[index] << " and " << curMin << endl;
        if( arr[index] - curMin > curMaxDifference ){
            curMaxDifference = arr[index] - curMin;
        }
        if( curMin < arr[index] ) curMin = arr[index];
    }
    return curMaxDifference;
}

int main(){
	vector<int> array;
	array.push_back(2);
	array.push_back(3);
	array.push_back(10);
	array.push_back(2);
	array.push_back(4);
	array.push_back(8);
	array.push_back(1);
	cout << maxDifference( array ) << endl;
	return 0;
}
