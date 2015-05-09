/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ModuleCurve.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 13:52:06 by ycribier          #+#    #+#             */
/*   Updated: 2015/01/18 20:44:22 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULECURVE_H
# define MODULECURVE_H

# include "Module.hpp"
# include <list>
# include <iostream>

class ModuleCurve : public Module {
public:
	ModuleCurve(std::string title, int x, int y, int w, int h);
	virtual ~ModuleCurve();

	virtual void	update();
	void			draw();

	std::string	toString() const;


private:
	ModuleCurve();
	ModuleCurve(ModuleCurve const &);
	ModuleCurve&	operator=(ModuleCurve const &);

protected:
	std::list<float>		_vtx;
	int						_refreshDelay;
	int						_t;
	int						_offsetX;
	bool					_plus;
};

std::ostream & 	operator<<(std::ostream & o, ModuleCurve const & i);

#endif /* !MODULECURVE_H */
