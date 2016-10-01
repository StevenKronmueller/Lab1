
/* Name : Steven Kronmueller
 * Course : CST8236 - Graphics
 * Lab1 : Sky Dancer Ballon Man
 * Date : September 30th, 2016
 */

#include <SFML/Graphics.hpp>
#include "TransformNode.h"

int main(int argc, char* argv)
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "Lab1 - WavyMan");

	// Creating all the shapes
	sf::CircleShape headCircle(10.0f);
	sf::RectangleShape lowerRightArmRect(sf::Vector2<float>(15.0f, 5.0f));
	sf::RectangleShape upperRightArmRect(sf::Vector2<float>(15.0f, 5.0f));
	sf::RectangleShape lowerLeftArmRect(sf::Vector2<float>(15.0f, 5.0f));
	sf::RectangleShape upperLeftArmRect(sf::Vector2<float>(20.0f, 40.0f));
	sf::RectangleShape bodyRect(sf::Vector2<float>(20.0f, 40.0f));
	sf::RectangleShape neckRect(sf::Vector2<float>(10.0f, 50.0f));

	// Colouring all the shapes
	headCircle.setFillColor(sf::Color::Green);
	lowerRightArmRect.setFillColor(sf::Color::Blue);
	upperRightArmRect.setFillColor(sf::Color::Red);
	lowerLeftArmRect.setFillColor(sf::Color::Cyan);
	upperLeftArmRect.setFillColor(sf::Color::Magenta);
	bodyRect.setFillColor(sf::Color::Yellow);
	neckRect.setFillColor(sf::Color::White);

	bool keyHeld = false;

	// Setting the size of the shapes
	upperRightArmRect.setSize(sf::Vector2f(105.0f, 15.0f));
	upperLeftArmRect.setSize(sf::Vector2f(105.0f, 15.0f));
	lowerRightArmRect.setSize(sf::Vector2f(110.0f, 17.0f));
	lowerLeftArmRect.setSize(sf::Vector2f(90.0f, 17.0f));
	bodyRect.setSize(sf::Vector2f(35.0f, 250.0f));
	neckRect.setSize(sf::Vector2<float>(20.0f, 55.0f));
	
	// Head (circle) properties
	headCircle.setPosition(260, 160);
	headCircle.setScale(4, 4);

	// Lower arms left and right properties
	lowerRightArmRect.setPosition(310, 290);
	lowerRightArmRect.setOrigin(0.0f, 5.0f);
	lowerRightArmRect.rotate(330);

	lowerLeftArmRect.setPosition(100, 225);
	lowerLeftArmRect.setOrigin(0.0f, 5.0f);
	lowerLeftArmRect.rotate(30);

	// Upper arms left and right properties
	upperRightArmRect.setPosition(425, 230);
	upperRightArmRect.setOrigin(20.0f, 0.0f);
	upperRightArmRect.rotate(345);

	upperLeftArmRect.setPosition(195, 270);
	upperLeftArmRect.setOrigin(20.0f, 5.0f);
	upperLeftArmRect.rotate(15);

	// Body properties
	bodyRect.setPosition(280, 300);
	bodyRect.setOrigin(5.0f, 10.0f);

	// Neck properties
	neckRect.setPosition(288, 250);
	neckRect.setOrigin(2.0f, 15.0f);

	// TransformNodes for all the shapes
	TransformNode head(&headCircle);
	TransformNode neck(&neckRect);
	TransformNode upperRightArm(&upperRightArmRect);
	TransformNode upperLeftArm(&upperLeftArmRect);
	TransformNode lowerRightArm(&lowerRightArmRect);
	TransformNode lowerLeftArm(&lowerLeftArmRect);
	TransformNode body(&bodyRect);

	// Assembling big wavy man
	body.AddChild(&upperLeftArm);
	body.AddChild(&upperRightArm);
	body.AddChild(&neck);
	upperRightArm.AddChild(&lowerRightArm);
	upperLeftArm.AddChild(&lowerLeftArm);
	neck.AddChild(&head);


	sf::Clock deltaTime;
	sf::Clock timer;

	while (window.isOpen())
	{
		float elaspedTime = deltaTime.restart().asSeconds();
		sf::Transform transform = headCircle.getTransform();
			
	    float bodyAngle = 10.0f;
		float upperRightArmAngle = -20.0f;
		float upperLeftArmAngle = 20.0f;
		float lowerRightArmAngle = -20.0f;
	    float lowerLeftArmAngle = 20.0f;
		float neckAngle = -10.0f;
		float headAngle = 5.0f;


		sf::Event sfEvent;
		while (window.pollEvent(sfEvent))
		{
			if (sfEvent.type == sf::Event::Closed)
			{
				window.close();
			}
			else if (sfEvent.type == sf::Event::KeyReleased)
			{
				keyHeld = false;
			}
			else if (sfEvent.type == sf::Event::KeyPressed)
			{
				keyHeld = true;
				
			}
		}
		if (keyHeld) {
			bodyRect.rotate(bodyAngle * elaspedTime);
			upperLeftArmRect.rotate(upperLeftArmAngle * elaspedTime);
			upperRightArmRect.rotate(upperRightArmAngle * elaspedTime);
			lowerLeftArmRect.rotate(lowerLeftArmAngle * elaspedTime);
			lowerRightArmRect.rotate(lowerRightArmAngle * elaspedTime);
			neckRect.rotate(neckAngle * elaspedTime);
			headCircle.rotate(headAngle * elaspedTime);
			
		}
		


		// Draw the wavy man to the screen.
		window.clear();

		window.draw(headCircle);
		window.draw(neckRect);
		window.draw(bodyRect);
		window.draw(lowerRightArmRect);
		window.draw(upperRightArmRect);
		window.draw(lowerLeftArmRect);
		window.draw(upperLeftArmRect);
		
		window.display();
	}

	return 0;
}