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
    bool isPalindrome(ListNode* head) {
        if(head->next==nullptr)
            return 1;//if there's only one element, it will be a palindrome by default
        //counting the total number of nodes
        ListNode *temp=head;
        int count=0;
        while(temp)
        {
            count++;
            temp=temp->next;
        }
        count/=2;
        ListNode *curr=head,*prev=nullptr;
        //number of nodes to be skipped
        while(count--)
        {
            prev=curr;
            curr=curr->next;
        }
            prev->next=NULL;
        //reversing the second linked list(pointed to by curr)
            ListNode *front=nullptr;
            prev=nullptr;
        while(curr)
        {
            front=curr->next;
            curr->next=prev;
            prev=curr;
            curr=front;
        }
        //comparing the two linked lists
        ListNode *head1=head, *head2=prev;
        //prev is pointing to second list while head is pointing to first list
        while(head1)
        {
            if(head1->val!=head2->val)
            return 0;
            head1=head1->next;
            head2=head2->next;
        }
        //since all the values match
        return 1;

    }
};