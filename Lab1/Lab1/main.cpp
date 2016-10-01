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
	sf::CircleShape headCircle(10);
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
	upperRightArmRect.setSize(sf::Vector2f(105, 15));
	upperLeftArmRect.setSize(sf::Vector2f(105, 15));
	lowerRightArmRect.setSize(sf::Vector2f(110, 17));
	lowerLeftArmRect.setSize(sf::Vector2f(110, 17));
	bodyRect.setSize(sf::Vector2f(35, 250));
	neckRect.setSize(sf::Vector2<float>(20.0f, 50.0f));
	
	// Head (circle) properties
	headCircle.setPosition(260, 170);
	headCircle.setScale(4, 4);

	// Lower arms left and right properties
	lowerRightArmRect.setPosition(310, 300);
	lowerRightArmRect.setOrigin(5, 0);
	lowerRightArmRect.rotate(330);
	lowerLeftArmRect.setPosition(188, 245);
	lowerLeftArmRect.rotate(30);

	// Upper arms left and right properties
	upperRightArmRect.setPosition(405, 245);
	upperRightArmRect.setOrigin(5, 0);
	upperRightArmRect.rotate(345);
	upperLeftArmRect.setPosition(87, 220);
	upperLeftArmRect.rotate(15);

	// Body properties
	bodyRect.setPosition(280, 300);

	// Neck properties
	neckRect.setPosition(288, 250);

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
	head.AddChild(&neck);


	sf::Clock deltaTime;
	while (window.isOpen())
	{
		float elaspedTime = deltaTime.restart().asSeconds();

		sf::Transform transform = headCircle.getTransform();

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

		if (keyHeld)
		{
			float angleAmount = 15.0f;
			bodyRect.rotate(angleAmount * elaspedTime);
		}

		if (!keyHeld)
		{
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