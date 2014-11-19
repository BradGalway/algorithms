#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    cin >> N;
    string s;
    bool flipped = 0;
    for( int i = 0; i < N; i++, flipped = false ){
        cin >> s;
        for( int pos = -1, k = s.length() - 1; k >= 0; k--, pos = -1 ){
            if( s[k] == 'z') continue;
            char max = 'z';
            for( int j = k - 1; j >= 0; j-- ){
                if( s[j] < max && s[j] > s[k] ){
                    max = s[j];
                    pos = j;
                }
            }
            if( pos != -1 ){
                char temp = s[k];
                s[k] = s[pos];
                s[pos] = temp;
                flipped = true;
            }
            
        }
        if( flipped ){
            cout << s << endl;
        }
        else{
            cout << "no answer" << endl;
        }
    }
    return 0;
}
