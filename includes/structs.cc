
struct RGB{
	int r = 0;									//Red
	int g = 0;									//Green
	int b = 0;									//Blue
	int o = 0;									//Opacity
};

struct Snow{
	float x1,y1,x2,y2;					//Position to respawn
	RGB color;									//Color of the snow
	bool opaco = false;					//Opacity true||false
	bool show = true;						//Show the snow or not
	int off = 0;								//Time to not show

};

struct Explosion{
	int x = 0;									//Posicion X de la explosion
	int y = 0;									//Posicion Y de la explosion
	bool explotando = false;					//Explosion en curso
};

struct Disparo{
	int x = 0;									//Posicion X del disparo
	int y = 0;									//Posicion Y del disparo
	bool disparando = false;		//Disparo en curso

};

struct Enemigo{
	int score;									//Puntuacion recibida al matarlo
	int x;						  				//Posicion X
	int y;						  				//Posicion Y
	char type;									//Enemy type
	Disparo disparo;							//Disparo del enemigo
	Explosion explosion;						//Explosion del enemigo
	bool esquina = false;						//Si está en una esquina, podrá atacar, sino no
	bool ascendiendo = false;
	bool finAscenso = false;
	int ascensoX = 0;
	int ascensoY = 0;
	bool descendiendo = false;  				//Si el enemigo está descendiendo en parabola hacia el jugador
	char direccion_descenso = 'R';					//La direccion X en la que desciende R|L
	bool fin_descenso = false;
	int descensoX = 0;
	int descensoY = 0;
	bool vivo = true;							//Vivo o muerto
	int index_animacion = rand()%4;

};

struct Jugador{
	int x;											//Posicion X
	int y;											//Posicion Y
	Disparo disparo;								//Disparo del jugador
	Explosion explosion;							//Explosion del jugador
	Enemigo enemigos[46];							//Enemigos que pertenencen al jugador
	int vidas = 3;									//Vidas disponibles
	int puntuacion = 7200;								//Puntuacion del jugador
	char direccion = 'R';							//Direccion horizontal en la que se mueve en el momento R|L
	bool vivo = true;								//Vivo o muerto
	bool gameOver = false;							//Si hemos perdido una vida
	int levels = 1;									//Nivel en el que se encuentra
	float velocidad_enemigos_descenso = 2;
	float velocidad_enemigos_disparo = 8;
};
