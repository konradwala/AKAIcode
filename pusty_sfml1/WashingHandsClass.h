#ifndef WashingHandsClass_h
#define WashingHandsClass_h
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <cmath>
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>
#include <fstream>
#include <math.h>
#include <memory>
#include <time.h>

class WashingHands
{
public:
	WashingHands(std::string name, sf::RenderWindow *window);
	sf::Sprite hands;
	sf::Sprite soap;
	sf::Sprite brush;
	sf::Sprite foam;
	sf::Sprite sink;
	sf::Sprite tiles;
	sf::Sprite watersplash;
	sf::Texture handsTexture;
	sf::Texture soapTexture;
	sf::Texture brushTexture;
	sf::Texture foamTexture;
	sf::Texture sinkTexture;
	sf::Texture tilesTexture;
	sf::Texture wirus[4];
	sf::Event event;
	sf::Texture watersplashTexture[3];
	sf::Sprite waterrr;
	sf::Texture waterrrTexture;
	sf::Sprite waterButton;
	sf::Texture waterButtonTexture;
	
	
	std::vector<sf::Sprite> virus;

	bool soapGrabbed;
	bool brushGrabbed;
	bool waterOn;
	bool end;

	int counter;
	int result;

	std::string playerName;

	void settingTextures();
	void settingSprites();
	void draw(sf::RenderWindow* window);
	void play(sf::RenderWindow* window);
	bool collision(sf::Sprite sprite);
	void moveTools();
	void grabbingTools();
	void makingfoam();
	void splashingWater();
	void waterOnn();

	void saveResult();

};

#endif