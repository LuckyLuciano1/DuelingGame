#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>

#include "Engine.h"
using namespace std;

int main()
{
	Engine basic(60.0);//sets up allegro and custom variables (input is FPS)
	
	basic.GameLoop();//runs repeatedly until user input halts the commands

	return 0;
}