// 100 7
// 1 101 1 
// 2 1 2
// 2 2 3 
// 2 3 3 
// 1 1 3 
// 2 3 1 
// 1 5 5

#include<bits/stdc++.h>
using namespace std;

const int NUM_MAX = 500001;
int p[NUM_MAX];
int d[NUM_MAX];

void init(){
    for(int i = 0; i < NUM_MAX; ++i){
        p[i] = i;
        d[i] = 0;
    }
}

int find(int x){
    if(p[x] != x){
        int t = find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
}

void unite(int x, int y){
    int x_root = find(x);
    int y_root = find(y);
    if(x_root == y_root){
        return;
    }else{
        p[x_root] = y_root;
    }
}

bool same(int x, int y){
    return find(x) == find(y);
}

int main(){
    init();

    int N, K;
    cin>>N>>K;
    int res = 0;
    int D, X, Y;
    for(int i = 0; i < K; ++i){
        cin>>D>>X>>Y;
        if(X > N || Y > N){
            res++;
            continue;
        }else if(D == 1){
            int u = find(X);
            int v = find(Y);
            if(u == v && ((d[X] - d[Y]) % 3 != 0)){
                res++;
            }else if(u != v){
                p[u] = v;
                d[u] = (d[Y] - d[X]);
            }
        }else if(D == 2){
            int u = find(X);
            int v = find(Y);
            if(u == v && ((d[X] - d[Y] - 1) % 3)){
                res++;
            }else if(u != v){
                p[u] = v;
                d[u] = (d[Y] - d[X]) + 1;
            }

        }

    }
    cout<<res;

    return 0;
}