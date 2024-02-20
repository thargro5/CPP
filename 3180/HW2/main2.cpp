#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}//constructer initializing member variables 
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode dummy(0); // Create a dummy node to simplify handling the result
    ListNode* current = &dummy; // Initialize the current pointer to the dummy node

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val < list2->val) {l,
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    // If either list1 or list2 is not fully processed, just attach it to the merged list
    if (list1 != nullptr) {
        current->next = list1;
    } else {
        current->next = list2;
    }

    return dummy.next; // Return the merged list (skip the dummy node)
}

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Example 1
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode* merged = mergeTwoLists(list1, list2);

    std::cout << "Example 1 Output: ";
    printList(merged); // Output: 1 1 2 3 4 4

    // Clean up memory (deallocating the merged list)
    while (merged != nullptr) {
        ListNode* temp = merged;
        merged = merged->next;
        delete temp;
    }

    // Example 2
    list1 = nullptr;
    list2 = nullptr;

    merged = mergeTwoLists(list1, list2);

    std::cout << "Example 2 Output: ";
    printList(merged); // Output: (empty list)

    // Clean up memory (deallocating the merged list)
    while (merged != nullptr) {
        ListNode* temp = merged;
        merged = merged->next;
        delete temp;
    }

    // Example 3
    list1 = nullptr;
    list2 = new ListNode(0);

    merged = mergeTwoLists(list1, list2);

    std::cout << "Example 3 Output: ";
    printList(merged); // Output: 0

    // Clean up memory (deallocating the merged list)
    while (merged != nullptr) {
        ListNode* temp = merged;
        merged = merged->next;
        delete temp;
    }

    return 0;
}
