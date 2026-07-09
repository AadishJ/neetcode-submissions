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
    void reorderList(ListNode* head) {
        ListNode* temp=head->next,*mid=head;
        while(temp && temp->next){
            mid=mid->next;
            temp=temp->next->next;
        }
        ListNode* head2 = mid->next;
        mid->next=nullptr;
        head2 = reverseList(head2);  
        head = merge(head,head2); 
        return;
    }
    ListNode* merge(ListNode* head1, ListNode* head2){
        ListNode* p1 = head1, *p2=head2;
        while(p2){
            ListNode* temp =p2;
            p2=p2->next;
            ListNode* n = p1->next;
            p1->next=temp;
            temp->next=n;
            p1=n;
        }
        return head1;
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
