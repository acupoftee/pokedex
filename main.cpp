#include <iostream>
#include "Move.h"
#include "Evolution.h"
#include "Pokemon.h"
#include "PokeDex.h"
#include "conio.h"

using namespace std;

int main() {
	cout << "Loading Pokemon" << std::endl;

	PokeDex pokeDex;
	pokeDex.initializePokemons();

	pokeDex.initializeLevelData();

	cout <<  "Loaded. Let's Begin!" << std::endl;
	
	//system("cls"); // Clear the Console

	pokeDex.launchMenu();

	return 0;
}
