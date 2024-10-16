#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
#include"plant.h"
#include"peeshooter.h"
#include"wallnut.h"
#include"cherrybomb.h"
#include"repeater.h"
#include"snowpee.h"
#include"sunflower.h"
using namespace sf;
using namespace std;

class plants_factory {
private:
	plants* p[45];
	int max_plants;

public:
	int plants_num;
	plants_factory() {
		plants_num = 0;
		max_plants = 45;
		for (int i = 0; i < max_plants; i++) {
			p[i] = nullptr;
		}

	}
	void position_setter(int a, int b) {

		p[plants_num - 1]->plants_position_setter(a, b);
	}


	void add_plant(char n) {
		switch (n) {
		case 'p': //peeshooter
			if (plants_num < max_plants) {
				p[plants_num] = new peeshooter;
				p[plants_num]->health_setter(100);
				//	p[plants_num]->set_plant_health(100);
					/*cout << plants_num << "plants " << endl;*/
				plants_num += 1;
			}
			break;
		case 's'://sunflower
			if (plants_num < max_plants) {
				p[plants_num] = new sunflower;
				p[plants_num]->health_setter(100);
				//	p[plants_num]->set_plant_health(100);
					/*cout << plants_num << "plants " << endl;*/
				plants_num += 1;

			}
			break;
		case 'c'://cherrybomb
			if (plants_num < max_plants) {
				p[plants_num] = new cherryBomb;

				p[plants_num]->health_setter(100);
				plants_num += 1;

			}
			break;
		case 'w':
			if (plants_num < max_plants) {
				p[plants_num] = new wallnut;
				//	p[plants_num]->set_plant_health(100);
					/*cout << plants_num << "plants " << endl;*/
				p[plants_num]->health_setter(100);
				plants_num += 1;
				break;
			}
		case 'r':
			if (plants_num < max_plants) {
				p[plants_num] = new repeater;
				//	p[plants_num]->set_plant_health(100);
				/*	cout << plants_num << "plants " << endl;*/
				p[plants_num]->health_setter(100);
				plants_num += 1;

			}
			break;
		case 'x':
			if (plants_num < max_plants) {
				p[plants_num] = new snowpee;
				//	p[plants_num]->set_plant_health(100);
					/*cout << plants_num <<"plants "<< endl;*/
				p[plants_num]->health_setter(100);
				plants_num += 1;

			}
			break;
		}
	}


	void draw_plant(RenderWindow& window, int i) {
		window.draw(p[i]->sprite_getter());
	}
	plants* plant_getter(int i) {
		return p[i];
	}
	void move_out_of_screen(int i) {
		p[i]->sprite_getter().setPosition(-1000, -1000); // Move the plant out of the screen
	}

	void removePlant(int index) {
		if (index >= 0 && index < plants_num) {
			// Delete the plant object
			delete p[index];
			// Shift the remaining plants in the array to fill the gap
			for (int i = index; i < plants_num - 1; ++i) {
				p[i] = p[i + 1];
			}
			// Decrement the number of plants
			plants_num--;
			// Set the last pointer in the array to nullptr
			p[plants_num] = nullptr;
		}
	}

};