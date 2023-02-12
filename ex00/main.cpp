# include <algorithm>
# include <iterator>
# include <iostream>
# include <list>
# include <vector>
# include <string>
# include <cstdlib>
# include "easyfind.hpp"


int main(int ac, char **av)
{
    (void)ac;
    std::vector<int> vec;
    for (int i = 3; i < 20; i += 2)
    {
        std::cout << i << std::endl;
        vec.push_back(i);
    }
    if (ac > 1)
        easyfind(vec, atoi(av[1]));
}