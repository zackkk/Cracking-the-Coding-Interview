struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
ListNode *sortList(ListNode *head) {
	if(head == nullptr || head->next == nullptr) return head;     
	ListNode *mid = findMiddle(head);
	ListNode *right = sortList(mid->next);
	mid->next = nullptr;
	ListNode *left = sortList(head);
	return mergeTwoLists(left, right);
}
    
ListNode *findMiddle(ListNode *head){
	ListNode *slow = head;
	ListNode *fast = head->next;
	while(fast != nullptr && fast->next != nullptr){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
    
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *dummy = new ListNode(-1); // not a build-in type, need new
    ListNode *cur = dummy;
    while(l1 != nullptr || l2 != nullptr){
        if (l1 == nullptr){
            cur->next = l2;
            break;
        }
        else if (l2 == nullptr){
            cur->next = l1;
            break;
        }
        else{
            if(l1->val < l2->val){
                cur->next = l1;
                l1 = l1->next;
                cur = cur->next;
            }
            else{
                cur->next = l2;
                l2 = l2->next;
                cur = cur->next;
            }
        }
    }
    return dummy->next;
}
};
