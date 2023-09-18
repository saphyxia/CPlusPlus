#include <iostream>
#include <vector>
#include <functional>

class MaxStringLength {
public:
int maxLength(std::vector<std::string> &arr) {
        std::vector<int> masks;
        for (std::string &s : arr) {
            int mask = 0;
            for (char ch : s) {
                ch -= 'a';
                if ((mask >> ch) & 1) { // 若 mask 已有 ch，则说明 s 含有重复字母，无法构成可行解
                    mask = 0;
                    break;
                }
                mask |= 1 << ch; // 将 ch 加入 mask 中
            }
            if (mask > 0) {
                masks.push_back(mask);
            }
        }

        int ans = 0;
        std::function<void(int, int)> backtrack = [&](int pos, int mask) {
            if (pos == masks.size()) {
                ans = std::max(ans, __builtin_popcount(mask));
                return;
            }
            if ((mask & masks[pos]) == 0) { // mask 和 masks[pos] 无公共元素
                backtrack(pos + 1, mask | masks[pos]);
            }
            backtrack(pos + 1, mask);
        };
        backtrack(0, 0);
        return ans;
    }
};


MaxStringLength maxlengthstring;

int main(void)
{
    std::vector<std::string> v_str;
    std::string str;

    std::cout << "Please enter strings:"<< std::endl;

	do {
		std::cin >> str;
		v_str.emplace_back(str);
	} while (std::cin.get() != '\n');

    std::cout << "the strings is:"<< std::endl;

    for(std::vector<std::string>::size_type i=0; i < v_str.size(); ++i)
        std::cout << v_str[i] << " ";
    std::cout << std::endl;

    std::cout << "the maxlength string is:"  << maxlengthstring.maxLength(v_str) << std::endl;

    system("pause");

    return 0;
}


