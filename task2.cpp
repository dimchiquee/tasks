#include <iostream>
#include <cstdio>>
#include <string>

int main()
{
    int z = 0;
    std::string s, x;
    std::getline(std::cin, s);
    x = "#" + s;
    for (int i = 0; i < x.length(); i++)
    {
        if ((x[i + 1] != ' ') && (x[i] == ' '))
        {
            x[i + 1] -= 32;
        }
        if ((x[i] != ' ') && (x[i] >= 97) && (z == 0))
        {
            x[i] -= 32;
            z++;
        }
    }
    x.erase(std::remove_if(x.begin(), x.end(), isspace), x.end());
    if ((x.length() == 1) || (x.length() > 100))
    {
        std::cout << "<Exception>";
    }
    else
        std::cout << x;
}
