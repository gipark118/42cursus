#include "vector.hpp"
#include "color.hpp"
#include <vector>

void test_vector_basic(ft::vector<int> &test, std::vector<int> &std_vec)
{
	std::cout << BLUE << "------[[FT]]------" << RESET << std::endl;
	std::cout << CYAN << "size: " << test.size() << std::endl;
	std::cout << "[value]" << std::endl;
	ft::vector<int>::iterator ite = test.end();
	for (ft::vector<int>::iterator it = test.begin(); it != ite; it++)
		std::cout << *it << " ";
	std::cout << RESET << std::endl;

	std::cout << BLUE << "------[[STD]]------" << RESET << std::endl;
	std::cout << CYAN <<"size: " << std_vec.size() << std::endl;
	std::cout << "[value]" << std::endl;
	std::vector<int>::iterator std_ite = std_vec.end();
	for (std::vector<int>::iterator std_it = std_vec.begin(); std_it != std_ite; std_it++)
		std::cout << *std_it << " ";
	std::cout << RESET << std::endl << std::endl;

	test[1] = 1;
	test[3] = 3;
	test.insert(test.begin(), 100);
	test.insert(test.begin() + 2, 3, 5);
	std_vec[1] = 1;
	std_vec[3] = 3;
	std_vec.insert(std_vec.begin(), 100);
	std_vec.insert(std_vec.begin() + 2, 3, 5);

	std::cout << BLUE << "------[[FT]]------" << RESET << std::endl;
	std::cout << CYAN << "size: " << test.size() << std::endl;
	std::cout << "[rvalue]" << std::endl;
	ft::vector<int>::const_reverse_iterator cite = test.rend();
	for (ft::vector<int>::const_reverse_iterator cit = test.rbegin(); cit != cite; cit++)
		std::cout << *cit << " ";
	std::cout << RESET << std::endl;

	std::cout << BLUE << "------[[STD]]------" << RESET << std::endl;
    std::cout << CYAN << "size: " << std_vec.size() << std::endl;
	std::cout << "[rvalue]" << std::endl;
	std::vector<int>::const_reverse_iterator std_cite = std_vec.rend();
	for (std::vector<int>::const_reverse_iterator std_cit = std_vec.rbegin(); std_cit != std_cite; std_cit++)
		std::cout << *std_cit << " ";
	std::cout << RESET << std::endl << std::endl;
}

void test_vector()
{
	std::cout << MAGENTA << "[vector] - initialize test" << RESET << std::endl;
	ft::vector<int> int_vector(5);
	std::vector<int> int_vector_std(5);
	test_vector_basic(int_vector, int_vector_std);

	std::cout << MAGENTA << "[vector] - value test" << RESET << std::endl;
	ft::vector<int> int_vector_val_ten(5, 10);
	std::vector<int> int_vector_val_ten_std(5, 10);
	test_vector_basic(int_vector_val_ten, int_vector_val_ten_std);

    std::cout << MAGENTA << "[vector] - assign_test" << RESET << std::endl;
	ft::vector<int> assign_test;
	std::vector<int> assign_test_std;
	assign_test.assign(int_vector_val_ten.begin(), int_vector_val_ten.end());
	assign_test_std.assign(int_vector_val_ten_std.begin(), int_vector_val_ten_std.end());
	test_vector_basic(assign_test, assign_test_std);

    std::cout << MAGENTA << "[vector] - insert_test" << RESET << std::endl;
	int_vector_val_ten.insert(int_vector_val_ten.begin() + 3, int_vector.begin(), int_vector.end());
	int_vector_val_ten_std.insert(int_vector_val_ten_std.begin() + 3, int_vector_std.begin(), int_vector_std.end());
	test_vector_basic(int_vector_val_ten, int_vector_val_ten_std);

    std::cout << GREEN << "=-=--=-=-=-=-=-=--=-=-=-=-=-=--=-=-=-=-=-=-=--=-=-=-=-=--=-=-=-=-=-=-" << RESET << std::endl;
}
