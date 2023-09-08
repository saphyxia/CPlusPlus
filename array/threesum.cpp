#include <iostream>
#include <vector>
#include <algorithm>

class threeSum_class {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n - 2; ++i) {
            int x = nums[i];
            if (i && x == nums[i - 1]) continue; // 跳过重复数字
            if (x + nums[i + 1] + nums[i + 2] > 0) break; // 当前遍历最小情况已经大于0
            if (x + nums[n - 2] + nums[n - 1] < 0) continue; // 当前遍历最大情况已经小于0
            int j = i + 1, k = n - 1;
            while (j < k) {
                int s = x + nums[j] + nums[k];
                if (s > 0) --k;
                else if (s < 0) ++j;
                else {
                    ans.push_back({x, nums[j], nums[k]});
                    for (++j; j < k && nums[j] == nums[j - 1]; ++j); // 跳过重复数字
                    for (--k; k > j && nums[k] == nums[k + 1]; --k); // 跳过重复数字
                }
            }
        }
        return ans;
    }

    void printf(std::vector<std::vector<int>> arr)
    {
        for (std::vector<int>::size_type i = 0; i < arr.size(); i++)
        {       
            for (std::vector<int>::size_type j = 0; j < arr[i].size(); j++)
                std::cout << arr[i][j] << " ";
            std::cout << std::endl;
        }
    }
};

threeSum_class zeroThreeSum;

int main(void)
{
    std::vector<int> v_arr;
    int i = 0;

    std::cout << "please enter an array" << std::endl;

	do {
		std::cin >> i;
		v_arr.emplace_back(i);
	} while (std::cin.get() != '\n');

    std::cout << "the  array is: " << std::endl;

    for(std::vector<int>::size_type i = 0; i < v_arr.size(); ++i)
        std::cout << v_arr[i] << " ";
    std::cout << std::endl;

    std::cout << "the zero threeSum array contains: " << std::endl;

    zeroThreeSum.printf(zeroThreeSum.threeSum(v_arr));

    system("pause");

    return 0;
}