//Given the head of a singly linked list, reverse the list, and return the rever
//sed list. 
//
// 
// Example 1: 
//
// 
//Input: head = [1,2,3,4,5]
//Output: [5,4,3,2,1]
// 
//
// Example 2: 
//
// 
//Input: head = [1,2]
//Output: [2,1]
// 
//
// Example 3: 
//
// 
//Input: head = []
//Output: []
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the list is the range [0, 5000]. 
// -5000 <= Node.val <= 5000 
// 
//
// 
// Follow up: A linked list can be reversed either iteratively or recursively. C
//ould you implement both? 
// Related Topics Linked List 
// 👍 6639 👎 127


//leetcode submit region begin(Prohibit modification and deletion)
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
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr)return head;
        ListNode *beforeHead = nullptr;
        ListNode *nextHead = head->next;
        while (true) {
            head->next = beforeHead;
            beforeHead = head;
            if(nextHead==nullptr)break;
            head = nextHead;
            nextHead = nextHead->next;
        }
        return head;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
