#include<stdio.h>
#include<queue> 

#include<map>

using namespace std;

//��pair����level��Ϣ 
/* sort
#include <algorithm>
bool cmp(int a,int b){
    return a>b;
}
sort(vec.begin(),vec.end()��cmp); // ����������
//Ĭ�������С����,�������������greater<int>()��ɴӴ�С

��תreverse(vec.begin(),vec.end()) 

vec.insert(vec.begin(),val)��ǰ�������Ԫ��
vec.insert(vec.begin()+2,val)�ڵڶ���Ԫ��ǰ������Ԫ��

vec.front()
vec.back()
*/

struct TreeNode {
    int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//�ö���ʵ�����Ĳ������ 
//����ķ���queue���������pair<TreeNode*,int>,pair ��.first,.second���� 
vector<vector<int>> levelOrder(TreeNode* root){
	vector<vector<int> > res;
	if(root==NULL){
		return res;
	}
	
	queue<TreeNode*> que;
	int count = 1;
	que.push(root);
	
	while(!que.empty()){
		int nextCount=0;
		vector<int> v;
		while(count--){
			TreeNode* tmp = que.front();
			que.pop();
			v.push_back(tmp->val);
			if(tmp->left){
				que.push(tmp->left);
				nextCount++;
			}
			if(tmp->right){
				que.push(tmp->right);
				nextCount++;
			}
		}
		res.push_back(v);
		count=nextCount;
	}
	return res;
}
vector<vector<int>> level_Order(TreeNode* root){
	vector<vector<int> > res;
	if(root==NULL){
		return res;
	} 
	
	queue<pair<TreeNode*,int> >que;
	
	que.push(make_pair(root,0));
	
	while(!que.empty()){
		
		TreeNode* tmp = que.front().first;
		int level = que.front().second;
		que.pop();
		
		if(res.size() == level){
			res.push_back(vector<int>());
		}
		
		res[level].push_back(tmp->val);
		
		if(tmp->left){
			que.push(make_pair(tmp->left,level+1));
		}
		if(tmp->right){
			que.push(make_pair(tmp->right,level+1));
		}
	}
	
	return res;
}

//No.279,һ������ɶ��ƽ�����ĺ�,����ƽ�����ĸ�����Сֵ12=4+4+4=9+1+1+1=1+1+...+1��󷵻�3
//ͼ��˼��,0��n,n+1���ڵ�,��n�ߵ�0�����·��,ÿ������֮���ƽ�����ͼ�һ���� 
int numSquares(int n){
	//pair<i,step> 
	queue<pair<int,int> > que;
    que.push(make_pair(n,0));
    vector<bool> flag(n+1,false);
    flag[n]==1;
    while(!que.empty()){
        int num = que.front().first;
        int step = que.front().second;
        que.pop();

        for(int i=1;;++i){
            int a = num-i*i;
            if(a < 0){
                break;
            }
            if(a == 0){
                return step + 1;
            }
            if(flag[a]==false){
            	flag[a]=true;
                que.push(make_pair(a,step+1));
            }
        }
    }
    return 0;
}

//ld127,Ѱ��string·����Ŀ��string,ÿ��·��ֻ���ڲ�һ���ַ����ַ���֮��
bool comp(const string& s1, const string& s2){
	int cnt=0;
	for(int i=0;i<s1.size();++i){
		if(s1[i]!=s2[i]){
			cnt++;
		}
		if(cnt>1){
			return false;
		}
	}
	return true;
}
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
	int n=wordList.size();
	if(n==0){
		return 0;
	}
	queue<pair<string,int> > que;
	que.push(make_pair(beginWord,1));
	vector<bool> visited(n,false);
	while(!que.empty()){
		string str=que.front().first;
		int step=que.front().second;
		que.pop();
		
		for(int i=0;i<n;++i){
			if(visited[i]==true){
				continue;
			}
			if(comp(wordList[i],str)){
				visited[i]=true;
				if(wordList[i]==endWord){
					return step+1;
				}
				que.push(make_pair(wordList[i],step+1));
			}
		}
		
	}
	return 0;
}

//ld126 ��ȷ����BFS
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList){
	unordered_set<string> wordSet;
	wordSet.insert(beginWord);
	for( string s : wordList){
		wordSet.insert(s);
	}
	
	vector<vector<string>> res;
    queue<vector<string>> paths;
	
	paths.push(vector<string>(1,beginWord));
	int minStep=INT_MAX;
	
	unordered_set<string> visited;
	
	while(!paths.empty()){
		vector<string> path = paths.front();
		paths.pop();
		
		string last=path.back();
		visited.insert(s);
		wordSet.erase(s);
		
		int step=path.size();
		if(step > minStep){
			break;
		}
		
		for(string s : wordSet){
			if(comp(s,last)){
				vector<string> newPath = path;
				newPath.push_back(s);
				if(s==endWord){
					if(step < minStep){
						minStep = step;
						res.push_back(newPath);
					}else if(step == minStep){
						res.push_back(newPath);
					}
				}
				paths.push(newPath);
			}
		}
	}
	return res;
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        //very interesting problem
        //It can be solved with standard BFS. The tricky idea is doing BFS of paths instead of words!
        //Then the queue becomes a queue of paths.
        unordered_set<string> wordSet;
        for( string s : wordList){
            wordSet.insert(s);
        }
        
        vector<vector<string>> ans;
        queue<vector<string>> paths;
        
        paths.push({beginWord});
        int level = 1;
        int minLevel = INT_MAX;
        
        //"visited" records all the visited nodes on this level
        //these words will never be visited again after this level 
        //and should be removed from wordList. This is guaranteed
        // by the shortest path.
        unordered_set<string> visited; 
        
        while (!paths.empty()) {
            vector<string> path = paths.front();
            paths.pop();
            if (path.size() > level) {
                //reach a new level
                for (string w : visited) wordSet.erase(w);
                visited.clear();
                if (path.size() > minLevel)
                    break;
                else
                    level = path.size();
            }
            string last = path.back();
            //find next words in wordList by changing
            //each element from 'a' to 'z'
            for (int i = 0; i < last.size(); ++i) {
                string news = last;
                for (char c = 'a'; c <= 'z'; ++c) {
                    news[i] = c;
                    if (wordSet.find(news) != wordSet.end()) {
                    //next word is in wordList
                    //append this word to path
                    //path will be reused in the loop
                    //so copy a new path
                        vector<string> newpath = path;
                        newpath.push_back(news);
                        visited.insert(news);
                        if (news == endWord) {
                            minLevel = level;
                            ans.push_back(newpath);
                        }
                        else
                            paths.push(newpath);
                    }
                }
            }
        }
        return ans;
    }

//ld126,���󷽷�,���ݷ���,���ҵ�����·��,���������Ž�
void findLa(const string& endWord, const vector<string>& wordList, vector<string>& path){
	string curWord=path.back();
	if(curWord==endWord){
		res.push_back(path);
		return;
	}
	
	int n=wordList.size();
	for(int i=0;i<n;++i){
		if(visited[i]==true){
			continue;
		}
		if(comp(wordList[i],curWord)){
			visited[i]=true;
			path.push_back(wordList[i]);
			findLa(endWord,wordList,path);
			visited[i]=false;
			path.pop_back();
		}
	}
}
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
	int n=wordList.size();
	if(n==0){
		return res;
	}
	visited=vector<bool>(n,false);
	
	vector<string> path;
	path.push_back(beginWord);
	
	findLa(endWord,wordList,path);
	
	return res;
}



/*
���ȶ���,����С��������priority_queue
Ĭ�����ɴ�С,����ʵ��priority_queue<int> pq;pq.push(),pq.top(),qp.pop()��Ĭ����less<int> 
��С��priority_queue<int,vector<int>,greater<int> > pq2; ��С����
�Զ���Ƚ� ������������priority_queue<int,vector<int>,function<bool(int,int)> > pq3(myCmp)
bool myCmp(int a,int b){
	return a%10>b%10; //������С���� 
}
*/
//��������Ƶ������ǰk���� O(nlogK)
bool pairCmp(pair<int,int> a, pair<int,int> b){
    return a.second>b.second;//С���� 
}
vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> res;
    if(k<=0){
        return res;
    }

    unordered_map<int,int> hash;
    for(int i=0;i<nums.size();++i){
        hash[nums[i]]++;
    }


    priority_queue<pair<int,int>, vector<pair<int,int> >, function<bool(pair<int,int>,pair<int,int>)> > pq(pairCmp);
    for(unordered_map<int,int>::iterator it=hash.begin();it!=hash.end();it++){
    	if(pq.size() == k){
    		//ֻ����k���� 
    		if(it->second > pq.top().second){
    			pq.pop();
    			pq.push(make_pair(it->first,it->second));
			}
		}else{
			pq.push(make_pair(it->first,it->second));
		}
    }
    for(int i=0;i<k;++i){
        res.push_back(pq.top().first);
        pq.pop();
    }
    return res;
}

int main(){
	
	return 0;
} 
