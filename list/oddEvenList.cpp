#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class oddEventList_Class {
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

    ListNode* oddEvenList(ListNode* head)
    {
        if (head == nullptr) {
            return head;
        }

        ListNode* evenHead = head->next;
        ListNode* odd = head;
        ListNode* even = evenHead;
        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }

    void printList(ListNode* head)
    {
        ListNode* p = head;
        while(p != nullptr)
        {
            std::cout<< p->val;
            p = p->next;
        }
        std::cout<<'\n';
    }

};

oddEventList_Class oddEventList;

int main(void)
{
    std::vector<int> v_arr;
    int i = 0;

    std::cout << "please enter am array" << std::endl;

	do {
		std::cin >> i;
		v_arr.emplace_back(i);
	} while (std::cin.get() != '\n');

    ListNode head;
    oddEventList.createList(&head,v_arr);

    std::cout << "the list is:" <<std::endl;
    oddEventList.printList(&head);

    std::cout << "the oddEvenList is:" <<std::endl;
    oddEventList.oddEvenList(&head);
    oddEventList.printList(&head);

    system("pause");

    return 0;
}