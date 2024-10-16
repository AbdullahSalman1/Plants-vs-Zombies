#pragma once
#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>

#include <iostream>
using namespace sf;
using namespace std;


class Balloon_zombie : public zombie {

    Texture eatingFrames[4];
    Texture walkingTexture[15];
    Clock frameTimer;

    int nf;

    int attack_timer;
    int eating_frames;

    int walking_frames;
public:
    Texture animationFrames[42];
    Balloon_zombie() : zombie("frame_0.gif", 25, 29, 0.2f, 125){

        nf = 4;
        attack_timer = 3;
        // Load multiple textures representing different frames of animation
        for (int i = 0; i < 4; ++i) {
            // Load texture for the frame
            if (!animationFrames[i].loadFromFile("baloon" + to_string(i) + ".png")) {
                cout << "Failed to load balloon zombie frame " << i << endl;
            }
        }

        for (int i = 0; i < 15 ; ++i) {
            // Load texture for the frame
            if (!walkingTexture[i].loadFromFile("bmove" + to_string(i) + ".png")) {
                cout << "Failed to load balloon zombie walking frame " << i << endl;
            }
        }

        for (int i = 0; i < 2;i++) {
            if (!eatingFrames[i].loadFromFile("eat" + to_string(i) + ".png")) {
                cout << "Failed to load football zombie eating frames " << i << endl;
            }
        }
        walking_frames = 15;
        damage = 25;
        zombieSpawnDelay_setter(10.0f);
        eating_frames = 2;

    }
    void animation_changer(int i) {
   //     animationFrames[i] = walkingTexture[i];
        animationFrames[i].loadFromFile("bmove" + to_string(i) + ".png");
    }

    // Override function to get the current animation frame
    Texture& getCurrentAnimationFrame() override {
        return animationFrames[currentFrameIndex];
    }
    void frame_number_setter(int i)override {
        nf = i;
    }
    int frame_number_getter()override {
        //    cout << "no of frames " <<number_of_frames<< endl;
        return nf;
    }
    void speed_setter(float c)override {
        speed = c;
    }
    float speed_getter()override {
        return speed;
    }
    int attack_timer_getter() {
        return attack_timer;
    }
    int health_getter()override {
        return health;
    }
    void health_reduction(int i)override {
        health -= i;
    }
    int eating_frames_getter() override {
        return eating_frames;
    }
    Texture& geteatingFrame()override {
        return eatingFrames[eating_frame_index];
    }
    void eating_frameNumber_setter(int n)override {
        eating_frames = n;
    }
    void eating_frame_number_setter(int i) override {
        eating_frame_index = i;
    }
    int eating_frame_number_getter()override {
        return eating_frame_index;
    }



    void balloon_moving_totalFrames(int n) override{
        walking_frames = 15;//******************
    }
    int move_totaFrame_getter() {
        return walking_frames;
    }

     void balloon_moving_spec_frame_setter(int i) {
         walking_current_index = i;
    }
     int  balloon_moving_spec_frame_setter_getter() {
         return walking_current_index;
     }
     Texture& bmovingtexture() {
         return walkingTexture[walking_current_index];
     }

};
