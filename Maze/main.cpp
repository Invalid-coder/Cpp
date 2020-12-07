#include<iostream>
#include<cstdlib>
#include<ctime>
#include <stdlib.h>

using namespace std;

bool deadend(int, int, int**, int, int); // ��������������� �������, ���������� ������
void visual(int**, int, int); // ����������� ���������� � ������� ���������� �������
void mazemake(int**, int, int); // ���������� ��������
const int wall = 0, pass = 1;

int main(){

	srand((unsigned)time(NULL));

	int height = 21, width = 21;

	int** maze = new int*[height];
	for(int i = 0; i < height; i++)
		maze[i] = new int[width];

	mazemake(maze, height, width);

	//visual(maze,height,width);

	for(int i = 0; i < height; i++)
    delete[] maze[i];
    delete[] maze;

    return 0;
}

bool deadend(int x, int y, int** maze, int height, int width){
	int a = 0;

	if(x != 1){
		if(maze[y][x-2] == pass)
			a+=1;
		}
	else a+=1;

	if(y != 1){
		if(maze[y-2][x] == pass)
			a+=1;
		}
	else a+=1;

	if(x != width-2){
		if(maze[y][x+2] == pass)
			a+=1;
		}
	else a+=1;

	if(y != height-2){
		if(maze[y+2][x] == pass)
			a+=1;
		}
	else a+=1;

	if(a == 4)
		return 1;
	else
		return 0;
}

void visual(int** maze, int height, int width){
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++)
			switch(maze[i][j]){
				case wall: cout<<"0 "; break;
				case pass: cout<<"  "; break;
			}
		cout<<endl;
		}
	cout<<endl;
}

void mazemake(int** maze, int height, int width){
	int x, y, c, a;

	for(int i = 0; i < height; i++) // ������ ����������� ������-��������
		for(int j = 0; j < width; j++)
			maze[i][j] = wall;

	x = 3; y = 3; a = 0; // ����� ����������� ����� � �������
	while(x != height - 1 && y != width - 1 && a < 100){ // ��, ��������, �������, ����� ���� ���, �� ����
		maze[y][x] = pass; a++;
		while(1){ // ����������� ����, ������� ����������� ������ �������
            system("cls");
            visual(maze,height,width);
			c = rand()%4; // ���������, ��� ���� ���������
			switch(c){  // �� ��� ������ � ����� ����������� �� ������
				case 0: if(y != 1)
					if(maze[y-2][x] == wall){ // �����
                    maze[y-1][x] = pass;
					maze[y-2][x] = pass;
					y-=2;
				}
				case 1: if(y != height-2)
					if(maze[y+2][x] == wall){ // ����
					maze[y+1][x] = pass;
					maze[y+2][x] = pass;
					y+=2;
				}
				case 2: if(x != 1)
					if(maze[y][x-2] == wall){ // ������
					maze[y][x-1] = pass;
					maze[y][x-2] = pass;
					x-=2;
				}
				case 3: if(x != width-2)
					if(maze[y][x+2] == wall){ // �������
					maze[y][x+1] = pass;
					maze[y][x+2] = pass;
					x+=2;
				}
			}
			if(deadend(x,y,maze,height,width))
			   break;
		}

		if(deadend(x,y,maze,height,width)) // ����������� ����� �� ������
			do{
				x = 2*(rand()%((width-1)/2))+1;
				y = 2*(rand()%((height-1)/2))+1;
			}
			while(maze[y][x] != pass);
	} // �� ���� � ���.
}
