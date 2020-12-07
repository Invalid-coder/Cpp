#include <iostream>
#include <stdlib.h>

using namespace std;

struct Cell
{
    int i;
    int j;
    char value = '_';
    Cell *p_next_cell;
};

class TicTacToe
{
public:

    int height;
    int width;
    bool finish;
    char currentTurn;
    Cell *p_root = NULL;

    void setUp()
    {
        finish = false;
        currentTurn = 'X';

        cout << "Height: ";
        cin >> height;
        cout << "Width: ";
        cin >> width;

        make_field();
    }

    Cell* addCell(int i,int j)
    {
        Cell *newCell = new Cell;
        newCell->p_next_cell = p_root;
        newCell->i = i;
        newCell->j = j;

        return newCell;
    }

    void make_field()
    {
        for(int i = height; i > 0; i--)
        {
            for(int j = width; j > 0; j--)
            {
                p_root = addCell(i,j);
            }
        }
    }

    void print_field()
    {
        Cell *cell = p_root;

        while(cell != NULL)
        {
            //cout << "i = " << cell->i << " j = " << cell->j << endl;
            cout << cell->value << ' ';

            if(cell->j == width)
            {
                cout << endl;
            }

            cell = cell->p_next_cell;
        }
    }

    Cell* get_cell(int i,int j)
    {
        Cell *current_cell = p_root;

        while(current_cell != NULL)
        {
            if(current_cell->i == i && current_cell->j == j)
            {
                break;
            }
            else
            {
                current_cell = current_cell->p_next_cell;
            }
        }

        return current_cell;
    }

    void play()
    {
        int row,col;
        Cell *cell;

        while(!finish)
        {
            system("cls");
            print_field();

            cout << "Row: ";
            cin >> row;
            cout << "Col: ";
            cin >> col;

            cell = get_cell(row,col);
            cell->value = currentTurn;

        }
    }
};
int main()
{
    TicTacToe game;
    game.setUp();
    game.play();

    return 0;
}
