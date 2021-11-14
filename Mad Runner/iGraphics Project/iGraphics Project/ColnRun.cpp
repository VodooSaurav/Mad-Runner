#include"iGraphics.h"
#include"bitmap_loader.h"
#define screenWidth 1200
#define screenHeight 600
#define screenHeight 600
#define jumpLimit 200

//for game char
int gcXAxis= 0;
int gcYAxis =100;
char g_char[7][20]={"game char\\1.bmp", "game char\\2.bmp", "game char\\3.bmp", "game char\\4.bmp", "game char\\5.bmp", "game char\\6.bmp", "game char\\7.bmp"};
char g_jump[2][20]= {"game char\\jump1.bmp","game char\\jump2.bmp"};
int g_charIndex=0;
int level=0;

//for obstacle
int obsXAxis = 1180;
int obsYAxis = 100;
char obs1[10]= {"obs\\1.bmp"};

//for jumping
bool jump = false;
bool jumpUp = false;
int characterCordinateJump = 0;
int standCounter=0;
bool standPosition = true;

//for audio
bool audioCheck=true;


/* 
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
	//place your drawing codes here
	iClear();

	 //for jumping
		if(jump)
    {
        if(jumpUp)
        {
            iShowBMP2(gcXAxis, gcYAxis+characterCordinateJump, g_jump[0], 0);

        }
        else
        {
            iShowBMP2(gcXAxis, gcYAxis+characterCordinateJump, g_jump[1], 0);
        }
    }
    else
    {
        if(!standPosition)
        {
            iShowBMP2(gcXAxis, gcYAxis, g_char[g_charIndex], 0);
            standCounter++;
            if(standCounter >= 20)
            {
                standCounter = 0;
                g_charIndex = 0;
                standPosition = true;

            }
        }
        else
        {
            iShowBMP2(gcXAxis, gcYAxis, g_char[g_charIndex], 0);

        }
	}

		
}
	
		
}

//currently turned off for complexion
void collision()
{
    if(gcXAxis < obsXAxis+80 && gcXAxis+120 > obsXAxis && gcYAxis < obsYAxis+80 && gcYAxis+120 > obsYAxis) 
    {
        //iText(0, 0, "Game Over");
        iPauseTimer(0);
    }
	else{
		iResumeTimer(0);
	}

}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
	
}

/*
	function iPassiveMouse() is called when the user moves the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iPassiveMouse(int mx, int my)
{
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	printf("x = %d, y= %d\n",mx,my);

	

	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
		//printf("x = %d, y= %d\n",mx,my);
		
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
			
		
	}
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed. 
*/
void iKeyboard(unsigned char key)
{
	if(key == ' ')
    {
        if(!jump)
        {
            jump = true;
            jumpUp = true;
        }
	}
	if(key == 'p')
	{
		//do something with 'q'
		iPauseTimer(0);
	}
	if(key == 'r')
	{
		iResumeTimer(0);
	}

		if(key == 'm'){

		if(audioCheck){
			audioCheck=false;
			PlaySound(0,0,0);
		}
		else{
			audioCheck=true;
			PlaySound("MyMusic.wav",NULL,SND_LOOP|SND_ASYNC);
		}
		}

	}
	//place your codes for other keys here


/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use 
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6, 
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12, 
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP, 
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT 
*/
void iSpecialKeyboard(unsigned char key)
{
	if(key == GLUT_KEY_HOME)
	{
	
	}

	if(key == GLUT_KEY_HOME)
	{
		
	}

	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
	//place your codes for other keys here
	else if(key == GLUT_KEY_LEFT)
    {
        gcXAxis-=10;
        g_charIndex--;
        //standPosition = false;//
        if(g_charIndex < 0)
            g_charIndex = 6;

        standPosition = false;

    }
    else if(key == GLUT_KEY_RIGHT)
    {
        gcXAxis+=10;
        g_charIndex++;
        //standPosition = false;
        if(g_charIndex >= 7)
        {
            g_charIndex = 0;

            standPosition = false;
        }

        }
}

 void run(){
 

        obsXAxis-=20;
        if(obsXAxis < 0 )
        {
           obsXAxis=1300;
           //collision();
		   //level=4;
        }
    }



int main()
{
	//place your own initialization codes here.
	
	
	iSetTimer(100,run);
	
	if(audioCheck)
	PlaySound("MyMusic.wav",NULL,SND_LOOP | SND_ASYNC);
	iInitialize(screenWidth,screenHeight,"Mad Runner");
	iStart();


	return 0;
}

