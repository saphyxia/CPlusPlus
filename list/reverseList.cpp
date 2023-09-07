#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class reverseList_class {
public:

    ListNode* createList(ListNode* head,std::vector<int> &v_arr)
    {

        if(v_arr.size() <= 1)
        {
            return head;
        }

        ListNode *p = head;

        p->val = v_arr[0];

        for(int i = 1; i < v_arr.size(); ++i)
        {
            ListNode *pNewNode;
            pNewNode = new ListNode(v_arr[i]);

            p->next = pNewNode;
            p = pNewNode;
        }

        return head;
    }

    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }

    void printList(ListNode const * head)
    {
        ListNode const * p = head;
        while(p != nullptr)
        {
            std::cout<< p->val;
            p = p->next;
        }
        std::cout<<'\n';
    }
};

reverseList_class reverseList;

int main(void)
{
    std::vector<int> v_arr;
    int i = 0;

    std::cout << "please enter an array" << std::endl;

	do {
		std::cin >> i;
		v_arr.emplace_back(i);
	} while (std::cin.get() != '\n');

    ListNode head;
    reverseList.createList(&head,v_arr);

    std::cout << "the list is:" <<std::endl;
    reverseList.printList(&head);

    std::cout << "the reverseList is:" <<std::endl;
    reverseList.printList(reverseList.reverseList(&head));

    system("pause");

    return 0;
}