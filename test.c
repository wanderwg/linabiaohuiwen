//判断是否为回文结构
ListNode* middleNode(ListNode* head) {
	if (head == NULL)
		return NULL;
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast) {
		fast = fast->next;
		if(fast==NULL)
			break;
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}
ListNode* reverseList(ListNode* head) {
	if (head == NULL)
		return head;
	ListNode* pCur = head;
	ListNode* pNewHead = NULL;
	while (pCur) {
		head = pCur->next;
		pCur->next = pNewHead;
		pNewHead = pCur;
		pCur = head;
	}
	return pNewHead;
}
bool chkPalindrome(ListNode* A) {
	ListNode* middle = middleNode(A);
	ListNode* r = reverseList(middle->next);
	ListNode* n1 = A;
	ListNode* n2 = r;
	while (n1&&n2) {
		if (n1->val != n2->val)
			return false;
		n1 = n1->next;
		n2 = n2->next;
	}
	return true;
}