#include <iostream>
#include <cstdio>>
#include <string>

int main()
{
    std::string s, x;
    int c = 0;
    std::getline(std::cin, s);
    x = "#" + s;
    for (int i = 0; i < x.length(); i++)
    {
        if ((x[i] != ' ') && (x[i] >= 97) && (c == 0))
        {
            x[i] -= 32;
            c++;
        }
        if ((x[i] == ' ') && (x[i + 1] != ' '))
        {
            x[i + 1] -= 32;
        }
    }
    x.erase(std::remove_if(x.begin(), x.end(), isspace), x.end());
    if ((x.length() > 100) || (x.length() == 1))
    {
        std::cout << "<Exception>";
    }
    else
        std::cout << x;
}
