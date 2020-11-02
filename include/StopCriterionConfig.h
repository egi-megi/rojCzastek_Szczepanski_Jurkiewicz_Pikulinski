//
// Created by Agnieszka Jurkiewicz on 01/11/2020.
//

#ifndef ROJCZASTEK_SZCZEPANSKI_JURKIEWICZ_PIKULINSKI_STOPCRITERIONCONFIG_H
#define ROJCZASTEK_SZCZEPANSKI_JURKIEWICZ_PIKULINSKI_STOPCRITERIONCONFIG_H
#include <vector>
#include <istream>

class StopCriterionConfig {
public:
    virtual double computeStopCriterion(double criterionValue)=0;
};


#endif //ROJCZASTEK_SZCZEPANSKI_JURKIEWICZ_PIKULINSKI_STOPCRITERIONCONFIG_H
