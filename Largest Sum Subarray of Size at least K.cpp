//
//  Largest Sum Subarray of Size at least K.cpp
//  
//
//  Created by Andreea-Ioana Deac on 29/11/2017.
//
// https://practice.geeksforgeeks.org/problems/largest-sum-subarray-of-size-at-least-k/0

#include <stdio.h>
#include <iostream>
using namespace std;

int a[1001][1001];
int cm[1001];


int main() {
    int t, n, sum, k, i,l, maxi;
    cin>>t;
    for(int j=0; j<t;j++){
        cin>>n;
        for(i=0; i<n; i++) {
            cin>>a[i][0];
            if( i==0)
                cm[0] = a[i][0];
            else
                if( a[i][0] > cm[0] )
                    cm[0] = a[i][0];
            for(l=0; l<i;l++) {
                a[l][i-l] = a[l][i-l-1] + a[i][0];
                if( l == 0 ) {
                    cm[i-l] = a[l][i-l];
                } else
                    if( a[l][i-l] > cm[i-l] )
                        cm[i-l] = a[l][i-l];
            }
        }
        cin>>k;
        maxi = cm[k-1];
        for(i =k; i<n ;i++ )
            if(maxi < cm[i])
                maxi = cm[i];
        cout<< maxi<<"\n";
    }
    return 0;
}
