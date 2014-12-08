#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long int factorial( long long int n ){
    long long int sum = n;
    if( n == 0 ) return 1;
    for( long long int i = n - 1; i >= 2; i-- ){
        sum *= i;
    }
    cout << n << "! = " << sum << endl;
    return sum;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int tests;
    cin >> tests;
    long long int row;
    for( int test = 0; test < tests; test++ ){
        cin >> row;
        int position = 1;
        bool found = false;
        for( ; position < row; position++ ){
	    cout << "position: " << position << endl;
            if(( factorial(row) / ( factorial(position) * factorial(row - position) ) ) % 2 == 0 ){
                found = true;
                cout << found << endl;
                break;
            }
        }
        if( !found ) cout << -1 << endl;
    }
    return 0;
}
