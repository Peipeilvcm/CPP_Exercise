
// 动态规划框架
/* base case初始化->状态(原问题和子问题中会变化的变量)->选择->dp数组含义
*/
// dp[0][0][...] = base
// for state1_val in 状态1的所有取值:
//     for state2_val in 状态2的所有取值:
//         for ...:
//             dp[state1_val][state2_val][...] = 求最值(选择1, 选择2)

// DFS、回溯，决策树遍历
/* 复杂度相同：邻接表O(V+E) 连接矩阵O(V^2)
*/
// result = []
// def backtrack(路径, 选择列表):
//     if 满足结束条件:
//         result.add(路径)
//         return
    
//     for 选择 in 选择列表:
//         做选择
//         backtrack(路径, 选择列表)
//         撤销选择

// BFS、
/* 复杂度相同：邻接表O(V+E) 连接矩阵O(V^2)

    双向BFS,知道终点在哪，可以两边扩散

*/
// 计算从起点 start 到终点 target 的最近距离
int BFS(Node start, Node target) {
    Queue<Node> q; // 核心数据结构
    Set<Node> visited; // 避免走回头路
    
    q.offer(start); // 将起点加入队列
    visited.add(start);
    int step = 0; // 记录扩散的步数

    while (q not empty) {
        int sz = q.size();
        /* 将当前队列中的所有节点向四周扩散 */
        for (int i = 0; i < sz; i++) {
            Node cur = q.poll();
            /* 划重点：这里判断是否到达终点 */
            if (cur is target)
                return step;
            /* 将 cur 的相邻节点加入队列 */
            for (Node x : cur.adj())
                if (x not in visited) {
                    q.offer(x);
                    visited.add(x);
                }
        }
        /* 划重点：更新步数在这里 */
        step++;
    }
}

// 单链表
/*
1. 合并两个有序队列：dummy head
2. 合并K个有序队列：dummy head + priority_queue, NlogK
3. 倒数第K个队列：快指针先走K步
4. 单链表中点：fast = 2* slow
5. 判断环：fast = 2* slow，fast回原点继续走，再次相遇就是环起点
6. 判断两链表交点，a+b
*/

// 二分搜索
// int binary_search(int[] nums, int target) {
//     int left = 0, right = nums.length - 1; 
//     while(left <= right) {
//         int mid = left + (right - left) / 2;
//         if (nums[mid] < target) {
//             left = mid + 1;
//         } else if (nums[mid] > target) {
//             right = mid - 1; 
//         } else if(nums[mid] == target) {
//             // 直接返回
//             return mid;
//         }
//     }
//     // 直接返回
//     return -1;
// }
// int left_bound(int[] nums, int target) {
//     int left = 0, right = nums.length - 1;
//     while (left <= right) {
//         int mid = left + (right - left) / 2;
//         if (nums[mid] < target) {
//             left = mid + 1;
//         } else if (nums[mid] > target) {
//             right = mid - 1;
//         } else if (nums[mid] == target) {
//             // 别返回，锁定左侧边界
//             right = mid - 1;
//         }
//     }
//     // 最后要检查 left 越界的情况
//     if (left >= nums.length || nums[left] != target)
//         return -1;
//     return left;
// }

// int right_bound(int[] nums, int target) {
//     int left = 0, right = nums.length - 1;
//     while (left <= right) {
//         int mid = left + (right - left) / 2;
//         if (nums[mid] < target) {
//             left = mid + 1;
//         } else if (nums[mid] > target) {
//             right = mid - 1;
//         } else if (nums[mid] == target) {
//             // 别返回，锁定右侧边界
//             left = mid + 1;
//         }
//     }
//     // 最后要检查 right 越界的情况
//     if (right < 0 || nums[right] != target)
//         return -1;
//     return right;
// }

// 滑动窗口
/* 滑动窗口算法框架 */
// void slidingWindow(string s, string t) {
//     unordered_map<char, int> need, window;
//     for (char c : t) need[c]++;
    
//     int left = 0, right = 0;
//     int valid = 0; 
//     while (right < s.size()) {
//         // c 是将移入窗口的字符
//         char c = s[right];
//         // 右移窗口
//         right++;
//         // 进行窗口内数据的一系列更新
//         ...

//         /*** debug 输出的位置 ***/
//         printf("window: [%d, %d)\n", left, right);
//         /********************/
        
//         // 判断左侧窗口是否要收缩
//         while (window needs shrink) {
//             // d 是将移出窗口的字符
//             char d = s[left];
//             // 左移窗口
//             left++;
//             // 进行窗口内数据的一系列更新
//             ...
//         }
//     }
// }

