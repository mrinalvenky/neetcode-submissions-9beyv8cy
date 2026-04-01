class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        res = ""
        for i in range(len(strs[0])):
            for s in strs:
                if i > (len(s) - 1):
                    return res
                if s[i] != strs[0][i]:
                    return res
            res += s[i]
        return res


# T : O(n * m) n -> number of entries in strs , m -> length of shortest string
# S : O(1)


        