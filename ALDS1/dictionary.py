class Dictionary:
    def __init__(self,size):
        self.size = size
        self.table = [None for i in range(size)]
    def insert(self, key):
        self.i = 0
        self.key = key
        while(1):
            j = self.hash()
            if self.table[j] is None:
                self.table[j] = self.key
                return j
            else:
                i+=1
    def search(self, key):
        self.i = 0
        self.key = key
        while(1):
            j = self.hash()
            if self.table[j] == self.key:
                return j      
            elif  self.table[j]==None or self.i>=self.size:
                return None
            else:
                j+=1
    def hash1(self):
        return self.key % self.size
    def hash2(self):
        return 1 + (self.key % (self.size-1))
    def hash(self):
        return (self.hash1() + self.i * self.hash2()) % self.size

