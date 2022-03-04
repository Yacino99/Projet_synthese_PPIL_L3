//
// Created by Anwender on 18/02/2022.
//
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
