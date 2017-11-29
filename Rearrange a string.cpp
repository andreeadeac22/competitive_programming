//
//  Rearrange a string.cpp
//  
//
//  Created by Andreea-Ioana Deac on 29/11/2017.
//
// https://practice.geeksforgeeks.org/problems/rearrange-a-string/0

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int a[27];

int main() {
    
    string s;
    int sum,t, l, len;
    cin>>t;
    for(int i=0; i<t; i++) {
        sum = 0;
        for( int j=0; j<26;j++){
            a[j]=0;
        }
        cin>> s;
        len = s.length();
        for(int j=0; j<len; j++) {
            l = (int)s[j];
            if(48<= l && l <=57)
                sum += l -48;
            else {
                a[l-65]++;
            }
        }
        for(int j=0; j<26; j++) {
            for( int k=0; k<a[j]; k++)
                cout<<(char)(j +65);
        }
        cout<<sum << "\n";
    }
    return 0;
}
