#include<stdio.h>

using namesapce std;

/*
ld17递归,实现回溯 
回溯,树的所有由根到叶子的路径
回溯,暴力,遍历 
*/
const string letterMap[10] = {
    " ",
    "",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "qprs",
    "tuv",
    "wxyz"//9
};
vector<string> res;
void findComp(const string &digits, int index, string &s){
    if(index==digits.size()){
        res.push_back(s);
        return;
    }
    
    char c = digits[index];
    string letters = letterMap[c-'0'];
    for(int i=0;i<letters.size();++i){
        s.push_back(letters[i]);
        findComp(digits,index+1,s);
        s.pop_back();
    }
}
vector<string> letterCombinations(string digits) {
    res.clear();
    if(digits == ""){
        return res;
    }
    
    string s="";
    findComp(digits,0,s);
    return res;
}

//ld46非重复数字数组全排列问题
vector<vector<int> > res2;
vector<bool> used;
void createPerm(const vector<int>& nums, int index, vector<int>& p){
	if(index == num.size()){
		res2.push_back(p);
		return;
	}
	
	for(int i=0;i<nums.size();++i){
		if(!used[i]){
			p.push_back(nums[i]);
			used[i]=true;
			createPerm(nums,index+1,p);
			p.pop_back();
			used[i]=false;
		}
	}
	
}
vector<vector<int>> permute(vector<int>& nums) {
    res2.clear();
    if(nums.empty()){
    	return res2;
	}
	used=vector<bool>(nums.size(),0);
	vector<int> p;
	createPerm(nums,0,p);
	return res2;
}
//ld47 有重复数字数组全排列
vector<vector<int> > res;
void backtrack(vector<int> nums, int i){
	int n=nums.size();
	if(i==n-1){
		res.push_back(nums);
		return;
	}
	
	for(int k=i;k<n;++k){
		if(k!=i && nums[i]==nums[k]){
			continue;
		}
		swap(nums[i],nums[k]);
		backtrack(nums,i+1);
	}
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
	if(nums.empty()){
		return res;
	}
	sort(nums.begin(),nums.end());
	backtrack(nums,0);
	return res;
}

//ld77回溯法,组合问题C(n,k)
vector<vector<int> > res3;
void createComb(int n, int k, int start, vector<int> &c){
	if(c.size()==k){
		res3.push_back(c);
		return;
	}
	
	//还有k-c.size()空位,从i...n中至少要k-c.size()个元素 
	//i最多有n-(k-c.size())+1,剪枝 
	for(int i=start;i<=n-(k-c.size())+1;i++){
		c.push_back(i);
		createComb(n,k,i+1,c);
		c.pop_back();
	}
}
vector<vector<int>> combine(int n, int k) {
    res3.clear();
    if(n<=0||k<=0||k>n){
    	return res3;
	}
	vector<int> c;
	createComb(n,k,1,c);
}

//ld78, 无重复数字的数组的所有子数组
vector<vector<int>> res;
void backtrack(const vector<int>& nums, vector<int>& one, int index){
	if(index == nums.size()){
		res.push_back(one);
		return;
	}
	backtrack(nums, one, index+1);
	one.push_back(nums[index]);
	backtrack(nums, one,index+1);
	one.pop_back();
}
vector<vector<int>> subsets(vector<int>& nums) {
	if(nums.empty()){
		return res;
	}
	
	vector<int> one;
	backtrack(nums, one, 0);
	return res;
}
//ld90, 有重复数字的数组的所有子数组
vector<vector<int> > res;
void backtrack(const vector<int>& nums, vector<int>& one, int index, int step){
	if(step > nums.size()){
		return;
	}
	res.push_back(one);
	
	for(int i=index;i<nums.size();){
		one.push_back(nums[i]);
		backtrack(nums, one, i+1, step+1);
		one.pop_back();
		int j=i+1;
		while(j<nums.size()){
			if(nums[i]==nums[j]){
				++j;
			}else{
				break;
			}
		}
		i=j;
	}
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	vector<int> one;
	sort(nums.begin(),nums.end());
	backtrack(nums,one,0,0);
	return res;
}

//字典序,求下一个排列
void reverse(vector<int>& nums, int l, int r){
	for(int i=l,j=r;i<j;++i,--j){
		swap(nums[i],nums[j]);
	}
}
void nextPermutation(vector<int>& nums) {
	int n = nums.size();
	if(n<2){
		return;
	}
	
	int k=-1;
	for(int i=n-2;i>=0;--i){
		if(nums[i] < nums[i+1]){
			k = i;
			break;
		}
	}
	
	if(k==-1){//已经是最后一个排列
		sort(nums.begin(),nums.end());
		return;
	}
	
	for(int i=n-1;i>k;--i){
		if(nums[i] > nums[k]){
			swap(nums[i],nums[k]);
			reverse(nums,k+1,n-1);
			return;
		}
	}
}

//ld79,二维字符数组,寻找单词
//从board[id][jd]开始寻找word[index..word.size()]
int direct[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int m,n;
vector<vector<bool> > visited;
bool inArea(int i, int j){
	if(i>=0 && i<m && j>=0 && j<n){
		return true;
	}
	return false;
}
bool findExit(const vector<vector<char>>& board, int index, int id, int jd, const string& word){
	if(index == word.size() - 1){
		return word[index] == board[id][jd];	
	}
	
	if(board[id][jd]==word[index]){
		//从id,jd四个方向寻找
		visited[id][jd] = true;
		for(int i=0;i<4;++i){
			int newI = id + direct[i][0];
			int newJ = jd +direct[i][1];
			if(inArea(newI,newJ) && !visited[newI][newJ]){
				if(findExit(board,index+1,newI,newJ,word)){
					return true;
				}
			}
		}
		visited[id][jd]=false;
	}
	return false;
}
bool exist(vector<vector<char>>& board, string word) {
	if(board.empty()||word.empty()){
		return false;
	}
	m = board.size();
	n = board[0].size();
	visited = vector<vector<bool> >(m,vector<bool>(n,false));
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			if(findExit(board,0,i,j,word)){
				return true;
			}
		}
	}
	return false;
}

//floodfill算法,岛屿个数,深度优先遍历
void dfs(vector<vector<char> >& grid, int x, int y){
	visited[x][y] = true;
	for(int i=0;i<4;++i){
		int newX = x+direct[i][0];
		int newY = y+direct[i][1];
		if(inArea(newX,newY) && !visited[newX][newY]){
			if(grid[newX][newY]=='1'){
				dfs(grid,newX,newY);
			}
		}
	}
}
int numIslands(vector<vector<char>>& grid) {
    if(grid.empty()){
    	return 0;
	} 
	m = grid.size();
	n = grid[0].size();
	visited = vector<vector<bool> >(m,vector<bool>(n,false));
	
	int res=0;
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			if(grid[i][j]=='1'&&!visited[i][j]){
				res++;
				dfs(grid,i,j);
			}
		}
	}
	
	return res;
}

//ld51,N皇后问题
vector<string> generateBoard(int n,vector<int> &row){
	vector<string> board(n,string(n,'.'));
	for(int i=0;i<n;++i){
		board[i][row[i]]='Q';
	}
	return board;
}
vector<vector<string>> res4;
vector<bool> col, dia1, dia2;	//存储冲突情况 
void putQueen(int n, int index, vector<int> &row){
	if(index == n){
		res4.push_back(generateBoard(n,row));
		return;
	}
	for(int i=0;i<n;++i){
		//将index行皇后摆放在第i列 
		if(!col[i] && !dia1[index+i] && !dia2[index-i+n-1]){
			row.push_back(i);
			col[i]=true;
			dia1[index+i]=true;
			dia2[index-i+n-1]=true;
			putQueen(n,index+1,row);
			col[i]=false;
			dia1[index+i]=false;
			dia2[index-i+n-1]=false;
			row.pop_back();
		}
	}
	return;
}
vector<vector<string>> solveNQueens(int n) {
    res4.clear();
    if(n<=0){
    	return res4;
	}
    col = vector<bool>(n,false);
    dia1 = vector<bool>(2*n-1,false);
    dia2 = vector<bool>(2*n-1,false);
    
    vector<int> row;
    putQueen(n,0,row);
    
    return res4;
}


//ld93,IP地址"25525511135"->"255.255.11.135", "255.255.111.35"
vector<string> res;
void backtrack(const string& s, int step, int index, string& ip){
	int size=s.size();
	if(step == 5){
		if(index == size){
			res.push_back(ip);
		}
		return;
	}
	
	for(int i=1;i<=3;++i){
		if(i!=1 && s[index]=='0'){
			break;
		}
		
		if(index+i<=size){
			string part = s.substr(index,i);
			if(stoi(part)<=255){
				string tmp = ip;
				if(step!=1){
					tmp+='.';
				}
				tmp+=part;
				backtrack(s, step+1, index+i, tmp);
			}
		}	
	}
}
vector<string> restoreIpAddresses(string s) {
	if(s.empty()){
		return res;
	}
	
	string ip;
	backtrack(s,1,0,ip);
	return res;
}

//ld131,找到所有回文子串的组合
bool isPalindrome(const string& str){
	int n = str.size();
	if(n==0){
		return false;
	}
	int l=0,r=n-1;
	
	while(l<r){
		if(str[l]!=str[r]){
			return false;
		}
		++l;
		--r;
	}
	return true;
}
vector<vector<string> > res;
void backtrack(const string &str, int index, vector<string> one){
	int n=str.size();
	if(index == n){
		res.push_back(one);
		return;
	}
	
	for(int i=1;index+i <= n;++i){
		string part=str.substr(index,i);
		if(isPalindrome(part)){
			vector<string> newV = one;
			newV.push_back(part);
			backtrack(str, index+i, newV);
		}
	}
}
vector<vector<string>> partition(string s) {
	if(s.empty()){
		return res;
	}
	vector<string> one;
	backtrack(s, 0, one);
	return res;
}


int main(){
	
	return 0;
}
