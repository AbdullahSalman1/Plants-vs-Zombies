#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
using namespace sf;
using namespace std;
#include"level.h"

//<*************************************************Level#1**************************************************>

class BeginnersGarden : public level {
private:
	Texture peeshooterTexture;
	Texture sunflowerTexture;
	Sprite peeshooterSprite;
	Sprite sunflowerSprite;
	Texture sunlightTexture;

public:
	enum GameState {
		peeshooterPosition,
		sunflowerPosition,
	
		Idle
	};
   //setting states
	GameState peeshooterState = Idle;
	GameState sunflowerState = Idle;
	
	BeginnersGarden(RenderWindow& window) {
		drawmap(window, "sp.png");


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
			cout << "Failed to load sunflower image!" << endl;
			return;
		}
		sunflowerSprite.setTexture(sunflowerTexture);
		sunflowerSprite.setPosition(0, 85); // Adjust position as needed

		}




	void run(Event event, RenderWindow& window, Score& score, level* level_1) {

		

		if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
			int mouseX = event.mouseButton.x;
			int mouseY = event.mouseButton.y;
		

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
			
			else if (peeshooterState == peeshooterPosition) {
				if (mouseX >= 300 && mouseX <= 1200 && mouseY >= 315 && mouseY <= 425) {
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

					cout << mouseX << "X" << endl;
					level_1->plants_factory_getter()->position_setter(mouseX, mouseY);
					peeshooterState = Idle;
				}
			}

			else if (sunflowerState == sunflowerPosition) {
				if (mouseX >= 300 && mouseX <= 1200 && mouseY >= 0 and mouseY <= 600) {
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
			
			else {
				// Otherwise, handle sunlight clicks

				int* currentScore = &score.scoreValue;
				S.handleMouseClicks(sunlights, mouseX, mouseY, *currentScore, false);
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

	}
};
