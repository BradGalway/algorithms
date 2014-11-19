#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>


// SCRATCH THIS QUESTION. APPARENTLY IT'S IMPOSSIBLE TO DO IT IN O(N)

using namespace std;

class threetuple{
   public:
	string id;
	int first;
	int second;
};

int main(){
	vector< threetuple > tuples;

	istream *infile = &cin;
	try{
		infile = new ifstream( "3tuples.txt" );
	}
	catch( exception e ){
		cerr << "Error opening the file" << endl;
		exit(0);
	}

	for( ;; ){
		threetuple temp;
		*infile >> temp.id;
		if( infile->fail() ){
			break;
		}
		*infile >> temp.first;
		*infile >> temp.second;

		tuples.push_back( temp );
	}

	int former = tuples[0].second;
	string formerid = tuples[0].id;
	cout << "(" << tuples[0].id << ", " << tuples[0].first << "), ";
	for( int i = 1; i < tuples.size(); i++ ){
		if( former <= tuples[i].first ){
			cout << "here1(" << formerid << ", " << former << "), ";
			cout << "(" << tuples[i].id << ", " << tuples[i].first << "), ";
			former = tuples[i].second;
			formerid = tuples[i].id;
		}
		else if( former <= tuples[i].second ){
			cout << "here2(" << tuples[i].id << ", " << tuples[i].first << "), ";
			cout << "(" << formerid << ", " << former << "), ";
			former = tuples[i].second;
			formerid = tuples[i].id;
		}
		else{
			cout << "here3(" << tuples[i].id << ", " << tuples[i].first << "), ";
			cout << "(" << tuples[i].id << ", " << tuples[i].second << "), ";
		}
		
	}
	cout << "(" << formerid << ", " << former << "), " << endl;
	return 0;
}
