#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
Problem: https://www.hackerrank.com/challenges/is-fibo
*/

int main() {
    int tests = 0, N = 0, a = 2, b = 3;
    cin >> tests;
    for( int i = 0; i < tests; i++, a = 2, b = 3 ){
        cin >> N;
        if( N < 4 ){ // Break out early if number <= 3
            cout << "IsFibo" << endl;
            continue;
        }
        bool isFibo = 0;
        while( a <= N ){ // Basically when both of your numbers are greater than N, N wasn't a fibo
            int temp = a;
            a = b;
            b += temp;
            if( b == N ){
                isFibo = true;
                break;
            }
        }
        if( isFibo ) cout << "IsFibo" << endl;
        else cout << "IsNotFibo" << endl;
    }
    return 0;
}
