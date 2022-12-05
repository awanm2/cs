import collections

# 1657. Determine if Two Strings Are Close
# https://leetcode.com/problems/determine-if-two-strings-are-close/

class Solution:
    def chars_matched(self, word1, word2):
        if (set(word1) == set(word2)):
            return True
        else:
            return False

    def count_chars(self, word):
        counter_word = collections.Counter(word)
        # counter_word is a dict of count of chars in the word. 
        # print(counter_word.values())
        # print(counter_word.keys())
        return sorted(counter_word.values())

    def match_freq(self, word1, word2):
        if (self.count_chars(word1) == self.count_chars(word2)):
            return True
        else:
            return False
    
    def closeStrings(self, word1: str, word2: str) -> bool:
        return (self.match_freq(word1, word2) and self.chars_matched(word1, word2))




def test(word1, word2):
    print("----")
    print(word1)
    print(word2)
    sol = Solution()
    if(sol.closeStrings(word1,word2)):
        print("Close strings")
    else:
        print("strings are not closed")

if __name__ == '__main__':
    test("cabbba", "abbccc")
    test("a", "bb")

