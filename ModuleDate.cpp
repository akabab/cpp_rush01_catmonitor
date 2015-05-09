/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ModuleDate.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 18:39:07 by ycribier          #+#    #+#             */
/*   Updated: 2015/01/18 18:48:30 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <CoreFoundation/CoreFoundation.h>
#include <iostream>
#include "ModuleDate.hpp"

std::string ModuleDate::getDate(void) {
    CFTimeZoneRef tz = NULL;
    CFGregorianDate d;
    char buff[23];

    tz = CFTimeZoneCopySystem();
    if (tz == NULL) { return "Date - Error"; }

    d = CFAbsoluteTimeGetGregorianDate(CFAbsoluteTimeGetCurrent(), tz);
    snprintf(buff, sizeof(buff), "%04d-%02d-%02d %02d:%02d:%06.2f",
        d.year, d.month, d.day, d.hour, d.minute, d.second);

    return std::string(buff);
}

ModuleDate::ModuleDate(std::string title, int x, int y, int w, int h)
    : Module(title, x, y, w, h) {
}

void        ModuleDate::update() {
    Module::update();
    ModuleDate::draw();
}


void        ModuleDate::draw() {
    Module::draw();

    //Text
    sf::Font font;
    font.loadFromFile("font/visitor1.ttf");
    sf::Text text(getDate(), font);
    text.setCharacterSize(18);
    text.setPosition(sf::Vector2f(3, this->_height / 2));
    // text.setStyle(sf::Text::Bold);
    text.setColor(sf::Color::White);
    this->_window->draw(text);

    this->_window->display();
}

ModuleDate::~ModuleDate() {

}
