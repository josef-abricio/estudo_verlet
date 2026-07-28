#include "point.hpp"

void Point::update(float gravity, float friction){
    float velocty_x = (pv.position.x - pv.old_position.x) * friction;
    float velocty_y = (pv.position.y - pv.old_position.y) * friction;

    pv.old_position.x = pv.position.x;
    pv.old_position.y = pv.position.y;

    pv.position.x += velocty_x;
    pv.position.y += velocty_y + gravity;
}

void Point::Draw(){
    DrawCircle(pv.position.x, pv.position.y, 3, WHITE);
}