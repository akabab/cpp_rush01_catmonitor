#ifndef MODULEINFOS_H
# define MODULEINFOS_H

# include "Module.hpp"
# include <sys/types.h>
# include <sys/sysctl.h>
# include <iostream>

class ModuleInfos : public Module {
public:
    ModuleInfos(std::string title, int x, int y, int w, int h);
    virtual ~ModuleInfos();

    void          update();
    void          draw();

private:
    ModuleInfos(ModuleInfos const &);
    std::string toString() const;
    ModuleInfos&  operator=(ModuleInfos const &);

    std::string		_osType;
    std::string		_osRelease;
    std::string		_hostname;
    std::string		_build;
};

// std::ostream &   operator<<(std::ostream & o, ModuleInfos const & i);

#endif
