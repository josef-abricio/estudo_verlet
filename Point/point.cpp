#include "point.hpp"

void Point::Load(){
    std::random_device rd;
    std::mt19937 gen(rd());
    
    for(int i = 0; i < 2; i++){
        listaVertex.push_back(pv);
    }
    for(int b = 0; b < listaVertex.size(); b++){
        std::uniform_int_distribution<int> valor_aleatoriosX(0, 800);
        std::uniform_int_distribution<int> valor_aleatoriosY(0, 600);

        listaVertex[b].position.x = float(valor_aleatoriosX(gen));
        listaVertex[b].position.y = float(valor_aleatoriosY(gen));

        listaVertex[b].old_position.x = listaVertex[b].position.x - 5;
        listaVertex[b].old_position.y = listaVertex[b].position.y - 5;
    }
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