#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <instance_file>" << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
