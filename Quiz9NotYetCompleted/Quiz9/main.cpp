//test
#include <stdio.h>
#include <windows.h>
#include <time.h>

#define LEFT_KEY 75
#define RIGHT_KEY 77
#define UP_KEY 72
#define DOWN_KEY 80
#define SNAKE_DRAW_INFO 0
#define SNAKE_X_COORDINATE 1
#define SNAKE_Y_COORDINATE 2
#define FIRST_SNAKE_HEAD_X_COORDINATE 50
#define FIRST_SNAKE_HEAD_Y_COORDINATE 15

void GotoXy(int x, int y);
void Initialization(char snake[3][3100]);
void DrawFrame(void);
void FrameWidth(void);
void FrameHeigh(void);
void FirstSnakeInfo(char snake[3][3100]);


int main(void) {
	char snake[3][3100];
	srand((unsigned int)(time(NULL)));
	Initialization(snake);
	GotoXy(30, 15);

	return 0;
}

void GotoXy(int x, int y) {
	COORD CursorPosition = { (short)x,(short)y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}

void DrawFrame(void) {
	FrameWidth();
	FrameHeigh();
}

void FrameWidth(void) {
	int x;
	for (x = 0; x<100; x = x + 2) {
		GotoXy(x, 0);
		printf("бс");
		GotoXy(x, 29);
		printf("бс");
	}
}

void FrameHeigh(void) {
	int y;
	for (y = 1; y<29; y++) {
		GotoXy(0, y);
		printf("бс");
		GotoXy(98, y);
		printf("бс");
	}
}

void Initialization(char snake[3][3100]) {
	DrawFrame();
	FirstSnakeInfo(snake);

}

void FirstSnakeInfo(char snake[3][3100]) {
	int init;

	snake[0][0] = '@'; // snake_head
	snake[1][0] = FIRST_SNAKE_HEAD_X_COORDINATE;
	snake[2][0] = FIRST_SNAKE_HEAD_Y_COORDINATE;

	//printf("Head:%c HeadX:%d HeadY:%d\n", snake[0][0], snake[1][0], snake[2][0]);

	for (init = 1; init <= 3; init++)
	{
		snake[0][init] = 'O'; // snake_body
		snake[1][init] = FIRST_SNAKE_HEAD_X_COORDINATE - init;
		snake[2][init] = FIRST_SNAKE_HEAD_Y_COORDINATE;
		//printf("Body:%c BodyX:%d BodyY:%d\n", snake[0][init], snake[1][init], snake[2][init]);
	}
}
