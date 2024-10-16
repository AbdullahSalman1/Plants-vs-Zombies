#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include <ctime>
#include <iostream>
using namespace sf;
using namespace std;
#include "plantfactory.h"
#include "zombiefactory.h"
#include "lawnmover.h"
#include  "score.h"
#include "sunlight.h"


class level {
private:
	plants_factory* plants_manager;
	zombies_factory* zombies_manager;
	Texture backgroundTexture;
	Clock removalTimer; // Timer for plant removal
	bool isRemovingPlant; // Flag to indicate if plant removal is in progress
	int plantToRemoveIndex; // Index of the plant to remove
	int tt;
	LawnMower* mover;
	int attacker_zombier;
	int balloon;
	int walkng_index;
	SoundBuffer cherryBombBuffer;
	Sound blastSound;

	SoundBuffer ZombieHitBuffer;
	Sound HitSound;
public:
	bool temp;
	Sunlight S;
	Sunlight sunlights[MAX_SUNLIGHTS];
	level() {

		plants_manager = new plants_factory;
		zombies_manager = new zombies_factory;
		//mover = new LawnMower(2);
		balloon = 0;
		tt = 0;
		removalTimer.restart();
		temp = false;
		walkng_index = -10;


		// Load audio file
		if (!cherryBombBuffer.loadFromFile("cherrybomb1.wav")) {
			cout << "Failed to load blast audio!" << endl;
		}
		blastSound.setBuffer(cherryBombBuffer);

		if (!ZombieHitBuffer.loadFromFile("zombiehit.mp3")) {
			cout << "Failed to load blast audio!" << endl;
		}
		HitSound.setBuffer(ZombieHitBuffer);
	}
	void number_setter(int n) {
		walkng_index = n;
	}
	 int number_getter() {
		 return walkng_index;
	}

	void drawmap(RenderWindow& window, string n) {

		if (!backgroundTexture.loadFromFile(n)) {
			cout << "Failed to load level image!" << endl;
			return;
		}

		Sprite backgroundSprite(backgroundTexture);
		window.draw(backgroundSprite);

	}
	plants_factory* plants_factory_getter() {
		return plants_manager;
	}
	int zombies_num_getter() {
		return zombies_manager->num_of_zombies;
	}
	void draw_zombies(RenderWindow& window) {
		for (int i = 0; i < zombies_num_getter(); i++) {
			zombies_manager->draw(window, i);

		}
	}
	int plants_num_getter() {
		return plants_manager->plants_num;
	}
	void draw_plants(RenderWindow& window) {
		int x = plants_num_getter();
		for (int i = 0; i < x;i++) {
			plants_manager->draw_plant(window, i);

		}
	}
	zombies_factory* zombies_factory_getter() {
		return zombies_manager;
	}


	void bullet_update(RenderWindow& window) {
		for (int i = 0; i < plants_num_getter(); i++) {

			plants_manager->plant_getter(i)->fire_update(i, plants_manager->plant_getter(i));
			plants_manager->plant_getter(i)->drawBullets(window);



		}

	}
	void initialize_lawn_mover(int n) {

		mover = new LawnMower(n);
	}

	int handleCollisions(RenderWindow& window) {

		static int collision_counter = 0;

		// Check for collisions between zombies and plants
		if (isRemovingPlant == false) {
			for (int i = 0; i < zombies_num_getter(); i++) {
				for (int j = 0; j < plants_num_getter(); j++) {
					plants* currentPlant = plants_factory_getter()->plant_getter(j);
					if (typeid(*currentPlant) != typeid(wallnut)) {
						if (zombies_factory_getter()->zombie_getter(i)->getSprite().getGlobalBounds().intersects(
							plants_factory_getter()->plant_getter(j)->sprite_getter().getGlobalBounds())) {
							// Collision detected
							zombies_factory_getter()->zombie_getter(i)->movement_setter(false); // Stop zombie movement

							tt = i;
							startPlantRemoval(j, i); // Start plant removal
							removalTimer.restart();
							temp = true;


							//	break;
						}
					}
					else if (typeid(*currentPlant) == typeid(wallnut)) {
						if (zombies_factory_getter()->zombie_getter(i)->getSprite().getGlobalBounds().intersects(
							plants_factory_getter()->plant_getter(j)->sprite_getter().getGlobalBounds())) {
							zombies_factory_getter()->zombie_getter(i)->health_reduction(50);
							cout << "health of zombie is " << zombies_factory_getter()->zombie_getter(i)->health_getter() << endl;
							if (zombies_factory_getter()->zombie_getter(i)->health_getter() <= 0) {
								zombies_manager->zombie_getter(i)->getSprite().setPosition(-1000, -1000);
							}
						}
					}
				}
			}
		}
		if (temp == true) {

			return tt;
		}


		// Check for collisions between bullets and zombies
		for (int i = 0; i < zombies_num_getter(); ++i) {
			for (int j = 0; j < plants_manager->plants_num; ++j) {
				plants* currentPlant = plants_manager->plant_getter(j);
				// Check if the current plant is peashooter, snowpee, or repeater
				if (typeid(*currentPlant) == typeid(peeshooter) || typeid(*currentPlant) == typeid(repeater)) {
					for (int k = 0; k < 10; ++k) {
						if (plants_manager->plant_getter(j)->bullets_getter(k).getGlobalBounds().intersects(
							zombies_manager->zombie_getter(i)->getSprite().getGlobalBounds())) {
							// Bullet hit zombie
							HitSound.play();
							plants_manager->plant_getter(j)->fire_position(-1000, -1000, k);
							cout << "health before reduction is " << zombies_manager->zombie_getter(i)->health_getter() << endl;
							zombie* currentZombie = zombies_manager->zombie_getter(i);
							if (typeid(*currentZombie) == typeid(Balloon_zombie)) {
								zombies_factory_getter()->load_ballon_textures(i);
							}
					 	
							
							zombies_manager->zombie_getter(i)->health_reduction(25);

							//cout << k << "kk" << endl;
							// Remove the bullet from the screen
							if (zombies_manager->zombie_getter(i)->health_getter() <= 0) {
								// Move the collided zombie outside of the screen
								zombies_manager->zombie_getter(i)->getSprite().setPosition(-1000, -1000);
							}
							//break; // Break out of bullet loop
						}
					}
				}
				else if (typeid(*currentPlant) == typeid(snowpee)) {

					for (int l = 0; l < 10; ++l) {
						if (plants_manager->plant_getter(j)->bullets_getter(l).getGlobalBounds().intersects(
							zombies_manager->zombie_getter(i)->getSprite().getGlobalBounds())) {



							cout << zombies_manager->zombie_getter(i)->health_getter() << " health of zombie " << endl;
							plants_manager->plant_getter(j)->fire_position(-1000, -1000, l); // Remove the bullet from the screen

							if (zombies_manager->zombie_getter(i)->health_getter() <= 0) {
								// Move the collided zombie outside of the screen
								zombies_manager->zombie_getter(i)->getSprite().setPosition(-1000, -1000);
							}


							break; // Break out of bullet loop
						}
					}
				}
			}
		}
		
		return -1;

	}



	void startPlantRemoval(int plantIndex, int i) {
		isRemovingPlant = true;
		plantToRemoveIndex = plantIndex;
		attacker_zombier = i;

	}



	void update() {
		if (isRemovingPlant && removalTimer.getElapsedTime().asSeconds() >= 1) {
			// Reduce plant's health by zombie's damage
			plants_factory_getter()->plant_getter(plantToRemoveIndex)->health_reduction(zombies_factory_getter()->zombie_getter(attacker_zombier)->damage);

			// Check if plant's health is less than or equal to zero
			if (plants_factory_getter()->plant_getter(plantToRemoveIndex)->health_getter() <= 0) {
				// Print the current health
				cout << "health " << plants_factory_getter()->plant_getter(plantToRemoveIndex)->health_getter() << endl;

				// Remove the plant
				plants_factory_getter()->removePlant(plantToRemoveIndex);temp = false;
				zombies_factory_getter()->zombie_getter(tt)->movement_setter(true);
				isRemovingPlant = false;
				plantToRemoveIndex = -1;
			}
			else {
				// Print the current health if it's above zero
				cout << "health " << plants_factory_getter()->plant_getter(plantToRemoveIndex)->health_getter() << endl;
			}

			// Restart the timer for the next update
			removalTimer.restart();
		}

	}


	void moveLawnMower() {
		static bool move = false;
		static int t = 0;
		for (int i = 0; i < zombies_num_getter(); i++) {
			//	cout << zombies_num_getter() << "number of zombies " << endl;
			for (int j = 0; j < mover->num_of_lawn_movers; j++) {
				//		cout << "num of zombies " << zombies_num_getter() << endl;
				if (mover->lawn_mover_getter(j).getGlobalBounds().intersects(zombies_manager->zombie_getter(i)->getSprite().getGlobalBounds())) {

					zombies_manager->zombie_getter(i)->getSprite().setPosition(-1000, -1000);
					move = true;
					t = j;
					break;
				}
			}
		}
		if (move) {

			mover->lawn_mover_getter(t).move(1, 0);
		}



	}
	void drawLawnMower(RenderWindow& window) {
		for (int i = 0; i < mover->num_of_lawn_movers;i++) {
			mover->draw(window);
		}
	}
	void handleMouseClick_ofSuns(int mouseX, int mouseY, RenderWindow& window, Score& score) {




		// Check if the mouse click is on the sunflower
		for (int i = 0; i < plants_manager->plants_num; i++) {


			plants* currentPlant = plants_manager->plant_getter(i);


			if (typeid(*currentPlant) == typeid(sunflower)) {
				for (int j = 0; j < plants_manager->plant_getter(i)->num_of_suns_getter();j++) {

					if (mouseX >= plants_manager->plant_getter(i)->bullets_getter(j).getPosition().x && mouseX <= plants_manager->plant_getter(i)->bullets_getter(j).getPosition().x + plants_manager->plant_getter(i)->bullets_getter(j).getLocalBounds().width &&
						mouseY >= plants_manager->plant_getter(i)->bullets_getter(j).getPosition().y && mouseY <= plants_manager->plant_getter(i)->bullets_getter(j).getPosition().y + plants_manager->plant_getter(i)->bullets_getter(j).getLocalBounds().height) {
						//	cout << "hello" << endl;;
							// Remove the sunflower from the screen

						currentPlant->bullets_getter(j).setPosition(-1000, -1000); // Move it off-screen

						score.addScore(25);


						for (int j = i; j < plants_manager->plant_getter(i)->num_of_suns_getter() - 1; j++) {
							plants_manager->plant_getter(i)->bullets_getter(j) = plants_manager->plant_getter(i)->bullets_getter(j + 1);
						}
						plants_manager->plant_getter(i)->sun_reduction(1);
						break; // No need to check further if one sunflower is found
					}
				}
			}
		}
	}


	void cherry_bomb_collision() {

		for (int i = 0; i < plants_factory_getter()->plants_num; i++) {
			plants* currentPlant = plants_factory_getter()->plant_getter(i);

			//	if (plants_factory_getter()->plant_getter(i)->hit_counter_getter() == true) 
			if (typeid(*currentPlant) == typeid(cherryBomb)) {
			
				if (plants_factory_getter()->plant_getter(i)->hit_counter_getter()) {
			
					for (int j = 0; j < zombies_factory_getter()->num_of_zombies; j++) {
						if (zombies_factory_getter()->zombie_getter(j) != nullptr) {
							{
						
								int zombieX = zombies_factory_getter()->zombie_getter(j)->getSprite().getPosition().x;
								int zombieY = zombies_factory_getter()->zombie_getter(j)->getSprite().getPosition().y;
								int cherryX = plants_factory_getter()->plant_getter(i)->sprite_getter().getPosition().x;
								int cherryY = plants_factory_getter()->plant_getter(i)->sprite_getter().getPosition().y;
								if (
									zombieX - cherryX >= -150 && zombieX - cherryX <= 150
									
									
									)

								{
									
									blastSound.play();
									zombies_factory_getter()->zombie_getter(j)->getSprite().setPosition(-1000, -1000);
									plants_factory_getter()->plant_getter(i)->sprite_getter().setPosition(-1000, -1000);
									
									break;
								}
							}
						}
					}
				}
			}
		}
	}


	virtual void run(Event event, RenderWindow& window, Score& score, level* level_1) = 0;
	virtual void draw_cards(RenderWindow& window) = 0;
	virtual void draw_sunlights(RenderWindow& window) = 0;
	
};







