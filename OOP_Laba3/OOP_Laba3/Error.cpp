#include "Error.h"

Error::Error(const std::string& value): _data(value) {}

const char* Error::what() const {
    return _data.c_str();
}