#coding:utf-8
class Queue:
    def __init__(self, size):
        self.head = 0
        self.tail = 0
        self.size = size
        self.array = [None] * size
    def enqueue(self, x):
        self.array[self.tail] = x
        self.tail = (self.tail+1)%self.size
    def dequeue(self):
        x = self.array[self.head]
        self.head = (self.head+1)%self.size
        return x
    def isEmpty(self):
        return self.head==self.tail
    def isFull(self):
        self.head = (self.tail+1)%self.size
N, Q = map(int,input().split())
queue = Queue(100000)
for n in range(N):
    name, time = input().split()
    queue.enqueue([name,int(time)])
total = 0
end_log = []
while(not queue.isEmpty()):
    name,time = queue.dequeue()
    if time > Q:
        time-=Q
        queue.enqueue([name,time])
        total += Q
    else:
        total += time
        print (name+" "+str(total))



