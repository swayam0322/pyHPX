#include <nanobind/nanobind.h>
#include "defs.hpp"

std::uint64_t fibonacci_hpx(std::uint64_t n) {
  if (n < 2)
    return n;

  hpx::future<std::uint64_t> n1 = hpx::async(fibonacci_hpx, n - 1);
  hpx::future<std::uint64_t> n2 = hpx::async(fibonacci_hpx, n - 2);

  return n1.get() + n2.get(); // wait for the Futures to return their values
}

NB_MODULE(pyhpx, m) {
    m.def("start", &start);
    m.def("stop", &stop);
    m.def("run", &fibonacci_hpx);
}