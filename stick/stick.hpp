#pragma once
#include <raylib.h>

class Stick{
public:

    struct stick_vertex{
        Vector2 point1;  
        Vector2 point2;  
    };
    stick_vertex st;

    void Update();
    void Render(Vector2& point1, Vector2& point2);
};