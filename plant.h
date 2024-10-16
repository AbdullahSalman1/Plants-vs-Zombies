#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
using namespace sf;
using namespace std;


class plants {
protected:
    int max_plants;
    int plants_counter;
    Texture texture; //for plants
    int hit_counts;
    int health;

public:

    Sprite sprite;
    Clock timer;
    plants() :max_plants(45), plants_counter(0) {
        hit_counts = 0;
    }

    plants(string name) {

        texture.loadFromFile(name);
        sprite.setTexture(texture);
        sprite.setScale(1, 1); // Adjust scale as needed
        sprite.setPosition(-100, -100);
    }

    void plants_position_setter(int a, int b) {
        sprite.setPosition(a, b);
    }
    Sprite& sprite_getter() {
        return sprite;
    }



    virtual void fire_update(int i, plants* currentPlant) = 0;
    virtual void  drawBullets(RenderWindow& window) = 0;
    virtual void fire_position(int a, int b, int n) = 0;
    virtual Sprite& bullets_getter(int i) = 0;
    virtual int hit_counter_getter() = 0;
    virtual void hit_counter_setter(int n) = 0;
    virtual void health_setter(int n) = 0;
    virtual int health_getter() = 0;
    virtual void health_reduction(int n) = 0;
    //only for sunflower
    virtual int num_of_suns_getter() = 0;
    virtual void sun_reduction(int i) = 0;
};











