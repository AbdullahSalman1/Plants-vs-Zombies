#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <ctime>
#include <iostream>

#include"DancingZombie.h"
#include "footballZombie.h"
#include"simpleZombie.h"
#include"ballon_zombie.h"
using namespace sf;
using namespace std;

class zombies_factory {
private:
	zombie* z[20];
	Clock spawnTimer; // Timer to control zombie spawning
	int max_zombies;
	int currentLevel;
	int zombies_y[5];
	int index;
	int remainder;
	int n;
	SoundBuffer zombieSoundBuffer;
	Sound zombieSound;
	int num_of_simple_zombies;
	int num_of_football_zombies;
	int num_of_dancing_zombies;
	int num_of_balloon_zombies;

public:
	int num_of_zombies;

	zombies_factory() {
		num_of_zombies = 0;
		max_zombies = 0;
		for (int i = 0; i < 20 ;i++) {
			z[i] = nullptr;

		}
		index = -10;
		zombies_y[0] = 210;
		zombies_y[1] = 320;
		zombies_y[2] = 440;
		zombies_y[3] = 90;
		zombies_y[4] = 550;
		remainder = 0;
		n = 0;
		max_zombies = 5;
		// Load audio file
		if (!zombieSoundBuffer.loadFromFile("Groan.wav")) {
		    cout << "Failed to load zombie audio!" << endl;
		}
		zombieSound.setBuffer(zombieSoundBuffer);
		 num_of_simple_zombies = 0;
		 num_of_football_zombies = 0;
		 num_of_dancing_zombies = 0;
		 num_of_balloon_zombies = 0;
	
	}
	void current_level_setter(int n) {
		currentLevel = n;
		if (n == 1) {
			max_zombies = 5;
		}
		else if (n == 2 || n==3) {
			max_zombies = 20;
		}
		
	}
	//void spawn_NewZombie() {
	//	if (spawnTimer.getElapsedTime().asSeconds() > 4) {
	//		n = 1;
	//       
	//	
	//			if (num_of_zombies < max_zombies) {
	//				/*if (currentLevel == 1) {
	//					z[num_of_zombies] = new simpleZombie;
	//				}
	//				if (currentLevel == 2) {
	//					z[num_of_zombies] = new football_zombie;
	//				}*/
	//				//	z[num_of_zombies] = new dancing_zombie;

	//				z[num_of_zombies] = new simpleZombie;
	//				zombieSound.play();
	//				/*z[num_of_zombies] = new football_zombie;
	//				z[num_of_zombies] = new dancing_zombie;
	//				z[num_of_zombies] = new Balloon_zombie;*/
	//				z[num_of_zombies]->movement_setter(true);
	//				z[num_of_zombies]->frame_index_setter(0);
	//				static int x = 100;

	//				z[num_of_zombies]->setPosition(1250 + x, zombies_y[n]);






	//				num_of_zombies += 1;
	//				x += 100;

	//				spawnTimer.restart();
	//			
	//		}
	//	}
	//}
	 
	void spawn_NewZombie() {
		static int x = 100;
		if (spawnTimer.getElapsedTime().asSeconds() > 4) {
			if (currentLevel == 1) {
				if (num_of_zombies < 5) {
					z[num_of_zombies] = new simpleZombie;
					zombieSound.play();
					z[num_of_zombies]->movement_setter(true);
					z[num_of_zombies]->frame_index_setter(0);
					z[num_of_zombies]->setPosition(1250 + x, 320);
					x += 100;
					num_of_zombies += 1;
					spawnTimer.restart();
				}
			}
			if (currentLevel == 2 || currentLevel == 3) {
				if (num_of_zombies < 20) {
					if (num_of_simple_zombies < 5) {
						z[num_of_zombies] = new simpleZombie;
						zombieSound.play();
						z[num_of_zombies]->movement_setter(true);
						z[num_of_zombies]->frame_index_setter(0);
						if (currentLevel == 2) {
								n = (rand() % 3);
								}
							else if (currentLevel == 3) {
							n = (rand() % 5);
							}
						z[num_of_zombies]->setPosition(1250 + x, zombies_y[n]);
						x += 100;
						num_of_simple_zombies += 1;
						num_of_zombies += 1;
						spawnTimer.restart();
					}
					if (num_of_football_zombies < 5) {
						z[num_of_zombies] = new football_zombie;
						zombieSound.play();
						z[num_of_zombies]->movement_setter(true);
						z[num_of_zombies]->frame_index_setter(0);
						if (currentLevel == 2) {
							n = (rand() % 3);
						}
						else if (currentLevel == 3) {
							n = (rand() % 5);
						}
						z[num_of_zombies]->setPosition(1250 + x, zombies_y[n]);
						x += 100;
						num_of_zombies += 1;
						num_of_balloon_zombies += 1;
						spawnTimer.restart();
					}
					if (num_of_dancing_zombies < 5) {
						z[num_of_zombies] = new dancing_zombie;
						zombieSound.play();
						z[num_of_zombies]->movement_setter(true);
						z[num_of_zombies]->frame_index_setter(0);
						if (currentLevel == 2) {
							n = (rand() % 3);
						}
						else if (currentLevel == 3) {
							n = (rand() % 5);
						}
						z[num_of_zombies]->setPosition(1250 + x, zombies_y[n]);
						x += 100;
						num_of_zombies += 1;
						num_of_dancing_zombies += 1;
						spawnTimer.restart();
					}
					if (num_of_balloon_zombies < 5) {
						z[num_of_zombies] = new Balloon_zombie;
						zombieSound.play();
						z[num_of_zombies]->movement_setter(true);
						z[num_of_zombies]->frame_index_setter(0);
						if (currentLevel == 2) {
							n = (rand() % 3);
						}
						else if (currentLevel == 3) {
							n = (rand() % 5);
						}
						z[num_of_zombies]->setPosition(1250 + x, zombies_y[n]);
						x += 100;
						num_of_zombies += 1;
						num_of_balloon_zombies += 1;
						spawnTimer.restart();
					}
				}
			}
		}
	
	}





	zombie* zombie_getter(int i) {

		return z[i];
	}

	void draw(RenderWindow& window, int i) {

		window.draw(z[i]->getSprite());
	}

	void move(int i) {
		
		if (z[i]->movement_getter() != false) {

			z[i]->getSprite().move(-z[i]->speed_getter(), 0);

		}
	}
	void set_index(int n) {
		index = n;
	}
	int get_index() {
		return index;
	}
	void load_ballon_textures(int t) {
		int x = z[t]->move_totaFrame_getter();
		cout << z[t]->move_totaFrame_getter() << "tota frames " << endl;
		for (int i = 0; i < x; i++) {
			z[t]->animation_changer(i);
			z[t]->frame_number_setter(15);
		}
	}
	void update(int i) {

		move(i);



		// Check if it's time to change the frame
		if (z[i]->getTime() >= 0.09) {
			// Change to the next frame

			z[i]->frame_index_setter((z[i]->frame_index_getter() + 1) % z[i]->frame_number_getter());
			//	z[i]->frame_index_setter(2);
			  //  cout << z[i]->frame_index_getter() << "frames"<<endl;
			z[i]->getSprite().setTexture(z[i]->getCurrentAnimationFrame());

			// Restart the frame timer
			z[i]->getClock().restart();

		}
	}

	void eating_textures_update(int i) {
		move(i);

		// Check if it's time to change the frame
		if (z[i]->getTime() >= 1) {
			// Change to the next frame
			z[i]->eating_frame_number_setter((z[i]->eating_frame_number_getter() + 1) % z[i]->eating_frames_getter());

			//	z[i]->frame_index_setter(2);
			//	//cout << z[i]->frame_index_getter() << endl;
			z[i]->getSprite().setTexture(z[i]->geteatingFrame());

			// Restart the frame timer
			z[i]->getClock().restart();

		}
	}

	void ballon_zombie_move(int i) {
		move(i);
		if (z[i]->getTime() >= 1) {
			// Change to the next frame
			z[i]->balloon_moving_spec_frame_setter((z[i]->balloon_moving_spec_frame_setter_getter() + 1) % z[i]->move_totaFrame_getter());

			//	z[i]->frame_index_setter(2);
			//	//cout << z[i]->frame_index_getter() << endl;
			z[i]->getSprite().setTexture(z[i]->bmovingtexture());

			// Restart the frame timer
			z[i]->getClock().restart();

		}
	}
	void updateAndDrawZombies(RenderWindow& window, int xx) {

		// Update and draw each active zombie
		for (int i = 0; i < max_zombies ; ++i) {
			if (z[i] != nullptr) {
				
				if (i == xx) {
					eating_textures_update(i);
				}
		
				else {
					update(i);
				}
				update(i);
				set_index(-10);
				draw(window, i); // Draw the zombie on the window
			}
		}
	}

	void removeZombie(int index) {
		delete z[index];
		z[index] = nullptr;
		num_of_zombies--;
	}
	void zombie_reduction(int i) {
		num_of_zombies -= i;
	}
	void setZombie(int index, zombie* newZombie) {
		if (index >= 0 && index < num_of_zombies) {
			z[index] = newZombie;
		}
		else {
			cout << "Error: Index out of range!" << endl;
		}
	}



};