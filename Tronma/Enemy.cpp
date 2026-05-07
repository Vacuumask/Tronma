#include"Enemy.h"

bool Enemy::start = true;
bool Enemy::EMP = false;

void Enemy::damage()
{
    canDamage = false;
    if (player->canBeDamaged == true) {
        player->health--;
        FxDamage.play();
    }
}

bool Enemy::attackedCollide() 
{
    if (active == true && alive == true) {
        for (int i = 0; i < player->attack.size(); i++) {
            if (player->attack[i]->active == true) {
                switch (i) {
                case 0:
                    if (canBeDamaged == true) {
                        if (!(x + c_x > player->x + player->attack[i]->x + player->attack[i]->width || x + c_x + c_width<player->x + player->attack[i]->x ||
                            y + c_y>player->y + player->attack[i]->y + player->attack[i]->height || y + c_y + c_height < player->y + player->attack[i]->y)) {
                            return true;
                        }
                    }
                    break;
                default:
                    if (!(x + c_x > player->attack[i]->x + player->attack[i]->width || x + c_x + c_width<player->attack[i]->x ||
                        y + c_y>player->attack[i]->y + player->attack[i]->height || y + c_y + c_height < player->attack[i]->y)) {
                        return true;
                    }
                    break;
                }
            }
        }
    }
    return false;
}