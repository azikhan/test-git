
#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include <time.h>
using namespace std;
//--Function Prototypes
int menu();
void printMaze();
void movePacmanLeft();
void movePacmanRight();
void movePacmanUp();
void movePacmanDown();
void playGame();
void gotoxy(int x, int y);
void scoreboard();
void winner();
bool gameover();
void readMaze();
void moveGhost1();
void moveGhost2();
void moveGhost3();
int ghostDirection();
int moveGhost4();
void gameOverMessage();

bool playingGame = true;
//---------Coordinates  Pac-Man-
int PacmanX = 9;
int PacmanY = 31;
//---------Coordinates  Ghost------------//

int g1x = 16; 
int g1y = 31;
int flag1 = 0;

int g2x = 1; 
int g2y = 29;
int flag2 = 0;

int g3x = 1; 
int g3y = 60;

int g4x = 5; // FOR FOLLOWING TOWARDS PACMAN
int g4y = 5;

int score = 0; //    for maintaining score record
int lives = 3; 


char previousItem = ' ';
string gD1 = "up";
string gD2 = "right";
// fixed number of Rows and Columns in Maze
const int rows = 24, cols = 71;
//-Array of Maze-
char maze[rows][cols] = {{"#####################################################################"},
                         {"||.. .....................................................  ......  ||"},
                         {"||.. %%%%%%%%%%%%%%%%       G...     %%%%%%%%%%%%%%  |%|..   %%%%   ||"},
                         {"||..        |%|   |%|     |%|...     |%|        |%|  |%|..    |%|   ||"},
                         {"||..        |%|   |%|     |%|...     |%|        |%|  |%|..    |%|   ||"},
                         {"||..        %%%%%%%%  . . |%|...     %%%%%%%%%%%%%%     ..   %%%%.  ||"},
                         {"||..        |%|       . . |%|...    ............... |%| ..       .  ||"},
                         {"||..        %%%%%%%%%%. . |%|...    %%%%%%%%%%%%    |%| ..   %%%%.  ||"},
                         {"||..               |%|.             |%|......       |%| ..    |%|.  ||"},
                         {"||..     ......... |%|.        P    |%|......|%|        ..    |%|.  ||"},
                         {"||..|%|  |%|%%%|%|.|%|. |%|            ......|%|        ..|%| |%|.  ||"},
                         {"||..|%|  |%|   |%|..    %%%%%%%%%%%%%  ......|%|        G.|%|.      ||"},
                         {"||..|%|  |%|   |%|..           ...|%|     %%%%%%        . |%|.      ||"},
                         {"||..|%|            .           ...|%|               |%| ..|%|.      ||"},
                         {"||..|%|  %%%%%%%%%%%%%%        ...|%|%%%%%%%%%%     |%| ..|%|%%%%%  ||"},
                         {"||...............................................   |%| ..........  ||"},
                         {"||   ............................................ G        .......  ||"},
                         {"||..|%|  |%|   |%|..    %%%%%%%%%%%%%  ......|%|    |%| ..|%|.      ||"},
                         {"||..|%|  |%|   |%|..           ...|%|     %%%%%%    |%| ..|%|.      ||"},
                         {"||..|%|            .     G     ...|%|               |%| ..|%|.      ||"},
                         {"||..|%|  %%%%%%%%%%%%%%        ...|%|%%%%%%%%%%     |%| ..|%|%%%%%  ||"},
                         {"||...............................................   |%| ..........  ||"},
                         {"||  .............................................          .......  ||"},
                         {"##################################################################### "}};

//CHANGING COLOUR
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);