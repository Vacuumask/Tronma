#include "Enemy3.h"

Bullet3::Bullet3()
{
	width = 24;
	height = 8;

	c_x = 0;
	c_y = 0;
	c_width = 24;
	c_height = 8;

	loadPicture();
	animationEnemy = new AnimationEnemy(&x, &y, pictures);
}

Bullet3::~Bullet3()
{
	if (player != NULL) {
		delete player;
		player = NULL;
	}
	if (animationEnemy != NULL) {
		delete animationEnemy;
		animationEnemy = NULL;
	}
}

void Bullet3::loadPicture()
{
	IMAGE img1, img2;
	loadimage(&img1, "../image/enemy/3/bullet1.png", width, height);
	pictures.push_back(img1);
	loadimage(&img2, "../image/enemy/3/bullet2.png", width, height);
	pictures.push_back(img2);

}

void Bullet3::run(float* dt)
{
	if (active == true) {
		x -= *xspeed * 2.2 * *dt;
		if (alive == true) {
			if (type == 1) {
				animationEnemy->run(331);
			}
			else {
				animationEnemy->run(332);
			}

			if (collide()) {
				damage();
				isOver();
			}
		}

		if (x <= -width) {
			isOver();
		}

		if (attackedCollide()) {
			beDamaged();
		}
	}
}

bool Bullet3::collide()
{
	if (active == true && canDamage == true && alive == true) {
		return !(x + c_x > player->x + player->c_x + player->c_width || x + c_x + c_width<player->x + player->c_x ||
			y + c_y>player->y + player->c_y + player->c_height || y + c_y + c_height < player->y + player->c_y);
	}
	return false;
}

void Bullet3::damage()
{
	canDamage = false;
	if (player->canBeDamaged == true) {
		player->health--;
	}
}

bool Bullet3::attackedCollide()
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
				case 1:
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

void Bullet3::beDamaged()
{
	isOver();
}

void Bullet3::isOver()
{
	x = -width;
	active = false;
	canDamage = false;
	alive = false;
}

Enemy3::Enemy3()
{
	width = 384;
	height = 144;

	c_x = 312;
	c_y = 18;
	c_width = 12;
	c_height = 57;

	loadPicture();
	animationEnemy = new AnimationEnemy(&x, &y, pictures);
}

Enemy3::~Enemy3()
{
	if (player != NULL) {
		delete player;
		player = NULL;
	}
	if (animationEnemy != NULL) {
		delete animationEnemy;
		animationEnemy = NULL;
	}
}

void Enemy3::loadPicture()
{
	IMAGE img0_1, img0_2, img0_3, img0_4, img0_5, img0_6, img0_7, img0_8, img0_9, img0_10, img0_11, img0_12;
	loadimage(&img0_1, "../image/enemy/3/run1.png", width, height);
	pictures.push_back(img0_1);
	loadimage(&img0_2, "../image/enemy/3/run2.png", width, height);
	pictures.push_back(img0_2);
	loadimage(&img0_3, "../image/enemy/3/run3.png", width, height);
	pictures.push_back(img0_3);
	loadimage(&img0_4, "../image/enemy/3/run4.png", width, height);
	pictures.push_back(img0_4);
	loadimage(&img0_5, "../image/enemy/3/run5.png", width, height);
	pictures.push_back(img0_5);
	loadimage(&img0_6, "../image/enemy/3/run6.png", width, height);
	pictures.push_back(img0_6);
	loadimage(&img0_7, "../image/enemy/3/run7.png", width, height);
	pictures.push_back(img0_7);
	loadimage(&img0_8, "../image/enemy/3/run8.png", width, height);
	pictures.push_back(img0_8);
	loadimage(&img0_9, "../image/enemy/3/run9.png", width, height);
	pictures.push_back(img0_9);
	loadimage(&img0_10, "../image/enemy/3/run10.png", width, height);
	pictures.push_back(img0_10);
	loadimage(&img0_11, "../image/enemy/3/run11.png", width, height);
	pictures.push_back(img0_11);
	loadimage(&img0_12, "../image/enemy/3/run12.png", width, height);
	pictures.push_back(img0_12);

	IMAGE img1_1, img1_2, img1_3, img1_4;
	loadimage(&img1_1, "../image/enemy/3/charge1.png", width, height);
	pictures.push_back(img1_1);
	loadimage(&img1_2, "../image/enemy/3/charge2.png", width, height);
	pictures.push_back(img1_2);
	loadimage(&img1_3, "../image/enemy/3/charge3.png", width, height);
	pictures.push_back(img1_3);
	loadimage(&img1_4, "../image/enemy/3/charge4.png", width, height);
	pictures.push_back(img1_4);

	IMAGE img2_1, img2_2, img2_3, img2_4, img2_5, img2_6, img2_7, img2_8, img2_9, img2_10, img2_11, img2_12, img2_13;
	loadimage(&img2_1, "../image/effect/ex1b.png", 96, 96);
	pictures.push_back(img2_1);
	loadimage(&img2_2, "../image/effect/ex2b.png", 96, 96);
	pictures.push_back(img2_2);
	loadimage(&img2_3, "../image/effect/ex3b.png", 96, 96);
	pictures.push_back(img2_3);
	loadimage(&img2_4, "../image/effect/ex4b.png", 96, 96);
	pictures.push_back(img2_4);
	loadimage(&img2_5, "../image/effect/ex5b.png", 96, 96);
	pictures.push_back(img2_5);
	loadimage(&img2_6, "../image/effect/ex6b.png", 96, 96);
	pictures.push_back(img2_6);
	loadimage(&img2_7, "../image/effect/ex7b.png", 96, 96);
	pictures.push_back(img2_7);
	loadimage(&img2_8, "../image/effect/ex8b.png", 96, 96);
	pictures.push_back(img2_8);
	loadimage(&img2_9, "../image/effect/ex9b.png", 96, 96);
	pictures.push_back(img2_9);
	loadimage(&img2_10, "../image/effect/ex10b.png", 96, 96);
	pictures.push_back(img2_10);
	loadimage(&img2_11, "../image/effect/ex11b.png", 96, 96);
	pictures.push_back(img2_11);
	loadimage(&img2_12, "../image/effect/ex12b.png", 96, 96);
	pictures.push_back(img2_12);
	loadimage(&img2_13, "../image/effect/void.png", 96, 96);
	pictures.push_back(img2_13);
}

void Enemy3::run(float* dt)
{
	if (active == true) {
		x -= *xspeed * 1 * *dt;
		if (alive == true) {
			if (isCharging == false) {
				animationEnemy->run(31);
				voidTime -= *dt;
				if (voidTime <= 0) {
					isCharging = true;
					voidTime = 0.8;
				}
			}
			else {
				animationEnemy->run(32);
				chargeTime -= *dt;
				if (chargeTime <= 0) {
					isCharging = false;
					chargeTime = 0.3;
					if (shootNum < 2) {
						acquire(1);
						shootNum++;
					}
					else {
						acquire(2);
						shootNum = 0;
					}
				}
			}

			if (collide()) {
				damage();
			}
		}
		else {
			animationEnemy->run(-3);
		}

		if (x <= -width) {
			isOver();
		}

		if (attackedCollide() && alive == true) {
			beDamaged();
		}
			
		for (int i = 0; i < bullet_Size; i++) {
			bullet3[i].run(dt);
		}
	}
}

bool Enemy3::collide()
{
	if (active == true && canDamage == true && alive == true) {
		return !(x + c_x > player->x + player->c_x + player->c_width || x + c_x + c_width<player->x + player->c_x ||
			y + c_y>player->y + player->c_y + player->c_height || y + c_y + c_height < player->y + player->c_y);
	}
	return false;
}

void Enemy3::damage()
{
	canDamage = false;
	if (player->canBeDamaged == true) {
		player->health--;
	}
}

bool Enemy3::attackedCollide()
{
	if (active == true && alive == true) {
		for (int i = 0; i < player->attack.size(); i++) {
			if (player->attack[i]->active == true) {
				switch (i) {
				case 0:
					if (canBeDamaged == true) {
						if (!(x + c_x > player->x + player->attack[i]->x + player->attack[i]->width || x + c_x + c_width<player->x + player->attack[i]->x ||
							y + c_y>player->y + player->attack[i]->y + player->attack[i]->height || y + c_y + c_height < player->y + player->attack[i]->y)) {
							player->damage = true;
							return true;
						}
					}
					break;
				case 1:
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

void Enemy3::beDamaged()
{
	canDamage = false;
	alive = false;
	isCharging = false;
}

void Enemy3::isOver()
{
	x = -width;
	*sec_enum -= 1;
	active = false;
	canDamage = false;
	alive = false;
	isCharging = false;
	shootNum = 0;
}

void Enemy3::acquire(int bullet)
{
	if (bullet == 1) {
		for (int i = 0; i < bullet_Size - 1; i++) {
			if (bullet3[i].active == false) {
				bullet3[i].x = x + c_x - 20;
				bullet3[i].y = y + 32;
				bullet3[i].active = true;
				bullet3[i].canDamage = true;
				bullet3[i].alive = true;
				bullet3[i].type = 1;

				bullet3[i].player = player;
				bullet3[i].xspeed = xspeed;
				//std::cout << sec_enum[sec];
				break;
			}
		}
	}
	else {
		bullet3[bullet_Size - 1].x = x + c_x - 20;
		bullet3[bullet_Size - 1].y = y + 32;
		bullet3[bullet_Size - 1].active = true;
		bullet3[bullet_Size - 1].canDamage = true;
		bullet3[bullet_Size - 1].canBeDamaged = false;
		bullet3[bullet_Size - 1].alive = true;
		bullet3[bullet_Size - 1].type = 2;

		bullet3[bullet_Size - 1].player = player;
		bullet3[bullet_Size - 1].xspeed = xspeed;
	}
}

Enemy3Pool::Enemy3Pool(int& sceneWidth, float* speed, Player* player, int* sec_enum)
{
	this->player = player;
	this->sec_enum = sec_enum;
	for (int i = 0; i < pool_Size; i++) {
		enemy3[i].player = player;
		enemy3[i].start_x = sceneWidth;
		enemy3[i].xspeed = speed;
	}
}

Enemy3Pool::~Enemy3Pool()
{
	if (player != NULL) {
		delete player;
		player = NULL;
	}
}

void Enemy3Pool::acquire(int sec)
{
	for (int i = 0; i < pool_Size; i++) {
		if (enemy3[i].active == false) {
			switch (sec) {
			case 0:
				enemy3[i].y = enemy3[i].y0;
				break;
			case 1:
				enemy3[i].y = enemy3[i].y1;
				break;
			case 2:
				enemy3[i].y = enemy3[i].y2;
				break;

			}
			enemy3[i].x = enemy3[i].start_x;
			enemy3[i].active = true;
			enemy3[i].canDamage = true;
			enemy3[i].alive = true;

			enemy3[i].sec_enum = &sec_enum[sec];
			sec_enum[sec]++;
			//std::cout << sec_enum[sec];
			break;
		}
	}
}

void Enemy3Pool::run(float* dt)
{
	for (int i = 0; i < pool_Size; i++) {
		enemy3[i].run(dt);
	}
}
