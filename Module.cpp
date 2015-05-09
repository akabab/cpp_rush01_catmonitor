/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Module.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 13:51:46 by ycribier          #+#    #+#             */
/*   Updated: 2015/01/18 22:02:10 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Module.hpp"
#include <sstream>

Module::Module(std::string title, int x, int y, int w, int h)
	: _active(true), _title(title), _x(x), _y(y), _width(w), _height(h) {
	this->_window = new sf::RenderWindow(sf::VideoMode(w, h), title, sf::Style::None);
	this->_window->setFramerateLimit(60);
	this->_window->setPosition(sf::Vector2<int>(_x, _y));

	_rect.setSize(sf::Vector2f(_width, _height));
	_rect.setFillColor(sf::Color::Black);
	_rect.setOutlineColor(sf::Color::White);
	_rect.setOutlineThickness(1);
}

Module::Module(Module const & src) {
	*this = src;
}

Module::~Module() {
	delete this->_window;
}

    sf::Vector2i grabbedOffset;
    bool grabbedWindow = false;

void		Module::moveWindow() {
	int x = std::rand() % 2400;
	int y = std::rand() % 1300;

	this->_window->setPosition(sf::Vector2<int>(x, y));
}

void		Module::update() {
	// if (!(std::rand() % 100))
	// 	this->moveWindow();

	// this->_window->setPosition(sf::Vector2<int>(this->_x++, this->_y++));


	if (!this->_active) {
		return;
	}

    this->_window->clear(sf::Color::Black);

    sf::Event event;

    while (this->_window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            this->_window->close();
        else if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Escape) {
                this->_active = false;
                this->_window->setVisible(this->_active); //must be handle somewhere else
            }
        }
        else if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                grabbedOffset = this->_window->getPosition() - sf::Mouse::getPosition();
                grabbedWindow = true;
            }
        }
        else if (event.type == sf::Event::MouseButtonReleased)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
                grabbedWindow = false;
        }
        else if (event.type == sf::Event::MouseMoved)
        {
            if (grabbedWindow)
                this->_window->setPosition(sf::Mouse::getPosition() + grabbedOffset);
        }
    }
}

void		Module::draw() {
	this->_window->draw(this->_rect);

	sf::Texture texture;
	sf::Image image;
    // std::cout << this->_bgImg << std::endl;
    std::ostringstream ss;
    ss << "img/bg-" << Module::theme << ".png";
	if (image.loadFromFile(ss.str())) {

		// image.createMaskFromColor(sf::Color(255,0,220), 0);
		texture.loadFromImage(image);
		sf::Sprite sprite;
		sprite.setTexture(texture);
		// sprite.setPosition(sf::Vector2f(this->_x, this->_y));
		this->_window->draw(sprite);
	}

	//Title
	sf::Font font;
	font.loadFromFile("font/qb.ttf");
	sf::Text text(this->_title, font);
	text.setCharacterSize(20);
	text.setPosition(sf::Vector2f(5, 7));
	// text.setStyle(sf::Text::Bold);
	text.setColor(sf::Color::White);
	this->_window->draw(text);

}

std::string		Module::toString() const {
	return "Module";
}

int Module::theme = 0;

Module &	Module::operator=(Module const & src) {
	return *this;
}

std::ostream &	operator<<(std::ostream & o, Module const & i) {
	o << i.toString();
	return o;
}
