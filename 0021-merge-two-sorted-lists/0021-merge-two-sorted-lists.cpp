/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* result = new ListNode();  // dummy head
        ListNode* tail = result; // pointer to the last node in result

        ListNode* current1 = list1;
        ListNode* current2 = list2;

        while (current1 != nullptr || current2 != nullptr) {
            if (current1 == nullptr) {
                tail->next = new ListNode(current2->val);
                tail = tail->next;
                current2 = current2->next;
            }
            else if (current2 == nullptr) {
                tail->next = new ListNode(current1->val);
                tail = tail->next;
                current1 = current1->next;
            }
            else if (current1->val <= current2->val) {
                tail->next = new ListNode(current1->val);
                tail = tail->next;
                current1 = current1->next;
            }
            else {
                tail->next = new ListNode(current2->val);
                tail = tail->next;
                current2 = current2->next;
            }
        }

        return result->next;
    }
};