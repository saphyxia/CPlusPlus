#include <iostream>
#include <vector>
#include <algorithm>

class minMoves_class {
public:
    int minMoves(std::vector<int>& nums) {
        int minNum = *std::min_element(nums.begin(),nums.end());
        int res = 0;
        for (int num : nums) {
            res += num - minNum;
        }
        return res;
    }
};

minMoves_class minMoves;

int main(void)
{
    std::vector<int> v_arr;
    int i = 0;

    std::cout << "please enter an array" << std::endl;

	do {
		std::cin >> i;
		v_arr.emplace_back(i);
	} while (std::cin.get() != '\n');

    std::cout << "the minmove is: " << minMoves.minMoves(v_arr) << std::endl;

    system("pause");

    return 0;
}