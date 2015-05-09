/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ModuleRam.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 14:10:46 by ycribier          #+#    #+#             */
/*   Updated: 2015/01/18 22:03:56 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULERAM_H
# define MODULERAM_H

# include "ModuleCurve.hpp"
# include <iostream>

class ModuleRam : public ModuleCurve {
public:
	ModuleRam(std::string title, int x, int y, int w, int h);
	virtual ~ModuleRam();

	void	update();
	static float	getLoad();

private:
	ModuleRam(ModuleRam const &);
	std::string	toString() const;
	ModuleRam&	operator=(ModuleRam const &);

};

// std::ostream & 	operator<<(std::ostream & o, ModuleRam const & i);

#endif /* !MODULERAM_H */
