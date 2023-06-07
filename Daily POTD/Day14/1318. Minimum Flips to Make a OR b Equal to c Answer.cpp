class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt = 0;
        while (a || b || c) {
            const bool a_bit = a & 1;
            const bool b_bit = b & 1;
            const bool c_bit = c & 1;
            cnt += c_bit && !a_bit && !b_bit;
            cnt += !c_bit && a_bit;
            cnt += !c_bit && b_bit;
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return cnt;
    }
};