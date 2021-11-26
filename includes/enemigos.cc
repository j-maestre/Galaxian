void CreateEnemigos(){
  for (int i = 0; i <36; i++) {
    //800, 300, 200, 150,
    int score=0;
    char type;

    if(i>=35){
      switch (rand()%3) {
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
    }

    if(i<20) score=60,type='G';
    if(i<28) score=80,type='P';
    if(i<34) score=100,type='R';
    Disparo disparo;
    Explosion explosion;
    Enemigo enemigo={score,(ANCHO*3)/5 -20 ,(ALTO*3)/2 +80,type,disparo,explosion};
    enemigos[i] = enemigo;

  }
}

void PrintEnemigos(){
  for (int i = 0; i < 36; i++) {
    esat::SpriteHandle sprite;
    switch (enemigos[i].type) {
      case 'G':
        sprite = alienVerde;
      break;
      case 'P':
        sprite = alienRosa;
      break;
      case 'R':
        sprite = alienRojo;
      break;
      case 'Y':
        sprite = alienAmarillo;
      break;
    }
    esat::DrawSprite(sprite,x,y);
  }
}
