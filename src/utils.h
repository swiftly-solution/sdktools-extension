#ifndef _utils_h
#define _utils_h

#include <string>

template <typename... Args>
std::string string_format(const std::string &format, Args... args)
{
    int size_s = snprintf(nullptr, 0, format.c_str(), args...) + 1; // Extra space for '\0'
    if (size_s <= 0)
        return "";

    size_t size = static_cast<size_t>(size_s);
    char* buf = new char[size];
    snprintf(buf, size, format.c_str(), args...);
    std::string out = std::string(buf, buf + size - 1); // We don't want the '\0' inside
    delete buf;
    return out;
}

#endif