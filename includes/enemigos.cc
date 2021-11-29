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
      // printf("\nROSA x: %d y:%d",x,y);

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
    Explosion explosion;
    Enemigo enemigo={score,x,y,type,disparo,explosion};
    enemigos[i] = enemigo;

  }
}

void PrintEnemigos(){
  // fps_count = (fps_count+1)%5;

  //Cada 10 frames cambiamos el sprite del alien para la animacion
  ++fps_count;
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
    //Si el alien que está más a la derecha ha tocado el borde derecho, invertimos la dirección
    if(enemigos[9].x + 24 >=ANCHO*3)direccion_enemigos = 'L';

    //Si el alien que está más a la izquierda ha tocado el borde izquierdo, invertimos la dirección
    if(enemigos[0].x <=0)direccion_enemigos = 'R';


    //Movemos los enemigos a la derecha
    if(direccion_enemigos == 'R' && enemigos[i].vivo && !enemigos[i].descendiendo){
      esat::DrawSprite(sprite,enemigos[i].x+=velocidad_enemigos,enemigos[i].y);

      //Movemos los enemigos a la izquierda
    }else if(direccion_enemigos == 'L' && enemigos[i].vivo &&!enemigos[i].descendiendo){
      esat::DrawSprite(sprite,enemigos[i].x-=velocidad_enemigos,enemigos[i].y);

      //Movemos el enemigo seleccionado hacia abajo 
    }else if(enemigos[i].vivo && enemigos[i].descendiendo){
      //
    }
  }
}


void debugEnemigos(){
  for (int i = 0; i <= N_ENEMIGOS -1; i++){
    // printf(" - Enemigo %d score %d - \n",i,enemigos[i].score);
    // printf("Type %c \n", enemigos[i].type);
    printf("DEBUG Enemigo type:%c x: %d y:%d \n",enemigos[i].type,enemigos[i].x,enemigos[i].y);
  }
  
}


void CalcularDescenso(){
  //Comprobar cuales pueden descender y cuales no (?)
}

void Disparoenemigos(){
  for (int i = 0; i < N_ENEMIGOS; i++){
    //Los enemigos disparan todo el rato siempre y cuando sea posible (hasta que llega hasta abajo)
    if(enemigos[i].descendiendo){
      
    }
  }
  
}