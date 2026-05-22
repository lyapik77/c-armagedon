#pragma once
#ifndef ISHUFFLE_H
#define ISHUFFLE_H

#include <cstddef>

class IShuffle {
public:
    virtual void shuffle() = 0;
    virtual void shuffle(size_t i, size_t j) = 0;
    virtual ~IShuffle() {}
};

#endif