#include <iostream>
#include <unistd.h>

[[noreturn]] int main()
{
    //variables
    int width = 128;
    int height = 32;
    int screen[width*height];
    int buffer[width*height];
    int neighbors = 0;

    //initialize board
    for (int i = 0; i < width*height; i++)
    {
        screen[i] = 0;
        buffer[i] = 0;
    }

    //draw glider
    /*
    screen[1]=1;
    screen[2+width]=1;
    screen[2*width]=1;
    screen[1+2*width]=1;
    screen[2+2*width]=1;
    */

    //r pentomino
    screen[width/2 + (width*height)/2]=1;
    screen[width/2 + (width*height)/2 + width]=1;
    screen[width/2 + (width*height)/2 + width*2]=1;
    screen[width/2 + (width*height)/2 + 1]=1;
    screen[width/2 + (width*height)/2 + width - 1]=1;

    //draw first frame (I'll probably change this if I revisit the project)
    for (int i = 0; i < width*height; i++)
    {
        if (i%width == 0)
        {
            std::cout << std::endl;
        }

        if(screen[i] == 1)
        {
            std::cout << "#";
        }
        if(screen[i] == 0)
        {
            std::cout << ".";
        }
    }
    usleep(500000);
    system("clear");

    while(true)
    {
        //clear buffer
        for (int i = 0; i < width*height; i++)
        {
            buffer[i] = 0;
        }
        //update board
        for (int i = 0; i < width*height; i++)
        {
            neighbors=0;
            //check for neighbors. I know I should use DRY, but I don't feel like it
            if(i%width != width-1 && i%width != 0)
            {
                if(screen[i-width-1] == 1)
                {
                    neighbors++;
                }
                if(screen[i-width] == 1)
                {
                    neighbors++;
                }
                if(screen[i-width+1] == 1)
                {
                    neighbors++;
                }
                if(screen[i-1] == 1)
                {
                    neighbors++;
                }
                if(screen[i+1] == 1)
                {
                    neighbors++;
                }
                if(screen[i+width-1] == 1)
                {
                    neighbors++;
                }
                if(screen[i+width] == 1)
                {
                    neighbors++;
                }
                if(screen[i+width+1] == 1)
                {
                    neighbors++;
                }
            }
            else if(i%width == width-1)
            {
                if(screen[i-width-1] == 1)
                {
                    neighbors++;
                }
                if(screen[i-width] == 1)
                {
                    neighbors++;
                }

                if(screen[i-1] == 1)
                {
                    neighbors++;
                }

                if(screen[i+width-1] == 1)
                {
                    neighbors++;
                }
                if(screen[i+width] == 1)
                {
                    neighbors++;
                }

            }
            else if(i%width == 0)
            {
                if(screen[i-width] == 1)
                {
                    neighbors++;
                }
                if(screen[i-width+1] == 1)
                {
                    neighbors++;
                }
                if(screen[i+1] == 1)
                {
                    neighbors++;
                }
                if(screen[i+width] == 1)
                {
                    neighbors++;
                }
                if(screen[i+width+1] == 1)
                {
                    neighbors++;
                }
            }

            //game rules
            if(screen[i] == 1)
            {
                if(neighbors != 2 && neighbors != 3)
                {
                    buffer[i] = 0;
                }
                else
                {
                    buffer[i] = 1;
                }

            }
            if(screen[i] == 0)
            {
                if(neighbors == 3)
                {
                    buffer[i] = 1;
                }

            }

        }

        //transfer buffer to screen
        for (int i = 0; i < width*height; i++)
        {
            screen[i] = buffer[i];
        }

        //draw screen
        system("clear");
        //std::cout << std::endl;

        for (int i = 0; i < width*height; i++)
        {
            if (i%width == 0)
            {
                std::cout << std::endl;
            }

            if(screen[i] == 1)
            {
                std::cout << "#";
            }
            if(screen[i] == 0)
            {
                std::cout << ".";
            }
        }
        usleep(200000);
        system("clear");
    }


}
