#coding:utf-8
class Node:
    def __init__(self, key=None):
        self.key = key
        self.prev = None
        self.next = None
class DoublyLinkedList:
    def __init__(self):
        self.head = Node()
        self.head.next = self.head
        self.head.prev = self.head
    def insert(self, key):
        new = Node(key)
        new.next = self.head.next
        self.head.next.prev = new
        self.head.next = new
        new.prev = self.head
    def search(self, key):
        cur = self.head.next
        while(1):
            if not cur.key is None:
                if cur.key == key:
                    return cur
                else:
                    cur = cur.next
            else:
                return None
    def delete(self, key):
        d = self.search(key)
        if d is not None:
            d.prev.next = d.next
            d.next.prev = d.prev
    def show(self):
        cur = self.head.next
        ls = []
        while(cur.key):
            ls.append(cur.key)
            cur = cur.next
        print (" ".join(ls))

    def deleteFirst(self):
        d = self.head.next
        if d.key is not None:
            d.prev.next = d.next
            d.next.prev = d.prev
    def deleteLast(self):
        d = self.head.prev
        if d.key is not None:
            d.prev.next = d.next
            d.next.prev = d.prev


dll = DoublyLinkedList()
N = int(input())
for n in range(N):
    cmd_x = input().split()
    if cmd_x[0]=="insert":
        dll.insert(cmd_x[1])
    elif cmd_x[0]=="delete":
        dll.delete(cmd_x[1])
    elif cmd_x[0]=="deleteFirst":
        dll.deleteFirst()
    else:
        dll.deleteLast()
dll.show()