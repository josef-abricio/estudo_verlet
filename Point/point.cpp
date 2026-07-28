#include "point.hpp"

void Point::Load(Vector2 position, Vector2 old_position){
    pv.position = position;
    pv.old_position = old_position;
    
    listaVertex.push_back(pv);
}

void Point::update(float gravity, float friction){
    for(int i = 0; i < listaVertex.size(); i++){
        float velocty_x = (listaVertex[i].position.x - listaVertex[i].old_position.x) * friction;
        float velocty_y = (listaVertex[i].position.y - listaVertex[i].old_position.y) * friction;
        
        listaVertex[i].old_position.x = listaVertex[i].position.x;
        listaVertex[i].old_position.y = listaVertex[i].position.y;
        
        listaVertex[i].position.x += velocty_x;
        listaVertex[i].position.y += velocty_y + gravity;
        
        if( listaVertex[i].position.x < 0){
            listaVertex[i].position.x = 0;
            listaVertex[i].old_position.x = listaVertex[i].position.x + velocty_x;
        }
        if( listaVertex[i].position.x > 800){
            listaVertex[i].position.x = 800;
            listaVertex[i].old_position.x = listaVertex[i].position.x + velocty_x;
        }
        if( listaVertex[i].position.y < 0){
            listaVertex[i].position.y = 0;
            listaVertex[i].old_position.y = listaVertex[i].position.y + velocty_y;
        }
        if( listaVertex[i].position.y > 600){
            listaVertex[i].position.y = 600;
            listaVertex[i].old_position.y = listaVertex[i].position.y + velocty_y;
        }
    }
}

void Point::Draw(){
    for(int i = 0; i < listaVertex.size(); i++){
        DrawCircle(listaVertex[i].position.x, listaVertex[i].position.y, 3, WHITE);
    }
}