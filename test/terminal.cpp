#include "terminal.hpp"

#include <iostream>

std::string Terminal::waitForInput() {
    writeToOutput("> ", false);

    std::string ret;
    std::getline(std::cin, ret, '\n');
    return ret;
}

void Terminal::writeToOutput(const std::string& str, bool newline) {
    writeToOutput(str.c_str(), newline);
}

bool Terminal::eof() const {
    return std::cin.eof();
}

void Terminal::writeToOutput(const char* str, bool newline) {
    auto lock = std::unique_lock<std::mutex>(cout_mtx_);
    std::cout << str;

    if (newline) {
        std::cout << '\n';
    }
}
