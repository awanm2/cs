# This is solution to 290. Word Pattern
# https://leetcode.com/problems/word-pattern/
# 

class wordPattern:
    def solveWordPattern(self, pattern: str, s: str) -> bool:
        words = s.split(" ")
	# Since we are looking for a bijecion
	# length of of words and s must be same.
        if(len(words)!=len(pattern)):
            print("here")
            return False
        pToSMap = {}  # map pattern to string word
        sTopMap = {}  # the other way around
        for c,w in zip(pattern, words):
            if c in pToSMap  and pToSMap[c] != w:
                return False
            if w in sTopMap and sTopMap[w] != c:
                return False
            pToSMap[c] = w
            sTopMap[w] = c
        print("HERE")
        return True

    def testResult (self, pattern: str, s: str, expected: bool):
        assert expected == self.solveWordPattern(pattern, s)

def test():
    wP = wordPattern()
    wP.testResult("abba", "dog cat cat dog", True)

def test2():
    wP = wordPattern()
    wP.testResult("aaba", "dog cat cat dog", True)

# 	#Input: pattern = "aaaa", s = "dog cat cat dog"
#	expected_result = false;





if __name__ == '__main__':
    test()
    test2()
