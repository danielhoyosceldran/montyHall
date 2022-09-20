#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <unordered_map>
#include "../GeneradorCout/coutGenerator.h"

using namespace std;

#define NUM_PORTES 3

//int randNum(int maxVal) { return 1 + rand() % (maxVal); }
int simulationGame(int numSimulation, bool changeDoor)
{
    int wins = 0;
    for (int i = 0; i < numSimulation; i++)
    {
        int winningDoor = 1 + rand() % NUM_PORTES;
        int chosenDoor  = 1 + rand() % NUM_PORTES;

        int openDoor;
        do
        {
            openDoor   = 1 + rand() % NUM_PORTES;
        } while (openDoor == winningDoor || openDoor == chosenDoor);

        if (changeDoor)
        {
            bool doors[3] = { false };
            doors[chosenDoor - 1]  = true;
            doors[openDoor - 1]   = true;
            do
            {
                chosenDoor = ((chosenDoor) % 3) + 1;
            } while (doors[chosenDoor - 1]);
        }
        if (chosenDoor == winningDoor) wins++;
    }
    return wins;
}

int charToInt(char *argv)
{
    int value = 0;
    int i = 0;

    while (argv[i] != '\0')
    {
        value *= 10;
        value += (int)argv[i] - '0';
        i++;
    }

    return value;
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    cout << endl;
    int numSim;
    
    if (argc < 2)   numSim = 100;
    else
    {
        if (((int)*argv[1] - '0') < 1)  return -1; // argv error
        numSim = charToInt(argv[1]);
    }

    cout << "Number of simulations: " << numSim << endl;

    // wpc = winning percent
    float wpcChanging     = simulationGame(numSim, true) / (float)numSim * 100;
    float wpcNoChanging   = simulationGame(numSim, false) / (float)numSim * 100;

    cout << "Winning chance changin yout door with " << numSim << " simulations: " << wpcChanging << "%" << endl;
    cout << "Winning chance not changin your door with " << numSim << " simulations: " << wpcNoChanging << "%" << endl;

    cout << endl;
    
    return 0;
}