/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ModuleNetwork.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 18:39:07 by ycribier          #+#    #+#             */
/*   Updated: 2015/01/18 23:22:34 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ModuleNetwork.hpp"
#include <iostream>
#include <sstream>

ModuleNetwork::ModuleNetwork(std::string title, int x, int y, int w, int h)
    : Module(title, x, y, w, h) {

    this->_t = 0;
}

void        ModuleNetwork::update() {
    Module::update();

    if (!this->_t) {
        this->_publicIp = sf::IpAddress::getPublicAddress(sf::Time::Zero);
        if (this->_publicIp.toInteger())
            this->_isConnected = true;
        else
            this->_isConnected = false;
    }
    ++this->_t;
    this->_t %= 300;

    ModuleNetwork::draw();
}

bool            ModuleNetwork::isConnected() {
    return this->_isConnected;
}

std::string     ModuleNetwork::getPublicIp() {
    return this->_publicIp.toString();
}


void        ModuleNetwork::draw() {
    Module::draw();



    //Text
    sf::Font font;
    font.loadFromFile("font/visitor1.ttf");


    sf::Text text(this->_publicIp.toString(), font);
    text.setCharacterSize(18);
    text.setPosition(sf::Vector2f(40, 40));
    // text.setStyle(sf::Text::Bold);
    text.setColor(sf::Color::White);
    this->_window->draw(text);

    std::ostringstream status;
    status << "je suis " << (this->_isConnected ? "connecte!" : "deconnecte!");
    sf::Text text2(status.str(), font);
    text2.setCharacterSize(17);
    text2.setPosition(sf::Vector2f(20, 70));
    this->_window->draw(text2);

    this->_window->display();
}

ModuleNetwork::~ModuleNetwork() {

}
