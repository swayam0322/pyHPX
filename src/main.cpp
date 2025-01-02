#include <nanobind/nanobind.h>
#include <hpx/hpx_main.hpp>
#include <hpx/iostream.hpp>

int main() {
    // Say hello to the world!
    hpx::cout << "Hello World!\n" << std::flush;
}

NB_MODULE(pyhpx, m) {
    m.def("main", &main);
}