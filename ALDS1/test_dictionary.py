import unittest
from dictionary import Dictionary
class DictionaryTest(unittest.TestCase):
    def setUp(self):
        self.size = 11
        self.num = 1
    def test_search1(self):
        d = Dictionary(self.size)
        self.assertIsNone(d.search(self.num))
    def test_search2(self): 
        d = Dictionary(self.size)
        d.insert(self.num)
        self.assertIsNotNone(d.search(self.num))
if __name__ == "__main__":
    unittest.main()