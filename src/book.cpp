#include <book.h>
#include <string>
#include <thread>

void Book::setId(std::string id) {
    this->id = id;
    std::thread T;
    T.join();
}
