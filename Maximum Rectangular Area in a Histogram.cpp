//
//  Maximum Rectangular Area in a Histogram.cpp
//  
//
//  Created by Andreea-Ioana Deac on 02/12/2017.
//

#include <iostream>
#include <fstream>
using namespace std;

int a[101];

ifstream fin("input.txt", ifstream::in);

int main() {
    int t, n, i, j, k, x, sum, maxi= 0;
    fin>>t;
    for(i=0;i<t;i++) {
        fin>>n;
        maxi=0;
        for(j=0; j<n; j++) {
            fin>>a[j];
        }
        for( j=0; j<n; j++) {
            sum = 0;
            //cout<<"j "<<j<<" ";
            for(k=j;k>=0 && a[j]<=a[k];k--) {
                //cout<<"k "<< k << " " ;
                sum+=a[j];
            }
            for(k=j+1;k<n && a[j]<=a[k];k++) {
                //cout<<"k "<< k << " ";
                sum+=a[j];
            }
            if(sum>maxi) {
                maxi=sum;
                //cout<<j<<" "<<sum<<"\n";
            }
        }
        cout<<maxi<<"\n";
    }
    return 0;
}
