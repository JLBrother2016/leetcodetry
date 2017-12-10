#include "../leetcodeutil.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = NULL;
        while (head) {
          ListNode* next = head->next;
          head->next = temp;
          temp = head;
          head = next;
        }    
    }

    return temp;
};

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if(head == NULL || head->next == NULL) {
//             return head;
//         }    
//         ListNode* prev=NULL;
//         ListNode* cur=head;
//         while(cur != NULL) {
//             ListNode* temp = cur->next;
//             cur->next = prev;
//             prev = cur;
//             cur = temp;
                
//         }
//         return prev;
        
//     }
// };

int main(int argc, char const *argv[])
{
  
  return 0;
}
