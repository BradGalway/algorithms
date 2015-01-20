#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    // I think the problem was you were given a string that was either a palindrome
    // or if you removed one character it would become one. Print out which character
    // would make it a palindrome if removed.
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    // Thought process: assume a palindrome. Start from the middle, and continue
    // going outwards until we find the character that violates it being a palindrome
     
    int tests = 0;
    cin >> tests;
    string s;
    for( int test = 0, a = 0, b = 0; test < tests; test++ ){
        cin >> s;
        a = s.length() / 2;
        b = s.length() / 2;
        if( s.length() % 2 == 0 ){
            a--;
        }
        bool palindrome = true;
        for( ; a >= 0 && b < s.length(); a--, b++ ){
            if( s[a] == s[b] ) continue;
            palindrome = false;
            break;
        }
        if( !palindrome ){
            //cout << "original a: " << a << ", b: " << b << endl;
            int originala = a;
            int originalb = b;
            a = (s.length() / 2) - 1;
            b = s.length() / 2;
            if( s.length() % 2 == 0 ){
                a--;
            }
            for( ; a >= 0 && b < s.length(); a--, b++ ){
                if( s[a] == s[b] ) continue;
                break;
            }
            if( a == -1 ) cout << originalb << endl;
            else if( s[a] == s[b+1] ) cout << b << endl;
            else cout << a << endl;
            
        }
        else cout << -1 << endl;
    }
    return 0;
}
