#include <iostream>
#include <cctype>


int main(int ac, char **av)
{
    int i = 0;
    if (ac == 1)
    {
        std::cout <<  "* LOUD AND UNBEARABLE FEEDBACK NOISE *"<< std::endl;
        return 0;
    }
    while(av[++i])
    {
        int j = -1;
        while (av[i][++j])
        {
            char uppercase_char = std::toupper(av[i][j]);
            std::cout << uppercase_char;
        }
    }
    std::cout <<  std::endl;
    return 0;
}
