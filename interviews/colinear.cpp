#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;

/*
  Find all collinear points in a given set
*/

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

// The "<" operator is misleading. It only means less than at the y-intercept.
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
	// Take in points and add them to a vector
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

	// The strategy is to make a series of lines with the points. Compare
	// each pair of points and add the lines properties to a map. If you find
	// two lines that are the same then you've found at least 3 points that are
	// collinear

	map< Line, vector< Point > > lines;
	
	double pSlope;
	double yintercept;
	for( int i = 0; i < points.size(); i++ ){
		for( int j = 0; j < points.size(); j++ ){// Should probably be j = i+1
			if( i != j ){
				// Find the equation of the line that the two points make
				pSlope = slope( points[i], points[j] );
				yintercept = points[i].y - (pSlope * points[i].x);

				Line line;
				line.slope = pSlope;
				line.yintercept = yintercept;
				// Add to the point to the map at this line if it doesn't already exist
				if( !contains( lines[line], points[i] ) ){
					lines[line].push_back( points[i] );
				}
				if( !contains( lines[line], points[j] ) ){
					lines[line].push_back( points[j] );
				}
			}
		}
	}

	// Print out the points that are collinear (more than 2 points on the line). 
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
