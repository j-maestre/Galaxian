void ColisionDispEnemigos(){
  if(players[0].disparo.disparando){
    for (int i = 0; i < N_ENEMIGOS; i++) {
      //Si el enemigo está vivo y aun no ha colisionado comprobamos si ha colisionado con el disparo
      if(enemigos[i].vivo){
        if(players[0].disparo.x > enemigos[i].x-18 && players[0].disparo.x < enemigos[i].x+18 && players[0].disparo.y > enemigos[i].y && players[0].disparo.y < enemigos[i].y+33  ){
          printf("COLISION EN x: %d y: %d\n", enemigos[i].x,enemigos[i].y);
          //Matamos al elien
          enemigos[i].vivo = false;

          //Lo marcamos como explotando y establecemos la posicion de la explosion
          enemigos[i].explosion.explotando = true;
          enemigos[i].explosion.x = enemigos[i].x+12;
          enemigos[i].explosion.y = enemigos[i].y+12;

          //Dejamos de disparar
          players[0].disparo.disparando = false;

          //Sumamos el score y comprobamos el score maximo
          score1+=enemigos[i].score;
          // if(score1 > max_score) max_score=score1;
        }//End colision
      }//End if vivo && !colisionado


    }//End for

  }
}
