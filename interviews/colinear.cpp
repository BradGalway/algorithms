#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

class Line {
	public:
	double slope;
	double yintercept;
};

class Point {
	public:
	double x;
	double y;
};

double slope( Point a, Point b ){
	return ( b.y - a.y ) / ( b.x - a.x );	
}

bool operator==(Line a, Line b){
	return ( a.slope == b.slope && a.yintercept == b.yintercept );
}

bool operator==( Point a, Point b ){
	return ( a.x == b.x && a.y == b.y );
}

bool operator<(Line a, Line b){
	return a.yintercept < b.yintercept;
}

bool contains( vector< Point > points, Point a ){
	for( int i = 0; i < points.size(); i++ ){
		if( a == points[i] ){
			return true;
		}
	}
	return false;
}

int main(){
	istream *infile = &cin;
	try {
		infile = new ifstream( "points.txt" );
	}
	catch(exception e ){
		cerr << "Something is wrong with your file" << endl;
	}

	vector< Point > points;
	double input;
	for ( ;; ){
		Point a;
		{// implement error checking
		*infile >> input;
		a.x = input;
		*infile >> input;
		a.y = input;
		
		if ( infile->fail() ) break;  

		points.push_back( a );
		cout << "added point: (" << a.x << ", " << a.y << ")" << endl;
		}
	}

	map< Line, vector< Point > > lines;
	
	double pSlope;
	double yintercept;
	for( int i = 0; i < points.size(); i++ ){
		for( int j = 0; j < points.size(); j++ ){
			if( i != j ){
				pSlope = slope( points[i], points[j] );
				yintercept = points[i].y - (pSlope * points[i].x);

				Line line;
				line.slope = pSlope;
				line.yintercept = yintercept;
				if( !contains( lines[line], points[i] ) ){
					lines[line].push_back( points[i] );
				}
				if( !contains( lines[line], points[j] ) ){
					lines[line].push_back( points[j] );
				}
			}
		}
	}

	for (std::map<Line,vector< Point > >::iterator it = lines.begin(); it != lines.end(); ++it){
		if( it->second.size() > 2 ){
			cout << "The following points are colinear in a line:" << endl;
			for( int i = 0; i < it->second.size(); i++ ){
				cout << "(" << it->second[i].x << ", " << it->second[i].y << ") ";
			}
			cout << endl;
		}
	}
}
