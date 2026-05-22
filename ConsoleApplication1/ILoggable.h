#pragma once
#ifndef ILOGGABLE_H
#define ILOGGABLE_H

#include <string>

class ILoggable {
public:
    virtual void logToScreen() const = 0;
    virtual void logToFile(const std::string& filename) const = 0;
    virtual ~ILoggable() {}
};

#endif