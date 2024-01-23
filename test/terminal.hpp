#pragma once

#include <mutex>
#include <string>

/**
 * A simple thread-safe interface to stdout and stdin.
 */
class Terminal {
public:
    std::string waitForInput();
    void writeToOutput(const std::string& str, bool newline = true);
    void writeToOutput(const char* str, bool newline = true);
    bool eof() const;

private:
    mutable std::mutex cout_mtx_;
};
