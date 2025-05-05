#include <iostream>
#include <memory>

void newArray ()
{
    int size;

    std::cout << "Give a size for the array: ";
    std::cin >> size;

    int* numbers = new int[size];

    for (int i = 0; i < size; ++i) 
    {
        std::cout << "Enter a value: ";
        std::cin >> numbers[i];
    }

    std::cout << "You entered: \n";
    for (int i = 0; i < size; ++i)
    {
        std::cout << numbers[i] << "\n";
    }

    delete[] numbers;

}

void uniquePTR() {
    int size;

    std::cout << "Give a size for the array: ";
    std::cin >> size;

    std::unique_ptr<int[]> numbers = std::make_unique<int[]>(size);

    for (int i = 0; i < size; ++i) 
    {
        std::cout << "Enter a value: ";
        std::cin >> numbers[i];
    }

    std::cout << "You entered: \n";
    for (int i = 0; i < size; ++i)
    {
        std::cout << numbers[i] << "\n";
    }

}

int main() {
    int state;
    std::cout << "1 for new/array or 2 for unique_ptr<int[]>: \n";
    std::cin >> state;

    if (state == 1)
    {
        newArray();
    } else if (state == 2)
    {
        uniquePTR();
    } else {
        std::cout << "Incorrect Input Detected\n";
    }
    
    return 0;
}
