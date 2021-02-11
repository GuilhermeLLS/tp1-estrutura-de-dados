#ifndef NODEROBO_HPP
#define NODEROBO_HPP

#include "Robo.hpp"

class NodeRobo{
    public:
        NodeRobo();
    private:
        Robo dado;
        NodeRobo *proximo;

    friend class FilaRobos;
};


#endif