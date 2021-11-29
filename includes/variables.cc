

const int ALTO=256, ANCHO=224;
const int N_NIEVE = 100,VELOCIDAD_FONDO=2;
const char FONT_PATH[26] = {"assets/fonts/prstart.ttf\0"};
const int N_ENEMIGOS = 46;

bool debug = true;

unsigned char fps=60;
double current_time,last_time;
int fps_count = 1;                                   //Contador de fps para las animaciones
Snow background[N_NIEVE];
int score1 = 0, score2 = 0, max_score = 0;
int frames_count = -1;
int credits = 0, N_players = 1;
int velocidad_enemigos = 1, velocidad_jugador = 5;
char direccion_enemigos = 'R';                          //Direccion horizontal en la que se mueven los enemigos R|L


bool players_selected = false;
bool interfaz = false;
bool start = false;
int player_actual = 1;

char Intro_l1 [22] = "WE ARE THE GALAXIANS\0";
char Intro_l2 [] = "MISION: DESTROY ALIENS\0";
char Score_title1 []= "- SCORE ADVANCE TABLE-\0";
char Score_title2 []= "CONVOY CHARGER\0";
int score_title2_x = 0;

esat::SpriteHandle spritesheet;
esat::SpriteHandle logo;
esat::SpriteHandle flecha;
esat::SpriteHandle namcot;
esat::SpriteHandle player;
esat::SpriteHandle playerDisparando;
esat::SpriteHandle alienAmarillo;
esat::SpriteHandle alienRojo;
esat::SpriteHandle animacion_alienRojo [4];
esat::SpriteHandle alienRosa;
esat::SpriteHandle animacion_alienRosa [4];
esat::SpriteHandle alienVerde;
esat::SpriteHandle animacion_alienVerde [4];
int animacion_selector = 0;

//Animaciones menu
int animationSpeed = 3;
int xAlienAm = ANCHO*3;
int xAlienRo = ANCHO*3;
int xAlienRos = ANCHO*3;
int xAlienVe = ANCHO*3;

int fps_count_start = 1;

Jugador players[2];
Enemigo enemigos[46];


// esat::SpriteHandle logo = esat::SubSprite(spritesheet,0,843,843,132);
