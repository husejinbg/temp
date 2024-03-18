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

#include "pokemon.h"

using namespace std;

//-------------You Can Add Your Functions Down Below-------------//

pokemon::pokemon()
{
    this->name = "";
    this->hpValue = 100;
    this->atkValue = 20;
}

pokemon::pokemon(string name, int atkValue)
{
    this->name = name;
    this->hpValue = 100;
    this->atkValue = atkValue;
}

pokemon::pokemon(const pokemon &p)
{
    this->name = p.name;
    this->hpValue = p.hpValue;
    this->atkValue = p.atkValue;
}

string pokemon::get_name()
{
    return this->name;
}

int pokemon::get_hpValue()
{
    return this->hpValue;
}

int pokemon::get_atkValue()
{
    return this->atkValue;
}


pokedex::pokedex()
{
    this->value = 0;
}

pokedex::pokedex(const pokedex &p)
{
    this->value = p.value;
    for(int i = 0; i < p.value; i++)
    {
        this->pokedexArray[i] = p.pokedexArray[i];
    }
}

void pokedex::updatePokedex(pokemon p)
{
    for(int i = 0; i < this->value; i++)
    {
        if(pokedexArray[i].get_name() == p.get_name())
        {
            // this is not a new pokemon
            return;
        }
    }
    pokedexArray[value] = p;
    value++;
}

void pokedex::printPokedex()
{
    for(int i = 0; i < this->value; i++)
    {
        cout << this->pokedexArray[i].get_name() << endl;
    }
}

player::player()
{
    this->name = "";
    this->pokemonNumber = 0;
    this->pokeballNumber = 10;
    this->badgeNumber = 0;
    this->playerPokemon = pokemon();
}

player::player(string name, const pokemon &p)
{
    this->name = name;
    this->pokemonNumber = 0;
    this->pokeballNumber = 10;
    this->badgeNumber = 0;
    this->playerPokemon = p;
}

int player::showPokemonNumber()
{
    return pokemonNumber;
}

int player::showPokeballNumber()
{
    return pokeballNumber;
}

int player::showBadgeNumber()
{
    return badgeNumber;
}

pokemon player::getPokemon()
{
    return playerPokemon;
}

void player::battleWon()
{
    badgeNumber++;
    pokeballNumber += 3;
}

void player::catchPokemon()
{
    // assuming that the player has at least 1 pokeball
    pokemonNumber++;
    pokeballNumber--;
}

enemy::enemy()
{
    this->name = "x";
    this->enemyPokemon = pokemon();
}

enemy::enemy(string name, const pokemon &p)
{
    this->name = name;
    this->enemyPokemon = p;
}

pokemon enemy::getPokemon()
{
    return enemyPokemon;
}

string enemy::getName()
{
    return name;
}




