//
//  Bird and maximum fruit gathering.cpp
//  
//
//  Created by Andreea-Ioana Deac on 29/11/2017.
//
// https://practice.geeksforgeeks.org/problems/bird-and-maximum-fruit-gathering/0

#include <stdio.h>
#include <iostream>
using namespace std;
int f[100001];
int a[200001];

int main() {
    int t, n, m, max, x, sum, ind;
    cin>>t;
    for(int i=0; i<t; i++){
        cin>> n>> m;
        sum = 0;
        for( int j=0; j<m && j<n; j++) {
            cin>>a[j];
            f[j] = a[j];
            sum += a[j];
        }
        max = sum;
        for(int j=m; j<n; j++){
            sum = sum - a[j%m];
            cin>>a[j%m];
            sum = sum + a[j%m];
            if(sum>max) {
                max=sum;
            }
        }
        ind = 0;
        if(n>m) {
            for(int j=n; j< n+m-1; j++) {
                sum = sum - a[j%m];
                a[j%m] = f[ind];
                ind++;
                sum = sum + a[j%m];
                if(sum>max) {
                    max = sum;
                }
            }
        }
        cout<<max<<"\n";
    }
    
    return 0;
}
