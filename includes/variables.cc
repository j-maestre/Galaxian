

const int ALTO=256, ANCHO=224;
const int N_NIEVE = 50,VELOCIDAD_FONDO=4;
const char FONT_PATH[26] = {"assets/fonts/prstart.ttf\0"};

unsigned char fps=25;
double current_time,last_time;

Snow background[N_NIEVE];
