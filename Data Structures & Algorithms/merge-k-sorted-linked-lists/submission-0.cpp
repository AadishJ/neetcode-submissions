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
    static bool comp(ListNode* a, ListNode* b){
        return a->val>b->val;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,decltype(&comp)> pq(comp);
        ListNode* head = new ListNode();
        for(int i=0;i<lists.size();i++){
            pq.push(lists[i]);
        }
        ListNode* temp = head;
        while(!pq.empty()){
            ListNode* p = pq.top();
            pq.pop();
            if(p->next) pq.push(p->next);
            temp->next = p;
            temp=temp->next;
        }
        return head->next;
    }
};
