
public class Main {

    static class ListNode {
        int val;
        ListNode next;

        ListNode(int val) {
            this.val = val;
            this.next = null;
        }
    }

    static class Solution {
        public boolean isPalindrome(ListNode head) {
            if (head == null || head.next == null)
                return true;

            // Find the middle
            ListNode slow = head;
            ListNode fast = head;

            while (fast != null && fast.next != null) {
                slow = slow.next;
                fast = fast.next.next;
            }

            // Reverse the second half
            ListNode prev = null;
            ListNode curr = slow;

            while (curr != null) {
                ListNode nextNode = curr.next;
                curr.next = prev;
                prev = curr;
                curr = nextNode;
            }

            // Compare both halves
            ListNode firstHalf = head;
            ListNode secondHalf = prev;

            while (secondHalf != null) {
                if (firstHalf.val != secondHalf.val)
                    return false;

                firstHalf = firstHalf.next;
                secondHalf = secondHalf.next;
            }

            return true;
        }
    }

    public static void main(String[] args) {
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(2);
        head.next.next.next = new ListNode(1);

        Solution obj = new Solution();

        System.out.println("Is Palindrome: " +
            (obj.isPalindrome(head) ? "True" : "False"));
    }
}
