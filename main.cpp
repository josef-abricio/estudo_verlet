#include <raylib.h>
#include <iostream>
#include <cmath>
#include "Point/point.hpp"
#include "stick/stick.hpp"

void Janela(){
    InitWindow(800,600, "Simulação");
    SetTargetFPS(60);
}

float distancia(Vector2& point1, Vector2& point2){
    float cateto_x = point2.x - point1.x;
    float cateto_y = point2.y - point1.y;
    float pitagoras = sqrt(cateto_x * cateto_x + cateto_y * cateto_y);

    return pitagoras;
}

int main(){
    Janela();
    Point point;
    Stick stick;
    
    point.Load({100, 100}, {100,100});
    point.Load({200, 100}, {200,100});
    point.Load({200, 200}, {200,100});
    point.Load({100, 200}, {200,200});
    while(!WindowShouldClose()){
        Vector2 MousePos = GetMousePosition();
        point.update(0.1, 1);

        float cateto_x = point.listaVertex[0].position.x - point.listaVertex[2].position.x;
        float cateto_y = point.listaVertex[0].position.y - point.listaVertex[2].position.y;
        float diagonal1 = sqrt(cateto_x * cateto_x + cateto_y * cateto_y);

        float cateto_x1 = point.listaVertex[1].position.x - point.listaVertex[3].position.x;
        float cateto_y1 = point.listaVertex[1].position.y - point.listaVertex[3].position.y;
        float diagonal2 = sqrt(cateto_x1 * cateto_x1 + cateto_y1 * cateto_y1);

        stick.Update(point.listaVertex[0].position, point.listaVertex[1].position, 60);
        stick.Update(point.listaVertex[1].position, point.listaVertex[2].position, 60);
        stick.Update(point.listaVertex[2].position, point.listaVertex[3].position, 60);
        stick.Update(point.listaVertex[3].position, point.listaVertex[0].position, 60);
        stick.Update(point.listaVertex[0].position, point.listaVertex[2].position, 84);
        stick.Update(point.listaVertex[1].position, point.listaVertex[3].position, 84);

        if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
            point.listaVertex[0].position = MousePos;
        }
        BeginDrawing();
            ClearBackground(BLANK);
            point.Draw();
            stick.Render(point.listaVertex[0].position, point.listaVertex[1].position);
            stick.Render(point.listaVertex[1].position, point.listaVertex[2].position);
            stick.Render(point.listaVertex[2].position, point.listaVertex[3].position);
            stick.Render(point.listaVertex[3].position, point.listaVertex[0].position);
            stick.Render(point.listaVertex[0].position, point.listaVertex[2].position);
            stick.Render(point.listaVertex[1].position, point.listaVertex[3].position);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}