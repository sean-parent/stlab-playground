#include <stlab/concurrency/future.hpp>
#include <stlab/concurrency/default_executor.hpp>
#include <stlab/concurrency/await.hpp>
#include <stlab/pre_exit.hpp>

#include <iostream>

using namespace stlab;
using namespace std;


int main() {
    future<int> f = async(default_executor, []() { return 42; });
    cout << await(std::move(f)) << endl;
    pre_exit();
}
