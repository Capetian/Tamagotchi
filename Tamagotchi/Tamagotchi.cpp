#include "stdafx.h"
#include "Tamagotchi.h"

 Tamagotchi::Tamagotchi() {
	 happiness = 20;
	 hunger = 50;
	 experience = 0;
	 clock.restart();
}
 Tamagotchi::Tamagotchi(int happiness, int hunger, int experience)
	 :happiness(happiness), hunger(hunger), experience(experience){}


 void Tamagotchi::getLivingTime() {
	 sf::Time time = clock.getElapsedTime();
	 birth = time.asSeconds();
 }


 ostream& operator<<(ostream &out, Tamagotchi *tamagotchi){
	 tamagotchi->getLivingTime();
	 out << "1" << endl;
	/* out << tamagotchi->birth << endl;*/
	 out << tamagotchi->happiness << endl;
	 out << tamagotchi->experience << endl;
	 out << tamagotchi->hunger << endl;

	 return out;
 }

 istream& operator>>(istream &in, Tamagotchi &tamagotchi) {
	 int tempType;
	 Chicken temp = Chicken();
	 if (in >> tempType) {
		 switch (tempType) {
		 case 0:
			 temp =Egg();
			 break;
		 case 1:
			 temp =Chicken();
			 break;
		 default:
			 temp = Egg();
			 break;
		 }
		 if (in >> temp.happiness) {
			 if (in >> temp.experience) {
				 if (in >> temp.hunger) {
					 tamagotchi = temp;
					 return in;
				 }
			 }
		 }
	 }
	 in.clear();
	 throw UnloadedGame();
	 return in;
 }


