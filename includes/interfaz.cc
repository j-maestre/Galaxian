#include <string>
using namespace std;
using std::cout;  //Similar a printf
using std::endl;
using std::copy;
using std::this_thread::sleep_for;     //Bloquea la ejecucion del proceso actual durante al menos el tiempo especificado
using namespace std::chrono_literals;  //Capacidad para acceder a las clases de la libreria crono


string toString(int num) {
	//Basic function to convert int to string
	char buffer[33];
	return itoa (num,buffer,10);
}

void ResetColor(){
    esat::DrawSetStrokeColor(255,255,255);
    esat::DrawSetFillColor(255,255,255);
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
	}else if(strlen(num_toChar) == 3) {
		strcat(num_toPrint, "0");
		strcat(num_toPrint,num_toChar);

		//Si el score supera los 999, se pintará genericamente
	}else{
		strcat(num_toPrint, num_toChar);
	}
	//Pintamos el array de char
  esat::DrawSetStrokeColor(color.r,color.g,color.b);
  esat::DrawSetFillColor(color.r,color.g,color.b);
	esat::DrawText(x, y,num_toPrint);
  ResetColor();
}

void Credits(int *credits){
  esat::DrawSetStrokeColor(0,238,254);
  esat::DrawSetFillColor(0,238,254);

  string num_toString = toString(*credits);
  const char *num_toChar = num_toString.c_str();

  char credits_to_print[] = "CREDIT \0";
  strcat(credits_to_print, num_toChar);

  esat::DrawText(60, (ALTO*3-60), credits_to_print);
}


void Score(int *max_score, int score = 0, int score2 = 0){
  ResetColor();
  esat::DrawSetTextSize(18);
  esat::DrawText(60, 40, "1 UP");
  esat::DrawText((ANCHO*3)/2 -50, 40, "HIGH SCORE");
  if(score>*max_score)*max_score=score;
  if(score2>*max_score)*max_score=score2;

  RGB color = {255, 0, 0};
  printScore((ANCHO*3)/2 +40,70,*max_score, color);
  printScore((ANCHO*3)/6 -40,70,score, color);

}


void InsertCoin(int *credits){
  esat::DrawSetTextSize(15);
  esat::DrawSetStrokeColor(255,178,0);
  esat::DrawSetFillColor(255,178,0);
  esat::DrawText(ANCHO/2,(ALTO*3)/1.3,"PUSH SPACE TO INSERT CREDITS");

  if(esat::IsSpecialKeyDown(esat::kSpecialKey_Space)){
    ++*credits;
  }
}

bool Players(){
  if(credits>0){
    esat::DrawSetTextSize(20);

    //Si pulsa arriba y tenemos almenos 1 credito, establecemos 1 jugador
    if(esat::IsSpecialKeyDown(esat::kSpecialKey_Up))players = 1;

    //Si hay marcado 1 jugador, pintamos "1 player" en verde
    if(players==1){
      esat::DrawSetStrokeColor(102,203,45);
      esat::DrawSetFillColor(102,203,45);
    }else{
      esat::DrawSetStrokeColor(255,255,255);
      esat::DrawSetFillColor(255,255,255);
    }
    esat::DrawText((ANCHO*3)/3,(ALTO*3)/2.5, "1 PLAYER");

    if(credits>1){

      //Si pulsa abajo y tiene mas de 1 credito establecemos 2 jugadores
      if(esat::IsSpecialKeyDown(esat::kSpecialKey_Down))players=2;

      //Si hay marcados 2 jugadores, pintamos "2 players" en verde
      if(players==2){
        esat::DrawSetStrokeColor(102,203,45);
        esat::DrawSetFillColor(102,203,45);
      }else{
        esat::DrawSetStrokeColor(255,255,255);
        esat::DrawSetFillColor(255,255,255);
      }
      esat::DrawText((ANCHO*3)/3,(ALTO*3)/2.5 +40, "2 PLAYERS");
      ResetColor();
    };

    if(esat::IsSpecialKeyDown(esat::kSpecialKey_Enter))return true;

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

  if(frames_count>=fps*1){
      esat::DrawText((ANCHO*3)/4-80,(ALTO*3)/3 , Intro_l1);
  }
  if(frames_count >=fps*2){
      esat::DrawText((ANCHO*3)/4 -100,(ALTO*3)/3 +40, Intro_l2);
  }

  if(frames_count>=fps*3){
    esat::DrawSetStrokeColor(255,255,255);
    esat::DrawSetFillColor(255,255,255);
    esat::DrawSetTextSize(20);
    esat::DrawText((ANCHO*3)/5 -20 ,(ALTO*3)/2 -30, Score_title1);
  }


}



  return false;
}
