#ifndef BEST_IMPROVEMENT
#define BEST_IMPROVEMENT

#include "Improvement.hpp"

/**
 * At a specific step of an algorithm with a given Instance, Permutation and
 * score, the BestImprovement rules tries to find the best Permutation in the
 * given Neighbourhood in order to improve the score.
 */
class BestImprovement : public Improvement {
public:
    BestImprovement(const Instance& instance);
    
    Permutation improve(Permutation& p, Neighbourhood& n);
};

#endif // BEST_IMPROVEMENT
