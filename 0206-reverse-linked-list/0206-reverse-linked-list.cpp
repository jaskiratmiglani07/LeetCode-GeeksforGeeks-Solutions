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
    ListNode* Reverse(ListNode *curr, ListNode *prev)
    {
        if(curr==nullptr)
            return prev;
        ListNode *future=curr->next;
        curr->next=prev;
        return Reverse(future,curr);
    }
    ListNode* reverseList(ListNode* head) {
        // vector<int>ans;
        // ListNode *temp=head;
        // while(temp)
        // {
        //     ans.push_back(temp->val);
        //     temp=temp->next;
        // };
        // int i=ans.size()-1;
        // temp=head;
        // while(temp)
        // {
        //     temp->val=ans[i];
        //     i--;
        //     temp=temp->next;
        // }
        // return head;
        //way 2
        // ListNode *curr= head, *prev=nullptr, *fut=nullptr;
        // while(curr)
        // {
        //     fut=curr->next;
        //     curr->next=prev;
        //     prev=curr;
        //     curr=fut;
        // }
        // head=prev;
        // return head;
        //way 3 using recursion
        return Reverse(head,nullptr);
        
    }
};