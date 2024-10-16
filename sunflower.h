#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
using namespace sf;
using namespace std;
#include"plant.h"
class sunflower :public plants {
    Clock sunTimer; // Timer to control the appearance of the sun



    int noofsuns = 0;
    Texture sunTexture; // Texture for the sun
public:
    Sprite sun[10];
    sunflower() :plants("img2_upd.png") {
        if (!sunTexture.loadFromFile("suno.png")) {
            cout << "Failed to load sun image in sunflower class!" << endl;
        }
    }

    void fire_update(int i, plants* currentPlant)override {
        // Check if it's time to spawn a sun

        if (sunTimer.getElapsedTime().asSeconds() >= 5) { // Adjust interval as needed

            sun[noofsuns].setTexture(sunTexture);
            sun[noofsuns].setScale(1, 1); // Adjust scale as needed
            sun[noofsuns].setPosition(currentPlant->sprite.getPosition().x + 20, currentPlant->sprite.getPosition().y - 50); // Adjust sun position relative to the current plant
            noofsuns += 1;
            sunTimer.restart();
        }
    }

    void drawBullets(RenderWindow& window) override {
        for (int i = 0; i < noofsuns;i++) {
            window.draw(sun[i]);
        }
    }

    void fire_position(int a, int b, int n)override {}
    Sprite& bullets_getter(int i) {

        return sun[i];
    }
    int hit_counter_getter() {
        return 1;
    }
    void hit_counter_setter(int n) {

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
    int no_of_suns_getter() {
        return noofsuns;
    }
    Sprite& sun_getter(int i) {
        return sun[i];
    }
    void sun_reduction(int i) {
        noofsuns -= 1;
    }
    int num_of_suns_getter() {
        return noofsuns;
    }
};