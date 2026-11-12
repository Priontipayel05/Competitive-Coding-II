
import java.util.Stack;

public class Main {

    static class MyQueue {
        private Stack<Integer> input;
        private Stack<Integer> output;

        public MyQueue() {
            input = new Stack<>();
            output = new Stack<>();
        }

        private void shiftStacks() {
            if (output.empty()) {
                while (!input.empty()) {
                    output.push(input.pop());
                }
            }
        }

        public void push(int x) {
            input.push(x);
        }

        public int pop() {
            shiftStacks();
            if (output.empty()) return -1;

            return output.pop();
        }

        public int peek() {
            shiftStacks();
            if (output.empty()) return -1;

            return output.peek();
        }

        public boolean empty() {
            return input.empty() && output.empty();
        }
    }

    public static void main(String[] args) {
        MyQueue q = new MyQueue();

        q.push(10);
        q.push(20);
        q.push(30);

        System.out.println("Front element: " + q.peek());
        System.out.println("Removed element: " + q.pop());
        System.out.println("Front element: " + q.peek());
        System.out.println("Is queue empty? " + (q.empty() ? "Yes" : "No"));
    }
}
