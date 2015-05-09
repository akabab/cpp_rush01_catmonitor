/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 12:52:13 by ycribier          #+#    #+#             */
/*   Updated: 2015/01/18 22:50:49 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./SFML/include/SFML/Graphics.hpp"

#include "ModuleCurve.hpp"
#include "ModuleInfos.hpp"
#include "ModuleCpu.hpp"
#include "ModuleRam.hpp"
#include "ModuleDate.hpp"
#include "ModuleNetwork.hpp"
#include "ModuleKitty.hpp"

#include <ctime>
#include <cstdlib>
#include <sstream>
#include <ncurses.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#define SHOW_NCURSE false

std::string toPercentStr(std::string prefix, float const val) {
    std::ostringstream ss;
	ss << prefix << static_cast<int>(val * 100) << "%";
	return ss.str();
}

void handleNcurse() {
    // Configure Ncurses
    initscr();                // Initialize ncurse
    curs_set(0);              // Hide cursor
    noecho();                 // Hide input
    nodelay(stdscr, true);    // No lock on input
    bool run = true;
    char    info[128];
    size_t  len = sizeof(info);
    std::ostringstream ss;
    if (sysctlbyname("kern.ostype", &info, &len, NULL, 0 ) != -1)
        ss << "Prenom du systeme : " << info;
    if (sysctlbyname("kern.osrelease", &info, &len, NULL, 0 ) != -1)
        ss << " - pas ubuntu " << info;
    if (sysctlbyname("kern.hostname", &info, &len, NULL, 0 ) != -1)
        ss << " - poste : " << info << "10";
    if (sysctlbyname("hw.machine", &info, &len, NULL, 0 ) != -1)
        ss << " - petit chiffres : " << info;
    while (getch() != 32) {
    	// Date
	    mvaddstr(0, 0, ("Date : " + ModuleDate::getDate()).c_str());
	    // Ram
	    mvaddstr(2, 0, toPercentStr("la memoire : ", ModuleRam::getLoad()).c_str());
	    // Cpu
	    mvaddstr(4, 0, toPercentStr("la puissance : ", ModuleCpu::getLoad() / 75 + 0.06f).c_str());
	    // Infos
	    mvaddstr(6, 0, ss.str().c_str());
	    // Unicorn
	    mvaddstr(8, 0, "                   n\n"
					   "        |\\   |  or\n"
					   "       _| \\-/ic\n"
					   "      /    un\n"
					   "    //    ~ + \\\n"
					   "   //         |\n"
					   "  //    \\      \\\n"
					   " |||     | .  .|\n"
					   "///     / \\___/");
    }
	endwin();

}

bool parseParams(int argc, char const *argv[]) {
	if (argc > 1) {
		std::string str(argv[1]);
		if (str == "-t" || str == "--text") {
			return SHOW_NCURSE;
		}
	}
	return true;
}

int     main(int argc, char const *argv[])
{
	std::srand(time(0));

	if (parseParams(argc, argv) == SHOW_NCURSE) {
		handleNcurse();
	} else {
		ModuleCpu		modCPU("Le processeur*", 2360, 10, 200, 100);
		ModuleRam		modRAM("La memoire", 2360, 125, 200, 100);
		ModuleDate		modDate("Date du jour", 2360, 230, 200, 100);
		ModuleInfos		modInfos("Informations", 2360, 335, 200, 100);
		ModuleNetwork	modNetwork("L'internet", 2360, 440, 200, 100);
		ModuleKitty		modCat("KittenPowa", 2360, 545, 200, 200);
		while (1) {
			modCPU.update();
			modRAM.update();
			modDate.update();
			modInfos.update();
			modNetwork.update();
			modCat.update();
		}
	}



/*
		float timeElapsed = clock.getElapsedTime().asSeconds();
		float fps = 1.f / timeElapsed;


		std::ostringstream fpsText;
		fpsText << "FPS: " << fps;*/


	return 0;
}
