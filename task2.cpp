#include <iostream>
#include <exception>
#include <ctime>

enum Pond
{
    emptySector,
    fish,
    boot   
};

class BootException : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "You caught the boot! You lost!";
    }
};

class FishException : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "You caught a fish! You won!";
    }
};

void initializationField(int inField[], int const inSIZE)
{    
    for (int i = 0; i < inSIZE; ++i)
    {
        inField[i] = Pond::emptySector;
    }

    int randomValue;    
    randomValue = rand() % 9;
    inField[randomValue] = Pond::fish;

    for (int i = 0; i < 3; ++i)
    {
        randomValue = rand() % 9;
        if (inField[randomValue] == Pond::emptySector)
        {
            inField[randomValue] = Pond::boot;
        }
        else {--i;}
    }        
    /*for (int i = 0; i < inSIZE; ++i)
    {
        std::cout << i + 1 << " " <<  inField[i] << std::endl;
    }*/
}

void game(int inField[], int inSector)
{
    if (inField[inSector] == Pond::emptySector)
    {
        std::cout << "You have reached an empty sector, try again!" << std::endl;
    }
    else if (inField[inSector] == Pond::boot)
    {
        throw BootException();
    }
    else if (inField[inSector] == Pond::fish)
    {
        throw FishException();
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
        catch (const BootException& x)
        {
            std::cerr << x.what() << std::endl;
            is_game = false;
        }
        catch (const FishException& x)
        {
            std::cerr << x.what() << std::endl;
            is_game = false;
        }
        catch (...)
        {
            std::cerr << "Some kind of exception has happened ..." << std::endl;
        }
    } while (is_game);   

    return 0;
}