from collections import defaultdict as dic 
class trieNode:
    def __init__(self, data=None):
        self.data=data # optional property
        self.wc=0 # count number of occurences of this char: useful for generating suggestions
        self.word_end = False # to mark a node as end of a word
        # if word_end is a boolean then trie can store only unique words
        # initializing with 0 and incrementing on every duplicate word will make this trie compatible with duplicates
        self.childs = dic(lambda:None) # map for child nodes

class TrieDatStr:
    def __init__(self):
        self.ROOT = trieNode()

    def insert(self, word):
        curr_node = self.ROOT

        for char in word:
            if curr_node.childs[char] is None:
                temp_node = trieNode(char)
                curr_node.childs[char] = temp_node 
            curr_node.childs[char].wc+=1 
            curr_node = curr_node.childs[char]
        curr_node.word_end = True 
        # if duplicate words are to be stored then word_end is taken as 0 initially
        # and incremented on each duplicate entry of the word

    def searchWord(self, word):

        curr_node = self.ROOT
        for char in word:
            if curr_node.childs[char] is not None:
                curr_node = curr_node.childs[char]
            else: return False 
        return curr_node.word_end

    def del_word(self, word):

        curr_node = self.ROOT
        for char in word:
            if curr_node.childs[char] is None:
                return False
            curr_node = curr_node.childs[char]
        
        if curr_node.word_end:
            curr_node.word_end = False
            # trie has to store duplicate words then 
            # word_end is an integer denoting the number of duplicates
            # decrementing it by one will mean deleting one copy 
            curr_node.wc -= 1 
            return True 
        return False
        
    def count_prefix(self, substr):

        curr_node = self.ROOT
        for char in substr:
            if curr_node.childs[char] is None:
                return False
            curr_node = curr_node.childs[char]
        
        return curr_node.wc

    def find_word_suggestions(self, pref):
        suggestions = []
        def rec_finder(node, prefix):
            if node.word_end:
                suggestions.append(prefix)

            #check if the node was infertile
            if len(node.childs.keys())==0:
                return

            for rel_ascii in range(26):
                char = chr(97 + rel_ascii) 
                if node.childs[char] is not None:
                    rec_finder(node.childs[char], prefix+char)

        curr_node = self.ROOT
        for char in pref:
            if curr_node.childs[char] is None:
                return False
            curr_node = curr_node.childs[char]

        rec_finder(curr_node, pref)
        
        return sorted(suggestions)

t=TrieDatStr()
t.insert('crystal')
t.insert('crypto')
t.insert('blown')
t.insert('purple')
t.insert('yellow')
t.insert('yellowish')
t.insert('yell')
t.insert('blue')
t.insert('blaze')
t.insert('black')
t.insert('call')
t.insert('fire')
t.insert('fist')
t.insert('first')
# try functions through interactive console
