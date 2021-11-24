
struct RGB{
	int r = 0;			//Red
	int g = 0;			//Green
	int b = 0;			//Blue
	int o = 0;	//Opacity
};

struct Snow{
	float x1,y1,x2,y2;		//Position to respawn
	RGB color;						//Color of the snow
	bool opaco = false;		//Opacity true||false
	bool show = true;			//Show the snow or not
	int off = 0;					//Time to not show

};
