#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

class twoSum_class {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end()) {
                return {it->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }

    void printf(std::vector<int> arr)
    {
        for (std::vector<int>::size_type i = 0; i < arr.size(); ++i)
            std::cout << arr[i] << " ";
        std::cout << std::endl;
    }
};

twoSum_class twoSumArray;

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

    std::cout << "please enter the target number" << std::endl;

    std::cin >> i;

    std::cout << "the number is: " << std::endl;

    std::cout << i << std::endl;

    std::cout << "the target twoSum index is: " << std::endl;

    twoSumArray.printf(twoSumArray.twoSum(v_arr,i));

    system("pause");

    return 0;
}



