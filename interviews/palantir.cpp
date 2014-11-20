#include <iostream>
#include <vector>
using namespace std;

// Problem: We have a MxN matrix of 0s and 1s. The goal is to make as many rows either all 1s or
// all 0s. The only operation we can do is flip all numbers in a column.

// I'm pretty sure this is an NP-Hard problem. I did a local search. I completed it on HackerRank
// so this version is only like half of what I did there. I'll try to do it again soon

// The trick to local search is a good cost function. I made the cost of each row be how far away
// it was to being all 0s or all 1s (whichever is closest). The cost of the matrix is the sum
// of the costs of the rows.
int cost( vector<string> &matrix, int N, int M ){
    int totalCost = 0;
    for( int i = 0, pCount = 0, tCount = 0; i < N; i++, pCount = 0, tCount = 0 ){
        for( int j = 0; j < M; j++ ){
            if( matrix[i][j] == 'P' ) pCount++;
            else tCount++;
        }
        if( pCount > tCount ) totalCost += (M - pCount);
        else totalCost += (M - tCount);
    }
    return totalCost;
}

// Flip a column
void flip(vector<string> &matrix, int N, int col ){
    for( int row = 0; row < N; row++ ){ // Loop through the rows flipping the certain column
        if( matrix[row][col] == 'P' ) matrix[row][col] = 'T';
        else matrix[row][col] = 'P';
    }
    return;
}


// This counts how many rows were "complete" i.e, all 0s or all 1s.
int countSame( vector<string> &matrix, int N, int M ){
    int same = 0;
    for( int i = 0; i < N; i++ ){// Go through each row
        int flag  = 1; // :(
        for( int j = 1; j < M; j++ ){ // Go through each column
            if( matrix[i][j] != matrix[i][0] ){ // If doesn't match the first column, break
                flag = 0;
                break;
            }
        }
        if( flag ) same += 1;
    }
    return same;
}

int main() {
    // local search
    // A local search goes through a graph of nodes hopping from node to node trying to find the lowest
    // cost node according to the cost function. Note that this may end up only finding a local
    // minimum depending on its path. Each "node" is a particular arrangement of the matrix (i.e,
    // no columns have been flipped vs 1st column vs 1st and 2nd etc.
    int M;
    int N;
    
    cin >> N;
    cin >> M;
    
    vector<string> matrix;
    string input;
    for( int i = 0; i < N; i++ ){
        cin >> input;
        matrix.push_back( input );
    }
    // Need to keep calculating new "current" costs and comparing them against a best cost.
    // I also need an unaltered "original" matrix for restarts.
    int currentCost = cost( matrix, N, M );
    int bestCost = currentCost;
    vector<string> bestState = matrix;
    bool done = false;
    for( ; !done ; ){ // The done flag gets set when none of the neighbours had a lower cost.
        for( int i = 0; i < M; i++ ){ // Go through each column and see if flipping it reduces cost
            vector<string> copy = matrix;
            flip( copy, N, i );
            if( cost( copy, N, M ) < bestCost ){
                bestCost = cost( copy, N, M );
                bestState = copy;
            }
        }
        if( currentCost == bestCost ) done = true;
        else{
            matrix = bestState;
            currentCost = bestCost;
        }
    }
    cout << countSame( matrix, N, M ) << endl;
    return 0;
}
