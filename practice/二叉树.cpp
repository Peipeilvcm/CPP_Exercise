#include<bits/stdc++.h>

using namespace std;

/*
二叉树 
*/
struct TreeNode {
    int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 递归遍历
void traverse(TreeNode* root){
	if(root == NULL) return;
	/* 前序遍历代码位置 */
	traverse(root->left);
	/* 中序遍历代码位置 */
	traverse(root->right);
	/* 后序遍历代码位置 */
}


// 颜色标记法
// 使用颜色标记节点的状态，新节点为白色，已访问的节点为灰色。
// 如果遇到的节点为白色，则将其标记为灰色，然后将其右子节点、自身、左子节点依次入栈。
// 如果遇到的节点为灰色，则将节点的值输出
enum Color {
    White,
    Gray
};
void pre_traverse(TreeNode* root){
    stack<pair<TreeNode*, Color> > stk;
    stk.push(make_pair(root, White));
    while(!stk.empty()){
        auto [node, color] = stk.top();
        stk.pop();
        if(node == nullptr){
            continue;
        }
        if(color == White){
            stk.push(make_pair(node->right, White));
            stk.push(make_pair(node->left, White));
            stk.push(make_pair(node, Gray)); // 前序
        }else{
            cout<<node->val; // visit
        }
    }
}

void in_traverse(TreeNode* root){
    stack<pair<TreeNode*, Color> > stk;
    stk.push(make_pair(root, White));
    while(!stk.empty()){
        auto [node, color] = stk.top();
        stk.pop();
        if(node == nullptr){
            continue;
        }
        if(color == White){
            stk.push(make_pair(node->right, White));
            stk.push(make_pair(node, Gray)); // 中序
            stk.push(make_pair(node->left, White));
        }else{
            cout<<node->val; // visit
        }
    }
}

void post_traverse(TreeNode* root){
    stack<pair<TreeNode*, Color> > stk;
    stk.push(make_pair(root, White));
    while(!stk.empty()){
        auto [node, color] = stk.top();
        stk.pop();
        if(node == nullptr){
            continue;
        }
        if(color == White){
            stk.push(make_pair(node, Gray)); // 后序
            stk.push(make_pair(node->right, White));
            stk.push(make_pair(node->left, White));
            
        }else{
            cout<<node->val; // visit
        }
    }
}




bool contain(TreeNode* root, int key){
	if(root == NULL){
		return false;
	}
	if(key == root->val){
		return true;
	}
	
	if(contain(root->left) || contain(root->right)){
		return true;
	}else{
		return false;
	}
}

void destroy(TreeNode* root){
	if(root == NULL){
		return;
	}
	destroy(root->left);
	destroy(root->right);
	delete root;
}

//222求解完全二叉树节点个数
int countNodes(TreeNode* root) {
    if(root == NULL){
    return 0;
    }
    int rD=0;
    int lD=0;
    TreeNode*p =root;
    while(p!=NULL){
        p=p->left;
        lD++;
    }
    p=root;
    while(p!=NULL){
        p=p->right;
        rD++;
    }

    if(lD==rD){//完全二叉树 
        return (1<<lD) - 1;
    }
    else{
        return countNodes(root->left)+countNodes(root->right)+1;
    }
}

//110判断是否是平衡二叉树
int Height(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    
    return max(Height(root->left),Height(root->right))+1;
}
 bool isBalanced(TreeNode* root) {
    if(root==NULL){
        return true;
    }
    
    if(isBalanced(root->left) && isBalanced(root->right)){
        int a = Height(root->left);
        int b = Height(root->right);
        if(a-b>=-1 && a-b<=1){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

//求所有二叉树上从根到叶子的路径
//atoi(s.c_str())
//to_string(int) 
vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> res;
    if(root==NULL){
        return res;
    }
    
    if(root->left==NULL&&root->right==NULL){
        string s = to_string(root->val);
        res.push_back(s);
        return res;
    }else{
        vector<string> vL = binaryTreePaths(root->left);
        vector<string> vR = binaryTreePaths(root->right);
        for(int i=0;i<vL.size();++i){
            string s = to_string(root->val) + "->" + vL[i];
            res.push_back(s);
        }
        for(int i=0;i<vR.size();++i){
            string s = to_string(root->val) + "->" + vR[i];
            res.push_back(s);
        }
        return res;
    }
}

//ld133,广度优先遍历,输出从根到叶子的路径
vector<vector<int>> pathSum(TreeNode* root, int sum) {
	vector<vector<int> > res;
	if(root==NULL){
		return res;
	}
	
	queue<pair<vector<TreeNode*>,int> > que;
	que.push(make_pair(vector<TreeNode*> (1,root),root->val));
	
	while(!que.empty()){
		vector<TreeNode*> path = que.front().first;
		int pathSum = que.front().second;
		que.pop();
		
		TreeNode* cur = path.back();
		if(cur->left==NULL&&cur->right==NULL){
			if(pathSum == sum){
				vector<int> valpath;
				for(TreeNode* ptr : path){
					valpath.push_back(ptr->val);
				}
				res.push_back(valpath);
			}
		}
		if(cur->left!=NULL){
			vector<TreeNode*> newpath = path;
			newpath.push_back(cur->left);
			int valSum = pathSum + cur->left->val;
			que.push(make_pair(newpath,valSum));
		}
		if(cur->right!=NULL){
			vector<TreeNode*> newpath = path;
			newpath.push_back(cur->right);
			int valSum = pathSum + cur->right->val;
			que.push(make_pair(newpath,valSum));
		}
	}
	
	return res;
	
}

//ld236 最小公共祖先
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if(root==NULL||root==p||root==q){
		return root;
	}
	TreeNode* left = lowestCommonAncestor(root->left,p,q);
	TreeNode* right = lowestCommonAncestor(root->right,p,q);
	
	if(left&&right){
		return root;
	}
	else if(!left){
		return right;
	}else{
		return left;
	}
	
}

int main(){
	
	return 0;
}
