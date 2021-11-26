
struct RGB{
	int r = 0;					//Red
	int g = 0;					//Green
	int b = 0;					//Blue
	int o = 0;					//Opacity
};

struct Snow{
	float x1,y1,x2,y2;			//Position to respawn
	RGB color;					//Color of the snow
	bool opaco = false;			//Opacity true||false
	bool show = true;			//Show the snow or not
	int off = 0;				//Time to not show

};

struct Explosion{
	int x = 0;					//Posicion X de la explosion
	int y = 0;					//Posicion Y de la explosion
	bool explotando = false;	//Explosion en curso
};

struct Disparo{
	int x = 0;					//Posicion X del disparo
	int y = 0;					//Posicion Y del disparo
	bool disparando = false;	//Disparo en curso

};

struct Enemigo{
	int score;					//Puntuacion recibida al matarlo
	int x;						//Posicion X
	int y;						//Posicion Y
	char type;
	Disparo disparo;			//Disparo del enemigo
	Explosion explosion;		//Explosion del enemigo
	char direccion = 'R';		//Direccion horizontal en la que se mueve en el momento R|L|D
	bool descendiendo = false;  //Si el enemigo está descendiendo en parabola hacia el jugador
	bool vivo = true;			//Vivo o muerto

};

struct Jugador{
	int score;					//Puntuacion recibida al matarlo
	int x;						//Posicion X
	int y;						//Posicion Y
	Disparo disparo;			//Disparo del enemigo
	Explosion explosion;		//Explosion del enemigo
	Enemigo enemigos[36];		//Enemigos que pertenencen al jugador
	int vidas;					//Vidas disponibles
	int puntuacion = 0;			//Puntuacion del jugador
	char direccion = 'R';		//Direccion horizontal en la que se mueve en el momento R|L
	bool vivo = true;			//Vivo o muerto
};
