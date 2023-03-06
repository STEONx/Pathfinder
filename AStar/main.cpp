#include <SFML/Graphics.hpp>
#include <iostream>

#include <vector>
#include "findway.h"
#include <math.h>

#include <algorithm>
using namespace find;
struct vertex2d
{
	find::vector2d x1;
	find::vector2d x2;

};
int main()
{
	sf::Vector2i CurrentMousePosition;
	sf::Vector2i StartMousePosition;
	
	std::vector<sf::RectangleShape> listposition;
	std::vector<vertex2d> pathposition;

	int aster[20][20];
	
	
	//std::vector<Button> buttonlist;
	Raster finder = {aster };
	for (int i = 0; i < 20; i++) {
		for (int v = 0; v < 20; v++)
		{
			finder.raster[i][v]=0;
			



		}
	}


	sf::RenderWindow window(sf::VideoMode(1800, 1000), "pong");
	//Button goal = { 70,70,800,800,"goalbtn" };
	//buttonlist.push_back(goal);
	
	window.setFramerateLimit(60);
	
	for(int i =0; i<20;i++){
		for (int v = 0; v < 20; v++) {
			
			sf::RectangleShape rectangle2(sf::Vector2f(34 - 4, 34 - 4));
			rectangle2.setFillColor(sf::Color(200,200,200));
			rectangle2.setPosition(30 * i+4	, 30 * v+4);
			listposition.push_back(rectangle2);
		}
	}
	

	while (window.isOpen())
	{
		sf::Event event;
		
		// get global mouse position
		
		// set mouse position relative to a window
		

		finder.vecpos();
		
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
		}		
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			finder.vecpos();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
				
				finder.doonestep();
				vector2d x111;
				vector2d x222;
				x111.X = finder.x11.X*30+17;
				x111.Y = finder.x11.Y * 30 + 17;
				x222.X = finder.x22.X * 30 + 17;
				x222.Y = finder.x22.Y * 30 + 17;
				std::cout <<"x22:" << x222.Y;
				vertex2d k;
				k.x1 = x111;
				k.x2 = x222;

				pathposition.push_back(k);
				
				//listposition[index].setFillColor(sf::Color::Yellow);
			}
			int locationx;
			int locationy;
			int index;

			sf::Vector2i position = sf::Mouse::getPosition(window);
			locationx = (position.x / 30) * 20;
			int locationxx = (position.x / 30);
			int locationyy = position.y / 30;
			locationy = position.y / 30;
			index = locationx + locationy;
			if (index < listposition.size()) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {
					
					finder.raster[locationxx][locationyy] = 4;
					//finder.vecpos();
					//listposition[index].setFillColor(sf::Color::Yellow);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
					finder.raster[locationxx][locationyy] = 0;

					//listposition[index].setFillColor(sf::Color(200, 200, 200));
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
					
					
					finder.raster[locationxx][locationyy] = 1;

					//finder.vecpos();
					//listposition[index].setFillColor(sf::Color::White); 
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
					finder.raster[locationxx][locationyy] = 3;
					//listposition[index].setFillColor(sf::Color::Cyan);
				}
				//action zuteilung
			}
			


		}
		
		for (int i = 0; i < 20; i++) {
			for (int v = 0; v < 20; v++)
			{
				int res = finder.raster[i][v];
				if (res == 0) {
					listposition[i * 20 + v].setFillColor(sf::Color(200,200,200));

				}
				if (res == 1) {
					listposition[i * 20 + v].setFillColor(sf::Color::Red);
					
				}
				if (res == 3) {
					listposition[i * 20 + v].setFillColor(sf::Color::Black);

				}
				if (res == 4) {
					listposition[i * 20 + v].setFillColor(sf::Color::Yellow);

				}
				if (res == 5) {
					
					listposition[i * 20 + v].setFillColor(sf::Color::Green);

				}
				if (res == 6) {

					listposition[i * 20 + v].setFillColor(sf::Color::Magenta);

				}
				if (res == 7) {

					listposition[i * 20 + v].setFillColor(sf::Color(0,150,240));

				}


			}
		}
		
	
		window.clear();

		/*for (auto j : pathposition) {
			sf::RectangleShape rectangle(sf::Vector2f(24, 2));

			
			/*sf::Vertex line[] =
			{
				sf::Vertex(sf::Vector2f(j.x1.X, j.x1.Y)),
				sf::Vertex(sf::Vector2f(j.x2.X, j.x2.Y))
			};
			

			window.draw(line, 2, sf::Lines);
			 
			//rechts unten
			if (j.x1.X< j.x2.X, j.x1.Y< j.x2.X) {
				sf::RectangleShape rectangle(sf::Vector2f(24, 2));
				
				rectangle.setFillColor(sf::Color(0, 0, 0));
				rectangle.setPosition(j.x1.X, j.x1.Y);
				rectangle.setRotation(45);
				window.draw(rectangle);
			}
			//lins unten

			if (j.x1.X >j.x2.X, j.x1.Y < j.x2.Y) {
				sf::RectangleShape rectangle(sf::Vector2f(24, 2));

				rectangle.setFillColor(sf::Color(0, 0, 0));
				rectangle.setPosition(j.x1.X, j.x1.Y);
				rectangle.setRotation(135);
				window.draw(rectangle);
			}
			//rechts oben
			if (j.x1.X< j.x2.X, j.x1.Y> j.x2.X) {
				sf::RectangleShape rectangle(sf::Vector2f(24, 2));
				
				rectangle.setFillColor(sf::Color(0, 0, 0));
				rectangle.setPosition(j.x1.X, j.x1.Y);
				rectangle.setRotation(315);
				window.draw(rectangle);
			}
			//lins oben

			if (j.x1.X >j.x2.X, j.x1.Y > j.x2.Y) {
				sf::RectangleShape rectangle(sf::Vector2f(24, 2));

				rectangle.setFillColor(sf::Color(0, 0, 0));
				rectangle.setPosition(j.x1.X, j.x1.Y);
				rectangle.setRotation(225);
				window.draw(rectangle);
			}
			//oben
			if (j.x1.X == j.x2.X, j.x1.Y > j.x2.Y) {
				sf::RectangleShape rectangle(sf::Vector2f(17, 2));

				rectangle.setFillColor(sf::Color(0, 0, 0));
				rectangle.setPosition(j.x1.X, j.x1.Y);
				rectangle.setRotation(270);
				window.draw(rectangle);
			}
			//unten
			if (j.x1.X == j.x2.X, j.x1.Y  <j.x2.Y) {
				sf::RectangleShape rectangle(sf::Vector2f(17, 2));

				rectangle.setFillColor(sf::Color(0, 0, 0));
				rectangle.setPosition(j.x1.X, j.x1.Y);
				rectangle.setRotation(90);
				window.draw(rectangle);
			}
			//rechts
			if (j.x1.X < j.x2.X, j.x1.Y == j.x2.Y) {
				sf::RectangleShape rectangle(sf::Vector2f(17, 2));

				rectangle.setFillColor(sf::Color(0, 0, 0));
				rectangle.setPosition(j.x1.X, j.x1.Y);
				rectangle.setRotation(0);
				window.draw(rectangle);
			}
			//links
			if (j.x1.X > j.x2.X, j.x1.Y == j.x2.Y) {
				sf::RectangleShape rectangle(sf::Vector2f(17, 2));

				rectangle.setFillColor(sf::Color(0, 0, 0));
				rectangle.setPosition(j.x1.X, j.x1.Y);
				rectangle.setRotation(180);
				window.draw(rectangle);
			}

			
			
			
			
		}*/
		
		

		
		
		
		
		for (auto d : listposition) {
			sf::RectangleShape rectangle(sf::Vector2f(38, 38));
			rectangle.setFillColor(sf::Color(0, 30, 255));
			rectangle.setPosition(d.getPosition().x-4, d.getPosition().y - 4);
			window.draw(rectangle);
			window.draw(d);

		}
		//for (auto d : buttonlist) {
			//window.draw(d.rectangle2);
			//window.draw(d.text);
		//}
		for (auto j : pathposition) {
			sf::RectangleShape rectangle(sf::Vector2f(24, 2));


			sf::Vertex line[] =
			{
				sf::Vertex(sf::Vector2f(j.x1.X, j.x1.Y)),
				sf::Vertex(sf::Vector2f(j.x2.X, j.x2.Y))
			};


			window.draw(line, 2, sf::Lines);
		}


		window.display();
		
		
	}
	return 0;
}

