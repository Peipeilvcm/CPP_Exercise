// 自顶向下 归并递归
ListNode* sortList(ListNode* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    ListNod *fast, *slow;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
    }

    ListNode* temp = slow->next;
    slow->next = NULL;
    ListNode* left = sortList(head);
    ListNode* right = sortList(temp);

    //合并left和right
    ListNode* new_head = (ListNode*) malloc(sizeof(ListNode));
    ListNode* p = new_head;
    while(left != NULL && right != NULL){
        if(left->val < right->val){
            p->next = left;
            p = p->next;
            left = left->next;
        }else{
            p->next = right;
            p = p->next;
            right = right->next;
        }
    }
    p->next = (left==NULL) ? right : left;

    return new_head->next;
}


// 自底向上
// 自底向上规定排序 (迭代)
ListNode* sortList(ListNode* head) {
	if (head == NULL || head->next == NULL) return head;
	int len = 0, intv = 1;
	ListNode* p = head;
	while (p != NULL) {
		len++;
		p = p->next;
	}
	ListNode* new_head = (ListNode*)malloc(sizeof(ListNode));
	new_head->next = head;
	
	while (intv < len) {
		ListNode* pre = new_head;
		ListNode* h = new_head->next;
		while (h != NULL) {
			ListNode *h1 = h; // 第一部分的头
			int i = intv;
			ListNode *h2 = h1;
			while (h2 != NULL && i != 0) {
				h2 = h2->next; // 第二部分的头
				-- i;
			}
			if (i != 0) { // 还没找到h2 就走到头了 说明没有h2了，无须merge了
				break;
			}

			// 获取h1、h2部分的长度(h1不用再算了，因为如果h2存在那么h1肯定是完整的intv长度
			int c1 = intv;
			ListNode* travelH2 = h2;
			i = intv;
			while (travelH2 != NULL && i != 0) {
				travelH2 = travelH2->next;
				-- i;
			}
			h = travelH2; // h指向h2的末尾的下一个元素 即下两单位合并的开始部分
			int c2 = intv - i;


			// merge h1和h2部分
			while (c1 != 0 && c2 != 0) {
				if (h1->val < h2->val) {
					pre->next = h1;
					h1 = h1->next;
					--c1;
				}
				else {
					pre->next = h2;
					h2 = h2->next;
					--c2;
				}
				pre = pre->next;
			}
			if (c1 == 0) pre->next = h2;
			else pre->next = h1;
			while (c1 > 0 || c2 > 0) {
				pre = pre->next;
				--c1;
				--c2;
			}
            pre->next = h;
		}

		intv *= 2;
	}

	return new_head->next;
}

