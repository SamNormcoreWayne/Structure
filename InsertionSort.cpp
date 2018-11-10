#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL);
};

struct ListNode* insertionSortList(struct ListNode* head) {
	ListNode *tmp = head;
	ListNode *tmp_2 = head;
	ListNode *Node = head;
	ListNode *key = nullptr;
	ListNode *pre = nullptr;
	ListNode *prekey = nullptr;

	while (Node->next)
		Node = Node->next;
	tmp = tmp->next;
	while (tmp->next)
	{
		key = tmp;
		while(tmp != tmp_2->next)
		{
			if (tmp_2 > key)
			{
				if (pre != nullptr)
				{
					key->next = tmp_2->next;
					pre->next = key;
					tmp_2->next = prekey->next->next;
					prekey->next = tmp_2;
				}
				tmp_2->next = key->next;
				key->next = tmp_2;
			}

			tmp_2 = key->next;
		}
		tmp = tmp->next;
	}


}