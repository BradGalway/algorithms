#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int tests = 0, N = 0, a = 2, b = 3;
    cin >> tests;
    for( int i = 0; i < tests; i++, a = 2, b = 3 ){
        cin >> N;
        if( N < 4 ){
            cout << "IsFibo" << endl;
            continue;
        }
        bool isFibo = 0;
        while( a <= N ){
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
