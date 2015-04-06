#include <iostream>
#include <cstdlib>

#include "rules/Initialization/RandomInitialization.hpp"
#include "rules/Neighbourhood/Neighbourhood.hpp"
#include "rules/Pivoting/FirstImprovement.hpp"
#include "IterativeImprovement.hpp"
#include "rules/RulesFactory.hpp"
#include "GlobalArgs.hpp"
#include "Instance.hpp"

int main(int argc, char *argv[]) {
    GlobalArgs g(argv[0]);
    
    if (argc < 9) {
        std::cout << "Missing argument" << std::endl;
        g.printHelp();
        return EXIT_FAILURE;
    }

    g.retrieve(argc, argv);
    g.checkArgs();

    Instance instance(g.filePath.c_str());
    Initialization* initialization = RulesFactory::getInitialization(g.init,
        instance);
    Neighbourhood* neighbourhood = RulesFactory::getNeighbourhood(g.neighbourhood,
        instance.size());
    Improvement* improvement = RulesFactory::getPivotingRule(g.pivoting,
        instance, *neighbourhood);
    
    IterativeImprovement ii(instance, *initialization, *improvement);
    ii.run();
    
    delete initialization;
    delete neighbourhood;
    delete improvement;

    return EXIT_SUCCESS;
}
