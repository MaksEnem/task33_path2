#include <iostream>
#include <ctime>

enum Pond
{
    emptySector,
    fish,
    boot   
};

void initializationField(int field[], int const SIZE)
{
    for (int i = 0; i < SIZE; ++i)
    {
        field[i] = Pond::emptySector;
    }

    for (int i = 0; i < 3; ++i)
    {
        int randomValue = rand() % 9;
        if (field[randomValue] == Pond::emptySector)
        {
            field[randomValue] = Pond::fish;
        }
        else
        {
            --i;
        }
    }

    for (int i = 0; i < 3; ++i)
    {
        int randomValue = rand() % 9;
        if (field[randomValue] == Pond::emptySector)
        {
            field[randomValue] = Pond::boot;
        }
        else
        {
            --i;
        }
    }
}

int main()
{
    std::srand(std::time(nullptr));
    int const SIZE = 10;
    int field[SIZE];
    
    initializationField(field, SIZE);





    for (int i = 0; i < SIZE; ++i)
    {
        if (field[i] == Pond::boot)
        {
            std::cout << "Boot" << std::endl;
        }
        else if (field[i] == Pond::emptySector)
        {
            std::cout << "Empty sector" << std::endl;
        }
        else if (field[i] == Pond::fish)
        {
            std::cout << "Fish" << std::endl;
        }        
    }

   

    return 0;
}