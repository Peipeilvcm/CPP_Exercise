//leetcode

//海明距离，取异或，与1去同，比较每位，得到1的位数
class Solution {
public:
    int hammingDistance(int x, int y) {
        int dist=0;
        int n=x^y;
        while(n)
        {
            if(n&1)
                dist++;
            n>>=1;
        }
        return dist;
    }
};


//476二进制求补
class Solution {
public:
    int findComplement(int num) {
        int mask=1;int temp=num;
        while(temp)
        {
            mask<<=1;
            temp>>=1;
        }
        mask -= 1;
        return mask^num;
    }
};

//561数组分离
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum=0;
        int n = nums.size();
        for(int i=0;i<n;i+=2)
        {
            sum+=nums[i];
        }
        return sum;
    }
};

//617合并两棵树
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1==NULL&&t2==NULL)
            return NULL;
        else if(t1==NULL)
        {
            return t2;
        }
        else if(t2==NULL)
        {
            return t1;
        }
        else
        {
            t1->val += t2->val;
            t1->left=mergeTrees(t1->left,t2->left);
            t1->right=mergeTrees(t1->right,t2->right);
            return t1;
        }
    }
};

//500.keyboard
//C++
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_set<char> set1 = {'Q','W','E','R','T','Y','U','I','O','P','q','w','e','r','t','y','u','i','o','p'};
        unordered_set<char> set2 = {'A','S','D','F','G','H','J','K','L','a','s','d','f','g','h','j','k','l'};
        unordered_set<char> set3 = {'Z','X','C','V','B','N','M','z','x','c','v','b','n','m'};

        vector<unordered_set<char>> sets={set1,set2,set3};

        vector<string> result;

        int n=words.size();
        for(int i=0;i<n;i++)
        {
            int index=0;

            if(set1.find(words[i][0])!=set1.end())
                index=0;
            else if(set2.find(words[i][0])!=set2.end())
                index=1;
            else
                index = 2;

            unordered_set<char> tmpSet=sets[index];
            int flag=0;

            for(char c:words[i])
            {
				if(tmpSet.find(c)!=tmpSet.end())    continue;
                else{
                    flag=1;
                    break;
                }
            }
            
            if(!flag){
                result.push_back(words[i]);
            }
        }
        return result;
    }
};

//Python
class Solution(object):
    def findWords(self, words):
        row1 = set('qwertyuiop')
        row2 = set('asdfghjkl')
        row3 = set('zxcvbnm')
        
        res = []
        for word in words:
            lw = set(word.lower())
            if lw.issubset(row1) or lw.issubset(row2) or lw.issubset(row3):
                res += word,
        return res

557. Reverse Words in a String III
class Solution{
public:
	string reverseWords(string s){
		string res = "",t = "";
		istringstream is(s);
		while(is>>t){
			reverse(t.begin(),t.end());
			res += t+" ";
		}
		res.pop_back();
		return res;
	}
};
class Solution{
public:
	string reverseWords(string s){
		int start=0,end=0,n=s.size();
		while(start<n&&end<n){
			while(end<n&&s[end]!=' ')	++end;
			for(int i=start,j=end-1;i<j;++i,--j){
				swap(s[i],s[j]);
			}
			start = ++end;
		}
		return s;
	}
};
//python
class Solution(object):
	def reverseWords(self,s):
		words = s.split()
		k = []
		for i in words:
			k.append(i[::-1])
		res = ' '.join(k)
		return res

 
575. Distribute Candies
//C++
class Solution{
	public:
	int distributeCandies(vector<int>& candies){
		int n=candies.size()/2;
		unorder_map<int,int> HASH;
		int res=0;
		for(int c:candies){
			HASH[c]++;
			if(HASH[c]==1&&res<n)
				res++;
		}
		return res;
	}
};

//Python
class Solution:
    def distributeCandies(self, candies):
		"""
        :type candies: List[int]
        :rtype: int
        """
        return min(len(candies)//2,len(set(candies)))
		
566. Reshape the Matrix
//C++
class Solution{
	public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& nums,int r,int c){
		int origin_r=nums.size();
		int origin_c=nums[0].size();
		int n=origin_c*origin_r;
		if(n==r*c){
			vector<vector<int>> res(r,vector<int>(c,0));
			for(int i=0;i<n;i++)
				res[i/c][i%c]=nums[i/origin_c][i%origin_c];
			return res;
		}
		else
			return res;
	}
};
//python
class Solution(object):
    def matrixReshape(self, nums, r, c):
        """
        :type nums: List[List[int]]
        :type r: int
        :type c: int
        :rtype: List[List[int]]
        """
        origin_r=len(nums)
        origin_c=len(nums[0])
        if origin_r*origin_c==r*c:
            temp = [num for row in nums for num in row]#展开成一维数组
            res = [[0 for j in xrange(c)] for i in xrange(r)]
            for i in xrange(r):
                for j in xrange(c):
                    res[i][j] = temp[i*c+j]
            return res
        else:
            return nums

412. Fizz Buzz
//python
class Solution(object):
    def fizzBuzz(self, n):
        res=[]
        for i in range(1,n+1):
            if i%3==0 and i%5==0:
                res.append("FizzBuzz")
            elif i%3==0:
                res.append("Fizz")
            elif i%5==0:
                res.append("Buzz")
            else:
                res.append(str(i))
        return res
//C++
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> temp;
        string A("FizzBuzz"),B("Fizz"),C("Buzz");
        string n1;
        char n2[10];
        for(int i=1;i<=n;i++){
            if(i%3==0&&i%5==0)
                temp.push_back(A);
            else if(i%3==0)
                temp.push_back(B);
            else if(i%5==0)
                temp.push_back(C);
            else{
                sprintf(n2,"%d",i);
                n1=n2;
                temp.push_back(n1);
            } 
        }
        return temp;  
    }
};

669. Trim a Binary Search Tree
//C++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(!root)
            return NULL;
        else{
            if(root->val>=L&&root->val<=R){
                root->left=trimBST(root->left,L,R);
                root->right=trimBST(root->right,L,R);
                return root;
            }
            else if(root->val<L){
                return trimBST(root->right,L,R);
            }
            else{
                return trimBST(root->left,L,R);
            }
        }
    }
};
//python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution(object):
    def trimBST(self, root, L, R):
        """
        :type root: TreeNode
        :type L: int
        :type R: int
        :rtype: TreeNode
        """
        if root==None:
            return None
        else:
            if root.val>=L and root.val<=R:
                root.left=self.trimBST(root.left,L,R)
                root.right=self.trimBST(root.right,L,R)
                return root
            elif root.val<L:
                return self.trimBST(root.right,L,R)
            else:
                return self.trimBST(root.left,L,R)
				
 
463. Island Perimeter
//C++
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int cnt=0,rep=0;
        int r=grid.size(),c=grid[0].size();
        if(grid.size()==0)
            return 0;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==1)
                {
                    cnt++;
                    if(i-1>=0&&j-1>=0)
                    {
                        if(grid[i-1][j]==1)
                            rep++;
                        if(grid[i][j-1]==1)
                            rep++;
                    }
                    else if(i-1>=0)
                    {
                        if(grid[i-1][j]==1)
                            rep++;
                    }
                    else if(j-1>=0)
                    {
                        if(grid[i][j-1]==1)
                            rep++;
                    }
                    else
                        continue;
                }
            }
        
        return 4*cnt-2*rep;
        
    }
};


496.Next Greater Element I
//C++
class Solution{
public:
	vector<int> nextGreaterElement(vector<int>& findNums,vector<int> nums){
		vector<int> res;
		stack<int> st;
		unorder_map<int,int> m;
		for(int num:nums){
			while(!st.empty()&&st.top()<num){
				m[st.top()]=num;
				st.pop();
			}
			st.push(num);
		}
		for(int num:findNums){
			res.push_back(m.count(num)	? m[num]:-1);
		}
		return res;
	}
};