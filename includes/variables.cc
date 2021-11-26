

const int ALTO=256, ANCHO=224;
const int N_NIEVE = 100,VELOCIDAD_FONDO=2;
const char FONT_PATH[26] = {"assets/fonts/prstart.ttf\0"};

bool debug = true;

unsigned char fps=60;
double current_time,last_time;
Snow background[N_NIEVE];
int score1 = 0, score2 = 0, max_score = 0;
int frames_count = -1;
int credits = 0, players = 1;

bool players_selected = false;

char Intro_l1 [22] = "WE ARE THE GALAXIANS\0";
char Intro_l2 [] = "MISION: DESTROY ALIENS\0";
char Score_title1 []= "- SCORE ADVANCE TABLE-\0";
char Score_title2 []= "CONVOY CHARGER\0";
int score_title2_x = 0;

esat::SpriteHandle spritesheet;
esat::SpriteHandle logo;
esat::SpriteHandle flecha;
esat::SpriteHandle namcot;
esat::SpriteHandle alienAmarillo;
esat::SpriteHandle alienRojo;
esat::SpriteHandle alienRosa;
esat::SpriteHandle alienVerde;

//Animaciones menu
int animationSpeed = 3;
int xAlienAm = ANCHO*3;
int xAlienRo = ANCHO*3;
int xAlienRos = ANCHO*3;
int xAlienVe = ANCHO*3;

Enemigo enemigos[36];


// esat::SpriteHandle logo = esat::SubSprite(spritesheet,0,843,843,132);
