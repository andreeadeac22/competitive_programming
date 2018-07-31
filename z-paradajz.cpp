//
//  z-paradajz.cpp
//  
//
//  Created by Andreea-Ioana Deac on 29/07/2018.
//

#include <iostream>
#include <map>
using namespace std;

int n,d,sum;
int a[200001];

map<int, int> opt;

int main() {
    int i;
    cin>>n>>d;
    for(i=0;i<n;i++){
        cin>>a[i];
        if(opt.find(a[i]) == opt.end())
            opt.insert(make_pair(a[i],1));
        else
            opt[a[i]]++;
        if(i-d>=0){
            if(opt.find(a[i-d])->second == 1)
                opt.erase(a[i-d]);
            else
                opt[a[i-d]]--;
        }
        sum += opt.begin()->first;
    }
    cout<<sum<<"\n";
    return 0;
}
