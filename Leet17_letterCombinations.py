class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []
        alphabet = [[], [], ['a', 'b', 'c'], ['d', 'e', 'f'], ['g', 'h', 'i'], ['j', 'k', 'l'], ['m', 'n', 'o'],
                    ['p', 'q', 'r', 's'], ['t', 'u', 'v'], ['w', 'x', 'y', 'z']]
        List = []
        idx = 0
        word = ''
        self.help(word, alphabet, digits, idx, List)
        return List

    def help(self, word, alphabet, digits, idx, List):
        currentDigit = int(digits[idx])


        if idx == len(digits):  # base case
            List.append(word)
            idx -= 1

        else:
            currentDigit = int(digits[idx])
            for j in alphabet[currentDigit]:
                word += j
                idx += 1
                self.help(word, alphabet, digits, idx, List)
                word = word[:-1]
                idx -= 1



        ### Make simpler if statement
        # if idx == len(digits) - 1:  # base case
        #     for j in alphabet[currentDigit]:
        #         word += j
        #         List.append(word)
        #         word = word[:-1]
        #     idx -= 1
        # else:
        #     for j in alphabet[currentDigit]:
        #         word += j
        #         idx += 1
        #         self.help(word, alphabet, digits, idx, List)
        #         word = word[:-1]
        #         idx -= 1

#
# if __name__ == '__main__':
#     digits="23"
#     #print(int(digits[-1]))
#
#     List = letterCombinations(digits)
#     for i in List:
#         print(i)



'''사람들이 함수속의 함수로 쓰는데 왜 이렇게 쓰는지 모르겠다

class Solution:
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        def combine(pres,dicts,digit):
            """
            :type pres:List[str], dicts: dictionary, digits: str
            :rtype: List[str]
            """
            letL=[]
            for pre in pres:
                for letter in dicts[digit]:
                    letL.append(pre+letter)
            return letL
            
        if digits=='':
            return []
            
        dicts={'1':[''], '2':['a','b','c'],'3':['d','e','f'],'4':['g','h','i'],'5':['j','k','l'],'6':['m','n','o'],'7':['p','q','r','s'],'8':['t','u','v'],'9':['w','x','y','z'],'0':[' ']}
        
        lets=['']
        for digit in digits:
            lets=combine(lets,dicts,digit)
        return lets
            



'''