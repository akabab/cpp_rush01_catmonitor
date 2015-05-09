/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ModuleCpu.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 14:10:46 by ycribier          #+#    #+#             */
/*   Updated: 2015/01/18 22:04:03 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULECPU_H
# define MODULECPU_H

# include "ModuleCurve.hpp"
# include <iostream>

class ModuleCpu : public ModuleCurve {
public:
	ModuleCpu(std::string title, int x, int y, int w, int h);
	virtual ~ModuleCpu();

	void	update();
	static float	getLoad();

private:
	ModuleCpu(ModuleCpu const &);
	std::string	toString() const;
	ModuleCpu&	operator=(ModuleCpu const &);

};

// std::ostream & 	operator<<(std::ostream & o, ModuleCpu const & i);

#endif /* !MODULECPU_H */
