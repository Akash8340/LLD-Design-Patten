#include<iostream>
using namespace std;

//Abstract class
class Character{
    public:
        virtual string getAbilities () = 0;
        virtual ~Character () {} // virtual destructor
};

// Concrete Component: Basic Mario character with no power-ups.
class Mario : public Character{
    public:
        string getAbilities() override {
            return "Mario";
        }
};

// Abstract Decorator: CharacterDecorator "is-a" Charatcer and "has-a" Character.
class CharacterDecorator : public Character{
    protected:
        Character *character;
    public:
        CharacterDecorator(Character *c){
            this->character = c;
        }
};


// Concrete Decorator: Height-Increasing Power-Up.
class HeightUp : public CharacterDecorator{
    public:
        HeightUp(Character *c) : CharacterDecorator(c) {}

        string getAbilities() override {
            return character -> getAbilities() + "with HeightUp";
        }

};

// Concrete Decorator: Gun Shooting Power-Up.
class GunpowerUp : public CharacterDecorator{
    public:
        GunpowerUp(Character *c) : CharacterDecorator(c) {}

        string getAbilities() override {
            return character -> getAbilities() + "with Gun Shooting power";
        }

};

// Concrete Decorator: Star Power-Up (temporary ability).
class StarPowerUp : public CharacterDecorator{
    public:
        StarPowerUp(Character *c) : CharacterDecorator(c) {}

        string getAbilities() override {
            return character -> getAbilities() + "with StarPower (Limited time)";
        }
};

int main(){

    // Create a basic Mario character.
    Character* mario = new Mario();
    cout << "Basic Character: " << mario->getAbilities() << endl;

    // Decorate Mario with a HeightUp power-up.
    mario = new HeightUp(mario);
    cout << "After HeightUp: " << mario->getAbilities() << endl;

    // Decorate Mario further with a GunPowerUp.
    mario = new GunpowerUp(mario);
    cout << "After GunPowerUp: " << mario->getAbilities() << endl;

    // Finally, add a StarPowerUp decoration.
    mario = new StarPowerUp(mario);
    cout << "After StarPowerUp: " << mario->getAbilities() << endl;

    delete mario;

    return 0;
}