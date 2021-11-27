#include "map.hpp"
#include "color.hpp"
#include <map>
#include <string>
#include <vector>

void test_map_basic(ft::map<int, std::string> &test, std::map<int, std::string> &std_map)
{
    std::cout << BLUE << "------[[FT]]------" << RESET << std::endl;
	std::cout << CYAN << "size: " << test.size() << std::endl;
	std::cout << "[value]" << std::endl;
	ft::map<int, std::string>::iterator ite = test.end();
	for (ft::map<int, std::string>::iterator it = test.begin(); it != ite; it++)
		std::cout << it->first << ": " << it->second << std::endl;
	std::cout << RESET;

    std::cout << BLUE << "------[[STD]]------" << RESET << std::endl;
	std::cout << CYAN <<"size: " << std_map.size() << std::endl;
	std::cout << "[value]" << std::endl;
	std::map<int, std::string>::iterator std_ite = std_map.end();
	for (std::map<int, std::string>::iterator std_it = std_map.begin(); std_it != std_ite; std_it++)
		std::cout << std_it->first << ": " << std_it->second << std::endl;
	std::cout << RESET << std::endl;

    std::cout << BLUE << "------[[FT]]------" << RESET << std::endl;
	test[-3] = "hey";
	test[5] = "mama";
    test[13] = "changed";
	std::cout << CYAN << "test.find(4)'s value is " << test.find(4)->second << std::endl;
	std::cout << "test.equal_range(7): " << test.equal_range(7).first->first << " ~ " << test.equal_range(7).second->first << RESET << std::endl;
	test.erase(++test.begin());
	test.erase(--(--test.end()));

    std::cout << BLUE << "------[[STD]]------" << RESET << std::endl;
	std_map[-3] = "hey";
	std_map[5] = "mama";
    std_map[13] = "changed";
	std::cout << CYAN << "std.find(4)'s value is " << std_map.find(4)->second << std::endl;
	std::cout << "std.equal_range(7): " << std_map.equal_range(7).first->first << " ~ " << std_map.equal_range(7).second->first << std::endl;
	std_map.erase(++std_map.begin());
	std_map.erase(--(--std_map.end()));
    std::cout << RESET << std::endl;

    std::cout << BLUE << "------[[FT]]------" << RESET << std::endl;
	std::cout << CYAN << "size: " << test.size() << std::endl;
	std::cout << "[value]" << std::endl;
	ite = test.end();
	for (ft::map<int, std::string>::iterator it = test.begin(); it != ite; it++)
		std::cout << it->first << ": " << it->second << std::endl;
	std::cout << RESET;

    std::cout << BLUE << "------[[STD]]------" << RESET << std::endl;
	std::cout << CYAN << "size: " << std_map.size() << std::endl;
	std::cout << "[value]" << std::endl;
	std_ite = std_map.end();
	for (std::map<int, std::string>::iterator std_it = std_map.begin(); std_it != std_ite; std_it++)
		std::cout << std_it->first << ": " << std_it->second << std::endl;
	std::cout << RESET << std::endl;
}

void test_map()
{
	std::cout << MAGENTA << "[map] - initialize test" << std::endl;
	std::vector< std::pair<const int, std::string> > initial_vec;
	for(int i = 0; i < 10; i++)
		initial_vec.push_back(std::pair<const int, std::string>(i, std::string(1, 'A' + i)));

	ft::map<int, std::string> int_string_map(initial_vec.begin(), initial_vec.end());
	std::map<int, std::string> int_string_map_std(initial_vec.begin(), initial_vec.end());
	test_map_basic(int_string_map, int_string_map_std);

    std::cout << GREEN << "=-=--=-=-=-=-=-=--=-=-=-=-=-=--=-=-=-=-=-=-=--=-=-=-=-=--=-=-=-=-=-=-" << RESET << std::endl;
}
