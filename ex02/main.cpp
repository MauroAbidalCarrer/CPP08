#include"MutantStack.hpp"
#include <list>

int main()
{
    std::cout << "**************** Test with MutantStack ****************" << std::endl;
	std::cout << "\n****** Push some values and display top value ******" << std::endl;
	MutantStack<int> mutant_stack;
	std::list<int> list_stack;

	mutant_stack.push(5);
	list_stack.push_back(5);

	mutant_stack.push(17);
	list_stack.push_back(17);

	std::cout << mutant_stack.top() << std::endl;
	std::cout << list_stack.back() << std::endl;

	std::cout << "\n****** remove top value and display size ******" << std::endl;
	mutant_stack.pop();
	list_stack.pop_back();

	std::cout << mutant_stack.size() << std::endl;
	std::cout << list_stack.size() << std::endl;

	std::cout << "\n****** push some values and use iterators to iterate and show ******" << std::endl;
	mutant_stack.push(3);
	list_stack.push_back(3);

	mutant_stack.push(5);
	list_stack.push_back(5);

	mutant_stack.push(737);
	list_stack.push_back(737);

	mutant_stack.push(0);
	list_stack.push_back(0);

	MutantStack<int>::iterator it = mutant_stack.begin();
	std::list<int>::iterator it2 = list_stack.begin();

	MutantStack<int>::iterator ite = mutant_stack.end();
	std::list<int>::iterator ite2 = list_stack.end();

	++it;
	++it2;

	--it;
	--it2;

	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;

	while (it2 != ite2)
	{
		std::cout << *it2 << " ";
		++it2;
	}
	std::cout << std::endl;

	std::cout << "\n****** create a stack from MutantStack. Can not be iterated ! (nothing to show) ******" << std::endl;
	std::stack<int> stack_from_mutant(mutant_stack);

	std::cout << "\n****** do it again with MutantStack from MutantStack and show using an elegant iteration ******" << std::endl;
	std::cout << "\n****** also create a std::list from std::list and show" << std::endl;
	MutantStack<int> mutant_stack_copy(mutant_stack);
	std::list<int> list_stack_copy(list_stack);

	for (MutantStack<int>::iterator mutant_stack_iterator = mutant_stack_copy.begin(); mutant_stack_iterator != mutant_stack_copy.end(); mutant_stack_iterator++)
		std::cout << *mutant_stack_iterator << " ";
	std::cout << std::endl;

	for (std::list<int>::iterator list_stack_iterator = list_stack_copy.begin(); list_stack_iterator != list_stack_copy.end(); list_stack_iterator++)
		std::cout << *list_stack_iterator << " ";
	std::cout << std::endl;
}