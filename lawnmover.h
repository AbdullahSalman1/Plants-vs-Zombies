#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
using namespace sf;
using namespace std;



class LawnMower {
public:
    int attack;
    Texture texture;
    Sprite* sprite;
    bool spawned;
    int num_of_lawn_movers;


    LawnMower(int k) {
        bool x = false;
        if (k == 2) {
            k += 1;
            x = true;
        }
        if (x != true) {
            if (k == 3) {
                k += 2;
            }
        }
        sprite = new Sprite[k];
        for (int i = 0; i < k;i++) {
            texture.loadFromFile("car.png");
            sprite[i].setTexture(texture);
            sprite[i].setScale(1.4f, 1.4f);
            sprite[0].setPosition(260, 340);

            if (k == 3) {
                sprite[1].setPosition(260, 230);
                sprite[2].setPosition(260, 430);
            }
            if (k == 5) {
                sprite[1].setPosition(260, 230);
                sprite[2].setPosition(260, 450);
                sprite[3].setPosition(260, 560);
                sprite[4].setPosition(260, 90);
            }
        }

        num_of_lawn_movers = k;
    
        spawned = true;
        attack = 1000;


    }


    void draw(RenderWindow& window) {
        for (int i = 0; i < num_of_lawn_movers;i++) {
            if (sprite[i].getPosition().x <= window.getSize().x) {
                window.draw(sprite[i]);
            }
        }
    }
    Sprite& lawn_mover_getter(int i) {
        return sprite[i];
    }

    int getAttack() {
        return attack;
    }
};