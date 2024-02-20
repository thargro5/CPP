#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode* head) {
    if (!head || !head->next) {
        return false;
    }

    ListNode* slow = head;
    ListNode* fast = head->next;

    while (slow != fast) {
        if (!fast || !fast->next) {
            return false;
        }

        slow = slow->next;
        fast = fast->next->next;
    }

    return true;
}

int main() {
    // Test Case 1: Create a cycle
    ListNode* node1 = new ListNode(3);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(0);
    ListNode* node4 = new ListNode(-4);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    // Create a cycle from node4 to node2
    node4->next = node2;

    bool result1 = hasCycle(node1);
    std::cout << "Test Case 1: " << (result1 ? "true" : "false") << std::endl;

    // Clean up memory
    delete node1;
    delete node2;
    delete node3;
    delete node4;

    // Test Case 2: Create a cycle with only two nodes
    ListNode* node5 = new ListNode(1);
    ListNode* node6 = new ListNode(2);
    // Create a cycle from node6 to node5
    node5->next = node6;
    node6->next = node5;

    bool result2 = hasCycle(node5);
    std::cout << "Test Case 2: " << (result2 ? "true" : "false") << std::endl;

    // Clean up memory
    delete node5;
    delete node6;

    // Test Case 3: No cycle
    ListNode* node7 = new ListNode(1);

    bool result3 = hasCycle(node7);
    std::cout << "Test Case 3: " << (result3 ? "true" : "false") << std::endl;

    // Clean up memory
    delete node7;

    return 0;
}
