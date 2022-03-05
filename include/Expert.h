/**
 * \file      Expert.h
 * \date      04 mars 2022
 * \brief     Classe Expert
 */

#pragma once

#ifndef PROJET_EXPERT_H
#define PROJET_EXPERT_H

#include <string>

using namespace std;

class Formes;

class Expert
{
protected :
    virtual Formes * resoudre(const string & d) const = 0;
};

#endif //PROJET_EXPERT_H