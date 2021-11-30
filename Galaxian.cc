#include "includes/all.cc"


int esat::main(int argc, char **argv) {
	srand(time(NULL));

	esat::WindowInit(ANCHO*3,ALTO*3);
	WindowSetMouseVisibility(true);

	//Creating items
	CreateBackGround();
	CreateSprites();
	CreateEnemigos();
	CreatePlayer();
	//debugEnemigos();
	//End creating items

	esat::DrawSetTextFont(FONT_PATH);

    while(esat::WindowIsOpened() && !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape)) {

    	last_time = esat::Time();
    	esat::DrawBegin();
    	esat::DrawClear(0,0,0);
			MoveBackground();
			Score();

			if(!interfaz){
				interfaz = Interfaz();
				Credits(&credits);
			}else{
				PrintEnemigos();
				if(!start){
					start = Start();

				}else{
					//LLamar al jugador
					PrintPlayer();
					Vidas();
					//Comprobar que toda la fila siga viva
					ComprobarFila();
					//Solo pueden atacar los que están en las esquinas
					PuedeAtacar();
					CheckColisiones();
					CalcularDescenso();
				}

			}

    	esat::DrawEnd();
    	//Control fps
    	do{
    		current_time = esat::Time();
    	}while((current_time-last_time)<=1000.0/fps);
    	esat::WindowFrame();
  }


  ReleaseSprites();
  esat::WindowDestroy();
//   printf("END\n");
//   debugEnemigos();
  return 0;
}
