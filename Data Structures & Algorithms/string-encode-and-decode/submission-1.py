def isdigit(c: str):
    return  c >= '0' and c <= '9'
class Solution:

    def encode(self, strs: List[str]) -> str:
        res = ""
        for s in strs:
            res += str(len(s)) + "#" + s
        return res

    def decode(self, s: str) -> List[str]:
        i = 0
        ret = []
        lstr = list(s)
        while i < len(lstr):
            l = 0
            while isdigit(lstr[i]) and i < len(lstr):
                l = l * 10 + int(lstr[i])
                i += 1
            if i >= len(lstr):
                return ret
            if lstr[i] == '#':
                i += 1
            if i >= len(lstr):
                ret.append("")
                return ret
            ret.append("".join(lstr[i : i + l]))
            i += l
        return ret
            
