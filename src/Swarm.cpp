//
// Created by Agnieszka Jurkiewicz on 28/10/2020.
//
#include "../include/Swarm.h"
#include "../include/Particle.h"
#include <iostream>
#include <math.h>

using namespace std;

Swarm::Swarm(int mAmountOfParticles, int mVectorDim, OptimizationExercisesConfig* config)
{
    amountOfParticles = mAmountOfParticles;
    vectorDim = mVectorDim;

    makeSwarm(amountOfParticles, vectorDim, config);
}

Swarm::~Swarm()
{
}

void Swarm::makeSwarm(int amountOfParticles, int vectorDim, OptimizationExercisesConfig* config)
{
    for (int i = 0; i < amountOfParticles; i++)
    {
        Particle particle(vectorDim,this,config);
        swarm.push_back(particle);
    }
    Gbest = &swarm.front();
}


void Swarm::computeGbest(Particle *particle)
{
    if (Gbest->getCostFunctionValuePbest() > particle->getCostFunctionValuePbest())
    {
        Gbest = particle;
    }
}

Particle Swarm::findTheBestParticle(float academicCondition, float w, float speedConstant1, float speedConstant2)
{
    double modelValueOfCostFunction = 0;
    while (Gbest->getCostFunctionValuePbest() - modelValueOfCostFunction > academicCondition)
    {
        for (auto &singleParticle : swarm) // access by reference to avoid copying
        {
            singleParticle.computePosition(w, speedConstant1, speedConstant2);
            singleParticle.computeCostFunctionValue();
            singleParticle.computeParticlePbest();
            Swarm::computeGbest(&singleParticle);
            std::cout << Gbest->costFunctionValuePbest << std::endl;
        }
    }
    return *Gbest;

}


