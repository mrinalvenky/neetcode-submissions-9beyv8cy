class Solution {
    public String addBinary(String a, String b) {
        StringBuilder aStr = new StringBuilder(a);
        StringBuilder bStr = new StringBuilder(b);
        StringBuilder res = new StringBuilder("");

        aStr.reverse();
        bStr.reverse();

        int i = 0, j = 0, carry = 0;

        while (i < aStr.length() && j < bStr.length()) {
            int ai = aStr.charAt(i++) - '0';
            int bj = bStr.charAt(j++) - '0';
            int sm = ai + bj + carry;
            if (sm >= 2) {
                sm -= 2;
                carry = 1;
            } else {
                carry = 0;
            }
            res.append((char)(sm + '0'));
        }
        while (i < aStr.length()) {
            int ai = aStr.charAt(i++) - '0';
            int sm = ai + carry;
            if (sm >= 2) {
                sm -= 2;
                carry = 1;
            } else {
                carry = 0;
            }
            res.append((char)(sm + '0'));
        }
        while (j < bStr.length()) {
            int bj = bStr.charAt(j++) - '0';
            int sm = bj + carry;
            if (sm >= 2) {
                sm -= 2;
                carry = 1;
            } else {
                carry = 0;
            }
            res.append((char)(sm + '0'));
        }
        if (carry > 0) {
            res.append((char)(carry + '0'));
        }
        return res.reverse().toString();
    }
}