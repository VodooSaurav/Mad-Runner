#ifndef Brain
#define Brain
#include<stdio.h>
#include"iGraphics.h"
#include"bitmap_loader.h"
int level=0;
int t1,t2,t3;

//For Run+Jump
#define jumpLimit 120
int gcXAxis= 0;
int gcYAxis =100;
int gcYAxis2 =140;
int gcYAxis3 =66;
char g_char[7][20]={"game char\\1.bmp", "game char\\2.bmp", "game char\\3.bmp", "game char\\4.bmp", "game char\\5.bmp", "game char\\6.bmp", "game char\\7.bmp"};
int g_charIndex=0;
char g_jump[2][20]= {"game char\\jump1.bmp","game char\\jump2.bmp"};
bool jump = false;
bool jumpUp = false;
int characterCordinateJump = 0;
int standCounter=0;
bool standPosition = true;

//For Background
char B_Render[16][20] = {"LT2\\IMG_15.bmp", "LT2\\IMG_14.bmp", "LT2\\IMG_13.bmp", "LT2\\IMG_12.bmp", "LT2\\IMG_11.bmp", "LT2\\IMG_10.bmp", "LT2\\IMG_9.bmp", "LT2\\IMG_8.bmp", "LT2\\IMG_7.bmp", "LT2\\IMG_6.bmp", "LT2\\IMG_5.bmp", "LT2\\IMG_4.bmp", "LT2\\IMG_3.bmp", "LT2\\IMG_2.bmp", "LT2\\IMG_1.bmp", "LT2\\IMG_0.bmp"};
char B_Render2[16][20] = {"LT\\IMG_0.bmp", "LT\\IMG_1.bmp", "LT\\IMG_2.bmp", "LT\\IMG_3.bmp", "LT\\IMG_4.bmp", "LT\\IMG_5.bmp", "LT\\IMG_6.bmp", "LT\\IMG_7.bmp", "LT\\IMG_8.bmp", "LT\\IMG_9.bmp", "LT\\IMG_10.bmp", "LT\\IMG_11.bmp", "LT\\IMG_12.bmp", "LT\\IMG_13.bmp", "LT\\IMG_14.bmp", "LT\\IMG_15.bmp"};
char B_Render3[16][20] = {"LT3\\IMG_20.bmp", "LT3\\IMG_19.bmp", "LT3\\IMG_18.bmp", "LT3\\IMG_17.bmp", "LT3\\IMG_16.bmp", "LT3\\IMG_15.bmp", "LT3\\IMG_14.bmp", "LT3\\IMG_13.bmp", "LT3\\IMG_12.bmp", "LT3\\IMG_11.bmp", "LT3\\IMG_10.bmp", "LT3\\IMG_9.bmp", "LT3\\IMG_8.bmp", "LT3\\IMG_7.bmp", "LT3\\IMG_6.bmp", "LT3\\IMG_5.bmp"};
int imgpos[16], i, j;
int slice = 16;
int width = 1200 / slice;





//For Obstacle+Collision
int obsXAxis = 1180;
int obsYAxis = 100;
//int obsXAxis2 = 1180;
int obsYAxis2 = 145;
int obsYAxis3 = 71;
char obs1[10]= {"obs\\4.bmp"};
char obs2[15]= {"obs\\obs2.bmp"};
char obs3[15]= {"obs\\obs3.bmp"};

//For Score
int highScore=0;
int score = 0;
char score_char[10];
int point =1;
char str[100], str2[100];
int len;
int indexNumber=0;


//All running functions
void iDrawJump(){

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
void iDrawJump2(){

	if(jump)
    {
        if(jumpUp)
        {
            iShowBMP2(gcXAxis, gcYAxis2+characterCordinateJump, g_jump[0], 0);

        }
        else
        {
            iShowBMP2(gcXAxis, gcYAxis2+characterCordinateJump, g_jump[1], 0);
        }
    }
    else
    {
        if(!standPosition)
        {
            iShowBMP2(gcXAxis, gcYAxis2, g_char[g_charIndex], 0);
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
            iShowBMP2(gcXAxis, gcYAxis2, g_char[g_charIndex], 0);

        }

}
}
void iDrawJump3(){

	if(jump)
    {
        if(jumpUp)
        {
            iShowBMP2(gcXAxis, gcYAxis3+characterCordinateJump, g_jump[0], 0);

        }
        else
        {
            iShowBMP2(gcXAxis, gcYAxis3+characterCordinateJump, g_jump[1], 0);
        }
    }
    else
    {
        if(!standPosition)
        {
            iShowBMP2(gcXAxis, gcYAxis3, g_char[g_charIndex], 0);
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
            iShowBMP2(gcXAxis, gcYAxis3, g_char[g_charIndex], 0);

        }

}
}
void jumpButton(){
		if(!jump)
        {
            jump = true;
            jumpUp = true;
        }
	
	}
void leftMove(){
	 gcXAxis-=10;
        g_charIndex--;
        //standPosition = false;//
        if(g_charIndex < 0)
            g_charIndex = 6;

        standPosition = false;
}
void rightMove(){
	 gcXAxis+=10;
        g_charIndex++;
        //standPosition = false;
        if(g_charIndex >= 7)
        {
            g_charIndex = 0;

            standPosition = false;
	
}
}

void run1()
{
		int i;
		for(i = 0; i < 16; i++)
	{
		imgpos[i] -= width;
		if(imgpos[i] < 0)
		{
			imgpos[i] = (slice*width) - width;
		}
	}

		if(jump)
        {
            if(jumpUp)
            {
                characterCordinateJump += 10;
                if(characterCordinateJump >= jumpLimit)
                {
                    jumpUp = false;
                }

            }
            else
            {
                characterCordinateJump -= 10;
                if(characterCordinateJump < 0)
                {
                    jump = false;
                    characterCordinateJump = 0;
                }

            }

        }
        g_charIndex++;
        if(g_charIndex >= 7)
        {
            g_charIndex = 0;
			i=1;
            score+= i*point;
			
		}

		//if(a==2)
		
		obsXAxis-=20;
        if(obsXAxis < 0 )
        {
            obsXAxis=1300;
        }
		
    }
void run2()
{
		int i;
		for(i = 0; i < 16; i++)
	{
		imgpos[i] -= width;
		if(imgpos[i] < 0)
		{
			imgpos[i] = (slice*width) - width;
		}
	}

		if(jump)
        {
            if(jumpUp)
            {
                characterCordinateJump += 10;
                if(characterCordinateJump >= jumpLimit)
                {
                    jumpUp = false;
                }

            }
            else
            {
                characterCordinateJump -= 10;
                if(characterCordinateJump < 0)
                {
                    jump = false;
                    characterCordinateJump = 0;
                }

            }

        }
        g_charIndex++;
        if(g_charIndex >= 7)
        {
            g_charIndex = 0;
			i=1;
            score+= i*point;
			
		}

		//if(a==2)
		
		obsXAxis-=20;
        if(obsXAxis < 0 )
        {
            obsXAxis=1300;
        }
		
    }
void run3()
{
		int i;
		for(i = 0; i < 16; i++)
	{
		imgpos[i] -= width;
		if(imgpos[i] < 0)
		{
			imgpos[i] = (slice*width) - width;
		}
	}

		if(jump)
        {
            if(jumpUp)
            {
                characterCordinateJump += 10;
                if(characterCordinateJump >= jumpLimit)
                {
                    jumpUp = false;
                }

            }
            else
            {
                characterCordinateJump -= 10;
                if(characterCordinateJump < 0)
                {
                    jump = false;
                    characterCordinateJump = 0;
                }

            }

        }
        g_charIndex++;
        if(g_charIndex >= 7)
        {
            g_charIndex = 0;
			i=1;
            score+= i*point;
			
		}

		//if(a==2)
		
		obsXAxis-=20;
        if(obsXAxis < 0 )
        {
            obsXAxis=1300;
        }
		
    }

//All background render functions
void iDrawBGR(){
	for(i=0; i < 16; i++)
		 {
			iShowBMP(imgpos[i], 0, B_Render[i]);
	     }
}
void iDrawBGR2(){
	for(i=0; i < 16; i++)
		 {
			iShowBMP(imgpos[i], 0, B_Render2[i]);
	     }
}
void iDrawBGR3(){
	for(i=0; i < 16; i++)
		 {
			iShowBMP(imgpos[i], 0, B_Render3[i]);
	     }
}

void positionfunction(){
	int i, j;
	for(i=0, j=0; i<slice; i++){
		imgpos[i] = j;
		j += width;
	}
}

//All Obstacle+Collison Functions

void iDrawCollision(){
	 iShowBMP2(obsXAxis, obsYAxis, obs1,0);
	
	}
void iDrawCollision2(){
	 iShowBMP2(obsXAxis, obsYAxis2, obs2,0);
	
	}
void iDrawCollision3(){
	 iShowBMP2(obsXAxis, obsYAxis3, obs3,0);
	
	}

void collision1()
{
    if(gcXAxis+82 > obsXAxis && obsXAxis+75 >gcXAxis  && gcYAxis+120 > obsYAxis && obsYAxis+60 > (gcYAxis+characterCordinateJump)) 
    {
        //iText(0, 0, "Game Over");
        iPauseTimer(t1);
		level=7;
    }
}
void collision2()
{
    if(gcXAxis+82 > obsXAxis && obsXAxis+75 >gcXAxis  && gcYAxis2+120 > obsYAxis2 && obsYAxis2+60 > (gcYAxis2+characterCordinateJump)) 
    {
        //iText(0, 0, "Game Over");
         iPauseTimer(t2);
		 level=7;
	}
}
void collision3()
{
    if(gcXAxis+82 > obsXAxis && obsXAxis+75 >gcXAxis  && gcYAxis3+120 > obsYAxis3 && obsYAxis3+60 > (gcYAxis3+characterCordinateJump)) 
    {
        //iText(0, 0, "Game Over");
         iPauseTimer(t3);
		 level=7;
	
    }
}

void iDrawInput(){
		  printf("Name: ", str);
		  iSetColor(0, 0, 0);
	      iText(900, 550, "Player Name : ", GLUT_BITMAP_TIMES_ROMAN_24);
		  iText(1050, 550, str, GLUT_BITMAP_TIMES_ROMAN_24);
		  sprintf(score_char, "%d", score);
	      printf("%s", score_char);
		  iSetColor(0, 0, 0);
		  iText(900, 500, "Score             : ", GLUT_BITMAP_TIMES_ROMAN_24);
		  iText(1050, 500, score_char, GLUT_BITMAP_TIMES_ROMAN_24);
}
void jumpPoint(){
	 if(obsXAxis < gcXAxis+260 && gcXAxis <= obsXAxis)
	   {
		   i=5;
		   score+=i*point;
	   
	   }
}
void scoringLevel2()
{
	if(score == 20)
		{
			//printf("Level = %d\n",level); in level 2
			//iPauseTimer(t2);
			obsXAxis=1300;
			iShowBMP(0,0,"game char\\Level up.bmp");
			//iText(500,10,"Press 'N' to proceed to next level", GLUT_BITMAP_TIMES_ROMAN_24);
		}

		else if(score>20){
			
		 //iResumeTimer(t2);
		 //level=3;
		 iDrawBGR2();
		 iDrawJump2();
		 iDrawCollision2();
		 iDrawInput();
		 iText(535,550, "Level 2", GLUT_BITMAP_TIMES_ROMAN_24);
		 
		}
}
void scoringLevel3()
{
	if(score == 40)
		{
			//iPauseTimer(t3);
			obsXAxis=1300;
			iShowBMP(0,0,"game char\\Level up.bmp");
			//iText(500,10,"Press 'N' to proceed to next level", GLUT_BITMAP_TIMES_ROMAN_24);
		}

		if(score>40){
			
		 //iResumeTimer(t3);
		  // level=4;
		 iDrawBGR3();
		 iDrawJump3();
		 iDrawCollision3();
		 iDrawInput();
		 iText(535,550, "Level 3", GLUT_BITMAP_TIMES_ROMAN_24);
		 
		}
}

/////HIGHSCORING//////
void HighScoreShow(){
	FILE *fp = fopen("high_score.txt", "r");
	fscanf(fp, "%d", &highScore);
	//strcpy( score_char, highScore);
	sprintf(score_char, "%d", highScore);
	iSetColor(255,255,255);
	iText(700, 330, score_char, GLUT_BITMAP_TIMES_ROMAN_24);

	iText(500, 330, " New High score : ", GLUT_BITMAP_TIMES_ROMAN_24);
	fclose(fp);
}


//function for calculating highscore
void HighScoreCalculate(){
	int FinalScore = score;
	FILE *fp = fopen("high_score.txt", "r");
	fscanf(fp, "%d", &highScore);
	if (highScore < FinalScore){
		highScore = FinalScore;
		FILE *fp = fopen("high_score.txt", "a");
		fprintf(fp, "Name  : %s\n ",str);
		fprintf(fp, "Score : %d ", highScore);
		
		fclose(fp);
	}
	fclose(fp);
}


#endif