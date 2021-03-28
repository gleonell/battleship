#include <iostream>
#include <cstdlib>

int main(void)
{
    while(true)
    {
        const int N = 10;
        int map[N][N] = {0};
        int x,y;
        int dir = 0;
        int ship_count = 0;

        while (ship_count < 3)
        {
            x = rand() % N;
            y = rand() % N;
            int temp_x = x;
            int temp_y = y;
        
            dir = rand() % 4;

            bool set_is_possible = 1;

            for (int i = 0; i < 5; i++) // проверка возможности простановки 3-x 5-ти палубный кораблей
            {
                if (x < 0 || y < 0 || x >= N || y >= N)
                {
                    set_is_possible = 0;
                    break;
                }

                if (map [x  ][y  ] == 1 ||
                    map [x+1][y  ] == 1 ||
                    map [x+1][y+1] == 1 ||
                    map [x  ][y+1] == 1 ||
                    map [x-1][y+1] == 1 ||
                    map [x-1][y  ] == 1 ||
                    map [x-1][y-1] == 1 ||
                    map [x  ][y-1] == 1 ||
                    map [x+1][y-1] == 1 )
                    {
                        set_is_possible = 0;
                        break;
                    }

                switch(dir)
                {
                    case 0:
                        x++;
                    break;
                    case 1:
                        y++;
                    break;
                    case 2:
                        x--;
                    break;
                    case 3:
                        y--;
                    break;
                }
            }

            if (set_is_possible == 1)
            {
                x = temp_x;
                y = temp_y;
                for (int i = 0; i < 5; i++) // растановка корабля 
                {
                    map[x][y] = 1;
                    switch(dir)
                    {
                        case 0:
                            x++;
                        break;
                        case 1:
                            y++;
                        break;
                        case 2:
                            x--;
                        break;
                        case 3:
                            y--;
                        break;
                    }
                } 
                ship_count++;
            }
        }
        for (int i = 0; i < N; i++) // output
        {
            for (int j = 0; j < N; j++)
            {
                if (map[i][j] == 0)
                    std::cout << '-';
                else
                    std::cout << map[i][j];
            }
            std::cout << std::endl;
        }
    }    
    return (0);
}
