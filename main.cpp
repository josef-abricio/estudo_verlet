#include <raylib.h>
#include <iostream>
#include "Point/point.hpp"
#include "stick/stick.hpp"

void Janela(){
    InitWindow(800,600, "Simulação");
    SetTargetFPS(60);
}

int main(){
    Janela();
    Point point;
    Stick stick;
    
    point.Load();
    while(!WindowShouldClose()){
        point.update(0.1, 1);
        stick.Update(point.listaVertex[0].position, point.listaVertex[1].position, 60);
        BeginDrawing();
            ClearBackground(BLANK);
            point.Draw();
            stick.Render(point.listaVertex[0].position, point.listaVertex[1].position);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}