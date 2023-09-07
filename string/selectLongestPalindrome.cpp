#include <iostream>
#include <vector>

class selectlongestPalindrome {
public:
    std::pair<int,int> expandAroundCenter(const std::string&s, int left,int right)
    {
        while(left>=0 && right<s.size() && s[left]==s[right])
        {
            --left;
            ++right;
        }
        return {left+1,right-1};
    }
    std::string longestPalindrome(std::string s) 
    {
        int start = 0, end=0;

        for(int i=0; i<s.size(); ++i)
        {
            auto [left1, right1] = expandAroundCenter(s, i, i);
            auto [left2, right2] = expandAroundCenter(s, i, i+1);

            if(right1 - left1 > end - start)
            {
                start = left1;
                end = right1;
            }

            if(right2 - left2 > end - start)
            {
                start = left2;
                end = right2;
            }
        }
        return s.substr(start , end-start+1);
    }
};

selectlongestPalindrome selectPalindrome;

int main(void)
{
    std::string str;

    std::cout << "Please enter a string:"<< std::endl;

    std::getline(std::cin, str);

    std::cout << "the string is:"<< std::endl;

    std::cout<< str << std::endl;

    std::cout << "the longestPalindrome is:"<< std::endl;

    std::cout << selectPalindrome.longestPalindrome(str) << std::endl;

    system("pause");

    return 0;
}