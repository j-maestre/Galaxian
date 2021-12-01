void CreateEnemigos(){
  for (int i = 0; i <=N_ENEMIGOS -1; i++) {
    //800, 300, 200, 150,
    int score=0;
    char type;
    int x=0,y=0;
  //Aliens verdes
    if(i<=29){
      score=60;
      type='G';
      //Segunda fila
      if(i>9 && i<=19){
        y=230;
        x=(100 + (i*45))-450;
      //Tercera fila
      }else if(i >19 && i<=29){
        y=200;
        x=(100 + (i*45))-900;

      //Primera fila
      }else if(i<=9){
        y=260;
        x=100 + (i*45);
      }
    };
    //Aliens rosas
    if(i>29 && i<=37){
      score=80;
      type='P';
      y=170;
      x=(100 + (i*45))-1305;
    };

    //Aliens rojos
    if(i>37 && i<=43){
      score=100;
      type='R';
      y=140;
      x=(100 + (i*45))-1620;
    };

    //Aliens amarillos
     if(i>=44){

      int random =rand()%3;
      switch (random) {
        case 0:
          score = 800;
        break;
        case 1:
          score = 300;
        break;
        case 2:
          score = 200;
        break;
        case 3:
          score = 150;
        break;
        default:
          score=300;
        break;
      }
      type='Y';
      y=100;
      if(i==44)x=235;
      if(i==45)x=370;
    }
    Disparo disparo;
    Explosion explosion={0,0,false};
    Enemigo enemigo={score,x,y,type,disparo,explosion};
    players[player_actual].enemigos[i] = enemigo;
    //enemigos[i] = enemigo;
  }

  //players[player_actual].enemigos = enemigos;
}

void ExplosionEnemigos(int posicion){
  fps_count_explosion++;

  //Cada 0'25 segundos muestro una animacion de la explosion
  if(fps_count_explosion>fps*(explosion_selector*0.1))explosion_selector++;
  if(explosion_selector<4){
    esat::DrawSprite(explosion_alien[explosion_selector],players[player_actual].enemigos[posicion].explosion.x, players[player_actual].enemigos[posicion].explosion.y);

    //Cuando ya he mostrado todas las explosiones, dejo de explotar y reinicio las variables
  }else if(explosion_selector>=4){
    explosion_selector=0;
    fps_count_explosion = 0;
    players[player_actual].enemigos[posicion].explosion.explotando = false;
  }
  // esat::DrawSprite();
}


void Disparar(int index){
  if(!players[player_actual].enemigos[index].disparo.disparando && players[player_actual].enemigos[index].vivo){
    players[player_actual].enemigos[index].disparo.x = players[player_actual].enemigos[index].descensoX;
    players[player_actual].enemigos[index].disparo.y = players[player_actual].enemigos[index].descensoY;
    players[player_actual].enemigos[index].disparo.disparando = true;
  }else{
    //Empiezo a disparar
    
    esat::DrawSprite(disparoEnemigo,players[player_actual].enemigos[index].disparo.x,players[player_actual].enemigos[index].disparo.y+=velocidad_enemigos_disparo);
    if(players[player_actual].enemigos[index].disparo.y>=ALTO*3)players[player_actual].enemigos[index].disparo.disparando=false;
  }
}


void Descender(int index, esat::SpriteHandle sprite){
  if(players[player_actual].enemigos[index].vivo && !players[player_actual].enemigos[index].fin_descenso){
    //velocidad_enemigos_descenso--;
    players[player_actual].enemigos[index].descensoY+=velocidad_enemigos_descenso;

    //Si el jugador (x+100 para la parabola) está a la derecha del alien, lo movemos hacia él
    if(players[player_actual].enemigos[index].descensoX < players[player_actual].x+100 && players[player_actual].enemigos[index].direccion_descenso == 'R'){
      //A medida que se vaya acercando, vamos disminuyendo la velocidad para la sensacion de una velocidad exponencial y cambiamos el sprite 

      players[player_actual].enemigos[index].descensoX+= velocidad_enemigos_descenso_x;

    //Cuando llega al final invertimos la direccion
    }else{
      players[player_actual].enemigos[index].direccion_descenso = 'L';
    }
    
    //Lo mismo para la parte izquierda
    if(players[player_actual].enemigos[index].descensoX > players[player_actual].x-100 && players[player_actual].enemigos[index].direccion_descenso == 'L'){
      players[player_actual].enemigos[index].descensoX-= velocidad_enemigos_descenso_x;
    }else{
      players[player_actual].enemigos[index].direccion_descenso = 'R';
    }
    esat::DrawSprite(sprite,players[player_actual].enemigos[index].descensoX, players[player_actual].enemigos[index].descensoY);

    //Cuando llega a abajo del todo, lo ponemos arriba y marcamos el fin de su descenso
    if(players[player_actual].enemigos[index].descensoY>=ALTO*3 && players[player_actual].enemigos[index].fin_descenso == false){
      printf("HA llegado abajo \n");
      players[player_actual].enemigos[index].fin_descenso = true;
      players[player_actual].enemigos[index].descensoY = 50;
    }

  };

    
    //Si ya he acabado de descender, lo vuelvo al sitio
    if(players[player_actual].enemigos[index].fin_descenso){

      bool al_sitioY = false;
      bool al_sitioX = false;

      if(players[player_actual].enemigos[index].descensoY<players[player_actual].enemigos[index].y){
        players[player_actual].enemigos[index].descensoY+=velocidad_enemigos_descenso;
        al_sitioY = false;
      }else{
        al_sitioY = true;
      }

      if(players[player_actual].enemigos[index].descensoX > players[player_actual].enemigos[index].x){
        players[player_actual].enemigos[index].descensoX-=velocidad_enemigos_descenso_x;
        al_sitioX = false;

      }
      if(players[player_actual].enemigos[index].descensoX < players[player_actual].enemigos[index].x){
        players[player_actual].enemigos[index].descensoX+=velocidad_enemigos_descenso_x;
        al_sitioX = false;
      }else{
        al_sitioX = true;
      }

      esat::DrawSprite(sprite,players[player_actual].enemigos[index].descensoX, players[player_actual].enemigos[index].descensoY);

      if(al_sitioY && al_sitioX){
        players[player_actual].enemigos[index].descendiendo = false;
        players[player_actual].enemigos[index].fin_descenso = false;
        players[player_actual].enemigos[index].descensoX = -20;
        players[player_actual].enemigos[index].descensoY = -20;
      }


    }
  
};

void PrintEnemigos(){

  fps_count<1000?++fps_count:fps_count=0;
  // printf("%d\n",fps_count);
  //if(fps_count%15 == 0){
  //  animacion_selector>=3?animacion_selector=0:++animacion_selector;
  //};

  for (int i = 0; i <=N_ENEMIGOS -1; i++) {

    //Cada 15 frames cambiamos el sprite del alien para la animacion
    if(fps_count%15 == 0){
      players[player_actual].enemigos[i].index_animacion>=3?players[player_actual].enemigos[i].index_animacion=0:++players[player_actual].enemigos[i].index_animacion;
    }
    esat::SpriteHandle sprite;
    switch (players[player_actual].enemigos[i].type) {
      case 'G':
        sprite = animacion_alienVerde[players[player_actual].enemigos[i].index_animacion];
      break;
      case 'P':
        sprite = animacion_alienRosa[players[player_actual].enemigos[i].index_animacion];
      break;
      case 'R':
        sprite = animacion_alienRojo[players[player_actual].enemigos[i].index_animacion];
      break;
      case 'Y':
        sprite = alienAmarillo;
      break;
    }
    //Si cualquier alien está vivo y ha tocado el borde derecho, invertimos la dirección
    if(players[player_actual].enemigos[i].vivo && players[player_actual].enemigos[i].x + 33 >=ANCHO*3)direccion_enemigos = 'L';

    //Si cualquier alien está vivo y ha tocado el borde izquierdo, invertimos la dirección
    if(players[player_actual].enemigos[i].vivo && players[player_actual].enemigos[i].x <=0)direccion_enemigos = 'R';


    //Movemos los enemigos a la derecha
    if(direccion_enemigos == 'R'){
      players[player_actual].enemigos[i].x+=velocidad_enemigos;
      if(players[player_actual].enemigos[i].vivo && !players[player_actual].enemigos[i].descendiendo)esat::DrawSprite(sprite,players[player_actual].enemigos[i].x,players[player_actual].enemigos[i].y);

      //Movemos los enemigos a la izquierda
    }else if(direccion_enemigos == 'L'){
      players[player_actual].enemigos[i].x-=velocidad_enemigos;
      if(players[player_actual].enemigos[i].vivo && !players[player_actual].enemigos[i].descendiendo)esat::DrawSprite(sprite,players[player_actual].enemigos[i].x,players[player_actual].enemigos[i].y);

      //Movemos el enemigo seleccionado hacia abajo
    }else if(players[player_actual].enemigos[i].vivo && players[player_actual].enemigos[i].descendiendo){
      //
    }

    //Si está explotando, llamamos a la funcion de explotar y le pasamos el indice del enemigo
    if(players[player_actual].enemigos[i].explosion.explotando)ExplosionEnemigos(i);

    //Si está descendiendo, llamamos a la funcion de descenso y le pasamos el index de quien está descendiendo y su sprite
    if(players[player_actual].enemigos[i].descendiendo){
      Descender(i, sprite);
      Disparar(i);
    }
  }
}


void CalcularDescenso(){
  cont_frecuencia++;
  if(cont_frecuencia%(fps*frecuencia) == 0){
    int random = rand()%251;
    printf("Sacamos num random: %d\n", random);
    if(random<=frecuencia_verde){
      //Baja un verde
      printf("VERDE \n");
      //decidir si sale por la izquierda o por la derecha
      if(rand()%2==0){
        //Sale por la izquierda
        printf("Sale por la izquierda\n");
        if(!players[player_actual].enemigos[indexAtaqueA1].descendiendo){
          //Si el de la esquina no está descendiendo ya, que descienda y que vaya hacia la derecha
          players[player_actual].enemigos[indexAtaqueA1].descendiendo = true;
          players[player_actual].enemigos[indexAtaqueA1].direccion_descenso = 'R';
          players[player_actual].enemigos[indexAtaqueA1].fin_descenso = false;
          players[player_actual].enemigos[indexAtaqueA1].descensoX = players[player_actual].enemigos[indexAtaqueA1].x;
          players[player_actual].enemigos[indexAtaqueA1].descensoY = players[player_actual].enemigos[indexAtaqueA1].y;
        }else{
          //si ya está descendiendo, comprobamos que el siguiente no esté muerto y que no esté descendiendo y le decimos que descienda
          if(!enemigos[indexAtaqueA1+1].descendiendo && enemigos[indexAtaqueA1+1].vivo){
            enemigos[indexAtaqueA1+1].descendiendo = true;
            enemigos[indexAtaqueA1+1].direccion_descenso = 'R';

            //Marcamos la posicion en la que desciende
            enemigos[indexAtaqueA1+1].fin_descenso = false;
            enemigos[indexAtaqueA1+1].descensoX = players[player_actual].enemigos[indexAtaqueA1].x;
            enemigos[indexAtaqueA1+1].descensoY = players[player_actual].enemigos[indexAtaqueA1].y;
          }
        }
      }else{
        //Sale por la derecha
        printf("Sale por la derecha\n");
        if(!players[player_actual].enemigos[indexAtaqueA2].descendiendo){
          //Si el de la esquina no está descendiendo ya, que descienda
          players[player_actual].enemigos[indexAtaqueA2].descendiendo = true;
          players[player_actual].enemigos[indexAtaqueA2].direccion_descenso = 'L';
          players[player_actual].enemigos[indexAtaqueA2].fin_descenso = false;
          players[player_actual].enemigos[indexAtaqueA2].descensoX = players[player_actual].enemigos[indexAtaqueA2].x;
          players[player_actual].enemigos[indexAtaqueA2].descensoY = players[player_actual].enemigos[indexAtaqueA2].y;
        }else{
          //si ya está descendiendo, comprobamos que el siguiente no esté muerto y que no esté descendiendo y le decimos que descienda
          if(!enemigos[indexAtaqueA2-1].descendiendo && enemigos[indexAtaqueA1-1].vivo){
            enemigos[indexAtaqueA2-1].descendiendo = true;
            enemigos[indexAtaqueA2-1].direccion_descenso = 'L';
            enemigos[indexAtaqueA2-1].fin_descenso = false;
            enemigos[indexAtaqueA2-1].descensoX = enemigos[indexAtaqueA2-1].x;
            enemigos[indexAtaqueA2-1].descensoY = enemigos[indexAtaqueA2-1].y;
          }
        }
      }
    }else if(random>frecuencia_verde && random<=frecuencia_rosa){
      //Baja un rosa
      printf("ROSA \n");
    }else if(random>frecuencia_rosa && random<=frecuencia_rojo){
      //baja un rojo
      printf("ROJO \n");
    }else if(random>frecuencia_rojo && random<=frecuencia_amarillo){
      //Baja un amarillo con rojos o solo si no quedan
      printf("AMARILLO \n");
    }
  }

}

void ComprobarFila(){
  //Comprobar si todos los de cada fila están muertos, si es así, marcamos esa fila como muerta
  if(!enemigos[0].vivo && !enemigos[1].vivo && !enemigos[2].vivo && !enemigos[3].vivo && !enemigos[4].vivo && !enemigos[5].vivo && !enemigos[6].vivo && !enemigos[7].vivo && !enemigos[8].vivo && !enemigos[9].vivo)fila1 = false;
  if(!enemigos[10].vivo && !enemigos[11].vivo && !enemigos[12].vivo && !enemigos[13].vivo && !enemigos[14].vivo && !enemigos[15].vivo && !enemigos[16].vivo && !enemigos[17].vivo && !enemigos[18].vivo && !enemigos[19].vivo)fila2 = false;
  if(!enemigos[20].vivo && !enemigos[21].vivo && !enemigos[22].vivo && !enemigos[23].vivo && !enemigos[24].vivo && !enemigos[25].vivo && !enemigos[26].vivo && !enemigos[27].vivo && !enemigos[28].vivo && !enemigos[29].vivo)fila3 = false;
  if(!enemigos[30].vivo && !enemigos[31].vivo && !enemigos[32].vivo && !enemigos[33].vivo && !enemigos[34].vivo && !enemigos[35].vivo && !enemigos[36].vivo && !enemigos[37].vivo)fila4 = false;
  if(!enemigos[38].vivo && !enemigos[39].vivo && !enemigos[40].vivo && !enemigos[41].vivo && !enemigos[42].vivo && !enemigos[43].vivo )fila5 = false;
}

void PuedeAtacar(){

  //Si hay algun enemigo vivo en esta fila, comprobamos las esquinas
  if(fila1){
    //Primera fila esquina izquierda
    //Boolean que especifica si se ha confirmado que el que está en la esquina puede atacar
    bool ataqueConfirmadoA1 = false;
    do{
      //Si el que está mas a la esquina izquierda ha muerto, incrementamos el indice para que pase al siguiente y marcamos la esquina de ese enemigo como false
      if(!players[player_actual].enemigos[indexAtaqueA1].vivo){
        players[player_actual].enemigos[indexAtaqueA1].esquina = false;
        ++indexAtaqueA1;
      }else{
        //Si el siguiente index de la esquina izquierda está vivo, dejamos de buscar la nueva esquina y marcamos la esquina de ese enemigo como true
        ataqueConfirmadoA1 = true;
        players[player_actual].enemigos[indexAtaqueA1].esquina = true;
      }
      //Repetimos el proceso para cada esquina

    }while(!ataqueConfirmadoA1);
  
  //Primera fila esquina derecha
    bool ataqueConfirmadoA2 = false;
    do{
      if(!players[player_actual].enemigos[indexAtaqueA2].vivo){
        players[player_actual].enemigos[indexAtaqueA2].esquina = false;
        --indexAtaqueA2;
      }else{
        ataqueConfirmadoA2 = true;
        players[player_actual].enemigos[indexAtaqueA2].esquina = true;
      }

    }while(!ataqueConfirmadoA2);
  }

  if(fila2){
  //Segunda fila esquina izquierda
    bool ataqueConfirmadoB1 = false;
    do{
      if(!players[player_actual].enemigos[indexAtaqueB1].vivo){
        players[player_actual].enemigos[indexAtaqueB1].esquina = false;
        ++indexAtaqueB1;
      }else{
        players[player_actual].enemigos[indexAtaqueB1].esquina = true;
        ataqueConfirmadoB1 = true;
      }

    }while(!ataqueConfirmadoB1);

  //Segunda fila esquina derecha
    bool ataqueConfirmadoB2 = false;
    do{
      if(!players[player_actual].enemigos[indexAtaqueB2].vivo){
        players[player_actual].enemigos[indexAtaqueB2].esquina = false;
        --indexAtaqueB2;
      }else{
        players[player_actual].enemigos[indexAtaqueB2].esquina = true;
        ataqueConfirmadoB2 = true;
      }

    }while(!ataqueConfirmadoB2);
  }

  if(fila3){
  //Tercera fila esquina izquierda
    bool ataqueConfirmadoC1 = false;
    do{
      if(!players[player_actual].enemigos[indexAtaqueC1].vivo){
        players[player_actual].enemigos[indexAtaqueC1].esquina = false;
        ++indexAtaqueC1;
      }else{
        players[player_actual].enemigos[indexAtaqueC1].esquina = true;
        ataqueConfirmadoC1 = true;
      }

    }while(!ataqueConfirmadoC1);

  //Tercera fila esquina derecha
    bool ataqueConfirmadoC2 = false;
    do{
      if(!players[player_actual].enemigos[indexAtaqueC2].vivo){
        players[player_actual].enemigos[indexAtaqueC2].esquina = false;
        --indexAtaqueC2;
      }else{
        players[player_actual].enemigos[indexAtaqueC2].esquina = true;
        ataqueConfirmadoC2 = true;
      }

    }while(!ataqueConfirmadoC2);
  }

  if(fila4){
    //Cuarta fila esquina izquierda
    bool ataqueConfirmadoD1 = false;
    do{
      if(!players[player_actual].enemigos[indexAtaqueD1].vivo){
        players[player_actual].enemigos[indexAtaqueD1].esquina = false;
        ++indexAtaqueD1;
      }else{
        players[player_actual].enemigos[indexAtaqueD1].esquina = true;
        ataqueConfirmadoD1 = true;
      }

    }while(!ataqueConfirmadoD1);

  //Cuarta fila esquina derecha
    bool ataqueConfirmadoD2 = false;
    do{
      if(!players[player_actual].enemigos[indexAtaqueD2].vivo){
        players[player_actual].enemigos[indexAtaqueD2].esquina = false;
        --indexAtaqueD2;
      }else{
        players[player_actual].enemigos[indexAtaqueD2].esquina = true;
        ataqueConfirmadoD2 = true;
      }

    }while(!ataqueConfirmadoD2);
  }

  if(fila5){

    //Quinta fila esquina izquierda
    bool ataqueConfirmadoE1 = false;
    do{
    
      if(!players[player_actual].enemigos[indexAtaqueE1].vivo){
        players[player_actual].enemigos[indexAtaqueE1].esquina = false;
        ++indexAtaqueE1;
      }else{

        ataqueConfirmadoE1 = true;
        players[player_actual].enemigos[indexAtaqueE1].esquina = true;
      }

    }while(!ataqueConfirmadoE1);

    //Quinta fila esquina derecha
    bool ataqueConfirmadoE2 = false;
    do{
    
      if(!players[player_actual].enemigos[indexAtaqueE2].vivo){
        players[player_actual].enemigos[indexAtaqueE2].esquina = false;
        ++indexAtaqueE2;
      }else{

        ataqueConfirmadoE2 = true;
        players[player_actual].enemigos[indexAtaqueE2].esquina = true;
      }

    }while(!ataqueConfirmadoE2);
  }


};


void debugEnemigos(){
  for (int i = 0; i <= N_ENEMIGOS -1; i++){
    printf(" - Enemigo %d score %d - \n",i,players[player_actual].enemigos[i].score);
    //printf(" - Enemigo %d score %d - \n",i,players[player_actual].enemigos[i].score);
    // printf("Type %c \n", players[player_actual].enemigos[i].type);
    // printf("DEBUG Enemigo type:%c x: %d y:%d \n",players[player_actual].enemigos[i].type,players[player_actual].enemigos[i].x,players[player_actual].enemigos[i].y);
   //printf("Index animacion de %d: %d",i,players[player_actual].enemigos[i].index_animacion);
  }

}
