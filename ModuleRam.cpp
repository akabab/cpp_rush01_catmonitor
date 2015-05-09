/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ModuleRam.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 14:12:01 by ycribier          #+#    #+#             */
/*   Updated: 2015/01/18 16:48:07 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ModuleRam.hpp"
#include <mach/mach_init.h>
#include <mach/mach_error.h>
#include <mach/mach_host.h>
#include <mach/mach_types.h>
#include <mach/vm_map.h>
#include <mach/vm_statistics.h>

ModuleRam::ModuleRam(std::string title, int x, int y, int w, int h)
	: ModuleCurve(title, x, y, w, h) {

	this->_refreshDelay = 10;
	this->_t = 0;
	this->_offsetX = 2;
}

void		ModuleRam::update() {
	ModuleCurve::update();

	if (!this->_t) {
		this->_vtx.push_back(getLoad());
	}
	++this->_t %= this->_refreshDelay;

    if (this->_vtx.size() > this->_width / this->_offsetX + 1) {
    	this->_vtx.pop_front();
    }

    ModuleCurve::draw();
}

float		ModuleRam::getLoad() {
	vm_size_t page_size;
	mach_port_t mach_port;
	mach_msg_type_number_t count;
	vm_statistics64_data_t vm_stats;

	mach_port = mach_host_self();
	count = sizeof(vm_stats) / sizeof(natural_t);
	if (KERN_SUCCESS == host_page_size(mach_port, &page_size) &&
		KERN_SUCCESS == host_statistics64(mach_port, HOST_VM_INFO,
										(host_info64_t)&vm_stats, &count)) {
		float free_memory = vm_stats.free_count * page_size;
		float used_memory = (vm_stats.active_count +
								 vm_stats.inactive_count +
								 vm_stats.wire_count) *  page_size;

		float total_memory = free_memory + used_memory;
		return used_memory / total_memory;
	}
	return 0;
}

ModuleRam::~ModuleRam() {

}

