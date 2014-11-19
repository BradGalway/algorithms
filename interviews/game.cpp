#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int tests;
    cin >> tests;
    
    int N;
    for( int i = 0; i < tests; i++ ){
        cin >> N;
        int numbers[N];
        int states[N];
        fill_n(states, N, -1);
        for( int j = 0; j < N; j++ ){
            cin >> numbers[j]; 
        }
        for( int j = N-1; j >= 0 ; j-- ){
            states[j] = numbers[j];
            for( int k = 2; k <= 4; k++ ){
                if( j + k >= N ) break;
                if( states[j+k] + numbers[j] > states[j] ) states[j] = states[j+k] + numbers[j];
            }
        }
        for( int j = 0; j < N; j++ ){
            cout << states[j] << " ";
        }
        cout << endl;
        
    }
    return 0;
}

