#include <iostream>
#include <cstdlib>

const int N = 10;

void ships_setting(int map[N][N], int ship_size, int ship_num)
{
    
    int x,y;
    int dir = 0;
    int ship_count = 0;

    while (ship_count < ship_num)
    {
        x = rand() % N;
        y = rand() % N;
        int temp_x = x;
        int temp_y = y;
        
        dir = rand() % 4;

        bool set_is_possible = 1;

        for (int i = 0; i < ship_size; i++) // проверка возможности простановки кораблей
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
            for (int i = 0; i < ship_size; i++) // растановка корабля 
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
}

int main(void)
{
    while (true)
    {
        int map[N][N] = {0};

        ships_setting(map, 4, 1);
        ships_setting(map, 3, 2);
        ships_setting(map, 2, 3);
        ships_setting(map, 1, 4);

        for (int i = 0; i < N; i++) // output
        {
            for (int j = 0; j < N; j++)
            {
                if (map[j][i] == 0)
                    std::cout << '-';
                else
                    std::cout << map[j][i];
            }
            std::cout << std::endl;
        }system("pause");
    }
    
    return (0);
}
