#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
using namespace sf;
using namespace std;

class Score {
private:
    Texture sunTexture;
    Sprite sunSprite;
    Font font;
    Text scoreText;

    Texture backgroundBox;
    Sprite box;
  

public:
    int scoreValue;
    Score() : scoreValue(50) {
        // Initialization
         // Load sun texture
        if (!sunTexture.loadFromFile("suno.png")) {
            cout << "Failed to load sun image!" << endl;
        }
        sunSprite.setTexture(sunTexture);
        sunSprite.setScale(0.1f, 0.1f); 
        sunSprite.setPosition(50, 50);

        // Load font for score text
        if (!font.loadFromFile("aerial.ttf")) {
            cout << "Failed to load font!" << endl;
        }
        scoreText.setFont(font);
        scoreText.setCharacterSize(15);
        scoreText.setFillColor(Color::White);
        scoreText.setPosition(70, 10); 

        if (!backgroundBox.loadFromFile("scorebox2.png")) {
            cout << "Failed to load box image!" << endl;
        }
        box.setTexture(backgroundBox);
        box.setPosition(65, 0);
       

    }

    //function overloading
    void addScore(int& value) {
        scoreValue += value;
    }

    void addScore(int a) {
        scoreValue += a;
    }

    void subtractScore(int value) {
        scoreValue -= value;
    }

    int getScore() {
        return scoreValue;
    }

    void update() {
        // Update score text
        scoreText.setString("Score: " + to_string(scoreValue));
    }

    void draw(RenderWindow& window) {
        // Draw score
        window.draw(box);
        window.draw(sunSprite);
        window.draw(scoreText);
    }
};
