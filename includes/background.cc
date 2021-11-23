

void CreateBackGround(){
	//N_NIEVE de columnas de copos de nieve

	for (int i = 0; i <N_NIEVE; i++) {
		float x1 = 1 + rand()% ((ANCHO*3)-1);
 	  float y1 = 1 + rand()% ((ALTO*3)-1);
 	  Snow copo ={x1,y1, x1+1, y1+1};
		if(rand()%4==1)copo.opaco=true;
		background[i]=copo;
	}
}

void MoveBackground(){
	esat::DrawSetStrokeColor(255,255,255);
	esat::DrawSetFillColor(255,255,255);
	for (int i = 0; i <N_NIEVE; i++){

		//Movemos el copo de nieve hacia abajo a la velocidad establecida
		background[i].y1+=VELOCIDAD_FONDO;
		background[i].y2+=VELOCIDAD_FONDO;

		//Si ha llegado hasta abajo, lo ponemos arriba
		if(background[i].y1 >= ALTO*3 || background[i].y2 >= ALTO*3){
			background[i].y1=1;
			background[i].y2=3;
		}

		//Si el copo es opaco, le ponemos opacidad
		if(background[i].opaco){
				esat::DrawSetStrokeColor(139,139,139,200);
				esat::DrawSetFillColor(139,139,139,200);
		}

		//1/40 posibilidades por frame de que el copo desaparezca
		if(rand()%40!=1 && background[i].show){
			float v[10]={background[i].x1,background[i].y1,background[i].x2,background[i].y1,background[i].x2,background[i].y2,background[i].x1,background[i].y2,background[i].x1,background[i].y1};
			esat::DrawSolidPath(v,5);
		}else{
			//No mostrar
			background[i].show=false;
			background[i].off++;

			//Cuando han pasado 20 frames sin mostrarse, ya puede volver a mostrarse
			if(background[i].off == 20){
				background[i].show=true;
				background[i].off=0;
			}
		}
	}
}
