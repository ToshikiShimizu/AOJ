# coding:utf-8
class Stack:
    def __init__(self, size):
        self.size = size
        self.top = 0
        self.array = [None] * size
    def pop(self):
        x = self.array[self.top]
        self.top-=1
        return x
    def push(self, x):
        self.top+=1
        self.array[self.top] = x
    def isEmpty(self):
        self.top = 0

stack = Stack(200)
ls = input().split()
for s in ls:
    if not s in['+','-','*']:
        stack.push(int(s))
    else:
        x2 = stack.pop()
        x1 = stack.pop()
        if s=='+':
            y = x1 + x2
        elif s=='-':
            y = x1 - x2
        else:
            y = x1 * x2
        stack.push(y)
print (stack.pop())

