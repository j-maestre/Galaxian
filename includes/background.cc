

void CreateBackGround(){
	//N_NIEVE de columnas de copos de nieve

	for (int i = 0; i <N_NIEVE; i++) {
		float x1 = 1 + rand()% ((ANCHO*3)-1);
 	  float y1 = 1 + rand()% ((ALTO*3)-1);
		RGB color ={0,0,0};

		int colorRandom = rand()%3;

		switch (colorRandom) {
			case 0:
				color.r=180;
			break;
			case 1:
				color.g=180;
			break;
			case 2:
				color.b=180;
			break;
			default:
				color.r=255;
				color.g=255;
				color.b=255;
			break;

		}

 	  Snow copo ={x1,y1, x1+1, y1+1, color};
		if(rand()%4==1)copo.opaco=true;
		background[i]=copo;
	}
}

void MoveBackground(){

	for (int i = 0; i <N_NIEVE; i++){
		esat::DrawSetStrokeColor(background[i].color.r,background[i].color.g,background[i].color.b);
		esat::DrawSetFillColor(background[i].color.r,background[i].color.g,background[i].color.b);

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
