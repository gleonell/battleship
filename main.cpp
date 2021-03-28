#include <iostream>
#include <cstdlib>

int main()
{
    const int N = 5;
    int map[N][N] = {0};
    int x,y;

    for (int i = 0; i < 2; i++)
    {
        x = rand() % N;
        y = rand() % N;
        map [x][y] = 1;
    }


    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cout << map[i][j];
        }
        std::cout << std::endl;
    }
    
    while (true)
    {
        std::cout << "Введите координаты цели: " << std::endl;
        std::cin >> x;
        std::cin >> y;

        if (map[x][y] == 1)
        {
            std::cout << "Попадание" << std::endl;
            map[x][y] = 0;
            bool ship_decected = false;

            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (map[i][j] == 1)
                    {
                        ship_decected = true;
                        break;
                    }
                }
                if (ship_decected == true)
                    break;
            }   
            if (ship_decected == false)
            {
                std::cout << "Победа" << std::endl;
                break;
            }        
        }
        else
            std::cout << "Промах" << std::endl;
    }

    return (0);
}