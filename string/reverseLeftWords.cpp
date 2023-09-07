#include <iostream>


class leftWords {
public:
    std::string reverseLeftWords(std::string s, int n)
    {
        if(s.size()==0)
            return s;

        std::string substr = s.substr(0,n);

        std::string res = s.substr(n,s.size()-n)+substr;

        return res;
    }
};

leftWords leftWordsString;

int main(void)
{
    std::string str;

    uint16_t n = 0;

    std::cout << "Please enter a string:"<< std::endl;

    std::getline(std::cin, str);

    std::cout << "the string is:"<< std::endl;

    std::cout<< str << std::endl;

    std::cout << "Please enter the index of leftWords:"<< std::endl;

    std::cin >> n;  

    std::cout << "the leftWords is:"<< std::endl;

    std::cout << leftWordsString.reverseLeftWords(str,n) << std::endl;

    system("pause");

    return 0;
}

