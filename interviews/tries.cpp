#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class TrieNode{
   public:
	string letter;
	enum { NumChars = 26 };
	bool isWord;
	TrieNode *letters[NumChars];

	TrieNode(){
		isWord = false;
		for( int i = 0; i < NumChars; i++ ){
			letters[i] = NULL;
		}
	}

	~TrieNode(){
		for( int i = 0; i < NumChars; i++ ){
			if( letters[i] != NULL ){
				delete letters[i];
			}
		}
	}
		

	void print( string sofar );
	void insert( const string &word );
	void remove( const string &word );
	void autocomplete( const string &word, string sofar, vector< string > &complete );
};

void TrieNode::autocomplete( const string &word, string sofar, vector< string > &complete ){
	sofar += letter;
	if( word == "" ){
		if( isWord ){
			complete.push_back( sofar );
		}	
		for( int i = 0; i < NumChars; i++ ){
			if( letters[i] != NULL ){
				letters[i]->autocomplete( word, sofar, complete );
			}
		}
	}
	else if( letters[ word[0] - 97 ] != NULL ){
		letters[ word[0] - 97 ]->autocomplete( word.substr( 1 ), sofar, complete );
	}
}

void TrieNode::print( string sofar ){
	if( this == NULL ){
		return;
	}
	sofar += letter;
	if( isWord ){
		cout << sofar << endl;
	}
	for( int i = 0; i < NumChars; i++ ){
		if( letters[i] != NULL ){
			letters[i]->print( sofar );
		}
	}
}

void TrieNode::insert( const string &word ){
	TrieNode *temp = this;
	for( int i = 0; i < word.length(); i++ ){
		if( temp->letters[ word[ i ] - 97 ] == NULL ){
			TrieNode *node = new TrieNode();
			node->letter = word[i];
			temp->letters[ word[ i ] - 97 ] = node;
		}
		if( i == word.length() - 1 ){
			temp->letters[ word[ i ] - 97 ]->isWord = true;
		}
		temp = temp->letters[ word[ i ] - 97 ];
	}	
}

int main(){
	string input;
	TrieNode *trie = new TrieNode();

	istream *infile = &cin;
	try{
		infile = new ifstream( "words.txt" );
	}
	catch( exception e ){
		cerr << "Something went wrong with the file IO" << endl;
	}

	for( ;; ){
		*infile >> input;
		if( infile->fail() )
			break;
		trie->insert( input );		
	}

	//trie->print("");

	vector< string > autoc;
	trie->autocomplete( "bradl", "", autoc );

	delete trie;

	return 0;
}
