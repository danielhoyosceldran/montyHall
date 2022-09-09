#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <unordered_map>
#include "../GeneradorCout/coutGenerator.h"

using namespace std;

#define NUM_PORTES 3

//int randNum(int maxVal) { return 1 + rand() % (maxVal); }
int game(int numSimulation, bool changeDoor)
{
    for (int i = 0; i < numSimulation; i++)
    {
        int winningDoor   = 1 + rand() % NUM_PORTES;
        int chosenDoor  = 1 + rand() % NUM_PORTES;
        int openDoor;
        do
        {
            openDoor   = 1 + rand() % PORTES;
        } while (openDoor == winningDoor || openDoor == portaEscollida);

        if (changeDoor)
        {
            bool doors[3] = { false };
            doors[chosenDoor - 1]  = true;
            doors[openDoor - 1]   = true;

            do
            {
                chosenDoor = ((chosenDoor) % 3) + 1;
            } while (!doors[chosenDoor - 1]);
        }
    }
}

int charToInt(char *argv[])
{
    int value = 0;
    int i = 0;

    while (argv[1][i] != '\0')
    {
        value *= 10;
        value += (int)argv[1][i] - '0';
        i++;
    }

    return value;
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    if (((int)*argv[1] - '0') < 1) return -1; // arg error  
    
    return 0;
}