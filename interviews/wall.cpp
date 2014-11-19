#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int countUp(int N){
    if( N == 0 ) return 1;
    int sum = 0;
    if( N - 1 >= 0 ){
        sum += countUp( N - 1 );
    }
    if( N - 4 >= 0 ){
        sum += countUp ( N - 4 );
    }
    return sum;
}

int numPrimes( int N ){
    //for( int i = ; i <= N; i++ ){
        
    //}
	return 0;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T, N, combos;
    //cin >> T;
    combos = countUp( 30 );
    cout << combos << endl;
    for( int i = 0; i < T; i++ ){
        //cin >> N;
        //combos = countUp( 7 );
	//cout << combos << endl;
        //cout << numPrimes( combos );
    }
    return 0;
}
