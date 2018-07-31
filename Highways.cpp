//
//  Highways.cpp
//  
//
//  Created by Andreea-Ioana Deac on 29/07/2018.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <pair<int, int> > edge[100001];
int n, h, start_node, end_node;

priority_queue<pair<int, int> > d; // -weight, index

int act_d[100001];
int viz[100000];

pair<int, int> closest_pair;
pair<int, int> neigh;

int main() {
    cin>>n>>h>>start_node>>end_node;
    int i,x,y,dist,node,w;
    for(i=0;i<n;i++)
        act_d[i+1] = 987654321;
    
    act_d[start_node] = 0;
    viz[start_node]= 1;
    
    for(i=0;i<h;i++) {
        cin>>x>>y>>dist;
        edge[x].push_back(make_pair(y, dist));
        edge[y].push_back(make_pair(x, dist));
        if(x == start_node) {
            d.push(make_pair(-dist, y));
            act_d[y] = dist;
        }
        if (y == start_node) {
            d.push(make_pair(-dist, x));
            act_d[x]=dist;
        }
    }
    
    for(i=0;i<n;i++) {
        int cod=0;
        do{
            if (d.empty())
                cod=1;
            else{
                closest_pair = d.top();
                d.pop();
                w = - (closest_pair.first);
                node = closest_pair.second;
                //cout<<w<<" "<<node<<"\n";
                if( w == act_d[node] && viz[node] == 0) {
                    //cout<<"act dist "<<w<<" and viz 0\n";
                    cod = 1;
                    viz[node] = 1;
                    for (int j=0;j<edge[node].size();j++) {
                        neigh = edge[node][j];

                        //cout<<"neight first "<<neigh.first<<"\n";
                        //cout<<"neigh second "<<neigh.second<<"\n";
                        
                        if(act_d[neigh.first] > act_d[node] + neigh.second && viz[neigh.first] == 0) {
                            //cout<<"update neigh first "<<neigh.first<<"\n";
                            act_d[neigh.first] = act_d[node] + neigh.second;
                            d.push(make_pair(-act_d[neigh.first], neigh.first));
                        }
                    }
                }
            }
        } while(!cod);
        if(viz[end_node] == 1)
            break;
    }
    if(viz[end_node]==0)
        cout<<"-1\n";
    else
        cout<<act_d[end_node]<<"\n";

    return 0;
}
