/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ModuleKitty.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 19:01:21 by ycribier          #+#    #+#             */
/*   Updated: 2015/01/18 19:51:12 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ModuleKitty.hpp"
#include "Module.hpp"

ModuleKitty::ModuleKitty(std::string title, int x, int y, int w, int h)
	: Module(title, x, y, w, h) {

}

ModuleKitty::~ModuleKitty() {

}

sf::Vector2i grabbed2Offset;
bool grabbed2Window = false;

void		ModuleKitty::update() {
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
                // this->_active = false;
                // this->_window->setVisible(this->_active); //must be handle somewhere else
            }
        }
        else if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                grabbed2Offset = this->_window->getPosition() - sf::Mouse::getPosition();
                grabbed2Window = true;
            } else {
            	Module::theme++;
            	if (Module::theme > 3) {
            		Module::theme = 0;
            	}
            }
        }
        else if (event.type == sf::Event::MouseButtonReleased)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
                grabbed2Window = false;
        }
        else if (event.type == sf::Event::MouseMoved)
        {
            if (grabbed2Window)
                this->_window->setPosition(sf::Mouse::getPosition() + grabbed2Offset);
        }
    }

    this->draw();
}

void		ModuleKitty::draw() {
	Module::draw();

	sf::Texture texture;
	sf::Image image;
	if (!image.loadFromFile(this->_window->getPosition().x < 1280 ? "img/unicorn.png" : "img/kitten.png"))
		return;
	// image.createMaskFromColor(sf::Color(255,0,220), 0);
	texture.loadFromImage(image);
	sf::Sprite sprite;
	sprite.setTexture(texture);
	// sprite.setPosition(sf::Vector2f(this->_x, this->_y));
	this->_window->draw(sprite);

    this->_window->display();
}

std::string		ModuleKitty::toString() const {
	return "ModuleKitty";
}

std::ostream &	operator<<(std::ostream & o, ModuleKitty const & i) {
	o << i.toString();
	return o;
}
