#pragma once

#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <ctime>
#include <iostream>
#include "game.h"
using namespace sf;
using namespace std;

class MainMenu {
private:
    RenderWindow window;
    Texture openingTexture;
    Sprite openingSprite;
    Texture playButtonTexture;
    Sprite playButtonSprite;
    Texture levelMenuTexture;
    Sprite levelMenuSprite;
    Texture level1_BoxTexture;
    Texture level2_BoxTexture;
    Texture level3_BoxTexture;
    Sprite levelBoxSprite1;
    Sprite levelBoxSprite2;
    Sprite levelBoxSprite3;
    bool isLevelMenuVisible = false;
    bool isGameStarted = false;

    SoundBuffer ButtonBuffer;
    Sound ButtonSound;
    Texture instructions;
    Sprite instructionsSprite;
    Clock timer;
public:
    SoundBuffer BackgroundSoundBuffer;
    Sound BackgroundSound;
    MainMenu() {
        // Load audio file
        if (!BackgroundSoundBuffer.loadFromFile("background.wav")) {
            cout << "Failed to load blast audio!" << endl;
        }
        BackgroundSound.setBuffer(BackgroundSoundBuffer);
    
        // Load opening screen image
        if (!openingTexture.loadFromFile("file.png")) {
            cout << "Failed to load opening screen image!" << endl;
            return;
        }
        openingSprite.setTexture(openingTexture);

        // Load "Play Game" button image
        if (!playButtonTexture.loadFromFile("startgame.png")) {
            cout << "Failed to load play button image!" << endl;
            return;
        }
        playButtonSprite.setTexture(playButtonTexture);
        playButtonSprite.setPosition(475, 600); // Adjust position as needed

        // Load level menu image
        if (!levelMenuTexture.loadFromFile("menu3_2.png")) {
            cout << "Failed to load level menu image!" << endl;
            return;
        }
        levelMenuSprite.setTexture(levelMenuTexture);

        // Load level box image
        if (!level1_BoxTexture.loadFromFile("L1.png")) {
            cout << "Failed to load level box image!" << endl;
            return;
        }if (!level2_BoxTexture.loadFromFile("L2.png")) {
            cout << "Failed to load level box image!" << endl;
            return;
        }if (!level3_BoxTexture.loadFromFile("L3.png")) {
            cout << "Failed to load level box image!" << endl;
            return;
        }
        if (!ButtonBuffer.loadFromFile("buttonclick.mp3")) {
            cout << "Failed to load button audio!" << endl;
        }
        if (!instructions.loadFromFile("instruc.jpg")) {
            cout << "Failed to load instructions image!" << endl;
            return;
        }
        ButtonSound.setBuffer(ButtonBuffer);
        levelBoxSprite1.setTexture(level1_BoxTexture);
        levelBoxSprite2.setTexture(level2_BoxTexture);
        levelBoxSprite3.setTexture(level3_BoxTexture);
        instructionsSprite.setTexture(instructions);
        // Set position for level boxes
        levelBoxSprite1.setPosition(300, 200);
        levelBoxSprite2.setPosition(500, 200);
        levelBoxSprite3.setPosition(700, 200);
    }


    void run() {
        BackgroundSound.play();
        window.create(VideoMode(1200, 700), "Main Menu");
        while (window.isOpen()) {
            Event event;
            while (window.pollEvent(event)) {
                if (event.type == Event::Closed)
                    window.close();
                else if (!isGameStarted && event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                    int mouseX = event.mouseButton.x;
                    int mouseY = event.mouseButton.y;
                
                    if (!isLevelMenuVisible) {
                        // Check if "Play Game" button is clicked
                        if (mouseX >= 475 && mouseX <= 725 && mouseY >= 600 && mouseY <= 675) {
                          
                            ButtonSound.play();
                            isLevelMenuVisible = true;
                      
                      
                            timer.restart(); // Restart the timer for instructions
                          
                        }
                    }
                    else {
                      
                     
                        
                        // Check if any level box is clicked
                        if (mouseY >= 200 && mouseY <= 360) {
                            if (mouseX >= 300 && mouseX <= 460) {
                                ButtonSound.play();
                                startGameWithLevel(1);
                            
                           
                            }
                            else if (mouseX >= 500 && mouseX <= 655) {
                                ButtonSound.play();
                                startGameWithLevel(2);
                             
                            
                            }
                            else if (mouseX >= 700 && mouseX <= 855) {
                                ButtonSound.play();
                                startGameWithLevel(3);
                        
                               
                            }
                        }
                    }
                }
            }

            window.clear();
            if (!isLevelMenuVisible) {
             
                window.draw(openingSprite);
                window.draw(playButtonSprite);
            }
            else {
                window.draw(instructionsSprite);
                // Check if the instructions timer has reached 10 seconds
                if (timer.getElapsedTime().asSeconds() >= 4) {
                    window.draw(levelMenuSprite);
                    window.draw(levelBoxSprite1);
                    window.draw(levelBoxSprite2);
                    window.draw(levelBoxSprite3);
                }
            }
            window.display();
            
        }
       
    }
  
    // Method to start the game with a selected level
    void startGameWithLevel(int level) {
   
        window.close();
        // Start the game with the selected level
        Game g(level);
        g.run();
    }
};
