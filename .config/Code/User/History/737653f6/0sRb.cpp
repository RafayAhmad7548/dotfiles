#include <iostream>
#include <string>
#include <cmath>
#include "util.h"
#include "BrickBreaker.h"

using namespace std;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height){
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}


BrickBreaker brickBreaker;

void GameDisplay(){

	glClearColor(0, 0, 148.0/2550.0, 0); // Red==Green==Blue==1 --> White Colour
	glClear(GL_COLOR_BUFFER_BIT); //Update the colors

	brickBreaker.getLevel()->draw();


	glutSwapBuffers(); // do not modify this line..
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 * */
void Timer(int m){

	GameLevel* level = brickBreaker.getLevel();

	if(level != nullptr && brickBreaker.getGameState() == "playing"){
		for(int i=0;i<3;i++){
			if(level->getBalls()[i] != nullptr){
				level->getBalls()[i]->move();
				level->getBalls()[i]->checkBoundCollision();
				level->getPaddle().checkCollision(*level->getBalls()[i]);
				if(level->getPaddle2() != nullptr) level->getPaddle2()->checkCollision(*level->getBalls()[i]);
			}
		}
		level->checkBrickCollision();
		level->moveFood();
		level->checkFoodCollision();

		if(Food::getPowerActive() && Food::getCounter() < 300) Food::count();
		else if(Food::getCounter() == 300) Food::resetPowerup(level->getPaddle(), level->getBalls());
		glutPostRedisplay();
	}


	glutTimerFunc(1000.0/60, Timer, 0);
}

/* This function is called (automatically) whenever your mouse moves witin inside the game window
 * You will have to add the necessary code here for finding the direction of shooting
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 * */
void MousePressedAndMoved(int x, int y){
	glutPostRedisplay();
}
void MouseMoved(int x, int y){
	if(x < brickBreaker.getLevel()->getPaddle().getWidth()/2) x = 0;
    else if(x > 1050 - brickBreaker.getLevel()->getPaddle().getWidth()/2) x = 1050 - brickBreaker.getLevel()->getPaddle().getWidth();
    else x -= brickBreaker.getLevel()->getPaddle().getWidth()/2;
	brickBreaker.getLevel()->getPaddle().setX(x);
	glutPostRedisplay();
}

/* This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */

void NonPrintableKeys(int key, int x, int y){
	if(brickBreaker.getLevel()->getPaddle2() != nullptr){
		if(key == GLUT_KEY_LEFT){
			if(brickBreaker.getLevel()->getPaddle2()->getX() >= 0) 
			brickBreaker.getLevel()->getPaddle2()->setX(brickBreaker.getLevel()->getPaddle2()->getX()-10);
		}
		else if(key == GLUT_KEY_RIGHT){
			if(brickBreaker.getLevel()->getPaddle2()->getX()+brickBreaker.getLevel()->getPaddle2()->getWidth() <= 1050)
			brickBreaker.getLevel()->getPaddle2()->setX(brickBreaker.getLevel()->getPaddle2()->getX()+10);
		}
		else if(key == GLUT_KEY_UP){

		}
		else if(key == GLUT_KEY_DOWN){

		}
	}

	glutPostRedisplay();
}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y){
	if(key == 27){
		exit(0);
	}
	if(key == 13){
		brickBreaker.setGameState("paused");
		brickBreaker.nextLevel();
	}
	if(key == 112){
		if(brickBreaker.getGameState() == "paused") brickBreaker.setGameState("playing");
		else if(brickBreaker.getGameState() == "playing") brickBreaker.setGameState("paused");
	}
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 * You will have to add the necessary code here for shooting, etc.
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 * */
void MouseClicked(int button, int state, int x, int y){

	if(button == GLUT_LEFT_BUTTON){
	}
	else if(button == GLUT_RIGHT_BUTTON){
	}
	glutPostRedisplay();
}


int main(int argc, char*argv[]){

	int width = 1050, height = 870; // i have set my window size to be 800 x 600

	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("OOP Project"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}