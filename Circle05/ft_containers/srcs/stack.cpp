#include "stack.hpp"
#include "color.hpp"
#include <stack>

void test_stack_basic(ft::stack<int> &test, std::stack<int> &std_test)
{
	std::cout << BLUE << "------[[FT]]------" << RESET << std::endl;
	std::cout << CYAN << "size: " << test.size() << RESET << std::endl;

    std::cout << BLUE << "------[[STD]]------" << RESET << std::endl;
	std::cout << CYAN << "size: " << std_test.size() << RESET << std::endl << std::endl;


	test.push(10);
	test.push(20);
	test.push(30);
	test.top() -= 4;
    std::cout << BLUE << "------[[FT]]------" << RESET << std::endl;
	std::cout << CYAN << "top: " << test.top() << std::endl;
	test.pop();
	test.pop();
	std::cout << "top: " << test.top() << RESET << std::endl;

	std_test.push(10);
	std_test.push(20);
	std_test.push(30);
	std_test.top() -= 4;
    std::cout << BLUE << "------[[STD]]------" << RESET << std::endl;
	std::cout << CYAN << "top: " << std_test.top() << std::endl;
	std_test.pop();
	std_test.pop();
	std::cout << "top: " << std_test.top() << RESET << std::endl << std::endl;


    std::cout << BLUE << "------[[FT]]------" << RESET << std::endl;
	std::cout << CYAN << "size: " << test.size() << RESET << std::endl;

    std::cout << BLUE << "------[[STD]]------" << RESET << std::endl;
	std::cout << CYAN << "size: " << std_test.size() << std::endl;
	std::cout << RESET << std::endl;
}

void test_stack()
{
	std::cout << MAGENTA << "[stack] - initialize test" << RESET << std::endl;
	ft::stack<int> int_stack;
	std::stack<int> int_stack_std;
	test_stack_basic(int_stack, int_stack_std);

    std::cout << GREEN << "=-=--=-=-=-=-=-=--=-=-=-=-=-=--=-=-=-=-=-=-=--=-=-=-=-=--=-=-=-=-=-=-" << RESET << std::endl;
}
