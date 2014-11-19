#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>

using namespace std;

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

vector<string> deserialize( string serialized ){
	vector< string > deserialized;
	for( int i = 0; i < serialized.length(); i++ ){
		string s;
		int length = 0;
		for( ;; i++ ){
			if( serialized[i] == '.' ){
				i++;
				break;
			}
			length *= 10;
			length += atoi( &serialized[i] );
		}
		for( int j = 0; j < length; j++, i++ ){
			s += serialized[i];
		}
		deserialized.push_back( s );
		i--;
	}
	return deserialized;
}

int main(){
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
