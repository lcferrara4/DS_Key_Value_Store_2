// open.cpp: Open Addressing Map

#include "map.h"

#include <stdexcept>

// Methods --------------------------------------------------------------------


void            OpenMap::insert(const std::string &key, const std::string &value) {
}

const Entry     OpenMap::search(const std::string &key) {
    return NONE;
}

void            OpenMap::dump(std::ostream &os, DumpFlag flag) {
}

size_t          OpenMap::locate(const std::string &key) {
    return 0;
}

void            OpenMap::resize(const size_t new_size) {
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
