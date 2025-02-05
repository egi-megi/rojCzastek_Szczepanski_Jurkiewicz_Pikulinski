#ifndef ROJCZASTEK_SZCZEPANSKI_JURKIEWICZ_PIKULINSKI_OPTIMIZATIONEXERCISESCONFIG_H
#define ROJCZASTEK_SZCZEPANSKI_JURKIEWICZ_PIKULINSKI_OPTIMIZATIONEXERCISESCONFIG_H

#include <vector>
#include <istream>

class OptimizationExercisesConfig
{
public:
    OptimizationExercisesConfig();
    virtual ~OptimizationExercisesConfig() = default;
    virtual double computeCostFunctionValue(std::vector<double> positionVector) = 0;
    virtual bool isXInRange(double position);
    virtual bool isPositionInRange(std::vector<double> positionVector);

    double lowerLimitPositionVector;
    double upperLimitPositionVector;
};

#endif //ROJCZASTEK_SZCZEPANSKI_JURKIEWICZ_PIKULINSKI_OPTIMIZATIONEXERCISESCONFIG_H
