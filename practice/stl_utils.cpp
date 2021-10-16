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
vec.emplace_bac
vec.pop_back()
vec.insert()
vec.erase()//任意位置删除
vec.swap()

#include <algorithm>
//翻转
reverse(vec.begin(), vec.end());

multiset // 红黑树，可以删除某个值的排序


// **set
insert(key)
set_.find(key) != set.end() ！
erase(key)

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



自定义比较 priority_queue<int,vector<int>,function<bool(int,int
)> > pq3(myCmp)
bool myCmp(int a,int b){
	return a%10>b%10; //这样是小根堆, 就是top依次从小至大。
}


struct ListNode {
    int _val;
    ListNode* _next;
    ListNode(int val): _val(val), _next(nullptr) {}
    ListNode(): _val(0), _next(nullptr) {}
    ListNode(const ListNode& ln){
        _val = ln.val;
        _next = ln._next;
    }
    ListNode& operator=(const ListNode& ln){
        _val = ln._val;
        _next = ln._next;
        return (*this);
    }
    ListNode& operator=(const ListNode& ln) = delete; // 或设置成private
};


struct Status {
    int val;
    ListNode *ptr;

    bool operator < (const Status &rhs) const {
        return val > rhs.val;
    }
};
priority_queue <Status> pq;


queue
定义一个queue的变量     queue<Type> M
查看是否为空范例        M.empty()    是的话返回1，不是返回0;
从已有元素后面增加元素   M.push()
输出现有元素的个数      M.size()
显示第一个元素          M.front()
显示最后一个元素        M.back()
清除第一个元素          M.pop()
M.emplace()

stack
top()：返回一个栈顶元素的引用，类型为 T&。如果栈为空，返回值未定义。
push(const T& obj)：可以将对象副本压入栈顶。这是通过调用底层容器的 push_back() 函数完成的。
push(T&& obj)：以移动对象的方式将对象压入栈顶。这是通过调用底层容器的有右值引用参数的 push_back() 函数完成的。
pop()：弹出栈顶元素。
size()：返回栈中元素的个数。
empty()：在栈中没有元素的情况下返回 true。
emplace()：用传入的参数调用构造函数，在栈顶生成对象。



// **map
insert(make_pair(first,second))
find
erase(key)
change(map)
map_[key] = val
count()

map<string,int> singers ={{"A", 1},{"B", 2}};



// **sort
#include <algorithm>
sort(vec.begin(), vec.end()); //采用的是从小到大的排序
//如果想从大到小排序，可以采用上面反转函数，也可以采用下面方法:
bool Comp(const int& a, const int& b) {
    return a > b;
}
sort(vec.begin(), vec.end(), Comp);
sort(vec.begin(), vec.end(), [](const int& a, const int& b){
    return a > b;
});


// ** regex
# include<regex>
regex pattern("[+-]?\\d*(\\.\\d+)?([eE][+-]?\\d+)?");
regex_match(str, pattern); // 返回bool

// ** string
str = str2.substr(index, len);
if(str.find(str2) == string::npos){...}
str.push_back(ch)
str.pop_back()

// 整数转string
std::to_string(int a)
std::stoi(string, nullptr, 16) // stoll, stol
