#include <raylib.h>
#include <iostream>
#include "Point/point.hpp"

void Janela(){
    InitWindow(800,600, "Simulação");
    SetTargetFPS(60);
}

int main(){
    Janela();
    Point point;
    
    while(!WindowShouldClose()){
        point.update();

        BeginDrawing();
            ClearBackground(BLANK);
            point.Draw();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}