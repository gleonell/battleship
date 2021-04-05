#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <stdlib.h>

const int N = 10;
int ships_ID = 1;
int ships_NUM[10] = {0};


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

            if (map [x  ][y  ] >= 1 ||
                map [x+1][y  ] >= 1 ||
                map [x+1][y+1] >= 1 ||
                map [x  ][y+1] >= 1 ||
                map [x-1][y+1] >= 1 ||
                map [x-1][y  ] >= 1 ||
                map [x-1][y-1] >= 1 ||
                map [x  ][y-1] >= 1 ||
                map [x+1][y-1] >= 1 )
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
                map[x][y] = ships_ID;
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
            ships_NUM[ships_ID] = ship_size;
            ships_ID++;
            ship_count++;
        }
    }
}

void map_print(int map[N][N], int mask[N][N])
{
    std::cout << ' ';

    for (int i = 0; i < N; i++)
    {
        std::cout << i;
    }

    std::cout << std::endl;

    for (int i = 0; i < N; i++) // output
        {
            std::cout << i;
            for (int j = 0; j < N; j++)
            {
                if (mask[j][i] == 1)
                {
                    if (map[j][i] == 0)
                        std::cout << '-';
                    else if (map[j][i] == -1)
                        std::cout << 'X';
                    else
                        std::cout << map[j][i];
                }
                else
                   std::cout << ' ';
            }
            std::cout << std::endl;
        }
}

int main(void)
{
    while (true)
    {
        int map[N][N] = {0};
        int mask[N][N] = {0};

        ships_setting(map, 4, 1);
        ships_setting(map, 3, 2);
        ships_setting(map, 2, 3);
        ships_setting(map, 1, 3);

        int x = 0, y = 0;
        while (true)
        {
            map_print(map, mask);

            std::cout << "Введите координаты цели: " << std::endl;
            std::cin >> x;
            std::cin >> y;

            if (map[x][y] >= 1)
            {
                ships_NUM[map[x][y]]--;

                if (ships_NUM[map[x][y]] <= 0)
                    std::cout << "Корабль потоплен" << std::endl;
                else
                    std::cout << "Попадание. Корабль ранен" << std::endl;
                map[x][y] = -1;
            }
            else
                  std::cout << "Промах" << std::endl;
                mask[x][y] = 1;

                sleep(1);
                system("clear");
                // bool ship_decected = false;

                // for (int i = 0; i < N; i++)
                // {
                //     for (int j = 0; j < N; j++)
                //     {
                //         if (map[i][j] == 1)
                //         {
                //             ship_decected = true;
                //             break;
                //         }
                //     }
                //     if (ship_decected == true)
                //         break;
                // }   
                // if (ship_decected == false)
                // {
                //     std::cout << "Победа" << std::endl;
                //     break;
                // }        
           // }
            // 
        }
        //system("pause");
    }
    
    return (0);
}
