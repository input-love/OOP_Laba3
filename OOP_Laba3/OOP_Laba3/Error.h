#pragma once
#include <string>

class Error: public std::exception {
public:
    Error(const std::string& value);
    const char* what() const override;

private:
    std::string _data;

};