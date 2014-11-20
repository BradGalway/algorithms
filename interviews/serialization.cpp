#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>

using namespace std;

/* Problem:
You have a vector of strings and we need to send them over the internet.
How can we send them such that when we get the message we can reconstruct the original vector?
*/

// The method is to have the length of the string followed by a dot.
// Example: {Brad, Mathew} -> 4.Brad6.Mathew
string serialize( vector< string > strings ){
	string serialized = "";
	for( int i = 0; i < strings.size(); i++ ){
		stringstream ss;
		ss << strings[i].length();
		serialized += ss.str();
		serialized += ".";
		serialized += strings[i];
	}
	return serialized;
}

// The only trick here is to interpret the character lengths as numerical.
vector<string> deserialize( string serialized ){
	vector< string > deserialized;
	for( int i = 0; i < serialized.length(); i++ ){
		string s;
		int length = 0;
		for( ;; i++ ){ // Interpret the length
			if( serialized[i] == '.' ){
				i++;
				break;
			}
			length *= 10;
			length += atoi( &serialized[i] );
		}
		for( int j = 0; j < length; j++, i++ ){// We know the length, just put it into its own string
			s += serialized[i];
		}
		deserialized.push_back( s );
		i--; // Needed because of the i++ in the look signature
	}
	return deserialized;
}

int main(){
	// Example vector
	vector< string > strings;
	strings.push_back( "bra" );
	strings.push_back( "dl" );	
	strings.push_back( "eyGa" );	
	strings.push_back( "l" );	
	strings.push_back( "way" );

	cout << serialize( strings ) << endl;
	vector< string> deserialized = deserialize( serialize( strings ) );
	for( int i = 0; i < deserialized.size(); i++ ){
		cout << deserialized[i] << " ";
	}
	cout << endl;
	return 0;
}
