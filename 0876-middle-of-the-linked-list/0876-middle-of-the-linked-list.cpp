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
   
    ListNode* middleNode(ListNode* head) {
 //way 1
    //     int count=0;
    //     //counting the total number of nodes
    //     ListNode *temp=head;
    //     while(temp)
    //     {
    //         count++;
    //         temp=temp->next;
    //     }
    //     count/=2; //these are the number of steps to be taken from start
    //     temp=head;
    //     while(count--)
    //     {
    //         temp=temp->next;
    //     }
    //     return temp;
    //way 2 using slow & fast pointers
        ListNode *slow=head, *fast=head;
        while(fast&&fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
    return slow;
        
    }
};