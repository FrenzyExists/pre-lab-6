#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum pkmType
{
    NONETYPE,
    WATER,
    FIRE,
    ELECTRIC,
    GRASS,
    BUG,
    NORMAL,
    PSYCHIC,
    POISON
};

const string pkmTypeStrings[] = {
    "NONETYPE",
    "Water",
    "Fire",
    "Electric",
    "Grass",
    "Bug",
    "Normal",
    "Psychic",
    "Poison"};

class Move
{
private:
    string myName;
    pkmType type;
    int power;

public:
    Move(string name, pkmType type, int power)
    {
        this->myName = name;
        this->type = type;
        this->power = power;
    }

    string getName()
    {
        return myName;
    }

    pkmType getType() const // Mark the function as const
    {
        return type;
    }

    int getPower()
    {
        return power;
    }

    void displayInfo()
        const
    {
        std::cout << "Move: " << myName << std::endl;
        std::cout << "Type: " << pkmTypeStrings[type] << std::endl;
        std::cout << "Power: " << power << std::endl;
    }
};


class Pikachu
{
private:
    int level;
    string nickname;

public:
    Pikachu(int level, pkmType, string nickname)
    {
        // TODO: Finish constructor
    }

    void growl(); // TODO: Implement growl
    string move(); // TODO: Implement move
};



class Pkm
{
private:
    int level;
    string growlSound = "Growl";
    vector<pkmType> myType;
    string nickname;
    int hp;
    vector<Move> myMoves;

public:
    Pkm(int level, pkmType firstType, pkmType secondType, string nickname, int hp)
    {
        this->level = level;
        this->nickname = nickname;
        this->myType = {firstType, secondType};
        this->hp = hp;
    }

    virtual void growl()
    {
        cout << growlSound << endl;
    }

    // getters
    string getNickname() { return this->nickname; }
    vector<pkmType> getType() { return this->myType; }
    vector<Move> getMoves() { return this->myMoves; }
    int getLevel() { return this->level; }
    int getHP() { return this->hp; }
    // setters
    void addType(pkmType newType)
    {
        if (this->myType.size() >= 2)
        {
            return;
        }
        this->myType.push_back(newType);
    }

    void setHP(int atk)
    {
        if (this->hp != 0)
        {
            this->hp -= atk;
            if (this->hp < 0)
                this->hp = 0;
        }
    }

    void setGrowl(string newGrowl) { this->growlSound = newGrowl; }
    void addMove(Move &newMove) {return;} // TODO: Implement this method
    void addMove(string newName, pkmType newType, int newPower) {return;} // TODO: Implement this method (Overloading)

    static vector<Pkm> findAllPkmsByType(vector<Pkm> &pkmns, pkmType pType)
    {
        vector<Pkm> foundPkms;
        for (auto pokemon : pkmns)
        {
            if (pokemon.getType()[0] == pType || pokemon.getType()[1] == pType)
            {
                foundPkms.push_back(pokemon);
            }
        }
        return foundPkms;
    }
};


class Charmander {}; // TODO: Implement Charmander Class
void makePokemonSound(Pkm *pokemon); // TODO: Implement this method


int main()
{

    vector<Move> moves;
    vector<Pkm> pokemons;

    // Generating Pokemon Moves
    moves.push_back(Move("Tackle", NORMAL, 40));
    moves.push_back(Move("Ember", FIRE, 40));
    moves.push_back(Move("Water Gun", WATER, 40));
    moves.push_back(Move("Thunder Shock", ELECTRIC, 40));
    moves.push_back(Move("Vine Whip", GRASS, 40));
    moves.push_back(Move("Bug Bite", BUG, 40));
    moves.push_back(Move("Scratch", NORMAL, 40));
    moves.push_back(Move("Fire Spin", FIRE, 35));
    moves.push_back(Move("Bubble", WATER, 40));
    moves.push_back(Move("Thunderbolt", ELECTRIC, 90));
    moves.push_back(Move("Razor Leaf", GRASS, 55));
    moves.push_back(Move("Poison Sting", BUG, 15));
    moves.push_back(Move("Headbutt", NORMAL, 70));
    moves.push_back(Move("Flamethrower", FIRE, 90));
    moves.push_back(Move("Surf", WATER, 90));
    moves.push_back(Move("Thunder", ELECTRIC, 110));
    moves.push_back(Move("Solar Beam", GRASS, 120));
    moves.push_back(Move("X-Scissor", BUG, 80));
    moves.push_back(Move("Ice Beam", WATER, 90));
    moves.push_back(Move("Psychic", PSYCHIC, 90));

    pokemons.push_back(Pkm(10, WATER, GRASS, "Squirtle", 50));
    pokemons.push_back(Pkm(12, FIRE, NONETYPE, "Charmander", 60));
    pokemons.push_back(Pkm(9, ELECTRIC, NONETYPE, "Pikachu", 55));
    pokemons.push_back(Pkm(8, BUG, NONETYPE, "Caterpie", 40));
    pokemons.push_back(Pkm(11, GRASS, POISON, "Bulbasaur", 55));
    pokemons.push_back(Pkm(10, WATER, NONETYPE, "Psyduck", 50));
    pokemons.push_back(Pkm(13, ELECTRIC, NONETYPE, "Raichu", 70));
    pokemons.push_back(Pkm(9, NORMAL, NONETYPE, "Rattata", 45));
    pokemons.push_back(Pkm(10, FIRE, NONETYPE, "Vulpix", 50));
    pokemons.push_back(Pkm(12, GRASS, POISON, "Ivysaur", 60));

    for (auto &pokemon : pokemons)
    {
        int RandIndex = rand() % moves.size();
        Move mv = moves[RandIndex];
        pokemon.addMove(mv);
    }

    Pikachu pikachu(10, ELECTRIC, "Sparky");

    Charmander charmander(5, FIRE, NONETYPE, "Char Char", 50);
    // Create a Pikachu pointer and pass it to the function
    Pkm *CharChar = &charmander;
    makePokemonSound(CharChar);

    makePokemonSound(&charmander);

    for (auto &pokemon : pokemons)
    {
        cout << "Nickname: " << pokemon.getNickname() << endl;
        cout << "Level: " << pokemon.getLevel() << endl;
        cout << "Types: ";
        for (auto type : pokemon.getType())
        {
            if (type != 0)
                cout << pkmTypeStrings[type] << " ";
            
        }
        cout << endl;
        cout << "HP: " << pokemon.getHP() << endl;
        cout << "Moves:" << endl;
        for (auto &move : pokemon.getMoves())
        {
            move.displayInfo();
        }
        cout << endl;
    }

    return 0;
}
