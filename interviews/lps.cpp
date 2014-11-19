#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main( int argc, char *argv[] ){
        string str = argv[1];
	int longest = 1;
	int lowerBound, upperBound = 0;
        for( int i = 0; i < str.length(); i++ ){
		int tempMax = 1;
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
