#include <iostream>
#include <vector>


class robclass {
public:
    int robRange(std::vector<int>& nums, int start, int end) {
        int first = nums[start], second = std::max(nums[start], nums[start + 1]);
        for (int i = start + 2; i <= end; i++) {
            int temp = second;
            second = std::max(first + nums[i], second);
            first = temp;
        }
        return second;
    }

    int rob(std::vector<int>& nums) {
        int length = nums.size();
        if (length == 1) {
            return nums[0];
        } else if (length == 2) {
            return std::max(nums[0], nums[1]);
        }
        return std::max(robRange(nums, 0, length - 2), robRange(nums, 1, length - 1));
    }
};

robclass robmax;

int main(void)
{

    std::vector<int> v_arr;
    int i = 0;

    std::cout << "please enter an array" << std::endl;

	do {
		std::cin >> i;
		v_arr.emplace_back(i);
	} while (std::cin.get() != '\n');

    std::cout << "the array is: " << std::endl;

    for(std::vector<int>::size_type i = 0; i < v_arr.size(); ++i)
        std::cout << v_arr[i] << " ";
    std::cout << std::endl;

    std::cout << "the maxrob is: " << robmax.rob(v_arr) << std::endl;

    system("pause");

    return 0;
}