#include<bits/stdc++.h> // 万能头文件

using namespace std;

void input1_c(){
    int a, b;
    while(scanf("%d %d", &a, &b) != EOF){
        int c =  a + b;
        printf("%d\n", c);
    }
}

void pq_test(){
    priority_queue<int> a; // 默认大顶堆，less<int> 从大到小
    priority_queue<int, vector<int>, greater<int> > b; // 从小到大

    for(int i = 0; i < 5; ++i){
        a.push(i);
        b.push(i);
    }
    while(!a.empty()){
        cout << a.top() << " ";
        a.pop();
    }
    cout << endl;
    while(!b.empty()){
        cout << b.top() << " ";
        b.pop();
    }
    cout << endl;
}

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(NULL), right(NULL){}
};

int main(){
    // input1_c();

    pq_test();
    
    return 0;
}