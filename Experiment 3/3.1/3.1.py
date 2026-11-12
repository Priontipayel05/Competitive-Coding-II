
class MyQueue:

    def __init__(self):
        self.input = []
        self.output = []

    def shiftStacks(self):
        if not self.output:
            while self.input:
                self.output.append(self.input.pop())

    def push(self, x):
        self.input.append(x)

    def pop(self):
        self.shiftStacks()
        if not self.output:
            return -1
        return self.output.pop()

    def peek(self):
        self.shiftStacks()
        if not self.output:
            return -1
        return self.output[-1]

    def empty(self):
        return not self.input and not self.output


if __name__ == "__main__":
    q = MyQueue()

    q.push(10)
    q.push(20)
    q.push(30)

    print("Front element:", q.peek())
    print("Removed element:", q.pop())
    print("Front element:", q.peek())
    print("Is queue empty?", "Yes" if q.empty() else "No")
