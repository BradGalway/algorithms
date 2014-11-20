#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Self-explanatory

int main(int argc, char *argv[]){
	string str = argv[1];
	
	for( int i = 0, j = str.length() - 1; i <= j ; i++, j-- ){
		if( str[i] != str[j] ){
			cout << "Not a palindrome" << endl;
			return false;
		}
	}
	cout << "Palindrome" << endl;
	return 0;
}
