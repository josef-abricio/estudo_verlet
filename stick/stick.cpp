#include "stick.hpp"

void Stick::Render(Vector2& point1, Vector2& point2){
    DrawLine(point1.x, point1.y, point2.x, point2.y, WHITE);
}