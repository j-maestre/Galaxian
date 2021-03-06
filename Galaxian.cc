#include "includes/all.cc"


int esat::main(int argc, char **argv) {
	srand(time(NULL));

	esat::WindowInit(ANCHO*3,ALTO*3);
	WindowSetMouseVisibility(true);

	//Creating items
	CreateBackGround();
	CreateSprites();
	//CreatePlayer();
	//CreateEnemigos();

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
				//Credits(&credits);
			}else if(!gameOver){
				PrintEnemigos();
				if(!start){
					start = Start();
					//debugEnemigos();
				}else{
					//LLamar al jugador
					PrintPlayer();
					Vidas();
					Levels();
					//Comprobar que toda la fila siga viva
					ComprobarFila();
					//Solo pueden atacar los que están en las esquinas
					PuedeAtacar();
					CheckColisiones();
					CalcularDescenso();
					//DebugPlayer();
					AmarilloKilled();
					CheckGameOver();

					//Si el player actual ha perdido una vida
					if(players[player_actual].gameOver){

						//Marcamos el game over del jugador como false
						players[player_actual].gameOver = false;

						//Si tenemos 2 jugadores, cambiamos al jugador y le asignamos sus aliens
						if(N_players==2){

							//Intercambio de turno si tenemos 2 jugadores
							player_actual==0?player_actual = 1:player_actual = 0;
							fps_count_start = 1;
							
							//Reiniciamos index de ataques
							indexAtaqueA1 = 0;
							indexAtaqueA2 = 9;
							indexAtaqueB1 = 10;
							indexAtaqueB2 = 19;
							indexAtaqueC1 = 20;
							indexAtaqueC2 = 29;
							indexAtaqueD1 = 30;
							indexAtaqueD2 = 37;
							indexAtaqueE1 = 38;
							indexAtaqueE2 = 43;
							
							//Mostramos la animacion
							start = false;
						}

						players[player_actual].x = 350;
						players[player_actual].y = 600;

					}
					if(score1 >= scoreToGetLive || score2 >= scoreToGetLive2){
							players[player_actual].vidas++;
							player_actual==0?scoreToGetLive+=7500:scoreToGetLive2+=7500;

						}
					
				}

			}

			if(gameOver)GameOver();

    	esat::DrawEnd();
    	//Control fps
    	do{
    		current_time = esat::Time();
    	}while((current_time-last_time)<=1000.0/fps);
    	esat::WindowFrame();
  }


  ReleaseSprites();
  esat::WindowDestroy();
  return 0;
}
