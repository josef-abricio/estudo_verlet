#pragma once
#include<raylib.h>

class Point{
public:
    struct PointVertex{
        Vector2 position = {100,100};
        Vector2 old_position = {99.0, 99.0};
    };
    PointVertex pv;

    void update();
    void Draw(); 
};