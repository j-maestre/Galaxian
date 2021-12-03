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

esat::SpriteHandle AnimacionDescenso(int index){
  //Calcular aqui lo cerca que está del jugador para disminuir o aumentar la velocidad en la que se mueve
  int index_animacion = 0;
  //Inclinacion parte izquierda
  
  if(players[player_actual].enemigos[index].direccion_descenso == 'L'){
      if(players[player_actual].enemigos[index].descensoX < players[player_actual].x-80 && players[player_actual].enemigos[index].descensoX < players[player_actual].x -100){
      //Sexto sprite
    
      index_animacion = 5;
      // velocidad_enemigos_descenso = 1;
      velocidad_enemigos_descenso_x = 1;
      
      }else if(players[player_actual].enemigos[index].descensoX < players[player_actual].x-60 && players[player_actual].enemigos[index].descensoX < players[player_actual].x -80){
        //Quinto sprite

        index_animacion = 4;
        // velocidad_enemigos_descenso = 2;
        velocidad_enemigos_descenso_x = 2;
      }else if(players[player_actual].enemigos[index].descensoX < players[player_actual].x-40 && players[player_actual].enemigos[index].descensoX < players[player_actual].x -60){
        //Cuarto sprite

        index_animacion = 3;
        // velocidad_enemigos_descenso = 3;
        velocidad_enemigos_descenso_x = 3;
      }else if(players[player_actual].enemigos[index].descensoX < players[player_actual].x-20 && players[player_actual].enemigos[index].descensoX < players[player_actual].x -40){
        //Tercer sprite
     
        index_animacion = 2;
        // velocidad_enemigos_descenso = 4;
        velocidad_enemigos_descenso_x = 4;
      }else if(players[player_actual].enemigos[index].descensoX < players[player_actual].x && players[player_actual].enemigos[index].descensoX < players[player_actual].x -20){
        //Segundo sprite
     
        index_animacion = 1;
        // velocidad_enemigos_descenso = 5;
        velocidad_enemigos_descenso_x = 4;
      }else{
        velocidad_enemigos_descenso_x = 4;
      }
  }

    if(players[player_actual].enemigos[index].direccion_descenso == 'R'){
      //Inclinacion parte derecha
  
      if(players[player_actual].enemigos[index].descensoX > players[player_actual].x+80 && players[player_actual].enemigos[index].descensoX > players[player_actual].x +100){
        //Sexto sprite

        index_animacion = 10;
        velocidad_enemigos_descenso_x = 1;

      }else if(players[player_actual].enemigos[index].descensoX > players[player_actual].x+60 && players[player_actual].enemigos[index].descensoX > players[player_actual].x + 80){
        //Quinto sprite

        index_animacion = 9;
        // velocidad_enemigos_descenso = 2;
        velocidad_enemigos_descenso_x = 2;
      }else if(players[player_actual].enemigos[index].descensoX > players[player_actual].x+40 && players[player_actual].enemigos[index].descensoX > players[player_actual].x + 60){
        //Cuarto sprite

        index_animacion = 8;
        // velocidad_enemigos_descenso = 3;
        velocidad_enemigos_descenso_x = 3;
      }else if(players[player_actual].enemigos[index].descensoX > players[player_actual].x+20 && players[player_actual].enemigos[index].descensoX > players[player_actual].x + 40){
        //Tercer sprite

        index_animacion = 7;
        // velocidad_enemigos_descenso = 4;
        velocidad_enemigos_descenso_x = 4;
      }else if(players[player_actual].enemigos[index].descensoX > players[player_actual].x && players[player_actual].enemigos[index].descensoX > players[player_actual].x + 20){
        //Segundo sprite
 
        index_animacion = 6;
        // velocidad_enemigos_descenso = 5;
        velocidad_enemigos_descenso_x = 4;
      }else{
        velocidad_enemigos_descenso_x = 4;
      }
    }
    switch(players[player_actual].enemigos[index].type){
      case 'G':
        return inclinacion_alienVerde[index_animacion];
      break;
      case 'P':
        return inclinacion_alienRosa[index_animacion];
      break;
      case 'R':
        return inclinacion_alienRojo[index_animacion];
      break;
      case 'Y':
      return alienAmarillo;
        // return inclinacion_alienVerde[index_animacion];
      break;
      default:
        printf("---------------ERROR DEFAULT-------------\n");
        return inclinacion_alienVerde[index_animacion];
      break;
    }

      
}


void Descender(int index, esat::SpriteHandle sprite){
 // printf("----Descendiendo-----\n");
 // printf("Posicion de partida del %d-> x:%d y:%d\n",index,players[player_actual].enemigos[index].descensoX, players[player_actual].enemigos[index].descensoY);
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
      //Movimiento de derecha a izquierda lineal
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
    if(!players[player_actual].enemigos[i].descendiendo){

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
    }else{
      //Comprobamos si está descendiendo y pedimos su sprite correspondiente
      if(players[player_actual].enemigos[i].descendiendo)sprite = AnimacionDescenso(i);
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
      if(!players[player_actual].enemigos[i].fin_descenso)Disparar(i);
    }
  }
}


void CalcularDescenso(){
  
  cont_frecuencia++;
  if(cont_frecuencia%(fps*frecuencia) == 0){
    //Sorteamos la frecuencia en la que sale
    frecuencia = 1 + rand()%3;
    printf("Frecuencia %d\n",frecuencia);
    int random = rand()%251;
    //DEBUG
    // random = 249;
    printf("Sacamos num random: %d\n", random);
    if(random<=frecuencia_verde){
      //Baja un verde
      printf("VERDE \n");
      int index1, index2;
      //Decidir que fila sale
      //decidir si sale por la izquierda o por la derecha
      int random = rand()%3;
      if(random == 0){
        //Sale la primera fila
        index1 = indexAtaqueA1;
        index2 = indexAtaqueA2;
      }else if(random == 1){
        //Sale la segunda fila
        index1 = indexAtaqueB1;
        index2 = indexAtaqueB2;
      }else{
        //Sale la tercera fila
        index1 = indexAtaqueC1;
        index2 = indexAtaqueC2;
      }
      if(rand()%2==0){
        //Sale por la izquierda
        printf("Sale por la izquierda\n");
        if(!players[player_actual].enemigos[index1].descendiendo){
          //Si el de la esquina no está descendiendo ya, que descienda y que vaya hacia la derecha
          players[player_actual].enemigos[index1].descendiendo = true;
          players[player_actual].enemigos[index1].direccion_descenso = 'R';
          players[player_actual].enemigos[index1].fin_descenso = false;
          players[player_actual].enemigos[index1].descensoX = players[player_actual].enemigos[index1].x;
          players[player_actual].enemigos[index1].descensoY = players[player_actual].enemigos[index1].y;
        }else{
          //si ya está descendiendo, comprobamos que el siguiente no esté muerto y que no esté descendiendo y le decimos que descienda
          if(!players[player_actual].enemigos[index1+1].descendiendo && players[player_actual].enemigos[index1+1].vivo){
            players[player_actual].enemigos[index1+1].descendiendo = true;
            players[player_actual].enemigos[index1+1].direccion_descenso = 'R';

            //Marcamos la posicion en la que desciende
            players[player_actual].enemigos[index1+1].fin_descenso = false;
            players[player_actual].enemigos[index1+1].descensoX = players[player_actual].enemigos[index1].x;
            players[player_actual].enemigos[index1+1].descensoY = players[player_actual].enemigos[index1].y;
          }
        }
      }else{
        //Sale por la derecha
        printf("Sale por la derecha\n");
        if(!players[player_actual].enemigos[index2].descendiendo){
          //Si el de la esquina no está descendiendo ya, que descienda
          players[player_actual].enemigos[index2].descendiendo = true;
          players[player_actual].enemigos[index2].direccion_descenso = 'L';
          players[player_actual].enemigos[index2].fin_descenso = false;
          players[player_actual].enemigos[index2].descensoX = players[player_actual].enemigos[index2].x;
          players[player_actual].enemigos[index2].descensoY = players[player_actual].enemigos[index2].y;
        }else{
          //si ya está descendiendo, comprobamos que el siguiente no esté muerto y que no esté descendiendo y le decimos que descienda
          if(!players[player_actual].enemigos[index2-1].descendiendo && players[player_actual].enemigos[indexAtaqueA2-1].vivo){
            players[player_actual].enemigos[index2-1].descendiendo = true;
            players[player_actual].enemigos[index2-1].direccion_descenso = 'L';
            players[player_actual].enemigos[index2-1].fin_descenso = false;
            players[player_actual].enemigos[index2-1].descensoX = players[player_actual].enemigos[index2-1].x;
            players[player_actual].enemigos[index2-1].descensoY = players[player_actual].enemigos[index2-1].y;
          }
        }
      }
    }else if(random>frecuencia_verde && random<=frecuencia_rosa){
      //Baja un rosa
      printf("ROSA \n");
      //decidir si sale por la izquierda o por la derecha
      if(rand()%2==0){
        //Sale por la izquierda
        printf("Sale por la izquierda\n");
        printf("Indes Atauqe D1: %d\n",indexAtaqueD1);
        if(!players[player_actual].enemigos[indexAtaqueD1].descendiendo){
          //Si el de la esquina no está descendiendo ya, que descienda y que vaya hacia la derecha
          players[player_actual].enemigos[indexAtaqueD1].descendiendo = true;
          players[player_actual].enemigos[indexAtaqueD1].direccion_descenso = 'R';
          players[player_actual].enemigos[indexAtaqueD1].fin_descenso = false;
          players[player_actual].enemigos[indexAtaqueD1].descensoX = players[player_actual].enemigos[indexAtaqueD1].x;
          players[player_actual].enemigos[indexAtaqueD1].descensoY = players[player_actual].enemigos[indexAtaqueD1].y;
        }else{
          //si ya está descendiendo, comprobamos que el siguiente no esté muerto y que no esté descendiendo y le decimos que descienda
          if(!players[player_actual].enemigos[indexAtaqueD1+1].descendiendo && players[player_actual].enemigos[indexAtaqueD1+1].vivo){
            players[player_actual].enemigos[indexAtaqueD1+1].descendiendo = true;
            players[player_actual].enemigos[indexAtaqueD1+1].direccion_descenso = 'R';

            //Marcamos la posicion en la que desciende
            players[player_actual].enemigos[indexAtaqueD1+1].fin_descenso = false;
            players[player_actual].enemigos[indexAtaqueD1+1].descensoX = players[player_actual].enemigos[indexAtaqueD1].x;
            players[player_actual].enemigos[indexAtaqueD1+1].descensoY = players[player_actual].enemigos[indexAtaqueD1].y;
          }
        }
      }else{
        //Sale por la derecha
        printf("Sale por la derecha\n");
        if(!players[player_actual].enemigos[indexAtaqueD2].descendiendo){
          //Si el de la esquina no está descendiendo ya, que descienda
          players[player_actual].enemigos[indexAtaqueD2].descendiendo = true;
          players[player_actual].enemigos[indexAtaqueD2].direccion_descenso = 'L';
          players[player_actual].enemigos[indexAtaqueD2].fin_descenso = false;
          players[player_actual].enemigos[indexAtaqueD2].descensoX = players[player_actual].enemigos[indexAtaqueD2].x;
          players[player_actual].enemigos[indexAtaqueD2].descensoY = players[player_actual].enemigos[indexAtaqueD2].y;
        }else{
          //si ya está descendiendo, comprobamos que el siguiente no esté muerto y que no esté descendiendo y le decimos que descienda
          if(!players[player_actual].enemigos[indexAtaqueD2-1].descendiendo && players[player_actual].enemigos[indexAtaqueD2-1].vivo){
            players[player_actual].enemigos[indexAtaqueD2-1].descendiendo = true;
            players[player_actual].enemigos[indexAtaqueD2-1].direccion_descenso = 'L';
            players[player_actual].enemigos[indexAtaqueD2-1].fin_descenso = false;
            players[player_actual].enemigos[indexAtaqueD2-1].descensoX = players[player_actual].enemigos[indexAtaqueD2-1].x;
            players[player_actual].enemigos[indexAtaqueD2-1].descensoY = players[player_actual].enemigos[indexAtaqueD2-1].y;
          }
        }
      }
    }else if(random>frecuencia_rosa && random<=frecuencia_rojo){
      //baja un rojo
      printf("ROJO \n");
      
    }else if(random>frecuencia_rojo && random<=frecuencia_amarillo){
      //Baja un amarillo con rojos o solo si no quedan
      printf("AMARILLO \n");

      if(rand()%2==0){
        //Sale el de la izquierda si no está ya descendiendo y está vivo
        printf("Izquierda \n");
        if(!players[player_actual].enemigos[44].descendiendo && players[player_actual].enemigos[44].vivo){
          players[player_actual].enemigos[44].descendiendo = true;
          players[player_actual].enemigos[44].direccion_descenso = 'R';
          players[player_actual].enemigos[44].fin_descenso = false;
          players[player_actual].enemigos[44].descensoX = players[player_actual].enemigos[44].x;
          players[player_actual].enemigos[44].descensoY = players[player_actual].enemigos[44].y;
          
          //Escuadron del amarillo
          if(players[player_actual].enemigos[38].vivo && !players[player_actual].enemigos[38].descendiendo){
            players[player_actual].enemigos[38].descendiendo=true;
            players[player_actual].enemigos[38].direccion_descenso = 'R';
            players[player_actual].enemigos[38].fin_descenso = false;
            players[player_actual].enemigos[38].descensoX = players[player_actual].enemigos[38].x;
            players[player_actual].enemigos[38].descensoY = players[player_actual].enemigos[38].y;
          }
          if(players[player_actual].enemigos[39].vivo && !players[player_actual].enemigos[39].descendiendo){
            players[player_actual].enemigos[39].descendiendo=true;
            players[player_actual].enemigos[39].direccion_descenso = 'R';
            players[player_actual].enemigos[39].fin_descenso = false;
            players[player_actual].enemigos[39].descensoX = players[player_actual].enemigos[39].x;
            players[player_actual].enemigos[39].descensoY = players[player_actual].enemigos[39].y;
          }
          if(players[player_actual].enemigos[40].vivo && !players[player_actual].enemigos[40].descendiendo){
            players[player_actual].enemigos[40].descendiendo=true;
            players[player_actual].enemigos[40].direccion_descenso = 'R';
            players[player_actual].enemigos[40].fin_descenso = false;
            players[player_actual].enemigos[40].descensoX = players[player_actual].enemigos[40].x;
            players[player_actual].enemigos[40].descensoY = players[player_actual].enemigos[40].y;
          }
          printf("Empieza a descender desde x:%d y:%d\n",players[player_actual].enemigos[45].descensoX,players[player_actual].enemigos[45].descensoY);
        }
      }else{
        //Sale el de la derecha si no está ya descendiendo y está vivo
        printf("Derecha \n");
        if(!players[player_actual].enemigos[45].descendiendo && players[player_actual].enemigos[45].vivo){
          players[player_actual].enemigos[45].descendiendo = true;
          players[player_actual].enemigos[45].direccion_descenso = 'L';
          players[player_actual].enemigos[45].fin_descenso = false;
          
          players[player_actual].enemigos[45].descensoX = players[player_actual].enemigos[45].x;
          players[player_actual].enemigos[45].descensoY = players[player_actual].enemigos[45].y;

          //Escuadron del amarillo
          if(players[player_actual].enemigos[41].vivo && !players[player_actual].enemigos[41].descendiendo){
            players[player_actual].enemigos[41].descendiendo=true;
            players[player_actual].enemigos[41].direccion_descenso = 'L';
            players[player_actual].enemigos[41].fin_descenso = false;
            players[player_actual].enemigos[41].descensoX = players[player_actual].enemigos[41].x;
            players[player_actual].enemigos[41].descensoY = players[player_actual].enemigos[41].y;
          }
          if(players[player_actual].enemigos[42].vivo && !players[player_actual].enemigos[42].descendiendo){
            players[player_actual].enemigos[42].descendiendo=true;
            players[player_actual].enemigos[42].direccion_descenso = 'L';
            players[player_actual].enemigos[42].fin_descenso = false;
            players[player_actual].enemigos[42].descensoX = players[player_actual].enemigos[42].x;
            players[player_actual].enemigos[42].descensoY = players[player_actual].enemigos[42].y;
          }
          if(players[player_actual].enemigos[43].vivo && !players[player_actual].enemigos[43].descendiendo){
            players[player_actual].enemigos[43].descendiendo=true;
            players[player_actual].enemigos[43].direccion_descenso = 'L';
            players[player_actual].enemigos[43].fin_descenso = false;
            players[player_actual].enemigos[43].descensoX = players[player_actual].enemigos[43].x;
            players[player_actual].enemigos[43].descensoY = players[player_actual].enemigos[43].y;
          }
          
          printf("Empieza a descender desde x:%d y:%d\n",players[player_actual].enemigos[45].descensoX,players[player_actual].enemigos[45].descensoY);
        }
      }

    }
  }

}

void ComprobarFila(){
  //Comprobar si todos los de cada fila están muertos, si es así, marcamos esa fila como muerta
  if(!players[player_actual].enemigos[0].vivo && !players[player_actual].enemigos[1].vivo && !players[player_actual].enemigos[2].vivo && !players[player_actual].enemigos[3].vivo && !players[player_actual].enemigos[4].vivo && !players[player_actual].enemigos[5].vivo && !players[player_actual].enemigos[6].vivo && !players[player_actual].enemigos[7].vivo && !players[player_actual].enemigos[8].vivo && !players[player_actual].enemigos[9].vivo)fila1 = false;
  if(!players[player_actual].enemigos[10].vivo && !players[player_actual].enemigos[11].vivo && !players[player_actual].enemigos[12].vivo && !players[player_actual].enemigos[13].vivo && !players[player_actual].enemigos[14].vivo && !players[player_actual].enemigos[15].vivo && !players[player_actual].enemigos[16].vivo && !players[player_actual].enemigos[17].vivo && !players[player_actual].enemigos[18].vivo && !players[player_actual].enemigos[19].vivo)fila2 = false;
  if(!players[player_actual].enemigos[20].vivo && !players[player_actual].enemigos[21].vivo && !players[player_actual].enemigos[22].vivo && !players[player_actual].enemigos[23].vivo && !players[player_actual].enemigos[24].vivo && !players[player_actual].enemigos[25].vivo && !players[player_actual].enemigos[26].vivo && !players[player_actual].enemigos[27].vivo && !players[player_actual].enemigos[28].vivo && !players[player_actual].enemigos[29].vivo)fila3 = false;
  if(!players[player_actual].enemigos[30].vivo && !players[player_actual].enemigos[31].vivo && !players[player_actual].enemigos[32].vivo && !players[player_actual].enemigos[33].vivo && !players[player_actual].enemigos[34].vivo && !players[player_actual].enemigos[35].vivo && !players[player_actual].enemigos[36].vivo && !players[player_actual].enemigos[37].vivo)fila4 = false;
  if(!players[player_actual].enemigos[38].vivo && !players[player_actual].enemigos[39].vivo && !players[player_actual].enemigos[40].vivo && !players[player_actual].enemigos[41].vivo && !players[player_actual].enemigos[42].vivo && !players[player_actual].enemigos[43].vivo )fila5 = false;

  if(!fila1 && !fila2 && !fila3 && !fila4 && !fila5){
    players[player_actual].levels++;
    CreateEnemigos();
    start = false;
    fila1 = true;
    fila2 = true;
    fila3 = true;
    fila4 = true;
    fila5 = true;
  }

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
        ataqueConfirmadoD1 = true;
        players[player_actual].enemigos[indexAtaqueD1].esquina = true;
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

void AmarilloKilled(){
  if(amarilloKill){
    amarilloKilledCount++;
    printf("Han matado al chino cudeiro!\n");
    //string text = sprintf("%d",players[player_actual].enemigos[amarilloKillIndex].score);
    ResetColor(255,0,0);
     char buffer[33];
     string num_toString = itoa (players[player_actual].enemigos[amarilloKillIndex].score,buffer,10);
     const char *num_toChar = num_toString.c_str();
     esat::DrawText(amarilloKillX,amarilloKillY,num_toChar);
     if(amarilloKilledCount >= fps*2){
       amarilloKilledCount = 1;
       amarilloKill = false;
     }
  }
}


void debugEnemigos(){
  for (int i = 0; i <= N_ENEMIGOS -1; i++){
    printf(" - Enemigo %d score %d - \n",i,players[player_actual].enemigos[i].score);
    //printf(" - Enemigo %d score %d - \n",i,players[player_actual].enemigos[i].score);
    // printf("Type %c \n", players[player_actual].enemigos[i].type);
    // printf("DEBUG Enemigo type:%c x: %d y:%d \n",players[player_actual].enemigos[i].type,players[player_actual].enemigos[i].x,players[player_actual].enemigos[i].y);
   //printf("Index animacion de %d: %d",i,players[player_actual].enemigos[i].index_animacion);
  }

}
