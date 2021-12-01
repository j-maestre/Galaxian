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
