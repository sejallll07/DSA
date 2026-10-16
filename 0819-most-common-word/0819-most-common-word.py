from collections import Counter

class Solution:
    def mostCommonWord(self, paragraph: str, banned: list[str]) -> str:

        paragraph = paragraph.lower()
    
        clean_chars = []
        for ch in paragraph:
            if ch.isalpha():
                clean_chars.append(ch)
            else:
                clean_chars.append(" ")
            
        clean_paragraph = "".join(clean_chars)
        words = clean_paragraph.split()
    
        banned_set = set(banned)
        word_counts = Counter(word for word in words if word not in banned_set)
        maxi = -1
        ans = ""
        
        for word in word_counts:
            if word_counts[word] > maxi:
                maxi = word_counts[word]
                ans = word
                
        return ans
