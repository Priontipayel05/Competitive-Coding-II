
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def isPalindrome(self, head):
        if not head or not head.next:
            return True

        # Find the middle
        slow = head
        fast = head

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        # Reverse the second half
        prev = None
        curr = slow

        while curr:
            nextNode = curr.next
            curr.next = prev
            prev = curr
            curr = nextNode

        # Compare both halves
        firstHalf = head
        secondHalf = prev

        while secondHalf:
            if firstHalf.val != secondHalf.val:
                return False

            firstHalf = firstHalf.next
            secondHalf = secondHalf.next

        return True


if __name__ == "__main__":
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(2)
    head.next.next.next = ListNode(1)

    obj = Solution()

    print("Is Palindrome:", obj.isPalindrome(head))
