#include <esat/window.h>
#include <esat/draw.h>
#include <esat/input.h>
#include <esat/sprite.h>
#include <esat/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


#include <chrono>
#include <thread>
#include <iostream>
#include <string>
using namespace std;
using std::cout;  //Similar a printf
using std::endl;
using std::copy;
using std::this_thread::sleep_for;     //Bloquea la ejecucion del proceso actual durante al menos el tiempo especificado
using namespace std::chrono_literals;  //Capacidad para acceder a las clases de la libreria crono

string toString(int num) {
	//Basic function to convert int to string
	char buffer[33];
	return itoa (num,buffer,10);
}

void ResetColor(int r = 255,int g = 255,int b = 255){
    esat::DrawSetStrokeColor(r,g,b);
    esat::DrawSetFillColor(r,g,b);
}



#include "includes/structs.cc"
#include "includes/variables.cc"
#include "includes/background.cc"
#include "includes/player.cc"
#include "includes/enemigos.cc"
#include "includes/interfaz.cc"
#include "includes/colisiones.cc"
