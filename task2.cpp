#include <iostream>
#include <exception>
#include <ctime>

enum Pond
{
    emptySector,
    fish,
    boot   
};

void initializationField(int inField[], int const inSIZE)
{    
    for (int i = 0; i < inSIZE; ++i)
    {
        inField[i] = Pond::emptySector;
    }

    int randomValue;
    for (int i = 0; i < 3; ++i)
    {
        randomValue = rand() % 9;
        if (inField[randomValue] == Pond::emptySector)
        {
            inField[randomValue] = Pond::fish;
        }
        else {--i;}
    }

    for (int i = 0; i < 3; ++i)
    {
        randomValue = rand() % 9;
        if (inField[randomValue] == Pond::emptySector)
        {
            inField[randomValue] = Pond::boot;
        }
        else {--i;}
    }
}

void game(int inField[], int inSector)
{
    if (inField[inSector] == Pond::emptySector)
    {
        std::cout << "You have reached an empty sector, try again!" << std::endl;
    }
    else if (inField[inSector] == Pond::boot)
    {
        throw "You caught the boot! You lost!";
    }
    else if (inField[inSector] == Pond::fish)
    {
        throw "You caught a fish! You won!";
    }
}

int main()
{
    std::srand(std::time(nullptr));
    int const SIZE = 10;
    int field[SIZE];
    int sector;
    initializationField(field, SIZE);   

    bool is_game = true;
    do {
        std::cout << "Enter a sector number from 1 to 10: ";
        std::cin >> sector;
        --sector;       

        try 
        {
            game(field, sector);
        }
        catch (const char* msg)
        {
            std::cout << msg << std::endl;
            is_game = false;
        }
    } while (is_game);   

    return 0;
}