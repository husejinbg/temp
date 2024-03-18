//--- 2023-2024 Spring BLG 252E Object Oriented Programing Assignment 1 ---//
//--------------------------//
//---Name & Surname:
//---Student Number:
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
#include <iostream> 
#include <stdio.h>
#include <string.h>
#include <fstream>

#include "pokemon.h"

using namespace std;

//-------------Do Not Change These Global Variables-------------//
int NAME_COUNTER = 0;   //Use this to keep track of the enemy names
int POK_COUNTER = 0;    //Use this to keep track of the pokemon names
int PLAYER_POKEMON_ATTACK = 20; //You don't have to use this variable but its here if you need it
int ENEMY_POKEMON_ATTACK = 10;  //You don't have to use this variable but its here if you need it
//--------------------------------------------------------------//

//---If Necessary Add Your Global Variables Here---// 
const int HP_VALUE = 100;
int NUMBER_OF_POKEMONS;
int NUMBER_OF_ENEMIES;
//-------------------------------------------------//

//-------------Do Not Change These Function Definitions-------------//
string* readEnemyNames(const char*);
string* readPokemonNames(const char*);
player characterCreate(string, int);
void mainMenu();
void fightEnemy(player*, string*, string*);
void catchPokemon(player*, string*);
//------------------------------------------------------------------//

//---If Necessary Add Your Function Definitions Here---// 
//
//
//
//-----------------------------------------------------//

//-------------Do Not Change This Function-------------//
int main(int argc, char* argv[]){
	system("clear");

    //---Creating Enemy and Pokemon Name Arrays---//
    string* enemyNames = readEnemyNames(argv[1]);         
    string* pokemonNames = readPokemonNames(argv[2]);
    

    string playerName;
    int pokemonChoice;

    cout << "Welcome to the Pokemon Game! \n" << endl;
    cout << "Please enter your name: "; 
    cin >> playerName;
    cout << "Please choose one of these pokemons as your pokemon: \n1- Bulbasaur \n2- Charmender \n3- Squirtle \nChoice: ";
    cin >> pokemonChoice;

    //---Character Creation--//
    player newPlayer = characterCreate(playerName, pokemonChoice);
    
    int menuChoice;

    while(true){
        mainMenu(); 
        cin>>menuChoice;

        switch (menuChoice){
        case 1:
            fightEnemy(&newPlayer, enemyNames, pokemonNames);
            break;
        case 2:
            catchPokemon(&newPlayer, pokemonNames);
            break;
        case 3:
            cout<<newPlayer.showPokemonNumber()<<endl;
            break;
        case 4:
            cout<<newPlayer.showPokeballNumber()<<endl;
            break;
        case 5:
            cout<<newPlayer.showBadgeNumber()<<endl;
            break;
        case 6:
            cout << endl;
            cout << "------- Pokedex -------" <<endl;
            newPlayer.playerPokedex.printPokedex();
            break;
        case 7:
            //---Deletes Dynamic Arrays From Memory and Exits---//
            delete[] enemyNames;
            delete[] pokemonNames;
            return EXIT_SUCCESS;
            break;
  
        default:
            cout << "Please enter a valid number!!!" << endl;
            break;
        }
    }
    return EXIT_FAILURE;
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
string* readEnemyNames(const char* argv)
{
    ifstream fin(argv);
    fin >> NUMBER_OF_ENEMIES;
    string* enemyNames = new string[NUMBER_OF_ENEMIES];
    for(int i = 0; i < NUMBER_OF_ENEMIES; i++)
    {
        fin >> enemyNames[i];
    }
    fin.close();
    return enemyNames;
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
string* readPokemonNames(const char* argv)
{
    ifstream fin(argv);
    fin >> NUMBER_OF_POKEMONS;
    string* pokemonNames = new string[NUMBER_OF_POKEMONS];
    for(int i = 0; i < NUMBER_OF_POKEMONS; i++)
    {
        fin >> pokemonNames[i];
    }
    fin.close();
    return pokemonNames;
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
player characterCreate(string playerName, int pokemonChoice){
    string pokemonName = "";
    if(pokemonChoice == 1)
    {
        pokemonName = "Bulbasaur";
    }
    else if(pokemonChoice == 2)
    {
        pokemonName = "Charmender";
    }
    else if(pokemonChoice == 3)
    {
        pokemonName = "Squirtle";
    }
    pokemon p(pokemonName, PLAYER_POKEMON_ATTACK);
    player plyr(playerName, p);
    return plyr;
};
//--------------------------------------------//

//-------------Do Not Change This Function-------------//
void mainMenu(){
    cout << endl;
    cout << "-------- Menu --------" << endl;
    cout << "1. Fight for a badge" << endl;
    cout << "2. Catch a Pokemon" << endl;
    cout << "3. Number of Pokemons" << endl;
    cout << "4. Number of Pokeballs " << endl;
    cout << "5. Number of Badges" << endl;
    cout << "6. Pokedex" << endl;
    cout << "7. Exit" << endl;
    cout << endl;
    cout << "Choice: ";
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
void fightEnemy(player* newPlayer, string* enemyNames, string* pokemonNames)
{
    int enemyIndex = NAME_COUNTER++;
    int pokemonIndex = POK_COUNTER++;
    string enemyPokemonName = pokemonNames[pokemonIndex];
    string enemyName = enemyNames[enemyIndex];
    pokemon p(enemyPokemonName, ENEMY_POKEMON_ATTACK);
    player enemy(enemyName, p);
    newPlayer->playerPokedex.updatePokedex(p);

    int playerPokemonHP = newPlayer->getPokemon().get_hpValue();
    int enemyPokemonHP = enemy.getPokemon().get_hpValue();

    cout << "You encounter with " << enemyName << " and his/hers pokemon " << enemyPokemonName << endl;

    cout << enemyPokemonName << " Health: " << enemyPokemonHP << " Attack: " << p.get_atkValue() << endl;

    while(playerPokemonHP > 0 && enemyPokemonHP > 0)
    {
        int choice;
        cout << endl;
        cout << "1- Fight" << endl;
        cout << "2- Runaway" << endl;   
        cout << "Choice: ";

        cin >> choice;
        if(choice == 1)
        {
            playerPokemonHP -= enemy.getPokemon().get_atkValue();
            enemyPokemonHP -= newPlayer->getPokemon().get_atkValue();
        }
        else if(choice == 2)
        {
            cout << "You ranaway" << endl;

            return;
        }
        else
        {
            cout << "Please enter a valid number!" << endl;
            cout << "Choice: ";
        }

        cout << "Your Pokemons Health: " << playerPokemonHP << endl;
        cout << enemyName << " Pokemons Health: " << enemyPokemonHP << endl;
    }

    if(newPlayer->getPokemon().get_hpValue() > 0)
    {
        newPlayer->battleWon();
        cout << "You Won!" << endl;
    }
    else
    {
        cout << "You Lost!" << endl;
    }
};
//--------------------------------------------//

//-------------Code This Function-------------//
void catchPokemon(player* newPlayer, string* pokemonNames)
{
    // assuming that the player has at least 1 pokeball
    int pokemonIndex = POK_COUNTER++;
    pokemon p(pokemonNames[pokemonIndex], ENEMY_POKEMON_ATTACK);
    newPlayer->playerPokedex.updatePokedex(p);

    cout << "You encounter with " << p.get_name() << " Health: " << p.get_hpValue() << " Attack: " << p.get_atkValue() << endl;

    int choice;
    cout << endl;
    cout << "1- Catch" << endl;
    cout << "2- Runaway" << endl;
    cout << "Choice: ";
    cin >> choice;
    if(choice == 1)
    {
        newPlayer->catchPokemon();
        cout << "You catch " << p.get_name() << endl;
    }
    else if(choice == 2)
    {
        cout << "You ranaway" << endl;
    }
    else
    {
        cout << "Please enter a valid number!" << endl;
        cout << "Choice: ";
    }

};
//--------------------------------------------//
