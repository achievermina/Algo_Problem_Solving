class Solution:
    def wordPattern(self, pattern: str, str: str) -> bool:
        dict = {}
        words = []
        start = 0

        for end in range(0, len(str)):

            if (str[end] == ' '):
                newstr = str[start:end]
                words.append(newstr)
                start = end + 1
                end = end + 1
            else:
                end += 1

            if (end == len(str) - 1):
                newstr = str[start:end + 1]
                words.append(newstr)

        if (len(pattern) != len(words)):
            return False

        for idx in range(0, len(pattern)):
            checkstr = words[idx]
            checkpattern = pattern[idx]
            if (dict.get(checkpattern) == None):
                if checkstr not in dict.values():
                    dict[checkpattern] = checkstr
                else:
                    return False
            elif (dict.get(checkpattern) != checkstr):
                return False

        return True