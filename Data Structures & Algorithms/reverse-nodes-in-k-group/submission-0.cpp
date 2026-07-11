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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int p=k;
        while(k!=1 && temp){
            temp=temp->next;
            k--;
        }
        if(!temp) return head;
        ListNode* nHead = temp->next;
        temp->next = nullptr;
        head =  reverseList(head);
        while(temp->next) temp=temp->next;
        temp->next= reverseKGroup(nHead,p);
        return head;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};
