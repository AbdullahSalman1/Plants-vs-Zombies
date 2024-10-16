#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <ctime>
#include <iostream>
using namespace sf;
using namespace std;
#include"plant.h"


class cherryBomb :public plants {
private:
    Clock blast_timer;
    //  Sprite blast_cherry[10];
    Texture blast_cherryTexture;
    int no_of_cherryBomb;
    bool remove_zombies;
    Clock blast_frame;

public:
    cherryBomb() : plants("cherryupd.png") {
        if (!blast_cherryTexture.loadFromFile("suno.png")) {
            cout << "Failed to load sun image!" << endl;
        }
        remove_zombies = false;
     

    }

    void drawBullets(RenderWindow& window) override {
        //  for (int i = 0; i < no_of_cherryBomb;i++) {
           //   window.draw(blast_cherry[i]);
          //}
    }



    void fire_update(int i, plants* currentPlant) override {
        remove_zombies = false;
        if (blast_timer.getElapsedTime().asSeconds() >= 4) {
            // Change the texture of the cherry bomb sprite to blast texture
            blast_frame.restart();
            if (!blast_cherryTexture.loadFromFile("cherrybombblast.png")) {
                cout << "Failed to load blast cherry bomb texture!" << endl;
                // Handle failure to load blast texture
                cout << "blast 2" << endl;
            // Set the blast cherry bomb texture
            currentPlant->sprite.setTexture(blast_cherryTexture);
            remove_zombies = true;
            // Restart the timer
            blast_timer.restart();
            blast_frame.restart();
        }
        // Check if it's time to remove the cherry bomb plant
        if (blast_frame.getElapsedTime().asSeconds() >= 3) {
            // Set the position of the cherry bomb plant off-screen
            currentPlant->sprite.setPosition(-1000, -1000);
            cout << "blast 3" << endl;
        }
       
        }


    }


    void fire_position(int a, int b, int n)override {}
    Sprite& bullets_getter(int i) {
        return sprite;
    }
    int hit_counter_getter() {
        if (blast_frame.getElapsedTime().asSeconds() >= 2) {
            return 1;
        }
        else {
            return 0;
        }
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