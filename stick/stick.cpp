#include "stick.hpp"

void Stick::Update(Vector2& point1, Vector2& point2, int length){
    //teorema de pitagoras para descobrir a distancia
    float cateto_X = point2.x - point1.x;
    float cateto_Y = point2.y - point1.y;
    float distance = sqrt(cateto_X * cateto_X + cateto_Y * cateto_Y);
    //A diferenã faz a margem de erro(exp: um ponto esta na distancia 15 mais deveria ser 10, 
    //diferença de 5 para consertar 
    float diferenca = length - distance;
    //pega a diferença e transforma em uma porcentagem, mas divide por 2 porque e para cada ponto
    float porcentagem = diferenca/distance/2;
    //os deslocamentos e a multiplicação de quanto precissa movimentar para poder completar a diferença
    float deslocamento_x = cateto_X * porcentagem;
    float deslocamento_y = cateto_Y * porcentagem;
    //aplicando o movimento nos pontos para poder os pontos se aproximarem um dos outros 
    //assim mantendo o tamanho pre-definido
    point1.x -= deslocamento_x * 0.5;
    point1.y -= deslocamento_y * 0.5;
    point2.x += deslocamento_x * 0.5;
    point2.y += deslocamento_y * 0.5;
}

void Stick::Render(Vector2& point1, Vector2& point2){
    DrawLine(point1.x, point1.y, point2.x, point2.y, WHITE);
}