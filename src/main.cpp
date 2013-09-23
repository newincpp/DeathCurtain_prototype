#include <cstdlib>
#include "DisplayManager.hh"

int main(int ac, char** av) {
    DisplayManager* d;
    if (ac > 2) {
	d = new DisplayManager(std::atoi(av[1]), std::atoi(av[2]));
    } else {
	d = new DisplayManager();
    }
    d->run();
    return EXIT_SUCCESS;
}
