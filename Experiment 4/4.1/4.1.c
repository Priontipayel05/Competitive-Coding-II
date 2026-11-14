
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* createNode(int val) {
    struct ListNode* newNode =
        (struct ListNode*)malloc(sizeof(struct ListNode));

    newNode->val = val;
    newNode->next = NULL;

    return newNode;
}

bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return true;

    struct ListNode *slow = head, *fast = head;

    // Find the middle
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half
    struct ListNode *prev = NULL, *curr = slow;

    while (curr != NULL) {
        struct ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    // Compare both halves
    struct ListNode *firstHalf = head;
    struct ListNode *secondHalf = prev;

    while (secondHalf != NULL) {
        if (firstHalf->val != secondHalf->val)
            return false;

        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;
}

int main() {
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(2);
    head->next->next->next = createNode(1);

    if (isPalindrome(head))
        printf("Is Palindrome: True\n");
    else
        printf("Is Palindrome: False\n");

    return 0;
}
