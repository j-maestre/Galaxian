

const int ALTO=256, ANCHO=224;
const int N_NIEVE = 100,VELOCIDAD_FONDO=4;
const char FONT_PATH[26] = {"assets/fonts/prstart.ttf\0"};

unsigned char fps=25;
double current_time,last_time;
Snow background[N_NIEVE];
int score1 = 0, score2 = 0, max_score = 0;
int frames_count = -1;
int credits = 0, players = 1;

bool players_selected = false;

char Intro_l1 [22] = "WE ARE THE GALAXIANS\0";
char Intro_l2 [] = "MISION: DESTROY ALIENS\0";
char Score_title1 []= "- SCORE ADVANCE TABLE-\0";
char score_title2 []= "CONVOY CHARGER\0";
int score_title2_x = 0;
