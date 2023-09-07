#include <iostream>
#include <vector>

class replaceStringSpace {
public:
    std::string replaceSpace(std::string s) {
        std::string str;
        for(std::string::size_type i = 0; i<s.size(); ++i)
        {
            s[i]==' ' ? str+="%20" : str+=s[i];
        }
        return str;
    }
};

replaceStringSpace replaceString;

int main(void)
{
    std::string str;

    std::cout << "Please enter a string:"<< std::endl;

    std::getline(std::cin, str);

    std::cout << "the string is:"<< std::endl;

    std::cout<< str << std::endl;

    std::cout << "the string after replacing the space is:"<< std::endl;

    std::cout << replaceString.replaceSpace(str) << std::endl;

    system("pause");

    return 0;
}