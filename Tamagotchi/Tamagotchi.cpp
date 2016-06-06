#include "stdafx.h"
#include "Tamagotchi.h"

 Tamagotchi::Tamagotchi() {
	 happiness = 20;
	 hunger = 50;
	 experience = 0;

}
 Tamagotchi::Tamagotchi(int happiness, int hunger, int experience)
	 :happiness(happiness), hunger(hunger), experience(experience){}



 ostream& operator<<(ostream &out, Tamagotchi *tamagotchi){
	 if (typeid(Egg) == typeid(*tamagotchi)) 
		 out << "0" << endl;
	 else if (typeid(Chicken) == typeid(*tamagotchi))
		 out << "1" << endl;
	 else if (typeid(Dragon) == typeid(*tamagotchi))
		 out << "2" << endl;
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


