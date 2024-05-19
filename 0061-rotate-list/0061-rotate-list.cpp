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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr||head->next==nullptr)
            return head;
        //count the number of nodes
        int count=0;
        ListNode* temp=head;
        while(temp)
        {
            count++;
            temp=temp->next;
        }
        k=k%count;
        if(k==0)
        return head;
        count-=k;
        ListNode* curr=head, *prev=nullptr;
        while(count--)
        {
             prev=curr;
             curr=curr->next;
        }
        prev->next=nullptr;
        ListNode *tail=curr;
        while(tail->next!=nullptr)
        {
            tail=tail->next;
        }
        tail->next=head;
        head=curr;
        return head;
        }
};