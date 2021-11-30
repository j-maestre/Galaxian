void CreatePlayer(){
    for (int i = 0; i < N_players; i++){
        Disparo disparo;
        Explosion explosion;
        Jugador player = {350,600};
        players[i] = player;
    }
    
};

void ExplosionPlayer(){
    fps_count_explosion_player++;

    //Cada 0'25 segundos muestro una animacion de la explosion
    if(fps_count_explosion_player>fps*(explosion_selector*0.1))explosion_selector++;
    if(explosion_selector<4){
        esat::DrawSprite(playerExplosion[explosion_selector],players[player_actual].explosion.x,players[player_actual].explosion.y);

        //Cuando ya he mostrado todas las explosiones, dejo de explotar y reinicio las variables
    }else if(explosion_selector>=4){
        explosion_selector=0;
        fps_count_explosion_player = 0;
        players[player_actual].explosion.explotando = false;
    }
    // esat::DrawSprite();
    
    
}

void PrintPlayer(){
    if(!players[player_actual].explosion.explotando){
        //Mostramos un sprite u otro dependiendo de si está disparando o no
        players[player_actual].disparo.disparando?esat::DrawSprite(playerDisparando,players[player_actual].x,players[player_actual].y+12):esat::DrawSprite(player,players[player_actual].x,players[player_actual].y);
        
        if(players[player_actual].disparo.disparando){
            //Mostrar la bala
            esat::DrawSprite(disparoPlayer,players[player_actual].disparo.x+20,players[player_actual].disparo.y-=velocidad_disparo_player);
            if(players[player_actual].disparo.y<=0)players[player_actual].disparo.disparando = false;
        }


        if(esat::IsSpecialKeyPressed(esat::kSpecialKey_Right)&& (players[player_actual].x)+40<ANCHO*3){
            players[player_actual].x+=velocidad_jugador;
        }
        if(esat::IsSpecialKeyPressed(esat::kSpecialKey_Left) && players[player_actual].x>0){
            players[player_actual].x-=velocidad_jugador;
        }

        if(esat::IsSpecialKeyDown(esat::kSpecialKey_Space) && !players[player_actual].disparo.disparando){
            players[player_actual].disparo.disparando = true;
            players[player_actual].disparo.x = players[player_actual].x;
            players[player_actual].disparo.y = players[player_actual].y;

        }
    }
    if(players[player_actual].explosion.explotando)ExplosionPlayer();
}

