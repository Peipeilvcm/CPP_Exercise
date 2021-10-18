#include<bits/stdc++.h>
using namespace std;

const int N = 100010;

int h_size = 0;
int heap[N];

void down(int idx){
    int t = idx;
    int left_idx = 2*idx;
    int right_idx = 2*idx+1;
    if(left_idx <= h_size && heap[left_idx] < heap[t]){
        t = left_idx;
    }
    if(right_idx <= h_size && heap[right_idx] < heap[t]){
        t = right_idx;
    }
    if(t != idx){
        swap(heap[idx], heap[t]);
        down(t);
    }
}

void up(int idx){
    while((idx<<1) && heap[idx<<1] > heap[idx]){
        swap(heap[idx<<1], heap[idx]);
        idx <<= 1;
    }
}


int main(){

    int n, m;
    cin>>n>>m;
    for(int i = 1; i <= n; ++i){
        cin>>heap[i];
    }
    h_size = n;
    for(int i = n/2; i>=1; --i){
        down(i);
    }

    while(m--){
        cout<<heap[1]<<" ";
        heap[1] = heap[h_size];
        --h_size;
        down(1);
    }

    return 0;
}


