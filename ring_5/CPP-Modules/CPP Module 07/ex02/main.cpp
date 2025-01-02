#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    {

        Array<int> numbers(MAX_VAL);
        Array<int> array(3);
        numbers[0] = 0;
        numbers[1] = 1;
        numbers[2] = 2;
        Array<int> algo(array);

        std::cout << numbers[0] << std::endl;
        std::cout << numbers[1] << std::endl;
        std::cout << numbers[2] << std::endl;

    }
    {
        Array<int> numbers(MAX_VAL);
        int* mirror = new int[MAX_VAL];
        srand(time(NULL));
        for (int i = 0; i < MAX_VAL; i++)
        {
            const int value = rand();
            numbers[i] = value;
            mirror[i] = value;
        }
        //SCOPE
        {
            Array<int> tmp = numbers;
            Array<int> test(tmp);
        }

        for (int i = 0; i < MAX_VAL; i++)
        {
            if (mirror[i] != numbers[i])
            {
                std::cerr << "didn't save the same value!!" << std::endl;
                return 1;
            }
        }
        try
        {
            numbers[-2] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            numbers[MAX_VAL] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        for (int i = 0; i < MAX_VAL; i++)
        {
            numbers[i] = rand();
        }
        delete [] mirror;//
        return 0;
    }
}