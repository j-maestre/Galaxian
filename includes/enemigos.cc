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
    enemigos[i] = enemigo;

  }
}

void ExplosionEnemigos(int posicion){
  fps_count_explosion++;

  //Cada 0'25 segundos muestro una animacion de la explosion
  if(fps_count_explosion>fps*(explosion_selector*0.1))explosion_selector++;
  if(explosion_selector<4){
    esat::DrawSprite(explosion_alien[explosion_selector],enemigos[posicion].explosion.x, enemigos[posicion].explosion.y);

    //Cuando ya he mostrado todas las explosiones, dejo de explotar y reinicio las variables
  }else if(explosion_selector>=4){
    explosion_selector=0;
    fps_count_explosion = 0;
    enemigos[posicion].explosion.explotando = false;
  }
  // esat::DrawSprite();
}

void PrintEnemigos(){
  // fps_count = (fps_count+1)%5;
  fps_count<1000?++fps_count:fps_count=0;
  // printf("%d ",fps_count);

  //Cada 10 frames cambiamos el sprite del alien para la animacion

  if(fps_count%15 == 0){
    animacion_selector>=3?animacion_selector=0:++animacion_selector;
  }


  for (int i = 0; i <=N_ENEMIGOS -1; i++) {
    esat::SpriteHandle sprite;
    switch (enemigos[i].type) {
      case 'G':
        sprite = animacion_alienVerde[animacion_selector];
      break;
      case 'P':
        sprite = animacion_alienRosa[animacion_selector];
      break;
      case 'R':
        sprite = animacion_alienRojo[animacion_selector];
      break;
      case 'Y':
        sprite = alienAmarillo;
      break;
    }
    //Si cualquier alien está vivo y ha tocado el borde derecho, invertimos la dirección
    if(enemigos[i].vivo && enemigos[i].x + 33 >=ANCHO*3)direccion_enemigos = 'L';

    //Si cualquier alien está vivo y ha tocado el borde izquierdo, invertimos la dirección
    if(enemigos[i].vivo && enemigos[i].x <=0)direccion_enemigos = 'R';


    //Movemos los enemigos a la derecha
    if(direccion_enemigos == 'R' && !enemigos[i].descendiendo){
      enemigos[i].x+=velocidad_enemigos;
      if(enemigos[i].vivo)esat::DrawSprite(sprite,enemigos[i].x,enemigos[i].y);

      //Movemos los enemigos a la izquierda
    }else if(direccion_enemigos == 'L' &&!enemigos[i].descendiendo){
      enemigos[i].x-=velocidad_enemigos;
      if(enemigos[i].vivo)esat::DrawSprite(sprite,enemigos[i].x,enemigos[i].y);

      //Movemos el enemigo seleccionado hacia abajo
    }else if(enemigos[i].vivo && enemigos[i].descendiendo){
      //
    }

    //Si está explotando, llamamos a la funcion de explotar y le pasamos el indice del enemigo
    if(enemigos[i].explosion.explotando)ExplosionEnemigos(i);
  }
}


void CalcularDescenso(){
  cont_frecuencia++;
  if(cont_frecuencia%(fps*frecuencia) == 0){
    int random = rand()%201;
    printf("Sacamos num random: %d\n", random);
    if(random<=frecuencia_verde){
      //Baja un verde
      printf("VERDE \n");
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

void Disparoenemigos(){
  for (int i = 0; i < N_ENEMIGOS; i++){
    //Los enemigos disparan todo el rato siempre y cuando sea posible (hasta que llega hasta abajo)
    if(enemigos[i].descendiendo){

    }
  }

}


void debugEnemigos(){
  for (int i = 0; i <= N_ENEMIGOS -1; i++){
    // printf(" - Enemigo %d score %d - \n",i,enemigos[i].score);
    // printf("Type %c \n", enemigos[i].type);
    // printf("DEBUG Enemigo type:%c x: %d y:%d \n",enemigos[i].type,enemigos[i].x,enemigos[i].y);
  }

}
