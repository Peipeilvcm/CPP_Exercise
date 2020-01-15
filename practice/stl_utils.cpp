// **pair<int,int>
make_pair(1,2)
.first, .second

//** vector
//初始化
int a[] = {1,2,3,4}
vector<int> nums(a, a+4);
vector<int> nums2(nums.begin(), nums.begin()+4);
vector<int> nums = {1,2,3,4} //C++11

vec.front()
vec.back()

vec.push_back()
vec.pop_back()
vec.insert()
vec.erase()//任意位置删除
vec.swap()

#include <algorithm>
//翻转
reverse(vec.begin(), vec.end());



// **set
insert
find
erase

set<int> record(vec.begin(),vec.end());
unordered_set<int> record(vec.begin(),vec.end());//是哈希表实现,O(1)查找,失去数据顺序性 

set.lower_bound()


// **queue
优先队列 priority_queue
默认由大到小,最大堆实现 priority_queue<int> pq; 默认是less<int> 由大到小
最小堆priority_queue<int,vector<int>,greater<int> > pq2; 由小到大。
pq.push()
pq.top()
qp.pop() 

自定义比较 priority_queue<int,vector<int>,function<bool(int,int)> > pq3(myCmp)
bool myCmp(int a,int b){
	return a%10>b%10; //这样是小根堆 
}



// **map
insert(make_pair(first,second))
find
erase
change(map)

map<string,int> singers ={{"A", 1},{"B", 2}};



// **sort
#include <algorithm>
sort(vec.begin(), vec.end()); //采用的是从小到大的排序
//如果想从大到小排序，可以采用上面反转函数，也可以采用下面方法:
bool Comp(const int& a, const int& b) {
    return a > b;
}
sort(vec.begin(), vec.end(), Comp);

// ** regex
# include<regex>
regex pattern("[+-]?\\d*(\\.\\d+)?([eE][+-]?\\d+)?");
regex_match(str, pattern); // 返回bool

// ** string
str = str2.substr(index, len);
if(str.find(str2) == string::npos){...}

