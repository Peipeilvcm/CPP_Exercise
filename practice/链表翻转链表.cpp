#include<bits/stdc++.h>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x),next(NULL) {}
};

pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail){
	if(head == tail){
		return {head, tail};
	}
	ListNode* prev = tail->next;
	ListNode* cur = head;
	ListNode* nex;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
	while(prev != tail){
		nex = cur->next;
		cur->next = prev;
		prev = cur;
		cur = nex;
	}
	return {tail, head};
}

ListNode* createList(int a[], int n){
	if(n<=0){
		return NULL;
	}
	
	ListNode* head = new ListNode(a[0]);
	ListNode* cur = head;
	
	for(int i=1;i<n;++i){
		cur->next = new ListNode(a[i]);
		cur = cur->next;	
	}
	
	return head;
}

void printList(ListNode* head){
	ListNode* cur=head;
	while(cur!=NULL){
		printf("%d ",cur->val);
		cur = cur->next; 
	}
	printf("NULL\n");
}

void delList(ListNode* head){
	ListNode* cur=head,*p;
	while(cur!=NULL){
		p = cur;
		cur = cur->next;
		delete p;
	}
	p=NULL;
}

//递归 
ListNode* reverseList(ListNode* head){
	
	if(head==NULL){
	    return NULL;
    }

    if(head->next == NULL){
        return head;
    }

    ListNode *p = head->next;
    head->next=NULL;

    ListNode *newHead = reverseList(p);
    p->next = head;
    return newHead;
}
//非递归
ListNode* reverseList2(ListNode* head){
	
	ListNode* pre = NULL;
	ListNode* cur = head;
	while(cur!=NULL){
		ListNode* next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	return pre;
} 

//m,n之间的翻转 
ListNode* reverseBetween(ListNode* head, int m, int n) {
        int index=1;
        ListNode* lp,*rp,*lp2,*rp2;
        ListNode* pre=NULL;
        ListNode* cur=head;
        ListNode* next=cur->next;
        while(index<m){
            pre=cur;
            cur=cur->next;
            next = cur->next;
            index++;
        }
        lp=pre;
        lp2=cur;
        while(index<n){
            cur->next=pre;
            pre=cur;
            cur=next;
            next=cur->next;
            index++;
        }
        rp2=cur;
        rp=cur->next;
        
        cur->next=pre;
        
        if(lp==NULL){
            head = rp2;
        }else{
            lp->next=rp2;
        }
        
        lp2->next=rp;
        
        return head;
    }

//No.24每两个节点交换
ListNode* swapPairs(ListNode* head){
	if(head==NULL){
        return NULL;
    }
	ListNode* vir = new ListNode(-1);
	vir->next = head;
	
	ListNode* pre = vir;
	ListNode* cur = head;
	ListNode* next = cur->next;
	
	while(next!=NULL){
		cur->next = next->next;
		next->next = cur;
		pre->next = next;
		
		if(cur->next != NULL){
			pre = pre->next->next;
			cur = pre->next;
			next = cur->next;
		}else{
			break;
		}
	}
	
	head = vir->next;
	delete vir;
	return head;
}

//No.25,不是两个,而是k个交换
ListNode* swapKGroup(ListNode* head){
	
} 

//148归并排序,自顶向上 
ListNode* mergeSort(ListNode* heap){
	
}

//237给定节点,删除节点,不能找到前一个节点,这个必须改值,复制下一个节点值,删除下一个节点 
void delNode(ListNode* node){
	if(node == NULL){
		return;
	}
	
	if(node->next == NULL){
		delete node;
		node = NULL;
		return;
	}
	
	node->val = node->next->val;
	ListNode* p = node->next;
	node->next = p->next;
	
	delete p;
	return;
} 

//双指针技术,与长度相关,删除倒数第N个节点 
ListNode* delNthFromEnd(ListNode* head,int N){
	if(head==NULL){
		return NULL;
	}
	ListNode* vir = new ListNode(-1);
	vir->next = head;
	
	ListNode* pre,q;
	
	pre = vir;
	q = head;
	while(N--){
		q = q->next;
		if(N == 0){
			break;
		}else if(q == NULL){
			return head;
		}
	}
	
	while(q!=NULL){
		pre = pre->next;
		q = q->next;
	}
	
	ListNode* delP = pre->next;
	pre->next = delP->next;
	delete delP;
	delP = NULL;
	
	head = vir->next;
	delete vir;
	vir = NULL;
	return head;
}

//ld23,合并k个有序链表
ListNode* mergeTwo(ListNode* l1,ListNode* l2){
	if(l1==NULL){//两两归并
		return l2;
	}
	if(l2==NULL){
		return l1;
	}
	
	if(l1->val<=l2->val){
		l1->next = mergeTwo(l1->next,l2);
		return l1;
	}else{
		l2->next = mergeTwo(l1,l2->next);
		return l2;
	}
}
ListNode* mergeKLists(vector<ListNode*>& lists) {
	int n=lists.size();
	if(n==1){
		return lists[0];
	}
	if(n==0){
		return NULL;
	}
	
	while(lists.size()>1){
		ListNode* l1 = lists.front();
		lists.erase(lists.begin());
		ListNode* l2 = lists.front();
		lists.erase(lists.begin());
		lists.push_back(mergeTwo(l1,l2));
	}
	
	return lists[0];
}


int main(){
	
	int a[] = {1,2,3,4,5};
	int n = sizeof(a)/sizeof(int);
	
	ListNode* head = createList(a,n);
	printList(head);
	
	head = reverseList2(head);
	printList(head);
	
	head = reverseBetween(head,1,4);
	printList(head);
	
	delList(head);
	
	return 0;
}
