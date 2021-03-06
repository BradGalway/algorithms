#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
Problem: Find the longest palindrome substring
*/

// This is an n^2 solution. Basically it just goes through every character, then checks to the left and right
// until it finds characters that don't match or reaches the end. Note that it also does "pairs" of characters.
// I.e aba vs abba. One will check b then its neighbours and the other will check bb and then its neighbours.
int main( int argc, char *argv[] ){
        string str = argv[1];
	int longest = 1;
	int lowerBound, upperBound = 0;
        for( int i = 0; i < str.length(); i++ ){
		int tempMax = 1;
		// One character and its neighbours
                for( int j = i, k = i; j >= 0 && k <= str.length() - 1; j--, k++ ){
			if( str[j] != str[k] ){
				break;
			}
			if( tempMax > longest ){
				longest = tempMax;
				lowerBound = j;
				upperBound = k;
			}
			tempMax += 2;
                }

		tempMax = 2;
		// Two characters and their neighbours
		for( int j = i, k = i + 1; j >= 0 && k <= str.length() - 1; j--, k++ ){
			if( str[j] != str[k] ){
				break;
			}
			if( tempMax > longest ){
				lowerBound = j;
				upperBound = k;
				longest = tempMax;
			}
			tempMax += 2;
                }
        }
	cout << "Longest ps: " << str.substr( lowerBound, upperBound + 1 ) << endl;
        return 1;
}

// Come back later and write the dynamic programming solution
