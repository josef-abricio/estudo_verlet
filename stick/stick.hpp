#pragma once
#include <raylib.h>
#include <cmath>

class Stick{
public:

    struct stick_vertex{
        Vector2 point1;  
        Vector2 point2; 
    };
    stick_vertex st;

    void Update(Vector2& point1, Vector2& point2, float length);
    void Render(Vector2& point1, Vector2& point2);
};