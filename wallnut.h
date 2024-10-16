#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
using namespace sf;
using namespace std;
#include"plant.h"

class wallnut : public plants {
private:
    Texture wallnut_animations[4];
    Clock ftimer;

    int current_frame;
    int n;

public:
    wallnut() :plants("wallnut1.png"), current_frame(1), n(0) {
        for (int i = 1; i <= 4;i++) {
            if (!wallnut_animations[i].loadFromFile("wallnut" + to_string(i) + ".png"))
                cerr << "Failed to load wallnut " << i << endl;
        }


    }
    void fire_update(int i, plants* currentPlant) override {

        currentPlant->plants_position_setter(currentPlant->sprite.getPosition().x + 1, currentPlant->sprite.getPosition().y);
        // Update the frame periodically
        if (currentPlant->timer.getElapsedTime().asSeconds() >= 0.2) { // Adjust interval as needed

            current_frame = (current_frame) % 3 + 1; // Update the frame

            currentPlant->sprite.setTexture(wallnut_animations[current_frame]);
            timer.restart();

        }
    }

    void drawBullets(RenderWindow& window) override {
        /* for (int i = 1; i <= 4;i++) {
             window.draw(sprite);
       }*/
    }
    void fire_position(int a, int b, int n)override {}
    Sprite& bullets_getter(int i) {
        return sprite;
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
    int num_of_suns_getter()override {
        //dont work for this function
        return 1;
    }
    void sun_reduction(int i) {
        //dont work for this function
    }
};