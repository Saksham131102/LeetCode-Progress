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
private:
    ListNode* mergeTwoLL(ListNode* &head1, ListNode* &head2) {
        if(head1 == nullptr)
            return head2;
        if(head2 == nullptr)
            return head1;
        if(head1->val > head2->val)
            return mergeTwoLL(head2, head1);
        
        ListNode* temp1 = head1;
        ListNode* temp2 = head2;

        while(temp1->next != nullptr && temp2 != nullptr) {
            if(temp1->val <= temp2->val && temp2->val <= temp1->next->val) {
                ListNode* t = temp2;
                temp2 = temp2->next;
                t->next = temp1->next;
                temp1->next = t;
                temp1 = temp1->next;
            }
            else {
                temp1 = temp1->next;
            }
        }

        if(temp1->next == nullptr)
            temp1->next = temp2;

        return head1;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return nullptr;
        while(lists.size() > 1) {
            vector<ListNode*> mergedLists;
            for(int i=0;i<lists.size();i=i+2) {
                ListNode* l1 = lists[i];
                ListNode* l2 = i+1 < lists.size() ? lists[i+1] : nullptr;
                mergedLists.push_back(mergeTwoLL(l1, l2));
            }
            lists = mergedLists;
        }
        return lists[0];
    }
};