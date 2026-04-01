class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res = defaultdict(list)
        for s in strs:
            cc = [0] * 26
            for c in s:
                cc[ord(c) - ord('a')] += 1
            res[tuple(cc)].append(s)
        return list(res.values())