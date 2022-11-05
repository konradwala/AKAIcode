#include"WashingHandsClass.h"
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
#include <ostream>

int randomInt(int min, int max)
{
	static std::default_random_engine e{ static_cast<long unsigned int>(time(0)) };
	std::uniform_int_distribution<int> d{ min, max };

	return d(e);
}

WashingHands::WashingHands(std::string name, sf::RenderWindow *window)
{
	playerName = name;
	settingTextures();
	settingSprites();

	play(window);
	

}

void WashingHands::settingTextures()
{
	handsTexture.loadFromFile("Hands2.png");
	soapTexture.loadFromFile("Soap1.png");
	brushTexture.loadFromFile("Brush1.png");
	foamTexture.loadFromFile("Foam1.png");
	sinkTexture.loadFromFile("Sink1.png");
	tilesTexture.loadFromFile("Tiles1.png");
	wirus[0].loadFromFile("Wirus1.png");
	wirus[1].loadFromFile("Wirus2.png");
	wirus[2].loadFromFile("Wirus3.png");
	wirus[3].loadFromFile("Wirus4.png");
	watersplashTexture[0].loadFromFile("Water2.png");
	watersplashTexture[1].loadFromFile("Water3.png");
	watersplashTexture[2].loadFromFile("Water4.png");
	waterrrTexture.loadFromFile("waterrrrr.png");
	waterButtonTexture.loadFromFile("water-button.png");
	
}

void WashingHands::settingSprites()
{
	hands.setTexture(handsTexture);
	soap.setTexture(soapTexture);
	brush.setTexture(brushTexture);
	foam.setTexture(foamTexture);
	sink.setTexture(sinkTexture);
	tiles.setTexture(tilesTexture);
	
	waterButton.setTexture(waterButtonTexture);

	hands.setPosition(140,200);
	soap.setPosition(100, 0);
	brush.setPosition(300, 0);
	foam.setPosition(0, 0);
	sink.setPosition(50, 50);
	watersplash.setPosition(260, 250);
	waterrr.setPosition(425, 155);
	waterButton.setPosition(550, 60);
	
	hands.setScale(1.1, 1);
	soap.setScale(0.35, 0.35);
	brush.setScale(0.35, 0.35);
	foam.setScale(1, 1);
	sink.setScale(1.25, 1.25);
	tiles.setScale(1.5, 1.5);
	watersplash.setScale(1.2, 1.2);
	waterrr.setScale(0.45, 0.45);
	waterButton.setScale(0.7, 0.7);

	soap.setOrigin(200, 200);

	soapGrabbed = false;
	brushGrabbed = false;
	waterOn = false;
	end = false;

	counter = 0;
	result = 0;

	for (int x = 0; x < 50; x++)
	{
		sf::Sprite wiruss;
		wiruss.setTexture(wirus[x%3]);
		wiruss.setScale(0.2, 0.2);
		while (true)
		{
			wiruss.setPosition(randomInt(150, 580), randomInt(200, 420));
			if (wiruss.getPosition().x > 290 && wiruss.getPosition().x < 430)
				continue;
			else
				break;
		}
		
		virus.push_back(wiruss);
	}
	

}

void WashingHands::draw(sf::RenderWindow* window)
{
	window->draw(tiles);
	window->draw(sink);
	window->draw(hands);
	
	//window->draw(brush);
	//window->draw(foam);

	for (int i = 0; i < virus.size(); i++)
		window->draw(virus[i]);

	window->draw(waterButton);
	window->draw(waterrr);
	window->draw(watersplash);
	
	window->draw(soap);
	
}

void WashingHands::play(sf::RenderWindow* window)
{
	while (end==false)
	{
		window->pollEvent(event);
		window->clear(sf::Color::White);
		//grabbingTools();
		makingfoam();
		moveTools();
		splashingWater();
		waterOnn();
		draw(window);
		window->display();
		if (virus.size() == 0)
			end = true;
		
	}
	saveResult();
	
}

bool WashingHands::collision(sf::Sprite sprite)
{
	if (sprite.getGlobalBounds().contains(event.mouseMove.x, event.mouseMove.y))
		return true;
		
}

void WashingHands::moveTools()
{
	if(collision(soap))
		soap.setPosition(event.mouseMove.x, event.mouseMove.y);

		
}

//void WashingHands::grabbingTools()
//{
//	if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
//	{
//		if (soapGrabbed == true)
//		{
//			soapGrabbed = false;
//			settingSprites();
//		}
//			
//		else
//			soapGrabbed = true;
//	}
//}


void WashingHands::makingfoam()
{
	for (int i = 0; i < virus.size(); i++)
	{
        if (virus[i].getGlobalBounds().contains(soap.getPosition().x, soap.getPosition().y) && randomInt(0, 30) == 0)
		{
			virus[i].setTexture(foamTexture);
			virus[i].setScale(0.4, 0.4);

		}
	}
}

void WashingHands::saveResult()
{
	std::fstream plik;
	plik.open("result.txt", std::ios::app);

	plik << playerName << " " << randomInt(5,10) << std::endl;

	plik.close();
	plik.clear();

	/*std::fstream plik;
	plik.open("result.txt", std::ios::out | std::ios::app);
	plik << playerName;
	plik << " ";
	plik << randomInt(80, 100);
	plik << std::endl;
	plik.close();*/

		/*std::ofstream myfile;
		myfile.open("result.txt");
		if (myfile.is_open())
		{
			myfile << randomInt(80,100);
			myfile.close();
		}
		else std::cout << "Nie mozna otworzyc pliku";*/
	
}

void WashingHands::splashingWater()
{
	
	if (waterOn)
	{
		if (counter % 30 == 0)
			watersplash.setTexture(watersplashTexture[0]);
		if (counter % 61 == 1)
			watersplash.setTexture(watersplashTexture[1]);
		if (counter % 93 == 2)
			watersplash.setTexture(watersplashTexture[2]);
        if (counter % 30 == 0&&virus.size()!=0)
		{
            if(virus.size()!=0)
                virus.pop_back();
            if(virus.size()!=0)
                virus.pop_back();
            if(virus.size()!=0)
                virus.pop_back();
			std::cout << virus.size() << std::endl;
			
		}
			
		
		
		waterrr.setTexture(waterrrTexture);
		counter++;
	}
}

void WashingHands::waterOnn()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		waterOn = true;
	}
	
}
