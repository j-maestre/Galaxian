void CreatePlayer(){
    printf("Create player\n");
    for (int i = 0; i < N_players; i++){
        printf("Create: %d \n",i);
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

    //Cuando ya he mostrado todas las explosiones, dejo de explotar, reinicio las variables y marco Game Over del jugador
    }else if(explosion_selector>=4){
        fps_count_explosion_player = 1;
        players[player_actual].explosion.explotando = false;
        players[player_actual].gameOver = true;
        explosion_selector=0;
    }
    // esat::DrawSprite();
    
    
}

void PrintPlayer(){
    if(!players[player_actual].explosion.explotando){
        //Mostramos un sprite u otro dependiendo de si está disparando o no
        players[player_actual].disparo.disparando?esat::DrawSprite(playerDisparando,players[player_actual].x,players[player_actual].y+12):esat::DrawSprite(player,players[player_actual].x,players[player_actual].y);
        

        //Disparo del jugador
        if(players[player_actual].disparo.disparando){
            //Mostrar la bala
            printf("Mostrando bala\n");
            printf("Bala Y: %d del player:%d\n",players[player_actual].disparo.y, player_actual);
            esat::DrawSprite(disparoPlayer,players[player_actual].disparo.x+20,players[player_actual].disparo.y-=velocidad_disparo_player);
            if(players[player_actual].disparo.y<=0)players[player_actual].disparo.disparando = false;
        }


        if(esat::IsSpecialKeyPressed(esat::kSpecialKey_Right)&& (players[player_actual].x)+40<ANCHO*3){
            players[player_actual].x+=velocidad_jugador;
        }
        if(esat::IsSpecialKeyPressed(esat::kSpecialKey_Left) && players[player_actual].x>0){
            players[player_actual].x-=velocidad_jugador;
        }

        if(esat::IsSpecialKeyPressed(esat::kSpecialKey_Space) && !players[player_actual].disparo.disparando){
            printf("Press space\n");
            players[player_actual].disparo.disparando = true;
            printf("He disparado en x:%d y:%d \n",players[player_actual].x,players[player_actual].y);
            players[player_actual].disparo.x = players[player_actual].x;
            players[player_actual].disparo.y = players[player_actual].y;

        }
    }
    // if(players[player_actual].explosion.explotando)players[player_actual].explosion.explotando=false;
    if(players[player_actual].explosion.explotando)ExplosionPlayer();
}


void DebugPlayer(){
    printf("DEBUG Player Disparo Y:%d X:%d \n",players[0].disparo.y,players[0].disparo.x);
}



void CheckGameOver(){
    if(!debug){

        
        if(N_players == 1 && players[0].vidas <=0){
            //Fin del juego
            gameOver = true;
            credits--;
        }else if(N_players == 2 && players[0].vidas <= 0 && players[1].vidas <= 0){
            //Fin del juego
        }
    }
}


void Levels(){
    for(int i = 1; i < players[player_actual].levels+1; i++){ 
        esat::DrawSprite(bandera, (ANCHO*3) - (i*27),(ALTO*3) - 100);
    }
}