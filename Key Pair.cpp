//
//  Key Pair.cpp
//  
//
//  Created by Andreea-Ioana Deac on 14/12/2017.
//

#include <iostream>
#include <algorithm>
using namespace std;

int a[201];

int main() {
    int t, n, x, i, j, k, cod;
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n>>x;
        for(j=0; j<n; j++) {
            cin>>a[j];
        }
        sort(a, a+n);
        j=0;
        k=n-1;
        cod = 0;
        while(j<n/2) {
            while(k>n/2) {
                if(a[j] + a[k] == x) {
                    cout<<"Yes"<<"\n";
                    j= n+1;
                    k = 0;
                }
                else {
                    if(a[j] + a[k] > x)
                        k--;
                    else
                        j++;
                }
            }
        }
        if(k>0)
            cout<<"No"<<"\n";
    }
    return 0;
}
