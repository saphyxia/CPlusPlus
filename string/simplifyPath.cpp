#include <iostream>
#include <vector>

class simplifyPathClass {
public:
    std::string simplifyPath(std::string path) {
        auto split = [](const std::string& s, char delim) -> std::vector<std::string> {
            std::vector<std::string> ans;
            std::string cur;
            for (char ch: s) {
                if (ch == delim) {
                    ans.push_back(move(cur));
                    cur.clear();
                }
                else {
                    cur += ch;
                }
            }
            ans.push_back(move(cur));
            return ans;
        };

        std::vector<std::string> names = split(path, '/');
        std::vector<std::string> stack;
        for (std::string& name: names) {
            if (name == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            }
            else if (!name.empty() && name != ".") {
                stack.push_back(move(name));
            }
        }
        std::string ans;
        if (stack.empty()) {
            ans = "/";
        }
        else {
            for (std::string& name: stack) {
                ans += "/" + move(name);
            }
        }
        return ans;
    }
};

simplifyPathClass stringSimplifyPath;

int main(void)
{
    std::string str;

    std::cout << "Please enter a path:"<< std::endl;

    std::getline(std::cin, str);

    std::cout << "the path is:"<< str << std::endl;

    std::cout << "the simplifypath is:"<< stringSimplifyPath.simplifyPath(str) << std::endl;

    system("pause");

    return 0;
}