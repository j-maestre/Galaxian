#include <string>
using namespace std;
using std::cout;  //Similar a printf
using std::endl;
using std::copy;
using std::this_thread::sleep_for;     //Bloquea la ejecucion del proceso actual durante al menos el tiempo especificado
using namespace std::chrono_literals;  //Capacidad para acceder a las clases de la libreria crono

void CreateSprites(){
  //Enemigos 24x24
  spritesheet=esat::SpriteFromFile("./assets/sprites/spritesheet.png");
  logo = esat::SubSprite(spritesheet,0,843,432,132);
  flecha = esat::SubSprite(spritesheet,360,1106,23,22);
  namcot = esat::SpriteFromFile("./assets/sprites/namcot.png");
  vidas = esat::SubSprite(spritesheet,382,712,21,28);
  bandera = esat::SubSprite(spritesheet,408,701,24,39);
  playerDisparando = esat::SubSprite(spritesheet,57,691,40,49); //Este sprite hay que pintarlo 12px mas abajo que el otro porque mide menos
  player = esat::SubSprite(spritesheet,6,679,40,61);
  disparoPlayer = esat::SubSprite(spritesheet,114,676,4,11);
  playerExplosion[0] = esat::SubSprite(spritesheet,6,750,87,84);
  playerExplosion[1] = esat::SubSprite(spritesheet,111,756,75,78);
  playerExplosion[2] = esat::SubSprite(spritesheet,210,756,81,75);
  playerExplosion[3] = esat::SubSprite(spritesheet,318,762,69,63);
  disparoEnemigo = esat::SubSprite(spritesheet,267,215,4,12);
  alienAmarillo = esat::SubSprite(spritesheet,9,9,33,33);
  alienRojo = esat::SubSprite(spritesheet,9,114,33,24);
  animacion_alienRojo[0] = esat::SubSprite(spritesheet,60,202,33,24);
  animacion_alienRojo[1] = esat::SubSprite(spritesheet,108,202,33,24);
  animacion_alienRojo[2] = esat::SubSprite(spritesheet,60,202,33,24);
  animacion_alienRojo[3] = esat::SubSprite(spritesheet,216,202,33,24);
  alienRosa = esat::SubSprite(spritesheet,9,294,33,24);
  animacion_alienRosa[0] = esat::SubSprite(spritesheet,60,382,33,24);
  animacion_alienRosa[1] = esat::SubSprite(spritesheet,108,382,33,24);
  animacion_alienRosa[2] = esat::SubSprite(spritesheet,60,382,33,24);
  animacion_alienRosa[3] = esat::SubSprite(spritesheet,216,382,33,24);
  alienVerde = esat::SubSprite(spritesheet,9,474,33,24);
  animacion_alienVerde[0] = esat::SubSprite(spritesheet,60,564,33,24);
  animacion_alienVerde[1] = esat::SubSprite(spritesheet,108,564,33,24);
  animacion_alienVerde[2] = esat::SubSprite(spritesheet,60,564,33,24);
  animacion_alienVerde[3] = esat::SubSprite(spritesheet,216,564,33,24);
  explosion_alien[0] = esat::SubSprite(spritesheet,154,647,48,48);
  explosion_alien[1] = esat::SubSprite(spritesheet,214,653,48,48);
  explosion_alien[2] = esat::SubSprite(spritesheet,262,644,48,48);
  explosion_alien[3] = esat::SubSprite(spritesheet,307,641,48,48);

}

string toString(int num) {
	//Basic function to convert int to string
	char buffer[33];
	return itoa (num,buffer,10);
}


void printScore(int x, int y, int num, RGB color){
  //Convertimos el int a string
	string num_toString = toString(num);

	//Convertimos la string a array de char
	const char *num_toChar = num_toString.c_str();

	//Array que se pintará en el score para añadir los "0" pertinentes
	char num_toPrint[5] = {"\0"};

	//Si la puntuacion tiene un solo digito, le añadimos tres "0" al principio
	if(strlen(num_toChar) == 1) {
		strcat(num_toPrint, "000");
		strcat(num_toPrint,num_toChar);

		//Añadimos dos "0" al principio
	}else if(strlen(num_toChar) == 2) {
		strcat(num_toPrint, "00");
		strcat(num_toPrint,num_toChar);

		//Añadimos un "0" al principio
	}else{
		strcat(num_toPrint, num_toChar);
	}

//Hasta 3 ceros a la izquierda
  // else if(strlen(num_toChar) == 3) {
		// strcat(num_toPrint, "0");
		// strcat(num_toPrint,num_toChar);

		// Si el score supera los 999, se pintará genericamente
	// }



	//Pintamos el array de char
  esat::DrawSetStrokeColor(color.r,color.g,color.b);
  esat::DrawSetFillColor(color.r,color.g,color.b);
	esat::DrawText(x, y,num_toPrint);
  ResetColor();
}

void Credits(int *credits){
  ResetColor(0,238,254);

  string num_toString = toString(*credits);
  const char *num_toChar = num_toString.c_str();

  char credits_to_print[] = "CREDIT \0";
  strcat(credits_to_print, num_toChar);

  esat::DrawSetTextSize(18);
  esat::DrawText(60, (ALTO*3-60), credits_to_print);
}


void Score(){
  ResetColor();
  esat::DrawSetTextSize(18);
  esat::DrawText(60, 40, "1 UP");
  esat::DrawText((ANCHO*3)/2 -100, 40, "HIGH SCORE");
  esat::DrawText((ANCHO*3)/2 +200, 40, "2 UP");
  if(score1>max_score)max_score=score1;
  if(score2>max_score)max_score=score2;

  RGB color = {255, 0, 0};
  printScore((ANCHO*3)/6 -40,70,score1, color);
  printScore((ANCHO*3)/2 -40,70,max_score, color);
  printScore((ANCHO*3)/2 +200,70,score2, color);

}


void InsertCoin(int *credits){
  esat::DrawSetTextSize(15);
  esat::DrawSetStrokeColor(255,178,0);
  esat::DrawSetFillColor(255,178,0);
  esat::DrawText(ANCHO/2,(ALTO*3)/1.3 +70,"PUSH SPACE TO INSERT CREDITS");

  //Logos
  esat::DrawSprite(logo,(ANCHO*3)/4 -50,(ALTO*3)/5);
  esat::DrawSprite(namcot,(ANCHO*3)/3 -30,(ALTO*3)/1.8);
  ResetColor();
  esat::DrawSetTextSize(20);
  esat::DrawText((ANCHO*3)/4 -50,(ALTO*3)/1.4, "©1979 1984 NAMCO LTD.");
  esat::DrawText((ANCHO*3)/4 -30,(ALTO*3)/1.4 +40, "ALL RIGHTS RESERVER");

  if(esat::IsSpecialKeyDown(esat::kSpecialKey_Space)){
    ++*credits;
  }
}

bool Players(){
  if(credits>0){
    esat::DrawSetTextSize(20);

    //Si pulsa arriba y tenemos almenos 1 credito, establecemos 1 jugador
    if(esat::IsSpecialKeyDown(esat::kSpecialKey_Up))N_players = 1;


    if(N_players==1){
      esat::DrawSprite(flecha,(ANCHO*3)/3 -40, (ALTO*3)/2.5 +20);
    }
    esat::DrawSetStrokeColor(181,107,233);
    esat::DrawSetFillColor(181,107,233);
    esat::DrawText((ANCHO*3)/3,(ALTO*3)/2.5 +40, "1 PLAYER");

    if(credits>1){

      //Si pulsa abajo y tiene mas de 1 credito establecemos 2 jugadores
      if(esat::IsSpecialKeyDown(esat::kSpecialKey_Down))N_players=2;

      //Si hay marcados 2 jugadores, pintamos "2 players"
      if(N_players==2){
        esat::DrawSprite(flecha,(ANCHO*3)/3 -40, (ALTO*3)/2.5 +60);
      }

      esat::DrawSetStrokeColor(181,107,233);
      esat::DrawSetFillColor(181,107,233);
      esat::DrawText((ANCHO*3)/3,(ALTO*3)/2.5 +80, "2 PLAYERS");
      ResetColor();
    };

    if(esat::IsSpecialKeyDown(esat::kSpecialKey_Enter)){
      //Despues de pulsar enter, creamos los jugadores necesarios y los enemigos del jugador 1
      CreatePlayer();
      CreateEnemigos();

      //Si cuando pulsa enter ha seleccionado dos jugadores, creamos los enemigos para el segundo jugador y se los asignamos
      if(N_players==2){
        player_actual = 1;
        CreateEnemigos();
        player_actual = 0;
      }
      return true;
    }

  }


  return false;
}

bool Interfaz(){

esat::DrawSetStrokeColor(255,0,0);
esat::DrawSetFillColor(255,0,0);
esat::DrawSetTextSize(25);

  if(!players_selected){
    InsertCoin(&credits);
    players_selected = Players();
  }else{
    frames_count++;

  if(frames_count>=fps*1 || debug){
      esat::DrawText((ANCHO*3)/4-80,(ALTO*3)/3 , Intro_l1);
  }
  if(frames_count >=fps*2 || debug){
      esat::DrawText((ANCHO*3)/4 -100,(ALTO*3)/3 +40, Intro_l2);
  }

  if(frames_count>=fps*3 || debug){
    ResetColor();
    esat::DrawSetTextSize(20);
    esat::DrawText((ANCHO*3)/5 -20 ,(ALTO*3)/2 -30, Score_title1);

  }

  if(frames_count>=fps*4 || debug){
    ResetColor(0, 238, 254);
    esat::DrawText((ANCHO*3)/5 +60 ,(ALTO*3)/2 +10, Score_title2);
  }

  score_frames_count++;

//Tarda en llegar al final 3 segundos
  if(frames_count>=fps*5 || debug){
    if(xAlienAm > (ANCHO*3)/5 +10){
      xAlienAm-=animationSpeed;
    }


    //Pintamos el sprite del alien correspondiente
    esat::DrawSprite(alienAmarillo,xAlienAm,(ALTO*3)/2 +40);

    //Pintamos el convoy board
    esat::DrawText(xAlienAm +90,(ALTO*3)/2 +60, "60");

    //Pintamos la puntuacion del enemigo
    esat::DrawSetTextSize(18);
    RGB colorScore ={0, 238, 254};

    //Funcion de parpadeo cada 0.5 segundos
    if(score_frames_count>=fps*0.5) printScore(xAlienAm +200,(ALTO*3)/2 +60,score_yellow[cont_score_yellow],colorScore);
    ResetColor(0, 238, 254);
    esat::DrawSetTextSize(12);

    //Pintamos el indicador de puntos
    esat::DrawText(xAlienAm +300,(ALTO*3)/2 +60, "PTS");
    esat::DrawSetTextSize(25);
  }
  if(frames_count>=fps*8 || debug){
    if(xAlienRo > (ANCHO*3)/5 +10){
      xAlienRo-=animationSpeed;
    }
    esat::DrawSprite(alienRojo,xAlienRo,(ALTO*3)/2 +90);
    esat::DrawText(xAlienRo +90,(ALTO*3)/2 +110, "50");
    esat::DrawSetTextSize(18);
    if(score_frames_count>=fps*0.5)esat::DrawText(xAlienRo + 200,(ALTO*3)/2 +110, "100");

    esat::DrawSetTextSize(12);
    esat::DrawText(xAlienRo +300,(ALTO*3)/2 +110, "PTS");
    esat::DrawSetTextSize(25);
  }

  if(frames_count>=fps*11 || debug){
    if(xAlienRos > (ANCHO*3)/5 +10){
      xAlienRos-=animationSpeed;
    }
    esat::DrawSprite(alienRosa,xAlienRos,(ALTO*3)/2 +140);
    esat::DrawText(xAlienRos +90,(ALTO*3)/2 +160, "40");
    esat::DrawSetTextSize(18);
    if(score_frames_count>=fps*0.5)esat::DrawText(xAlienRos + 200,(ALTO*3)/2 +160, "80");
    esat::DrawSetTextSize(12);
    esat::DrawText(xAlienRos +300,(ALTO*3)/2 +160, "PTS");
    esat::DrawSetTextSize(25);
  }

  if(frames_count>=fps*14 || debug){
    if(xAlienVe > (ANCHO*3)/5 +10){
      xAlienVe-=animationSpeed;
    }
    esat::DrawSprite(alienVerde,xAlienVe,(ALTO*3)/2 +190);
    esat::DrawText(xAlienVe +90,(ALTO*3)/2 +210, "30");
    esat::DrawSetTextSize(18);
    if(score_frames_count>=fps*0.5){
      esat::DrawText(xAlienVe +200,(ALTO*3)/2 +210, "60");



    }
    esat::DrawSetTextSize(12);
    esat::DrawText(xAlienVe +300,(ALTO*3)/2 +210, "PTS");
    esat::DrawSetTextSize(25);


  }

  //Si el frame_count ha llegado al limite, lo reiniciamos a 0
  if(score_frames_count>=fps){
    score_frames_count = 0;
    cont_score_yellow <3?cont_score_yellow++:cont_score_yellow = 0;

  }

  if(frames_count>=fps*17 || debug){
    if(esat::IsSpecialKeyDown(esat::kSpecialKey_Space)){
      return true;
    }
  }

}



  return false;
}

bool Start(){
  ResetColor(255,0,0);
  fps_count_start++;
  if(fps_count_start<fps*3){
    if(player_actual==0)esat::DrawText(250,450,"PLAYER ONE");
    if(player_actual==1)esat::DrawText(250,450,"PLAYER TWO");
    
  }else{
    fps_count_start = 1;
    return true;
  }

  return false;
}


void Vidas(){
  for (int i = 0; i < players[player_actual].vidas-1; i++) {
    esat::DrawSprite(vidas,(i+1)*30,ALTO*3 -50);
  }
}

void GameOver(){
    Credits(&credits);
    ResetColor(255,0,0);
    esat::DrawText((ANCHO*3)/2.5,(ALTO*3)/1.5,"GAME OVER");
}

void ReleaseSprites(){
  esat::SpriteRelease(spritesheet);
  esat::SpriteRelease(logo);
  esat::SpriteRelease(flecha);
  esat::SpriteRelease(vidas);
  esat::SpriteRelease(playerDisparando);
  esat::SpriteRelease(player);
  esat::SpriteRelease(disparoPlayer);
  esat::SpriteRelease(namcot);
  esat::SpriteRelease(disparoEnemigo);
  esat::SpriteRelease(alienAmarillo);
  esat::SpriteRelease(alienRojo);
  esat::SpriteRelease(alienRosa);
  esat::SpriteRelease(alienVerde);
  esat::SpriteRelease(animacion_alienRojo[0]);
  esat::SpriteRelease(animacion_alienRojo[1]);
  esat::SpriteRelease(animacion_alienRojo[2]);
  esat::SpriteRelease(animacion_alienRojo[3]);
  esat::SpriteRelease(animacion_alienVerde[0]);
  esat::SpriteRelease(animacion_alienVerde[1]);
  esat::SpriteRelease(animacion_alienVerde[2]);
  esat::SpriteRelease(animacion_alienVerde[3]);
  esat::SpriteRelease(animacion_alienRosa[0]);
  esat::SpriteRelease(animacion_alienRosa[1]);
  esat::SpriteRelease(animacion_alienRosa[2]);
  esat::SpriteRelease(animacion_alienRosa[3]);
  esat::SpriteRelease(explosion_alien[0]);
  esat::SpriteRelease(explosion_alien[1]);
  esat::SpriteRelease(explosion_alien[2]);
  esat::SpriteRelease(explosion_alien[3]);
  esat::SpriteRelease(playerExplosion[0]);
  esat::SpriteRelease(playerExplosion[1]);
  esat::SpriteRelease(playerExplosion[2]);
  esat::SpriteRelease(playerExplosion[3]);
  // esat::SpriteRelease(sprite);
}
