#include <iostream>

#include "raytracer.hpp"

int main()
{
    try {
        raytracer raytracer;
        raytracer.run();
    } catch (std::out_of_range &e) {
        std::cerr << e.what();
    } catch (std::exception &e) {
        std::cerr << e.what();
    }
    return 0;
}
