/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ModuleNetwork.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 22:22:49 by ycribier          #+#    #+#             */
/*   Updated: 2015/01/18 23:12:43 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULENETWORK_H
# define MODULENETWORK_H

# include "./SFML/include/SFML/Network.hpp"
# include "Module.hpp"
# include <iostream>

class ModuleNetwork : public Module {
public:
    ModuleNetwork(std::string title, int x, int y, int w, int h);
    virtual ~ModuleNetwork();

    void          update();
    void          draw();

    bool			isConnected();
    std::string		getPublicIp();

private:
    ModuleNetwork(ModuleNetwork const &);
    std::string toString() const;
    ModuleNetwork&  operator=(ModuleNetwork const &);

    bool					_isConnected;
    sf::IpAddress			_publicIp;
    int _t;
};

// std::ostream &   operator<<(std::ostream & o, ModuleNetwork const & i);

#endif /* !MODULENETWORK_H */
