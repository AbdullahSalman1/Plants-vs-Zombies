#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
using namespace sf;
using namespace std;
#include"zombie.h"
#include"zombiefactory.h"
class simpleZombie :public zombie {
private:

    Texture animationFrames[5]; // Array to store animation frames

    Clock frameTimer;
    int nf;
    int attack_timer;
    Texture eatingFrames[2];
    int eating_frames;
public:

    simpleZombie() :zombie("simple-0.png", 20, 5, 0.2f, 100)
    {

        // Load multiple textures representing different frames of animation
        for (int i = 0; i < 5; ++i) {
            // Load texture for the frame
            if (!animationFrames[i].loadFromFile("simple-" + to_string(i) + ".png")) {
                cerr << "Failed to load simple zombie frame " << i << endl;
            }
        }
        for (int i = 0; i < 2;i++) {
            if (!eatingFrames[i].loadFromFile("eat" + to_string(i) + ".png")) {
                cerr << "Failed to load Simple zombie eating frames " << i << endl;
            }
        }
        attack_timer = 6;
        nf = 5;//number of frames 
        zombieSpawnDelay_setter(10.0f);
        damage = 20;
        eating_frames = 2;
    }

    // Override function to get the current animation frame
    Texture& getCurrentAnimationFrame() override {
        return animationFrames[currentFrameIndex];
    }
    Texture& geteatingFrame()override {
        return eatingFrames[eating_frame_index];
    }

    void frame_number_setter(int i)override {
        nf = 5;
    }
    int frame_number_getter()override {
        return nf;
    }
    int eating_frames_getter() override {
        return eating_frames;
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
    void eating_frameNumber_setter(int n)override {
        eating_frames = n;
    }
    void eating_frame_number_setter(int i) override {
        eating_frame_index = i;
    }
    int eating_frame_number_getter()override {
        return eating_frame_index;
    }
    void animation_changer(int i) override {}
  

    Texture& bmovingtexture() { ///////////////
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







