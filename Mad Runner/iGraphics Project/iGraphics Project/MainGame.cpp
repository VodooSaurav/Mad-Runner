//#include"iGraphics.h"
#include"Brain.h"

#define screenWidth 1200
#define screenHeight 600




//for audio
bool audioCheck=true;


/* 
	function iDraw() is called again and again by the system.
	
*/
void drawTextBox()
{
	iSetColor(150, 150, 150);
	iRectangle(450, 280, 300, 50);
}
void iDraw()
{
	//place your drawing codes here
	iClear();
	drawTextBox();

	if(level==0)
	{
	iShowBMP(0, 0,"game char\\BG.bmp");
	iPauseTimer(t1);
	iPauseTimer(t2);
	iPauseTimer(t3);
	}

	if(level==1)
		{
		iSetColor(255, 255, 255);
		iText(455, 305, str);
		//iShowBMP2(0, 0, "game char\\Input_BG.bmp", 0);
		iText(520, 370, "Enter Your Name Here: ");
		iText(10, 10, "Write Your Name in The Box & Press 'F2' to continue.");
	}
	
	else if(level==2){ //level=1
	     iResumeTimer(t1);
		 iDrawBGR();
		 iDrawJump();
		 iDrawCollision();
		 iDrawInput();
		 iText(535,550, "Level 1", GLUT_BITMAP_TIMES_ROMAN_24);
		 scoringLevel2();
		 scoringLevel3();
		 collision1();
		 collision2();
		 collision3();
	   }
	
		

		
		
	if(level==5) // level 2
	{
	iShowBMP(0, 0,"game char\\help.bmp");
	}

	else if(level==6) // level 3
	{
	HighScoreCalculate();
	iShowBMP(0,0,"game char\\hs.bmp");
	HighScoreShow();
	}

	else if(level==7)
	{
	iShowBMP(0,0,"end.bmp");
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
	//printf("gcX = %d , gcY= %d, obX = %d, obY= %d\n",gcXAxis,gcYAxis,obsXAxis,obsYAxis);
	if(level==0)
	{
		if(mx>=495 && mx<=702 && my>=300 && my<=342){
			level=1; 
	}
}

	if(level==0)
	{
	if(mx>=503 && mx<=798 && my>=154 && my<=201){

			level=5;
	}
	if(level==0)
	{
	if(mx>=374  && mx<=829 && my>=228  && my<=276){

			level=6;
	}
}
	}

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



/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed. 
*/
void iKeyboard(unsigned char key)
{
	if(key == ' ')
    {
       jumpButton(); 
	   jumpPoint();
	  
	}
	if(key == 'p')
	{
		//do something with 'q'
		iPauseTimer(t1);
	}
	if(key == 'h')
	{
		iResumeTimer(t1);
	}
	
	if(key == 'b')
	{
		if(level==2){
			level=0;
		}
		else if(level==7){
			level=0;
		}
	}
		/*else if(level==3){
			level=0;
		}
		else if(level==4){
			level=0;
		}
	}*/
	/*if(key == 'b')
	{
		if(level==3){
			level=0;
		}
	}
	if(key == 'b')
	{
		if(level==4){
			level=0;
		}
	}*/


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
		

	int i;
	if(level == 1)
	{
        if(key == '\r')
		{
			level = 0;
			strcpy(str2, str);
			printf("%s\n", str2);
			for(i = 0; i < len; i++)
				str[i] = 0;
			len = 0;
		}
		else
		{
			str[len] = key;
			len++;
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
	if(level==6)
	{
		level=0;
	}
	else if(level==5){
		level=0;
	}

	}

	if(level == 1){
		if(key == GLUT_KEY_F2)
		{
		level = 2;
		}
		
	}
	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
	//place your codes for other keys here
	else if(key == GLUT_KEY_LEFT)
    {
		leftMove();
    }
    else if(key == GLUT_KEY_RIGHT)
    {
	  // a=2;
       rightMove();
    }
}




int main()
{
	//place your own initialization codes here.
	len = 0;
	level = 0;
	str[0]= 0;
	indexNumber = strlen(str) - 1;
	
	positionfunction();
	
	run1();
	
	t1=iSetTimer(80,run1); 
	t2=iSetTimer(60,run2); 
	t3=iSetTimer(40,run3);
	
	
if(audioCheck)
	PlaySound("MyMusic.wav",NULL,SND_LOOP | SND_ASYNC);
	
	iInitialize(screenWidth,screenHeight,"Mad Runner");
	iStart();
	return 0;
	//You have the authority to change values and making improvements in levels,ending etc.
}

