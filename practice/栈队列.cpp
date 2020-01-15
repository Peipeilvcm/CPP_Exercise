#include<stdio.h>
#include<stack>
#include<string>

using namespace std;

/*
ջstack
����queue 
*/

//����ƥ��
bool isValid(string s){
	stack<char> st;
	for(int i=0;i<s.size();++i){
		if(s[i]=='('||s[i]=='{'||s[i]=='['){
			st.push(s[i]);
		}else{
			if(st.size() == 0)
				return false;
			
			char c = st.top();
			st.pop();
			
			char match;
			if(s[i] == ')'){
				match='(';
			}else if(s[i]=='}'){
				match='{';
			}else if(s[i]==']'){
				match='[';
			}else{
				return false;
			}
			
			if(match!=c){
				return false;
			}
		} 
	}
	if(st.size() == 0){
		return true;
	}
	return false;
} 

//�沨�����ʽ�Ӽ��˳����� 
int evalRPN(vector<string>& tokens) {
    stack<int> res;
    for(int i=0;i<tokens.size();++i){
        if(tokens[i]=="+"){
            int a = res.top();
            res.pop();
            int b=res.top();
            res.pop();
            res.push(a+b);
            
        }else if(tokens[i]=="-"){
            int a = res.top();
            res.pop();
            int b=res.top();
            res.pop();
            res.push(b-a);
        }else if(tokens[i]=="*"){
            int a = res.top();
            res.pop();
            int b=res.top();
            res.pop();
            res.push(b*a);
        }else if(tokens[i]=="/"){
            int a = res.top();
            res.pop();
            int b=res.top();
            res.pop();
            res.push(b/a);
        }else{
            int tmp = atoi(tokens[i].c_str());
            res.push(tmp);
        }
    }
    return res.top();
}

//��ջʵ�ֵݹ�
struct TreeNode {
    int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
struct Command{
    string s;//go,print
    TreeNode* node;
    Command(string s,TreeNode* node):s(s),node(node){}
};
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    if(root == NULL){
        return res;
    }
    
    stack<Command> st;
    st.push(Command("go",root));
    while(!st.empty()){
        Command command = st.top();
        st.pop();
        
        if(command.s == "print"){
            res.push_back(command.node->val);	//������visit���� 
        }else{//go
            if(command.node->right){
                st.push(Command("go",command.node->right));
            }
            if(command.node->left){
                st.push(Command("go",command.node->left));
            }
            st.push(Command("print",command.node)); //�����˳��Ϳ��Ըĳ��������
        }
    }
    return res;
} 

int main(){
	
	return 0;
}
