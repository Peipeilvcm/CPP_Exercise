
```C++
/*
在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int rowCount = array.size();
        int colCount = array[0].size();
        
        int i, j;
        
        for(i = rowCount - 1, j = 0; i >= 0&& j < colCount; ){
            if(target == array[i][j]){
                return true;
            } else if(target < array[i][j]){
                i--;
            } else if (target > array[i][j]){
                j++;
            }
        }
        return false;
    }
};

/*
请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy
*/
class Solution {
public:
	void replaceSpace(char *str,int length) {
        if(str == NULL || length < 0){
            return;
        }
        
        int count = 0;
        for(int i = 0; i < length; i++){
            if(str[i] == ' '){
                count++;
            }
        }
        for(int i = length-1; i >=0 ; i--){
            if(str[i] == ' '){
                str[i+2*count] = '0';
                str[i+2*count-1] = '2';
                str[i+2*count-2] = '%';
                count--;
            }else{
                str[i+2*count] = str[i];
            }
        }
	}
};

/*
输入一个链表，按链表从尾到头的顺序返回一个ArrayList。
*/
class Solution {
public:
    vector<int> res;
    vector<int> printListFromTailToHead(ListNode* head) {
        ListNode* p = NULL;
        p = head;
        if(p != NULL){
            if(p->next != NULL){
                printListFromTailToHead(p->next);
            }
            res.push_back(p->val);
        }
        return res;
    }
};

/*
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
*/
class Solution {
public:
    
    
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        return reConstructBinaryTree(pre, 0, pre.size()-1, vin, 0, vin.size()-1);
    }
    
    TreeNode* reConstructBinaryTree(const vector<int>& pre, int startPre, int endPre, const vector<int>& vin, int startIn, int endIn){
        if(startPre > endPre || startIn > endIn){
            return NULL;
        }
        
        TreeNode* root = new TreeNode(pre[startPre]);
        
        for(int i = startIn; i <= endIn; ++i){
            if(vin[i] == pre[startPre]){
                root->left = reConstructBinaryTree(pre, startPre+1, startPre+i-startIn, vin, startIn, i-1);
                root->right = reConstructBinaryTree(pre, startPre+i-startIn+1, endPre, vin, i+1, endIn);
                break;
            }
        }
        return root;
    }
};


/*
两栈造队列
*/
class Solution
{
public:
    void push(int node) {
       stack1.push(node);
    }

    int pop() {
        int a;
        if(stack2.empty()){
            while(!stack1.empty()){
                a=stack1.top();
                stack2.push(a);
                stack1.pop();
            }
        }
        a=stack2.top();
        stack2.pop();
        return a;
         
    }
private:
    stack<int> stack1;
    stack<int> stack2;
};

/*
旋转数组
*/
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int size = rotateArray.size();
        if (size == 0){
            return 0;
        }
        
        int left = 0, right = size-1;
        int mid = 0;
        
        while(rotateArray[left] >= rotateArray[right]){
            if(right - left == 1){
                mid = right;
                break;
            }
            mid = left + (right - left)/2;
            
            if(rotateArray[left]==rotateArray[right] && rotateArray[left]==rotateArray[mid]){
                return MinOrder(rotateArray, left, right);
            }
            
            if(rotateArray[mid] >= rotateArray[left]){
                left = mid;
            }else{
                right = mid;
            }
        }
        return rotateArray[mid];
    }
    
    int MinOrder(const vector<int> &num, int left, int right){
        int result = num[left];
        for(int i = left+1; i < right; ++i){
            if(num[i] < result){
                result = num[i];
            }
        }
        return result;
    }
};

/*
斐波那契
*/
int Fibonacci(int n) {
    int a1 = 0, a2 = 1;
    while(n--){
        a2 = a1 + a2;
        a1 = a2 - a1;
    }
    return a1;
}

/*
数组中逆序对
*/





```