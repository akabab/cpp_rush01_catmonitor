/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ModuleInfos.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 18:39:07 by ycribier          #+#    #+#             */
/*   Updated: 2015/01/18 20:28:54 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ModuleInfos.hpp"
#include <CoreFoundation/CoreFoundation.h>
#include <iostream>
#include <sstream>

ModuleInfos::ModuleInfos(std::string title, int x, int y, int w, int h)
    : Module(title, x, y, w, h) {

    char    info[128];
    size_t  len = sizeof(info);
    if (sysctlbyname("kern.ostype", &info, &len, NULL, 0 ) != -1)
        this->_osType = std::string(info);
    if (sysctlbyname("kern.osrelease", &info, &len, NULL, 0 ) != -1)
        this->_osRelease = std::string(info);
    if (sysctlbyname("kern.hostname", &info, &len, NULL, 0 ) != -1)
        this->_hostname = std::string(info);
    if (sysctlbyname("hw.machine", &info, &len, NULL, 0 ) != -1)
        this->_build = std::string(info);
}

void        ModuleInfos::update() {
    Module::update();

    this->draw();
}

void        ModuleInfos::draw() {
    Module::draw();

    //Text
    sf::Font font;
    font.loadFromFile("font/kg.ttf");

    std::ostringstream os;

    // sf::Text    text_osType(this->_osType.c_str(), font);
    // sf::Text    text_osRelease(this->_osRelease.c_str(), font);
    sf::Text    text_hostname(this->_hostname.c_str(), font);
    sf::Text    text_build(this->_build.c_str(), font);

    os << this->_osType << " " << this->_osRelease;
    sf::Text    text_os(os.str(), font);

    //Darwin
    text_os.setCharacterSize(25);
    text_os.setPosition(sf::Vector2f(60, 30));
    text_os.setColor(sf::Color::White);
    this->_window->draw(text_os);


    std::ostringstream moi;
    moi << "je suis " << this->_hostname << "10"; // << "sur OSX " << this->_build;
    sf::Text    text_moi(moi.str(), font);

    //e3r11p..
    text_moi.setCharacterSize(20);
    text_moi.setPosition(sf::Vector2f(30, 60));
    text_moi.setColor(sf::Color::White);
    this->_window->draw(text_moi);

    //x86_64
    text_build.setCharacterSize(18);
    text_build.setPosition(sf::Vector2f(140, 75));
    text_build.setColor(sf::Color::White);
    this->_window->draw(text_build);

    // text.setStyle(sf::Text::Bold);


    this->_window->display();
}

ModuleInfos::~ModuleInfos() {

}
