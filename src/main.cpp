#include <iostream>

#include "raytracer.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
        return EXIT_FAILURE;
    try {
        raytracer raytracer(argv[1]);
        raytracer.run();
    } catch (std::out_of_range &e) {
        std::cerr << e.what();
    } catch (std::exception &e) {
        std::cerr << e.what();
    }
    return EXIT_SUCCESS;
}
