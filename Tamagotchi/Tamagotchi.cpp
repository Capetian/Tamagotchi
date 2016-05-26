#include "stdafx.h"
#include "Tamagotchi.h"

 Tamagotchi::Tamagotchi() {
	//setTamagotchiImage();
	 happiness = 60;
	 health = 60;
	 cleanliness = 60;
	 energy = 60;
	 hunger = 60;
	 clock.restart();
}

 Tamagotchi::Tamagotchi(int happiness, int health, int cleanliness, int energy, int hunger)
 :happiness(happiness), health(health), cleanliness(cleanliness), energy(energy), hunger(hunger){}

 int Tamagotchi::getEnergy() {
	 return energy;
 }

 void Tamagotchi::getLivingTime() {
	 sf::Time time = clock.getElapsedTime();
	 birth = time.asSeconds();
 }


 ostream& operator<<(ostream &out, Tamagotchi *tamagotchi){
	 tamagotchi->getLivingTime();
	 
	 out << tamagotchi->birth << endl;
	 out << tamagotchi->happiness << endl;
	 out << tamagotchi->health << endl;
	 out << tamagotchi->hunger << endl;
	 out << tamagotchi->energy << endl;
	 return out;
 }
 


