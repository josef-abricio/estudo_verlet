#pragma once
#include <raylib.h>
#include <vector>
#include <iostream>
#include <random>

class Point{
public:
    struct PointVertex{
        Vector2 position = {100,100};
        Vector2 old_position = {95.0,95.0};
    };
    PointVertex pv;
    
    std::vector<PointVertex> listaVertex;

    void Load();
    void update(float gravity, float friction);
    void Draw();
};