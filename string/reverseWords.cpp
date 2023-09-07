#include <iostream>
#include <vector>

class reverseStringWords {
public:

    void swapChar(std::vector<char>&s, int left, int right)
    {
        char temp;

        while(left < right)
        {
            temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }

    void reverseWords(std::vector<char>& s) {
        int left=0, right=0;
        int length = s.size();

        while(right<length)
        {
            if(s[right] == ' ')
            {
                swapChar(s, left, right-1);
                right++;
                left = right;
            }
            else
            {
                right++;
            }
        }
        swapChar(s, left,length-1);
        swapChar(s, 0,length-1);
    }
};

reverseStringWords reverseString;

int main(void)
{
    std::string str;

    std::cout << "Please enter a string:"<< std::endl;

    std::getline(std::cin, str);

    std::vector<char> v_str(str.begin(),str.end());

    std::cout << "the string is:"<< std::endl;

    for(std::vector<char>::size_type i = 0; i<v_str.size(); ++i)
        std::cout << v_str[i];
    std::cout<< "\n";

    std::cout << "the string after reversing the words is:"<< std::endl;

    reverseString.reverseWords(v_str);

    for(std::vector<char>::size_type i = 0; i<v_str.size(); ++i)
        std::cout << v_str[i];
    std::cout<< "\n";

    system("pause");

    return 0;
}