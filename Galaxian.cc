#include "includes/all.cc"


int esat::main(int argc, char **argv) {
	srand(time(NULL));

	esat::WindowInit(ANCHO*3,ALTO*3);
	WindowSetMouseVisibility(true);
	CreateBackGround();
	CreateSprites();
	CreateEnemigos();
	esat::DrawSetTextFont(FONT_PATH);

    while(esat::WindowIsOpened() && !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape)) {

    	last_time = esat::Time();
    	esat::DrawBegin();
    	esat::DrawClear(0,0,0);
			MoveBackground();
			Score(&max_score, score1, score2);
			Credits(&credits);
			Interfaz();
			PrintEnemigos();

    	esat::DrawEnd();
    	//Control fps
    	do{
    		current_time = esat::Time();
    	}while((current_time-last_time)<=1000.0/fps);
    	esat::WindowFrame();
  }
  esat::WindowDestroy();
  return 0;
}
