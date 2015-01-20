#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
using namespace std;

// This is just me practicing how to use templates.

template <typename T>
class ClassTemp {
	T a;
	T b;
   public:
	ClassTemp( T a, T b ): a( a ), b( b ){}
	void print();
};

template <>
class ClassTemp<char> {
	char a;
	char b;
   public:
	ClassTemp( char a, char b ): a( a ), b( b ){}
	void uppercase();
	void print();
};

void ClassTemp<char>::uppercase(){
	if( a >= 'a' && a <= 'z' ) a -= 32;
}

void ClassTemp<char>::print(){
	cout << "a: " << a << ", b: " << b << endl;
}

template <typename T>
void ClassTemp<T>::print(){
	cout << "a: " << a << ", b: " << b << endl;
}

template <typename Type>
Type max( Type a, Type b ){
	if( a >= b ) return a;
	return b;
}

template <typename Type>
Type max( vector< Type > list ){
	Type max;
	if( list.size() > 0 ) max = list[0];
	for( int i = 1; i < list.size(); i++ ){
		if( list[i] > max ) max = list[i];
	}
	return max;
}
		
int main( int argc, char *argv[] ){
	istream *infile = &cin;
	char input;
	vector<char> list;
	try{
		infile = new fstream( "chars.txt" );
	}
	catch( exception e ){
		cerr << "Error with IO" << endl;
	}

	for( ;; ){
		*infile >> input;
		if( infile->fail() ) break;
		list.push_back( input );
	}

	cout << max<char>( list ) << endl;

	ClassTemp<int> temp(3, 4);
	temp.print();

	ClassTemp<char> temp2('d', 'x');
	temp2.uppercase();
	temp2.print();

	return 0;
}
