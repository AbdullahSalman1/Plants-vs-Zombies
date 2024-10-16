#pragma once
//#pragma once
//
#include <SFML/Graphics.hpp>
#include <ctime>
//#include <iostream>
using namespace sf;
using namespace std;


class zombie {
protected:

    // Index of the current animation frame
    bool isMoving;
    float frameChangeInterval; // Interval between frame changes (in seconds)
    Sprite sprite;
    Texture T;
    int numZombies; // Number of active zombies
    float zombieSpawnDelay; // Delay between zombie spawns
    Clock zombieSpawnTimer;
    Clock frameTimer;
    int hit_counter;
    int eating_frame_index;

    int walking_current_index;

public:
    int currentFrameIndex;
    int number_of_frames;
    float speed;
    int damage;
    int health;
    zombie() :currentFrameIndex(0), frameChangeInterval(1.0f), numZombies(0) {
        isMoving = true;
        hit_counter = 0;
        number_of_frames = 0;
        health = 100;
        eating_frame_index = 0;

    }
    zombie(const string& path, int i, int nf, float c, int heal) {
        T.loadFromFile(path);
        sprite.setTexture(T);
        damage = i;
        number_of_frames = nf;
        speed = c;
        health = heal;

    }
    Sprite& getSprite() {
        return sprite;
    }

    float zombieSpawnDelay_getter() {
        return zombieSpawnDelay;
    }

    void zombieSpawnDelay_setter(float f) {
        zombieSpawnDelay = f;
    }

    void setPosition(float x, float y) {
        sprite.setPosition(x, y);
    }

    int getTime() {
        return frameTimer.getElapsedTime().asSeconds();
    }

    float frame_getter() {
        return frameChangeInterval;
    }

    Clock& getClock() {
        return frameTimer;
    }
    void frame_index_setter(int n) {
        currentFrameIndex = n;

    }
    int frame_index_getter() {
        return currentFrameIndex;
    }

    //Pure virtual functions
    virtual Texture& getCurrentAnimationFrame() = 0; 
    virtual void frame_number_setter(int i) = 0;
    virtual int frame_number_getter() = 0;
    virtual void speed_setter(float c) = 0;
    virtual float speed_getter() = 0;
    virtual int attack_timer_getter() = 0;
    virtual int health_getter() = 0;
    virtual void health_reduction(int i) = 0;

    virtual int  eating_frames_getter() = 0;
    virtual Texture& geteatingFrame() = 0;
    virtual void eating_frameNumber_setter(int n) = 0;
    virtual void eating_frame_number_setter(int i) = 0;
    virtual int eating_frame_number_getter() = 0;
   virtual  void animation_changer(int i) = 0;



    virtual void balloon_moving_totalFrames(int n) = 0;

    virtual void balloon_moving_spec_frame_setter(int i) = 0;
    virtual int  balloon_moving_spec_frame_setter_getter() = 0;
    virtual int move_totaFrame_getter() = 0;
    virtual Texture& bmovingtexture() = 0;

    void movement_setter(bool x) {
        isMoving = x;
    }
    bool movement_getter() {
        return isMoving;
    }
    void incrementHitCounter() {
        hit_counter++;
    }
    int getHitCounter() {
        return hit_counter;
    }

};


