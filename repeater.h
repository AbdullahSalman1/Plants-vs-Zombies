#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
using namespace sf;
using namespace std;
#include"plant.h"
class repeater : public plants {
    Clock fireTimer; // Timer to control the firing rate
    Sprite bullets[10]; // Array to store active bullets
    //	Sprite sprite;//peeshooter
    Sprite  fireSprite; // to load texture
    Texture fireTexture; // Texture for the firing effect
    int numBullets; // Number of active bullets
public:
    repeater() : plants("repeater.png") {
        numBullets = 0;
        if (!fireTexture.loadFromFile("pea.png")) {
            cout << "Failed to load repeater bullet image!" << endl;
        }
        fireSprite.setTexture(fireTexture);
        fireSprite.setScale(1, 1); // Adjust scale as needed
        fireSprite.setPosition(500, 500); // Initialize fire position off-screen


    }
    //    // Function to update the bullets
    void fire_update(int i, plants* currentPlant)override {
        // Check if it's time to fire
        if (fireTimer.getElapsedTime().asSeconds() >= 2) { // Adjust firing rate as needed
            // Create a new bullet
            if (numBullets < 10) {
                bullets[numBullets].setTexture(fireTexture);
                bullets[numBullets].setScale(1.0f, 1.0f); // Adjust scale as needed
                cout << sprite.getPosition().x << endl;

                bullets[numBullets].setPosition(currentPlant->sprite.getPosition().x + 20, currentPlant->sprite.getPosition().y); // Adjust fire position relative to peashooter
                numBullets++; // Increment the number of bullets
                fireTimer.restart();
            }
        }

        // Move each bullet
        for (int i = 0; i < numBullets; ++i) {
            bullets[i].move(2.0f, 0); // Adjust the movement speed as needed
        }

        // Remove bullets that have crossed the screen
        for (int i = 0; i < numBullets; ++i) {
            if (bullets[i].getPosition().x > 1200) { // Adjust the width of the window
                // Swap with the last bullet and decrement numBullets
                swap(bullets[i], bullets[numBullets - 1]);
                numBullets--;
                i--; // Recheck the current index as it now contains a new bullet
            }
        }
    }


    // Function to draw the bullets
    void  drawBullets(RenderWindow& window) {
        for (int i = 0; i < numBullets; ++i) {
            window.draw(bullets[i]);

        }
    }
    void fire_position(int a, int b, int n) {
        bullets[n].setPosition(a, b);
    }
    Sprite& bullets_getter(int i) {
        return bullets[i];
    }
    int hit_counter_getter() {
        return hit_counts;
    }
    void hit_counter_setter(int n) {
        hit_counts += n;
    }
    void health_setter(int n)override {
        health = n;
    }

    int health_getter() override {
        return health;
    }
    void health_reduction(int n)override {
        health -= n;
    }
    int num_of_suns_getter()override {
        //dont work for this function
        return 1;
    }
    void sun_reduction(int i) {
        //dont work for this function
    }
};