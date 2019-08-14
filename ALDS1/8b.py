class Node:
    def __init__(self, key):
        self.key = key
        self.parent = None
        self.left = None
        self.right = None
    

class BinarySearchTree:
    def __init__(self):
        self.root = None

    def insert(self, key):
        new = Node(key)
        if self.root is None:
            self.root = new
        else:
            current = self.root
            while(current is not None):
                parent = current
                if current.key > new.key:
                    current = current.left
                else:
                    current = current.right
            current = new
            if parent.key > new.key:
                parent.left = new
            else:
                parent.right = new

    def inorder(self, node=None):
        if node is None:
            node = self.root
        if node.left is not None:
            self.inorder(node.left)
        print(" "+str(node.key),end="")
        if node.right is not None:
            self.inorder(node.right)

    def preorder(self, node=None):
        if node is None:
            node = self.root
        print(" "+str(node.key),end="")
        if node.left is not None:
            self.preorder(node.left)
        if node.right is not None:
            self.preorder(node.right)

    def find(self, key, node=None):
        if node is None:
            node = self.root
        if node.key > key:
            if node.left is not None:
                return self.find(key, node.left)
        elif node.key < key:
            if node.right is not None:
                return self.find(key, node.right)
        else:
            return True
        return False
        


            

if __name__=="__main__":
    bst = BinarySearchTree()
    n = int(input())
    for i in range(n):
        cmd = list(input().split())
        if cmd[0]=="insert":
            bst.insert(int(cmd[1]))
        elif cmd[0]=="print":
            bst.inorder()
            print()
            bst.preorder()
            print()
        else:
            if bst.find(int(cmd[1])):
                print ("yes")
            else:
                print ("no")
            