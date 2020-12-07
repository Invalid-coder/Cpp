#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

struct SpaceShip
{
    int x;
    int y;
    int id;
    bool inField;
};

const int WIDTH = 1024;
const int HEIGHT = 768;

int random_range(int low,int high)
{
    return rand() % (high - low + 1) + low;
}

int amount = random_range(0,10);
SpaceShip ships[10];
void simulation();


int main()
{
    srand((unsigned int)time(NULL));
    simulation();

    return 0;
}

SpaceShip getNewShip(int id)
{
    SpaceShip ship;
    ship.x = random_range(0,WIDTH);
    ship.y = random_range(0,HEIGHT);
    ship.id = id;
    ship.inField = true;

    return ship;
}

SpaceShip moveShip(SpaceShip ship)
{
    int option = random_range(0,3);

    if(option == 0)
    {
        ship.x += random_range(0,100);
        ship.y += random_range(0,100);
    }
    else if(option == 1)
    {
        ship.x -= random_range(0,100);
        ship.y -= random_range(0,100);
    }
    else if(option == 2)
    {
        ship.x += random_range(0,100);
        ship.y -= random_range(0,100);
    }
    else if(option == 1)
    {
        ship.x -= random_range(0,100);
        ship.y += random_range(0,100);
    }

    return ship;
}

void printShipData(SpaceShip ship)
{
    cout << "id = " << ship.id << " Coordinates: x = " << ship.x << " y = " << ship.y << endl;
}

void initialize_ships(int amount)
{
    for(int i = 0; i < amount; i++)
    {
        ships[i] = getNewShip(i+1);
    }
}

bool empty_field()
{
    int beyond = 0;

    for(int i = 0; i < amount; i++)
    {
        if((ships[i].x > WIDTH || ships[i].x < 0) || (ships[i].y > HEIGHT || ships[i].y < 0))
        {
            beyond++;
        }
    }

    if(beyond == amount)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool breaking_border(SpaceShip ship)
{
    if((ship.x > WIDTH || ship.x < 0) || (ship.y > HEIGHT || ship.y < 0))
    {
        return true;
    }

    return false;
}

void simulation()
{
    initialize_ships(amount);

    cout << "Amount of ships = " << amount << endl;

    while (!empty_field())
    {
        int ship = random_range(0,amount);

        if(!ships[ship].inField){continue;}

        cout << "Initial data: ";
        printShipData(ships[ship]);

        ships[ship] = moveShip(ships[ship]);

        cout << "New data: ";
        printShipData(ships[ship]);

        if(breaking_border(ships[ship]))
        {
            ships[ship].inField = false;
            cout << "Ship id = " << ships[ship].id<< " crossed the border" << endl;
        }

        cout << endl;
    }

    cout << "Simulation was finished successfully!";
}
