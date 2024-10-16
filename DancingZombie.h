#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>
#include "zombie.h"
//#include <iostream>
using namespace sf;
using namespace std;


class dancing_zombie : public zombie {
    Texture animationFrames[42]; // Array to store animation frames
    Texture eatingFrames[2];
    Clock frameTimer;

    int nf;

    int attack_timer;
    int eating_frames;
public:
    dancing_zombie() : zombie("frame_0.gif", 25, 29, 0.5f, 125)
    {

        nf = 42;
        attack_timer = 3;
        // Load multiple textures representing different frames of animation
        for (int i = 0; i < 42; ++i) {
            // Load texture for the frame
            if (!animationFrames[i].loadFromFile("frame_" + to_string(i) + ".gif")) {
                cerr << "Failed to load dancing frame " << i << endl;
            }
        }
        for (int i = 0; i < 2;i++) {
            if (!eatingFrames[i].loadFromFile("eat" + to_string(i) + ".png")) {
                cerr << "Failed to load football zombie eating frames " << i << endl;
            }
        }
        damage = 25;
        zombieSpawnDelay_setter(10.0f);
        eating_frames = 2;

    }

    // Override function to get the current animation frame
    Texture& getCurrentAnimationFrame() override {
        return animationFrames[currentFrameIndex];
    }
    void frame_number_setter(int i)override {
        nf = 42;
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
    void animation_changer(int i) override{}

    Texture& bmovingtexture() { 
        return animationFrames[0];
    }
    void balloon_moving_totalFrames(int n) override { }
    int move_totaFrame_getter() {
        return 1;
    }

    void balloon_moving_spec_frame_setter(int i) {
       
    }
    int  balloon_moving_spec_frame_setter_getter() {
        return 1;
    }
};
