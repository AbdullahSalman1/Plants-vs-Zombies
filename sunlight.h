#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
#include "plant.h"
using namespace sf;
using namespace std;
#define MAX_SUNLIGHTS 5 // Maximum number of sunlights
class Sunlight {
    bool isActive; // Indicates if sunlight is active
    float positions[2]; // Array to store positions of sunlights
    Clock timer; // Timer for sunlight interval

public:
    void drawSunlight(RenderWindow& window, Sunlight sunlights[MAX_SUNLIGHTS], Texture& sunlightTexture) {
        Sprite sunlightSprite(sunlightTexture);

        for (int i = 0; i < MAX_SUNLIGHTS; i++) {
            if (sunlights[i].isActive) {
                int x = sunlights[i].positions[0]; // Accessing x-coordinate
                int y = sunlights[i].positions[1]; // Accessing y-coordinate
                sunlightSprite.setPosition(x, y);

                // cout << x << "   " << y << endl;
                 // Draw sunlight sprite if x is not zero
                if (x >= 200 && x <= 1150) {
                    window.draw(sunlightSprite);
                }
            }
        }
    }

    void handleSunlight(Sunlight sunlights[MAX_SUNLIGHTS], const int windowHeight) {
        // Check if it's time to create new sunlight
        static Clock sunlightTimer; // Static timer to track the time since the last sunlight was created

        if (sunlightTimer.getElapsedTime().asSeconds() > 3) {
            // Reset timer
            sunlightTimer.restart();

            // Find an inactive sunlight and activate it
            for (int i = 0; i < MAX_SUNLIGHTS; i++) {
                if (!sunlights[i].isActive) {
                    // Activate sunlight
                    sunlights[i].isActive = true;

                    // Set initial position (adjust position as needed)
                    int x = (rand() % 700) + 300;
                    while (x < 200) {
                        x = (rand() % 700) + 300;
                    }
                    sunlights[i].positions[0] = x;
                    sunlights[i].positions[1] = 0; // Adjust the range as per your game screen size

                    break; // Exit loop after activating one sunlight
                }
            }
        }

        // Move active sunlights
        for (int i = 0; i < MAX_SUNLIGHTS; i++) {
            if (sunlights[i].isActive) {
                // Move sunlight downwards
                sunlights[i].positions[1] += 1.5; // Adjust the speed as needed

                // Check if sunlight reached the bottom of the screen
                if (sunlights[i].positions[1] > windowHeight) { // Adjust the value as per your game screen height
                    // Deactivate sunlight
                    sunlights[i].isActive = false;
                }
            }
        }
    }
    bool handleMouseClicks(Sunlight sunlights[MAX_SUNLIGHTS], const int mouseX, const int mouseY, int& score, bool x) {
        bool sunlightClicked = false;
        for (int i = 0; i < MAX_SUNLIGHTS; i++) {
            if (sunlights[i].isActive) {
                // Check if the mouse click intersects with the sunlight
                if (mouseX >= sunlights[i].positions[0] && mouseX <= sunlights[i].positions[0] + 50 &&
                    mouseY >= sunlights[i].positions[1] && mouseY <= sunlights[i].positions[1] + 50) {
                    // Deactivate the sunlight
                    sunlights[i].isActive = false;
                    score += 25;
                    sunlightClicked = true;
                    break; // Exit loop after deactivating one sunlight
                }
            }
        }


        return sunlightClicked;
    }
};