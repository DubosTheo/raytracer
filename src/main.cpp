#include <iostream>

#include "raytracer.hpp"

int main()
{
    try {
        raytracer raytracer;
        if (!raytracer.init())
            return EXIT_FAILURE;
        raytracer.run();
    } catch (std::out_of_range &e) {
        std::cerr << e.what();
    } catch (std::exception &e) {
        std::cerr << e.what();
    }
    return EXIT_SUCCESS;
}
