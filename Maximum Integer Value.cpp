//
//  Maximum Integer Value.cpp
//  
//
//  Created by Andreea-Ioana Deac on 29/11/2017.
//
// https://practice.geeksforgeeks.org/problems/maximum-integer-value/0

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    int n, sum, x, y, len;
    long mod = 1000000007;
    cin>>n;
    for(int i=1; i<=n; i++) {
        cin>>s;
        len = s.length();
        x = (int)s[0]-48;
        sum = x;
        for( int j=1; j<len; j++ ) {
            y = (int)s[j] - 48;
            if( x*y < x+y )
                sum += y;
            else {
                if(sum>mod)
                    sum= sum - mod;
                sum = sum * y;
            }
            x=y;
        }
        cout<<sum<< "\n";
    }
    return 0;
}
