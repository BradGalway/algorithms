#include <iostream>
using namespace std;

/*
Problem: You have a string consisting of the lower characters 'a' and 'b'.
You want to reverse the substring in such a way that will result in the "largest"
string. Example: aaabbab -> [bbaaa]ab
*/

/*
Solution: I used a bit of dynamic programming here but I really didn't need to.
*/
int main(int argc, char *argv[]){

	if( argc != 2 ){
		cerr << "Incorrect input" << endl;
		return 1;
	}
	string s = argv[1];
	int b = -1;
	
	for( int i = 0; i < s.length(); i++ ){ // Find location of first 'b'
		if( s[i] == 'b' ){
			b = i;
			break;
		}
	}
	if( b == -1 ){
		cout << "0, 0" << endl;
		return 0;
	}
	
	int a[s.length() - (1 + b)];
	if( s[0] == 'a' ){
		a[0] = 1;
	}
	else{
		a[0] = 0;
	}
	int max = 0;
	for( int i = 1; i < s.length(); i++ ){
		if( i < b ){
			a[i] = -1;
		}
		else if( s[i] == 'a' ){
			a[i] = a[i-1] + 1;
		}
		else{
			a[i] = 0;
		}
		if( a[i] > max ){
			max = i;
		}
	}

	cout << b << ", " << max << endl;	
	return 0;
}
