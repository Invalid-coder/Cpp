#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string>
#include <vector>


using namespace std;

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN};

int random_int(int a,int b)
{
    return rand() % (b - a) + a;
}

struct SnakeGame
{
    bool finish;
    int height;
    int width;
    char head;
    char tail;
    char fruit;
    int tailX[100],tailY[100];
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


    int tail_length;
    int x,y,fruitX,fruitY,score;

    Direction dir;

    void set_up()
    {
        finish = false;
        height = 20;
        width = 40;
        head = '<';
        tail = '=';
        fruit = 'F';
        tail_length = 0;
        x = width / 2 + 1;
        y = height / 2 + 1;
        dir = STOP;
        SetConsoleTextAttribute(hConsole,7);
        score = 0;

        do
        {
            fruitX = random_int(1, width - 1);
            fruitY = random_int(1, height - 1);
        }
        while(fruitX == x && fruitY == y);

    }

    void Draw()
    {
        system("cls");

        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width; j++)
            {
                if(i == 0 || i == height - 1 || j == 0 || j == width - 1)
                {
                    cout << '#';
                }
                else if(i == y && j == x)
                {
                    cout << head;
                }
                else if(i == fruitY && j == fruitX)
                {
                    cout << fruit;
                }
                else
                {
                    bool print = false;

                    for(int k = 0; k < tail_length; k++)
                    {
                        if(j == tailX[k] && i == tailY[k])
                        {
                            print = true;
                            if(k == tail_length - 1)
                            {
                                cout << '8';
                            }
                            else
                            {
                                cout << tail;
                            }
                        }
                    }

                    if(!print)
                    {
                        cout << ' ';
                    }
                }
            }

            cout << endl;
        }

        cout << "Your score: " << score << endl;
    }

    void Input()
    {
        if(_kbhit())
        {
            switch(getch())
            {
                case 97: if(dir != RIGHT) dir = LEFT,head = '<'; break;
                case 119: if(dir != DOWN) dir = UP,head = '^'; break;
                case 100: if(dir != LEFT) dir = RIGHT,head = '>'; break;
                case 115: if(dir != UP) dir = DOWN,head = 'v'; break;
                case 75: if(dir != RIGHT) dir = LEFT; break;
                case 72: if(dir != DOWN) dir = UP; break;
                case 77: if(dir != LEFT) dir = RIGHT; break;
                case 80: if(dir != UP) dir = DOWN; break;
                case 27: dir = STOP; break;
            }
        }
    }

    void move_snack()
    {
        int prevX = tailX[0];
        int prevY = tailY[0];
        int prev2X,prev2Y;
        tailX[0] = x;
        tailY[0] = y;


        for(int i = 1; i < tail_length; i++)
        {
            prev2X = tailX[i];
            prev2Y = tailY[i];
            tailX[i] = prevX;
            tailY[i] = prevY;
            prevX = prev2X;
            prevY = prev2Y;
        }

        /*
        for(int i = tail_length - 1; i > 0; i--)
        {
            tailX[i] = tailX[i - 1];
            tailY[i] = tailY[i - 1];
            cout << tailX[i] << ' ' << tailY[i] << endl;
        }

        if(tail_length == 3)
        {
            finish = true;
            return;
        }
        */
        switch(dir)
        {
            case LEFT: x--; break;
            case RIGHT: x++; break;
            case UP: y--; break;
            case DOWN: y++; break;
        }

        //if(x < 0 || x > width || y < 0 || y > height)
        //{
            //finish = true;
        //}
        if(x < 0)
        {
            x = width - 2;
        }
        else if (x >= width - 1)
        {
            x = 0;
        }
        else if(y < 0)
        {
            y = height - 2;
        }
        else if (y >= height - 1)
        {
            y = 0;
        }


        for(int i = 0; i < tail_length; i++)
        {
            if(tailX[i] == x && tailY[i] == y)
            {
                finish = true;
                break;
            }
        }

        if(x == fruitX && y == fruitY)
        {
            score += 10;
            tail_length++;
            do
            {
                fruitX = random_int(1, width - 1);
                fruitY = random_int(1, height - 1);
            }
            while(fruitX == x && fruitY == y);
        }
    }

    void play()
    {
        set_up();

        while(!finish)
        {
            Draw();
            Input();
            move_snack();
        }

        cout << "Game over";
    }

};

int main()
{
    srand(time(NULL));

    SnakeGame game;
    game.play();


    return 0;
}
