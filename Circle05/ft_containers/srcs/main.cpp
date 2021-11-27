#include "test.hpp"
#include "color.hpp"
#include <iostream>
#include <string.h>

int main(int argc, char **argv)
{

    int i = 1;

    std::cout << GREEN << "=-=--=-=-=-=-=-=--=-=-=-=-=-=--=-=-=-=-=-=-=--=-=-=-=-=--=-=-=-=-=-=-" << std::endl << std::endl;
    if (argc < 2)
    {
        std::cout << "[MANUAL]" << std::endl;
        std::cout << "./ft_containers [container name1] [container name2] ..." << RESET << std::endl;
    }
    else
    {
        while(i < 4)
        {
            if (!strcmp(argv[i], "vector"))
                test_vector();
            else if (!strcmp(argv[i], "stack"))
                test_stack();
            else if (!strcmp(argv[i], "map"))
                test_map();
            i++;
        }
    }
	return 0;
}
