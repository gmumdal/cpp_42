#include <iostream>
#include <Array.hpp>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    const Array<int> number(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //deep copy check
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
        try {
            for (int i = 0; i < MAX_VAL; i++) {
                const int value = rand();
                tmp[i] = value;
                test[i] = value;
                if (tmp[i] == numbers[i] || test[i] == numbers[i]) {
                    throw std::logic_error("copy array modify original array!");
                }
            }
            std::cout << "deep copy ok!" << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
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
    std::cout << "const check : " << number[0] << std::endl;
    delete [] mirror;
    return 0;
}