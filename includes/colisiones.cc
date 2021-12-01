void ColisionDispEnemigos(){
  if(players[player_actual].disparo.disparando){
    for (int i = 0; i < N_ENEMIGOS; i++) {
      //Si el enemigo está vivo y aun no ha colisionado comprobamos si ha colisionado con el disparo
      if(players[player_actual].enemigos[i].vivo){
        if(players[player_actual].disparo.x > players[player_actual].enemigos[i].x-18 && players[player_actual].disparo.x < players[player_actual].enemigos[i].x+18 && players[player_actual].disparo.y > players[player_actual].enemigos[i].y && players[player_actual].disparo.y < players[player_actual].enemigos[i].y+33  || 
           players[player_actual].disparo.x > players[player_actual].enemigos[i].descensoX-18 && players[player_actual].disparo.x < players[player_actual].enemigos[i].descensoX+18 && players[player_actual].disparo.y > players[player_actual].enemigos[i].descensoY && players[player_actual].disparo.y < players[player_actual].enemigos[i].descensoY+33){
          printf("COLISION EN x: %d y: %d\n", players[player_actual].enemigos[i].x,players[player_actual].enemigos[i].y);
          //Matamos al elien
          players[player_actual].enemigos[i].vivo = false;

          //Lo marcamos como explotando y establecemos la posicion de la explosion
          players[player_actual].enemigos[i].explosion.explotando = true;
          if(players[player_actual].enemigos[i].descendiendo){
            players[player_actual].enemigos[i].explosion.x = players[player_actual].enemigos[i].descensoX+12;
            players[player_actual].enemigos[i].explosion.y = players[player_actual].enemigos[i].descensoY+12;
          }else{
            players[player_actual].enemigos[i].explosion.x = players[player_actual].enemigos[i].x+12;
            players[player_actual].enemigos[i].explosion.y = players[player_actual].enemigos[i].y+12;
          }

          //Dejamos de disparar
          players[player_actual].disparo.disparando = false;

          //Sumamos el score al jugador
          player_actual==0?score1+=players[player_actual].enemigos[i].score: score2+=players[player_actual].enemigos[i].score;
         

        }//End colision
      }//End if vivo && !colisionado


    }//End for

  }
}

void ColisionDispJugador(){
  if(!players[player_actual].explosion.explotando){
    for(int i = 0; i< N_ENEMIGOS; ++i){
      if(players[player_actual].enemigos[i].disparo.x > players[player_actual].x-22 && players[player_actual].enemigos[i].disparo.x < players[player_actual].x+22 && players[player_actual].enemigos[i].disparo.y > players[player_actual].y && players[player_actual].enemigos[i].disparo.y < players[player_actual].y+33){
        printf("COLISION");
        players[player_actual].explosion.explotando = true;
        players[player_actual].explosion.x = players[player_actual].x;
        players[player_actual].explosion.y = players[player_actual].y;
        players[player_actual].vidas--;
        players[player_actual].enemigos[i].disparo.disparando = false;
        players[player_actual].enemigos[i].disparo.x = -20;
        players[player_actual].enemigos[i].disparo.y = -20;
        
      }

    }
  }
}


void CheckColisiones(){

  //Colisiones del disparo del jugador con los enemigos
  ColisionDispEnemigos();

  //Colision del disparo de los enemigos con el jugador
  ColisionDispJugador();
}

