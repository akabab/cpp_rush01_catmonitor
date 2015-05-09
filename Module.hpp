/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Module.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 13:52:06 by ycribier          #+#    #+#             */
/*   Updated: 2015/01/18 20:02:52 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_H
# define MODULE_H

#include "./SFML/include/SFML/Graphics.hpp"
# include <iostream>

class Module {
public:
	Module(std::string title, int x, int y, int w, int h);
	Module(Module const &);
	virtual ~Module();
	static int 				theme;

	std::string	toString() const;

	virtual void	update();
	virtual void	draw();

	void			moveWindow();

	Module&	operator=(Module const &);

protected:
	bool					_active;
	sf::RenderWindow *		_window;

	std::string				_title;
	int						_x;
	int						_y;
	int						_width;
	int						_height;
	sf::RectangleShape		_rect;

private:
	Module();
};

std::ostream & 	operator<<(std::ostream & o, Module const & i);

#endif /* !MODULE_H */
