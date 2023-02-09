#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <algorithm>
# include <iterator>
# include <iostream>
# include <list>
# include <vector>
# include <string>
# include <cstdlib>

template<typename T> void easyfind(T intContainer, int toFind)
{
    typename T::iterator findRet = find(intContainer.begin(), intContainer.end(), toFind);
    if (findRet == intContainer.end())
        std::cout << "Container does not contains " << toFind << "." << std::endl;
    else
        std::cout << "Container contains " << toFind << "." << std::endl;
}

#endif