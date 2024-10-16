#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
using namespace sf;
using namespace std;
#include"level.h"

//<*************************************************Level#2************************************************>

class Zombie_outskirts :public level {
private:
	Texture peeshooterTexture;
	Texture sunflowerTexture;
	Texture cherrybombTexture;
	Texture wallnutTexture;

	Sprite peeshooterSprite; 
	Sprite sunflowerSprite;
	Sprite cherrybombSprite;
	Sprite wallnutSprite;

	Texture sunlightTexture;
public:
	enum GameState {
		peeshooterPosition,
		sunflowerPosition,
		cherrybombposition,
		wallnutposition,
		Idle
	};



	//setting states
	GameState peeshooterState = Idle;
	GameState sunflowerState = Idle;
	GameState cherrybombstate = Idle;
	GameState wallnutState = Idle;
	
	Zombie_outskirts(RenderWindow& window) {
		drawmap(window, "level_1fin.jpg");


		if (!sunlightTexture.loadFromFile("suno.png")) {
			cout << "Failed to load sunlight image!" << endl;
			return;
		}

		// Placement of peeshooter card
		if (!peeshooterTexture.loadFromFile("peaCard.png")) {
			cout << "Failed to load peeshooter selection image!" << endl;
			return;
		}
		peeshooterSprite.setTexture(peeshooterTexture);
		peeshooterSprite.setPosition(0, 0); // Adjust position as needed

		// Placement of sunflower card
		if (!sunflowerTexture.loadFromFile("sunflowerCard.png")) {
			cout << "Failed to load sunflower selection image!" << endl;
			return;
		}
		sunflowerSprite.setTexture(sunflowerTexture);
		sunflowerSprite.setPosition(0, 85); // Adjust position as needed

		// Placement of cherrybomb card
		if (!cherrybombTexture.loadFromFile("cherrycard.png")) {
			cout << "Failed to load cherrybomb selection image!" << endl;
			return;
		}
		cherrybombSprite.setTexture(cherrybombTexture);
		cherrybombSprite.setPosition(0, 170); // Adjust position as needed

		// Placement of wallnut card
		if (!wallnutTexture.loadFromFile("card_wallnut.png")) {
			cout << "Failed to load wallnut selection image!" << endl;
			return;
		}
		wallnutSprite.setTexture(wallnutTexture);
		wallnutSprite.setPosition(0, 255); // Adjust position as needed

		 }



	void run(Event event, RenderWindow& window, Score& score, level* level_1) {

		

		if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
			int mouseX = event.mouseButton.x;
			int mouseY = event.mouseButton.y;
			cout << mouseX << endl;
			cout << mouseY << endl;

			if (mouseX >= 0 && mouseX <= peeshooterTexture.getSize().x && mouseY >= 0 && mouseY <= peeshooterTexture.getSize().y) {
				// Plant a peashooter
				cout << "p selected" << endl;
				  if (score.getScore() >= 100) {
				level_1->plants_factory_getter()->add_plant('p');
				peeshooterState = peeshooterPosition;
				score.subtractScore(100);
				}
			}

			//sunflower selection condition

			if (mouseX >= sunflowerSprite.getPosition().x && mouseX <= sunflowerSprite.getPosition().x + sunflowerSprite.getLocalBounds().width &&
				mouseY >= sunflowerSprite.getPosition().y &&
				mouseY <= sunflowerSprite.getPosition().y + sunflowerSprite.getLocalBounds().height) {
				if (score.getScore() >= 100) {
					level_1->plants_factory_getter()->add_plant('s');
					sunflowerState = sunflowerPosition;
					score.subtractScore(100);
				}

			}
			//cherrybomb selection condition

			if (mouseX >= cherrybombSprite.getPosition().x && mouseX <= cherrybombSprite.getPosition().x + cherrybombSprite.getLocalBounds().width &&
				mouseY >= cherrybombSprite.getPosition().y && mouseY <= cherrybombSprite.getPosition().y + cherrybombSprite.getLocalBounds().height) {
				if (score.getScore() >= 150) {
					level_1->plants_factory_getter()->add_plant('c');
					cherrybombstate = cherrybombposition;
					score.subtractScore(150);
				}
			}


			//wallnut selection condition
			if (mouseX >= wallnutSprite.getPosition().x && mouseX <= wallnutSprite.getPosition().x + wallnutSprite.getLocalBounds().width &&
				mouseY >= wallnutSprite.getPosition().y && mouseY <= wallnutSprite.getPosition().y + wallnutSprite.getLocalBounds().height) {
				if (score.getScore() >= 50) {
					level_1->plants_factory_getter()->add_plant('w');
					wallnutState = wallnutposition;
					score.subtractScore(50);
				}
			}
			
			else if (peeshooterState == peeshooterPosition) {
				if (mouseX >= 300 && mouseX <= 1200 && mouseY >= 210 && mouseY <= 530) {
					mouseX -= 300;
					int count = 0;
					while (mouseX >= 100) {
						mouseX -= 100;
						count++;
					}
					mouseX = 300 + count * 100;
					mouseY -= 100;
					count = 0;
					while (mouseY >= 110) {
						mouseY -= 110;
						count++;
					}
					mouseY = 100 + count * 110;

					
					level_1->plants_factory_getter()->position_setter(mouseX, mouseY);
					peeshooterState = Idle;
				}
			}

			else if (sunflowerState == sunflowerPosition) {
				if (mouseX >= 300 && mouseX <= 1200 && mouseY >= 210 and mouseY <= 530) {
					mouseX -= 300;
					int count = 0;
					while (mouseX >= 100) {
						mouseX -= 100;
						count++;
					}
					mouseX = 300 + count * 100;
					mouseY -= 100;
					count = 0;
					while (mouseY >= 110) {
						mouseY -= 110;
						count++;
					}
					mouseY = 100 + count * 110;
					
					level_1->plants_factory_getter()->position_setter(mouseX, mouseY);
					sunflowerState = Idle;
				}
			}
			else if (wallnutState == wallnutposition) {
				if (mouseX >= 300 && mouseX <= 1200 && mouseY >= 210 && mouseY <= 530) {
					mouseX -= 300;
					int count = 0;
					while (mouseX >= 100) {
						mouseX -= 100;
						count++;
					}
					mouseX = 300 + count * 100;
					mouseY -= 100;
					count = 0;
					while (mouseY >= 110) {
						mouseY -= 110;
						count++;
					}
					mouseY = 100 + count * 110;
					level_1->plants_factory_getter()->position_setter(mouseX, mouseY);
					wallnutState = Idle;
				}
			}
			
			else if (cherrybombstate == cherrybombposition) {
				if (mouseX >= 300 && mouseX < 1200 && mouseY >= 210 and mouseY <= 530) {
					mouseX -= 300;
					int count = 0;
					while (mouseX >= 100) {
						mouseX -= 100;
						count++;
					}
					mouseX = 300 + count * 100;
					mouseY -= 100;
					count = 0;
					while (mouseY >= 110) {
						mouseY -= 110;
						count++;
					}
					mouseY = 100 + count * 110;
					level_1->plants_factory_getter()->position_setter(mouseX, mouseY);
					cherrybombstate = Idle;
				}
			}
			

			else {
				// Otherwise, handle sunlight clicks
				sunflower s;
				int* currentScore = &score.scoreValue;
				S.handleMouseClicks(sunlights, mouseX, mouseY, *currentScore, false);
				handleMouseClick_ofSuns(mouseX, mouseY, window, score);
			}

		}


	}
	void draw_sunlights(RenderWindow& window) {
		S.handleSunlight(sunlights, window.getSize().y);
		S.drawSunlight(window, sunlights, sunlightTexture);
	}
	void draw_cards(RenderWindow& window) {
		window.draw(peeshooterSprite);
		window.draw(sunflowerSprite);
		window.draw(cherrybombSprite);
		window.draw(wallnutSprite);
	
	}
};

