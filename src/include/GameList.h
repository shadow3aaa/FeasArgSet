#ifndef GAMELIST_H
#define GAMELIST_H

#pragma once

#include <string>

struct listGame {
    std::string name;
    unsigned int fixed_target_fps;
    int scaling_a;
    int scaling_b;
} __attribute__((packed)) __attribute__((aligned(64)));

#endif
