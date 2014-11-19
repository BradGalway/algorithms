#include <iostream>
#include <vector>
using namespace std;

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

void flip(vector<string> &matrix, int N, int i ){
    for( int j = 0; j < N; j++ ){
        if( matrix[j][i] == 'P' ) matrix[j][i] = 'T';
        else matrix[j][i] = 'P';
    }
    return;
}

int countSame( vector<string> &matrix, int N, int M ){
    int same = 0;
    for( int i = 0; i < N; i++ ){
        int flag  = 1; // :(
        for( int j = 1; j < M; j++ ){
            if( matrix[i][j] != matrix[i][0] ){
                flag = 0;
                break;
            }
        }
        if( flag ) same += 1;
    }
    return same;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    // local search
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
    int currentCost = cost( matrix, N, M );
    int bestCost = currentCost;
    vector<string> bestState = matrix;
    cout << "intitial cost: " << bestCost << endl;
    bool done = false;
    for( ; !done ; ){
        for( int i = 0; i < M; i++ ){
            vector<string> copy = matrix;
            flip( copy, N, i );
            cout << "flipped cost: " << cost( copy, N, M ) << endl;
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
