class Solution {
public:
    std::string removeTrailingZeros(std::string num) {
        int i = num.length() - 1;
        while (i >= 0 && num[i] == '0') {
            num.pop_back();
            i--;
        }
        return num;
    }
};