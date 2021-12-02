

const int ALTO=256, ANCHO=224;
const int N_NIEVE = 100,VELOCIDAD_FONDO=2;
const char FONT_PATH[26] = {"assets/fonts/prstart.ttf\0"};
const int N_ENEMIGOS = 46;

bool debug = true;

unsigned char fps=60;
double current_time,last_time;
int fps_count = 1;                              //Contador de fps para las animaciones
Snow background[N_NIEVE];
int score1 = 0, score2 = 0, max_score = 0;
int frames_count = -1, score_frames_count = 0;
int credits = 0, N_players = 1;
int velocidad_enemigos = 1, velocidad_enemigos_disparo = 8;
int velocidad_enemigos_descenso = 2,  velocidad_enemigos_descenso_x = 4;
int velocidad_jugador = 5;
int velocidad_disparo_player = 15;
char direccion_enemigos = 'R';                   //Direccion horizontal en la que se mueven los enemigos R|L

int frecuencia_verde = 150;
int frecuencia_rosa = 200;
int frecuencia_rojo = 210;
int frecuencia_amarillo = 250;
int frecuencia = 4;
int cont_frecuencia = 0;

//Indices de quien puede atacar (esquinas)
int indexAtaqueA1 = 0;
int indexAtaqueA2 = 9;
int indexAtaqueB1 = 10;
int indexAtaqueB2 = 19; 
int indexAtaqueC1 = 20;
int indexAtaqueC2 = 29;
int indexAtaqueD1 = 30;
int indexAtaqueD2 = 37;
int indexAtaqueE1 = 38;
int indexAtaqueE2 = 43;
bool fila1 = true, fila2 = true, fila3 = true, fila4 = true, fila5 = true;

bool players_selected = false;
bool interfaz = false;
bool start = false;
bool win = false;
bool gameOver = false;
bool amarilloKill = false;
int amarilloKillX,amarilloKillY, amarilloKillIndex, amarilloKilledCount = 1;
int player_actual = 0;

char Intro_l1 [22] = "WE ARE THE GALAXIANS\0";
char Intro_l2 [] = "MISION: DESTROY ALIENS\0";
char Score_title1 []= "- SCORE ADVANCE TABLE-\0";
char Score_title2 []= "CONVOY CHARGER\0";
int score_title2_x = 0;
int score_yellow [4]={150,800,300,200}, cont_score_yellow = 0;

esat::SpriteHandle spritesheet;
esat::SpriteHandle spritesheet_invertido;
esat::SpriteHandle logo;
esat::SpriteHandle flecha;
esat::SpriteHandle namcot;
esat::SpriteHandle vidas;
esat::SpriteHandle bandera;
esat::SpriteHandle player;
esat::SpriteHandle playerDisparando;
esat::SpriteHandle playerExplosion [4];
esat::SpriteHandle alienAmarillo;
esat::SpriteHandle alienRojo;
esat::SpriteHandle animacion_alienRojo [4];
esat::SpriteHandle inclinacion_alienRojo[6];
esat::SpriteHandle alienRosa;
esat::SpriteHandle animacion_alienRosa [4];
esat::SpriteHandle inclinacion_alienRosa[6];
esat::SpriteHandle alienVerde;
esat::SpriteHandle animacion_alienVerde [4];
esat::SpriteHandle inclinacion_alienVerde[11];
esat::SpriteHandle explosion_alien[4];
esat::SpriteHandle disparoPlayer;
esat::SpriteHandle disparoEnemigo;
int animacion_selector = 0;
int explosion_selector = 0;

//Animaciones menu
int animationSpeed = 3;
int xAlienAm = ANCHO*3;
int xAlienRo = ANCHO*3;
int xAlienRos = ANCHO*3;
int xAlienVe = ANCHO*3;

int fps_count_start = 1;
int fps_count_explosion = 1;

int fps_count_explosion_player = 1;

Jugador players[2];
//Enemigo enemigos[46];


// esat::SpriteHandle logo = esat::SubSprite(spritesheet,0,843,843,132);
