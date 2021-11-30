void ColisionDispEnemigos(){
  if(players[player_actual].disparo.disparando){
    for (int i = 0; i < N_ENEMIGOS; i++) {
      //Si el enemigo está vivo y aun no ha colisionado comprobamos si ha colisionado con el disparo
      if(enemigos[i].vivo){
        if(players[player_actual].disparo.x > enemigos[i].x-18 && players[player_actual].disparo.x < enemigos[i].x+18 && players[player_actual].disparo.y > enemigos[i].y && players[player_actual].disparo.y < enemigos[i].y+33  || 
           players[player_actual].disparo.x > enemigos[i].descensoX-18 && players[player_actual].disparo.x < enemigos[i].descensoX+18 && players[player_actual].disparo.y > enemigos[i].descensoY && players[player_actual].disparo.y < enemigos[i].descensoY+33){
          printf("COLISION EN x: %d y: %d\n", enemigos[i].x,enemigos[i].y);
          //Matamos al elien
          enemigos[i].vivo = false;

          //Lo marcamos como explotando y establecemos la posicion de la explosion
          enemigos[i].explosion.explotando = true;
          if(enemigos[i].descendiendo){
            enemigos[i].explosion.x = enemigos[i].descensoX+12;
            enemigos[i].explosion.y = enemigos[i].descensoY+12;
          }else{
            enemigos[i].explosion.x = enemigos[i].x+12;
            enemigos[i].explosion.y = enemigos[i].y+12;
          }

          //Dejamos de disparar
          players[player_actual].disparo.disparando = false;

          //Sumamos el score y comprobamos el score maximo
          score1+=enemigos[i].score;
          // if(score1 > max_score) max_score=score1;
        }//End colision
      }//End if vivo && !colisionado


    }//End for

  }
}

void ColisionDispJugador(){
  if(!players[player_actual].explosion.explotando){
    for(int i = 0; i< N_ENEMIGOS; ++i){
      if(enemigos[i].disparo.x > players[player_actual].x-18 && enemigos[i].disparo.x < players[player_actual].x+18 && enemigos[i].disparo.y > players[player_actual].y && enemigos[i].disparo.y < players[player_actual].y+33){
        printf("COLISION");
        players[player_actual].explosion.explotando = true;
        players[player_actual].explosion.x = players[player_actual].x;
        players[player_actual].explosion.y = players[player_actual].y;
        players[player_actual].vidas--;
        enemigos[i].disparo.x = -20;
        enemigos[i].disparo.y = -20;
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

