#include <iostream>
#include<unordered_map>

class Isomorphic {
public:
    bool isIsomorphic(std::string s, std::string t)
    {
        std::unordered_map<char, char> s2t;
        std::unordered_map<char, char> t2s;
        
        int len = s.length();

        for (int i = 0; i < len; ++i) {
            char x = s[i], y = t[i];
            if ((s2t.count(x) && s2t[x] != y) || (t2s.count(y) && t2s[y] != x)) {
                return false;
            }
            s2t[x] = y;
            t2s[y] = x;
        }
        return true;
    }
};

Isomorphic stringIsomorphic;

int main(void)
{
    std::string str[2];

    std::cout << "Please enter a string:"<< std::endl;

    std::getline(std::cin, str[0]);

    std::cout << "Please enter the another string:"<< std::endl;

    std::getline(std::cin, str[1]);

    std::cout << "the first string is:"<< std::endl;

    std::cout << str[0] << std::endl;

    std::cout << "another string is:"<< std::endl;

    std::cout << str[1] << std::endl;

    std::cout << "These two strings are isomorphic strings:" << std::boolalpha << stringIsomorphic.isIsomorphic(str[0],str[1]) << std::endl;

    system("pause");

    return 0;
}
