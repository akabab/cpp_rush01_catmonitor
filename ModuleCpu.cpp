/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ModuleCpu.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 14:12:01 by ycribier          #+#    #+#             */
/*   Updated: 2015/01/18 22:04:40 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ModuleCpu.hpp"
#include <sys/types.h>
#include <sys/sysctl.h>

ModuleCpu::ModuleCpu(std::string title, int x, int y, int w, int h)
	: ModuleCurve(title, x, y, w, h) {

	this->_refreshDelay = 30;
	this->_t = 0;
	this->_offsetX = 20;
	this->_plus = true;
}

void		ModuleCpu::update() {
	ModuleCurve::update();

	if (!this->_t) {
		float	fakeLoad = static_cast<float>(std::rand() % 100) / 100;
		this->_vtx.push_back(fakeLoad);
	}
	++this->_t %= this->_refreshDelay;

    if (this->_vtx.size() > this->_width / this->_offsetX + 1) {
    	this->_vtx.pop_front();
    }

    ModuleCurve::draw();
}

float		ModuleCpu::getLoad() {
	return static_cast<float>(std::rand() % 100) / 100;
}

ModuleCpu::~ModuleCpu() {

}

