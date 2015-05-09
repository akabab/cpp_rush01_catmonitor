#ifndef MODULEDATE_H
# define MODULEDATE_H

# include "Module.hpp"
# include <iostream>

class ModuleDate : public Module {
public:
    ModuleDate(std::string title, int x, int y, int w, int h);
    virtual ~ModuleDate();

    void          update();
    void          draw();
    static std::string   getDate();

private:
    ModuleDate(ModuleDate const &);
    std::string toString() const;
    ModuleDate&  operator=(ModuleDate const &);

};

// std::ostream &   operator<<(std::ostream & o, ModuleDate const & i);

#endif /* !MODULEDATE_H */
