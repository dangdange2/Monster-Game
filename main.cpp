#include <iostream>
#include <conio.h>
#include <ctime>
#include <cstdlib>
using namespace std;

class GameObject
{
protected:
    int speed;
    int x, y;
    char shape;
public:
    GameObject(int startX, int startY, int speed, char shape)
    {
        this->x = startX;
        this->y = startY;
        this->speed = speed;
        this->shape = shape;
        srand((unsigned)time(NULL));
    }

    virtual void move()=0;
    char getShape(){return shape;}

    int getX() {return x;}
    int getY() {return y;}
    int collide()
    {

        if( (this->x<0 || this->x>19) || (this->y<0 || this->y>9) ) return 1;
        else return 0;
    }
};

class Human : public GameObject
{
public:
    Human(int x, int y, int speed, char shape) : GameObject(x, y, speed, shape) {}

    void move()
    {

        char dir;
        dir = _getch();

        if(dir=='w')
        {
            y--;
            if(collide() == 1)
            {
                y++;
            }
        }

        if(dir=='a')
        {
            x--;
            if(collide() == 1)
            {
                x++;
            }
        }

        if(dir=='s')
        {
            y++;
            if(collide()==1)
            {
                y--;
            }
        }

        if(dir=='d')
        {
            x++;

            if(collide()==1)
            {
                x--;
            }
        }
    }
};

class Monster : public GameObject
{
public:
    Monster(int x, int y, int speed, char shape) : GameObject(x, y, speed, shape) {}

    void move()
    {
        for(int i=0; i<speed; i++)
        {
            int dir;
            dir = rand()%4;
            if(dir==0)
            {
                y--;
                if(collide()==1)
                {
                    y++;
                }
            }

            if(dir==1)
            {
                x--;
                if(collide()==1)
                {
                    x++;
                }
            }

            if(dir==2)
            {
                y++;
                if(collide()==1)
                {
                    y--;
                }
            }

            if(dir==3)
            {
                x++;
                if(collide()==1)
                {
                    x--;
                }
            }
        }
    }
};

class Food : public GameObject
{
public:
    Food(int x, int y, int speed, char shape) : GameObject(x, y, speed, shape) {}

    void move()
    {
        for(int i=0; i<speed; i++)
        {
            int dir;
            dir = rand()%4;
            if(dir==0)
            {
                y--;
                if(collide()==1)
                {
                    y++;
                }
            }

            if(dir==1)
            {
                x--;
                if(collide()==1)
                {
                    x++;
                }
            }

            if(dir==2)
            {
                y++;
                if(collide()==1)
                {
                    y--;
                }
            }

            if(dir==3)
            {
                x++;
                if(collide()==1)
                {
                    x--;
                }
            }
        }
    }
};

bool show_map(Human player, Monster mob, Food food)
{
    bool isBlank = true;
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<20; j++)
        {
            isBlank = true;
            if((player.getX() == mob.getX() && player.getY() == mob.getY()) || (food.getX() == mob.getX() && food.getY() == mob.getY()))
            {
                system("cls");
                cout << "===Game Over!==="<<endl;
                return false;
            }
            else if((player.getX() == food.getX() && player.getY() == food.getY()))
            {
                system("cls");
                cout << "===You Win!!!===" << endl;
                return false;
            }

            if(j==player.getX() && i==player.getY())
            {
                cout << player.getShape();
                isBlank = false;
            }
            else if(j==mob.getX() && i==mob.getY())
            {
                cout << mob.getShape();
                isBlank = false;

            }
            else if(j==food.getX() && i==food.getY())
            {
                cout << food.getShape();
                isBlank = false;

            }
            if(isBlank) cout << '-';
        }
        cout << endl;
    }
    return true;
}

int main()
{
    Human player(0, 0, 1, 'H');
    Monster mob(5, 5, 2, 'M');
    Food food(18, 8, 1, '@');
    while(1)
    {
        if(!show_map(player, mob, food)) break;
        player.move();
        mob.move();
        food.move();
        system("cls");
    }

}
