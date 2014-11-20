#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
https://www.hackerrank.com/contests/101july13/challenges/red-john-is-back
*/

// This will give you the number of ways you can array the bricks. Horrible non-polynomial run-time.
// If you wanted one possible way you could do it in O(1) time but ALL possible ways is gross.
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

// For whatever reason the question then asks you to determine how many prime numbers are <= the
// number of brick combinations possible. I think you can do this using DP.
int numPrimes( int N ){
	int primes[N-1];
	for( int i = 0; i < N-1; i++ ){
        	primes[i] = i + 2;
    	}
	int numPrimes = 0;
	for( int i = 0; i < N-1; i++ ){
        	if( primes[i] == 0 ) continue;
		numPrimes++;
		int temp = primes[i];
		for( int j = i; j < N-1; j+= temp ) primes[j] = 0;
    	}
	return numPrimes;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T, N, combos;
    cin >> T;
    for( int test = 0; test < T; test++ ){
	cin >> N;
	combos = countUp( N );
	//cout << "combos: " << combos << endl;
	cout << numPrimes( combos ) << endl;
    }
    return 0;
}
