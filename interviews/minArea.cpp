#include <vector>
#include <iostream>
using namespace std;

// This was a cool coding challenge problem that I had for a gaming company in London. Basically it was, given a set of n points on a graph, what is the smallest size square that I could draw such that k points are strictly INSIDE the square.

// I only had 30 minutes to do this so I just deteremined what the size of the box had to be if i wanted to fit ALL the points then I just tried every permutation of decreasing the size of the box until I found the smallest one that still fit k points

//Helper function that just determines if there are k points in the square
bool containsK(vector<int> x, vector<int> y, int k, int minX, int maxX, int minY, int maxY){
    int count = 0;
    for( int i = 0; i < x.size(); i++ ){
        if( x[i] > minX && y[i] > minY && x[i] < maxX && y[i] < maxY ) count++;
    }
    if( count < k ) return false;
    else return true;
}

// Try every permutation
int recurseArea( vector<int> &x, vector<int> &y, int k, int minX, int maxX, int minY, int maxY ){
    int minArea = (maxY - minY) * (maxX - minX);
    cout << "curMin: " << minArea << endl;
    if (containsK(x,y,k,minX+1,maxX,minY+1,maxY)){
        minArea = recurseArea(x,y,k,minX+1,maxX,minY+1,maxY);
    }
    if (containsK(x,y,k,minX+1,maxX,minY,maxY-1)){
        int temp = recurseArea(x,y,k,minX+1,maxX,minY+1,maxY);
        if( temp < minArea ) minArea = temp;
    }
    if (containsK(x,y,k,minX,maxX-1,minY+1,maxY)){
        int temp = recurseArea(x,y,k,minX,maxX-1,minY+1,maxY);
        if( temp < minArea ) minArea = temp;
    }
    if (containsK(x,y,k,minX+1,maxX,minY+1,maxY)){
        int temp = recurseArea(x,y,k,minX,maxX-1,minY,maxY-1);
        if( temp < minArea ) minArea = temp;
    }
    return minArea;
}

/*
 * Complete the function below.
 */
int minarea(vector < int > x, vector < int > y, int k) {
    int minX = x[0];
    int minY = y[0];
    int maxX = x[0];
    int maxY = y[0];
    
    // Find the size of the box needed to fit all points.
    // Assuming x and y are of the same size
    for( int i = 0; i < x.size(); i++ ){
        if( x[i] < minX ) minX = x[i];
        if( x[i] > maxX ) maxX = x[i];
        if( y[i] < minY ) minY = x[i];
        if( y[i] > maxY ) maxY = y[i];
    }
    minX--;
    maxX++;
    minY--;
    maxY++;

	// This part is key. It needs to be an actual square.
	if(maxX - minX < maxY - minY) maxX = minX + (maxY - minY);
	else if(maxY - minY < maxX - minX) maxY = minY + (maxX - minX);

	cout << minX << " " << maxX << " " << minY << " " << maxY << endl;
    
    // I think the only way I know to do this would be by brute force (all combinations of reducing the square.)
    return recurseArea(x,y,k,minX,maxX,minY,maxY);

}

int main(){
	vector<int> x;
	vector<int> y;

	x.push_back(0);
	x.push_back(2);
	y.push_back(0);
	y.push_back(4);

	cout << minarea(x, y, 2) << endl;
	return 0;
}
