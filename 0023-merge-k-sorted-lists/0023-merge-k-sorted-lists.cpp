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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //num,index
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        ListNode* resultHead = new ListNode();
        ListNode* currentNode = resultHead;
        for(int i = 0; i < lists.size(); i++){
            if(lists[i] != nullptr){
                minHeap.push({lists[i]->val, i});
            }
        }
        while(!minHeap.empty()){
            int smallest = minHeap.top().first;
            int index = minHeap.top().second;
            minHeap.pop();

            currentNode->next = new ListNode(smallest);
            currentNode = currentNode->next;
            if(lists[index]->next != nullptr){
                lists[index] = lists[index]->next;
                minHeap.push({lists[index]->val, index});
            }
        }
        return resultHead->next;
    }
};