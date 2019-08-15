"""
バグあり、要修正
"""
class Node:
    def __init__(self, key):
        self.key = key
        self.parent = None
        self.left = None
        self.right = None
    

class BinarySearchTree:
    def __init__(self):
        self.root = Node(None)

    def insert(self, key):
        new = Node(key)
        if self.root.key is None:
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
                new.parent = parent
            else:
                parent.right = new
                new.parent = parent

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
            return node
        return None
    def delete(self, key):
        node = self.find(key)

        if node.left is not None and node.right is not None:
            ptr = node
            while(ptr.left is not None):
                ptr = ptr.left

            if ptr.right is not None:
                ptr.right.parent = ptr.parent
                ptr.parent.left = ptr.right
            else:
                ptr.parent.left = None
            node.key = ptr.key
        elif node.left is not None and node.right is None:
     
            if (self.root == node):
                self.root = node.left
            else:
                node.left.parent = node.parent
                if node.key < node.parent.key:
                    node.parent.left = node.left
                else:
                    node.parent.right = node.left
      
        elif node.left is None and node.right is not None:
   
            if (self.root == node):
                self.root = node.right
            else:
                node.right.parent = node.parent
                if node.key < node.parent.key:
                    node.parent.left = node.right
                else:
                    node.parent.right = node.right
        else:
            if (self.root == node):
                self.root = Node(None)
            else:
                if node.key < node.parent.key:
                    node.parent.left = None
                else:
                    node.parent.right = None

            

        


            

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
        elif cmd[0]=="delete":
            bst.delete(int(cmd[1]))
        else:
            if bst.find(int(cmd[1])) is not None:
                print ("yes")
            else:
                print ("no")
