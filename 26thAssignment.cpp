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
// ListNode definition (ListNode.h)
#ifndef LISTNODE_H
#define LISTNODE_H

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

#endif

struct CompareNodes {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; 
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, CompareNodes> minHeap;
        
        for(auto node: lists) {
            if(node) 
                minHeap.push(node);
        }
        
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while(!minHeap.empty()) {
            ListNode* curr = minHeap.top(); 
            minHeap.pop();
            
            tail->next = curr;
            tail = tail->next;
            
            if(curr->next) 
                minHeap.push(curr->next);
        }
        
        return dummy.next;
    }
};