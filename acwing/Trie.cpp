#include<bits/stdc++.h>
using namespace std;


// 插入字符串，查找字符串，查找字符串前缀
class Trie{
private:
    bool isEnd;
    vector<Trie* > children;

public:
    Trie(): isEnd(false), children(26, nullptr){

    }

    void insert(string word){
        Trie* node = this;
        for(auto ch: word){
            int pos = ch - 'a';
            if(node->children[pos] == nullptr){
                node->children[pos] = new Trie();
            }
            node = node->children[pos];
        }
        node->isEnd = true;
    }

    bool search(string word){
        Trie* node = this;
        for(auto ch: word){
            int pos = ch - 'a';
            if(node->children[pos] == nullptr){
                return false;
            }else{
                node = node->children[pos];
            }
        }
        return node->isEnd;
    }

    bool searchPrefix(string prefix){
        Trie* node = this;
        for(auto ch: prefix){
            int pos = ch - 'a'; 
            if(node->children[pos]){
                node = node->children[pos];
            }else{
                return false;
            }
        }
        return true;
    }
};


// 最大异或值，找到数组中最大的两个数的异或值
class BitTrie{
private:
    vector<BitTrie* > children;
public:
    BitTrie(): children(2, nullptr){}

    void insert(int num){
        
        BitTrie* node = this;
        for(int i = 31; i >= 0; --i){
            int bit = ((num>>i) & 1);
            if(node->children[bit] == nullptr){
                node->children[bit] = new BitTrie();
            }
            node = node->children[bit];
        }
    }

    int maxXOR(int num){
        BitTrie* node = this;
        int x = 0;
        for(int i = 31; i >= 0; --i){
            int bit = ((num>>i) & 1);
            if(bit == 1){
                if(node->children[0] != nullptr){
                    x <<= 1;
                    x |= 1;
                    node = node->children[0];
                }else{
                    x <<= 1;
                    node = node->children[1];
                }
            }else{
                if(node->children[1] != nullptr){
                    x <<= 1;
                    x |= 1;
                    node = node->children[1];
                }else{
                    x <<= 1;
                    node = node->children[0];
                }
            }
        }
        return x;
    }
};

int findMaximumXOR(vector<int>& nums) {
    BitTrie* root = new BitTrie();
    for(auto& num : nums){
        root->insert(num);
    }
    int x = 0;
    for(auto& num : nums){
        x = max(x, root->maxXOR(num));
    }
    return x;
}

int main(){

    vector<int> test = {3,10,5,25,2,8};
    cout<<findMaximumXOR(test);

    return 0;
}
