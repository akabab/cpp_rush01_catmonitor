/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ModuleKitty.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 19:01:31 by ycribier          #+#    #+#             */
/*   Updated: 2015/01/17 20:15:25 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULEKITTY_H
# define MODULEKITTY_H

# include "Module.hpp"
# include <iostream>
# include <list>

class ModuleKitty : public Module {
public:
	ModuleKitty(std::string title, int x, int y, int w, int h);
	virtual ~ModuleKitty();

	void	update();
	void	draw();

	std::string	toString() const;


private:
	ModuleKitty();
	ModuleKitty(ModuleKitty const &);
	ModuleKitty&	operator=(ModuleKitty const &);
	std::list<Module *>			_modules;

};

std::ostream & 	operator<<(std::ostream & o, ModuleKitty const & i);

#endif /* !MODULEKITTY_H */
