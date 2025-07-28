#include <stlab/copy_on_write.hpp>

#include <iostream>
#include <cstdlib>

using namespace stlab;
using namespace std;

int main() {
    copy_on_write<int> p{42};
    auto q = p;
    q.write() = 43;
    std::cout << *p << std::endl;
    std::cout << *q << std::endl;
}
