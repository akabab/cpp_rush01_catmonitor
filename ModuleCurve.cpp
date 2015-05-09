/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ModuleCurve.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 13:51:46 by ycribier          #+#    #+#             */
/*   Updated: 2015/01/18 20:46:42 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ModuleCurve.hpp"
#include <mach/mach_init.h>
#include <mach/mach_error.h>
#include <mach/mach_host.h>
#include <mach/mach_types.h>
#include <mach/vm_map.h>
#include <mach/vm_statistics.h>


#include "./SFML/include/SFML/Graphics.hpp"

#include <sstream>

ModuleCurve::ModuleCurve(std::string title, int x, int y, int w, int h)
	: Module(title, x, y, w, h) {

	this->_plus = false;
}

ModuleCurve::~ModuleCurve() {

}

void		ModuleCurve::update() {
	Module::update();

}

void		ModuleCurve::draw() {
	Module::draw();

	std::list<float>::iterator		it;
	std::list<float>::iterator		ite = this->_vtx.end();

	//Curve
	int		padding = 20;
	int		startX = this->_width - (this->_vtx.size() - 1) * this->_offsetX;
	float	prev = -1;
	int 	i = -1;
	for (it = this->_vtx.begin(); it != ite; ++it) {
		if (prev != -1) {
	        sf::Vertex line[] = {
	            sf::Vertex(sf::Vector2f(this->_offsetX * i + startX, this->_height - (prev * 0.8 * this->_height)), sf::Color::White),
	            sf::Vertex(sf::Vector2f(this->_offsetX * (i + 1) + startX, this->_height - (*it * 0.8 * this->_height)), sf::Color::White)
	        };
        	this->_window->draw(line, 2, sf::Lines);
		}
		prev = *it;
		i++;
	}

	//Percent
	sf::Font font;
	font.loadFromFile("font/visitor1.ttf");
	std::ostringstream percent;
	percent << static_cast<int>(prev * 100) << '%';
	sf::Text text(percent.str(), font);
	text.setCharacterSize(15);
	text.setPosition(sf::Vector2f(this->_width - 30, this->_height - (prev * 0.8 * this->_height) - 19));
	// text.setStyle(sf::Text::Bold);
	text.setColor(sf::Color::White);
	this->_window->draw(text);

	if (this->_plus) {
	    sf::Font font;
	    font.loadFromFile("font/kg.ttf");
		sf::Text text(std::string("* Intel(R) Core(TM) i5-3470S @ 2.90GHz"), font);
		text.setCharacterSize(12);
		text.setPosition(sf::Vector2f(5, this->_height - 17));
		// text.setStyle(sf::Text::Bold);
		text.setColor(sf::Color::White);
		this->_window->draw(text);
	}

    this->_window->display();
}

std::string		ModuleCurve::toString() const {
	return "ModuleCurve";
}

std::ostream &	operator<<(std::ostream & o, ModuleCurve const & i) {
	o << i.toString();
	return o;
}
