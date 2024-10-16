#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <ctime>
#include <iostream>
using namespace sf;
using namespace std;
#include "level.h"
#include"BeginnersGarden.h"
#include"zombiesOutskirts.h"
#include"sunflowerfields_level.h"

class Game {
    SoundBuffer BackgroundSoundBuffer;
    Sound BackgroundSound;
public:
    int selected_level;
    Game(int n) {
        selected_level = n;
        // Load audio file
        if (!BackgroundSoundBuffer.loadFromFile("background.wav")) {
            cout << "Failed to load blast audio!" << endl;
        }
        BackgroundSound.setBuffer(BackgroundSoundBuffer);
    }
    int plants_selection_number = 0;
    level* level_1 = nullptr;

    void run() {
        BackgroundSound.play();
        Score score;

        RenderWindow window1;
        if (selected_level == 1) {
            level_1 = new BeginnersGarden(window1);
        }
        if (selected_level == 2) {
            level_1 = new Zombie_outskirts(window1);
        }
        if (selected_level == 3) {
            level_1 = new Sunflower_fields(window1);
        }

        level_1->initialize_lawn_mover(selected_level); //level dependent



        srand(time(NULL));
        RenderWindow window(VideoMode(1200, 700), "Plants Vs Zombies");


        level_1->zombies_factory_getter()->current_level_setter(selected_level);//level dependent
        while (window.isOpen()) {
            Event event;
            int xx = 1;
            while (window.pollEvent(event)) {
                if (event.type == Event::Closed)
                    window.close();

                level_1->run(event, window, score, level_1);
            }
            if (selected_level == 1)
                level_1->drawmap(window, "sp.png");
            if (selected_level == 2)
                level_1->drawmap(window, "level_1fin.jpg");
            if (selected_level == 3)
                level_1->drawmap(window, "FullPatch.jpg");
            level_1->draw_cards(window);
            level_1->draw_sunlights(window);

            // Spawn a new zombie
            level_1->zombies_factory_getter()->spawn_NewZombie();

            int t = level_1->handleCollisions(window);
             
            level_1->zombies_factory_getter()->updateAndDrawZombies(window, t);
            level_1->cherry_bomb_collision();
            //   level_1->temp = false;


            level_1->drawLawnMower(window);
            level_1->moveLawnMower();


            level_1->update();

            score.update();
            score.draw(window);



            level_1->bullet_update(window);
            level_1->draw_plants(window);
            level_1->draw_zombies(window);

            window.display();
        }
    }

};