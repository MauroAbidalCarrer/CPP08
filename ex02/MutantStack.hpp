#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP
# include <iostream>
# include <string>
# include <stack>

template<class T>
class MutantStack : public std::stack<T>
{
    public:
    //constructors and destructors
    MutantStack() {}
    MutantStack(const MutantStack& other)
    {
        *this = other;
    }
    ~MutantStack() {}
    //overloads
    MutantStack& operator=(const MutantStack& rhs)
    {
        static_cast<std::stack<T>&>(*this) = rhs;
        return *this;
    }
    //methods
	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin() 
	{
		return this->c.begin();
	}
	iterator end()
	{
		return this->c.end();
	}
};
#endif