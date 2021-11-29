void CreatePlayer(){
    for (int i = 0; i < N_players; i++){
        Disparo disparo;
        Explosion explosion;
        Jugador player = {350,600};
        players[i] = player;
    }
    
    
};

void PrintPlayer(){
    //Mostramos un sprite u otro dependiendo de si está disparando o no
    players[0].disparo.disparando?esat::DrawSprite(playerDisparando,players[0].x,players[0].y+12):esat::DrawSprite(player,players[0].x,players[0].y);
    
    if(players[0].disparo.disparando){
        //Mostrar la bala
    }


    if(esat::IsSpecialKeyPressed(esat::kSpecialKey_Right)&& (players[0].x)+40<ANCHO*3){
        players[0].x+=velocidad_jugador;
    }
    if(esat::IsSpecialKeyPressed(esat::kSpecialKey_Left) && players[0].x>0){
        players[0].x-=velocidad_jugador;
    }

    if(esat::IsSpecialKeyDown(esat::kSpecialKey_Space)){
        players[0].disparo.disparando = true;
    }
}