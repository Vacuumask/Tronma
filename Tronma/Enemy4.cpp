#include "Enemy4.h"

Bullet4::Bullet4()
{
	width = 1024;
	height = 20;

	c_x = 0;
	c_y = 0;
	c_width = 1024;
	c_height = 20;

	canBeDamaged = false;

	loadPicture();
	animationEnemy = new AnimationEnemy(&x, &y, pictures);
}

Bullet4::~Bullet4()
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

void Bullet4::loadPicture()
{
	IMAGE img1;
	loadimage(&img1, "../image/enemy/4/bullet.png", width, height);
	pictures.push_back(img1);

}

void Bullet4::run(float* dt)
{
	if (active == true) {
		if (alive == true) {
			animationEnemy->run(46);
			shootTime -= *dt;

			if (collide()) {
				damage();
			}
		}

		if (shootTime <= 0) {
			isOver();
		}

		if (attackedCollide()) {
			beDamaged();
		}
	}
}

bool Bullet4::collide()
{
	if (active == true && canDamage == true && alive == true) {
		return !(x + c_x > player->x + player->c_x + player->c_width || x + c_x + c_width<player->x + player->c_x ||
			y + c_y>player->y + player->c_y + player->c_height || y + c_y + c_height < player->y + player->c_y);
	}
	return false;
}

void Bullet4::damage()
{
	canDamage = false;
	if (player->canBeDamaged == true) {
		player->health--;
	}
}

bool Bullet4::attackedCollide()
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

void Bullet4::beDamaged()
{
	isOver();
}

void Bullet4::isOver()
{
	shootTime = 0.6;
	x = -width;
	active = false;
	canDamage = false;
	alive = false;
}

Enemy4::Enemy4()
{
	width = 144;
	height = 144;

	c_x = 0;
	c_y = 0;
	c_width = 144;
	c_height = 144;

	loadPicture();
	animationEnemy = new AnimationEnemy(&x, &y, pictures);
}

Enemy4::~Enemy4()
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

void Enemy4::loadPicture()
{
	IMAGE img0_1, img0_2, img0_3, img0_4, img0_5, img0_6, img0_7, img0_8;
	loadimage(&img0_1, "../image/enemy/4/shoot1.png", width, height);
	pictures.push_back(img0_1);
	loadimage(&img0_2, "../image/enemy/4/shoot2.png", width, height);
	pictures.push_back(img0_2);
	loadimage(&img0_3, "../image/enemy/4/shoot3.png", width, height);
	pictures.push_back(img0_3);
	loadimage(&img0_4, "../image/enemy/4/shoot4.png", width, height);
	pictures.push_back(img0_4);
	loadimage(&img0_5, "../image/enemy/4/shoot5.png", width, height);
	pictures.push_back(img0_5);
	loadimage(&img0_6, "../image/enemy/4/shoot6.png", width, height);
	pictures.push_back(img0_6);
	loadimage(&img0_7, "../image/enemy/4/shoot7.png", width, height);
	pictures.push_back(img0_7);
	loadimage(&img0_8, "../image/enemy/4/shoot8.png", width, height);
	pictures.push_back(img0_8);

	IMAGE img1_1, img1_2, img1_3, img1_4, img1_5, img1_6, img1_7, img1_8, img1_9, img1_10, img1_11, img1_12;
	loadimage(&img1_1, "../image/enemy/4/die1.png", width, height);
	pictures.push_back(img1_1);
	loadimage(&img1_2, "../image/enemy/4/die2.png", width, height);
	pictures.push_back(img1_2);
	loadimage(&img1_3, "../image/enemy/4/die3.png", width, height);
	pictures.push_back(img1_3);
	loadimage(&img1_4, "../image/enemy/4/die4.png", width, height);
	pictures.push_back(img1_4);
	loadimage(&img1_5, "../image/enemy/4/die5.png", width, height);
	pictures.push_back(img1_5);
	loadimage(&img1_6, "../image/enemy/4/die6.png", width, height);
	pictures.push_back(img1_6);
	loadimage(&img1_7, "../image/enemy/4/die7.png", width, height);
	pictures.push_back(img1_7);
	loadimage(&img1_8, "../image/enemy/4/die8.png", width, height);
	pictures.push_back(img1_8);
	loadimage(&img1_9, "../image/enemy/4/die9.png", width, height);
	pictures.push_back(img1_9);
	loadimage(&img1_10, "../image/enemy/4/die10.png", width, height);
	pictures.push_back(img1_10);
	loadimage(&img1_11, "../image/enemy/4/die11.png", width, height);
	pictures.push_back(img1_11);
	loadimage(&img1_12, "../image/enemy/4/die12.png", width, height);
	pictures.push_back(img1_12);

	IMAGE img2_1, img2_2, img2_3, img2_4, img2_5, img2_6, img2_7, img2_8, img2_9, img2_10, img2_11, img2_12, img2_13;
	loadimage(&img2_1, "../image/effect/ex1d.png", width, height);
	pictures.push_back(img2_1);
	loadimage(&img2_2, "../image/effect/ex2d.png", width, height);
	pictures.push_back(img2_2);
	loadimage(&img2_3, "../image/effect/ex3d.png", width, height);
	pictures.push_back(img2_3);
	loadimage(&img2_4, "../image/effect/ex4d.png", width, height);
	pictures.push_back(img2_4);
	loadimage(&img2_5, "../image/effect/ex5d.png", width, height);
	pictures.push_back(img2_5);
	loadimage(&img2_6, "../image/effect/ex6d.png", width, height);
	pictures.push_back(img2_6);
	loadimage(&img2_7, "../image/effect/ex7d.png", width, height);
	pictures.push_back(img2_7);
	loadimage(&img2_8, "../image/effect/ex8d.png", width, height);
	pictures.push_back(img2_8);
	loadimage(&img2_9, "../image/effect/ex9d.png", width, height);
	pictures.push_back(img2_9);
	loadimage(&img2_10, "../image/effect/ex10d.png", width, height);
	pictures.push_back(img2_10);
	loadimage(&img2_11, "../image/effect/ex11d.png", width, height);
	pictures.push_back(img2_11);
	loadimage(&img2_12, "../image/effect/ex12d.png", width, height);
	pictures.push_back(img2_12);
	loadimage(&img2_13, "../image/effect/void.png", width, height);
	pictures.push_back(img2_13);
}

void Enemy4::run(float* dt)
{
	if (active == true) {
		if (alive == true) {
			if (isCharging == false && isShooting == false && isWaiting == false && isBacking == false) {
				x -= *xspeed * 1 * *dt;
				animationEnemy->run(41);
				if (x <= 880) {
					isCharging = true;
					x = 880;
				}
			}
			else if (isCharging == true) {
				animationEnemy->run(42);
				chargeTime -= *dt;
				if (chargeTime <= 0) {
					isCharging = false;
					isShooting = true;
					//chargeTime = 2;
					acquire(0);
				}
			}
			else if (isShooting == true) {
				animationEnemy->run(43);
				shootTime -= *dt;
				if (shootTime <= 0) {
					isShooting = false;
					isWaiting = true;
					//shootTime = 0.6;
				}
			}
			else if (isWaiting == true) {
				animationEnemy->run(44);
				waitTime -= *dt;
				if (waitTime <= 0) {
					isWaiting = false;
					isBacking = true;
					//waitTime = 1;
				}
			}
			else {
				animationEnemy->run(45);
				x += *xspeed * 1 * *dt;
				if (x >= 1024) {
					isOver();
				}
			}
		}
		else {
			dieTime -= *dt;
			animationEnemy->run(-4);
			if (dieTime <= 0) {
				isOver();
			}
		}

		if (attackedCollide()) {
			beDamaged();
		}

		bullet4[0].run(dt);
	}
}

bool Enemy4::collide()
{
	return false;
}

void Enemy4::damage()
{
}

bool Enemy4::attackedCollide()
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

void Enemy4::beDamaged()
{
	bullet4[0].isOver();
	canDamage = false;
	alive = false;
	isCharging = false;
	isShooting = false;
	isWaiting = false;
	isBacking = false;
}

void Enemy4::isOver()
{
	bullet4[0].isOver();
	chargeTime = 2;
	shootTime = 0.6;
	waitTime = 1;
	dieTime = 2;
	x = -width;
	*sec_enum -= 1;
	active = false;
	canDamage = false;
	alive = false;
	isCharging = false;
	isShooting = false;
	isWaiting = false;
	isBacking = false;
}

void Enemy4::acquire(int bullet)
{
	if (bullet4[0].active == false) {
		bullet4[0].x = -width;
		bullet4[0].y = y + 65;
		bullet4[0].active = true;
		bullet4[0].canDamage = true;
		bullet4[0].alive = true;

		bullet4[0].player = player;
		//bullet4[0].xspeed = xspeed;
	}
}

Enemy4Pool::Enemy4Pool(int& sceneWidth, float* speed, Player* player, int* sec_enum)
{
	this->player = player;
	this->sec_enum = sec_enum;
	for (int i = 0; i < pool_Size; i++) {
		enemy4[i].player = player;
		enemy4[i].start_x = sceneWidth;
		enemy4[i].xspeed = speed;
	}
}

Enemy4Pool::~Enemy4Pool()
{
	if (player != NULL) {
		delete player;
		player = NULL;
	}
}

void Enemy4Pool::acquire(int sec)
{
	for (int i = 0; i < pool_Size; i++) {
		if (enemy4[i].active == false) {
			switch (sec) {
			case 0:
				enemy4[i].y = enemy4[i].y0;
				break;
			case 1:
				enemy4[i].y = enemy4[i].y1;
				break;
			case 2:
				enemy4[i].y = enemy4[i].y2;
				break;

			}
			enemy4[i].x = enemy4[i].start_x;
			enemy4[i].active = true;
			enemy4[i].canDamage = true;
			enemy4[i].alive = true;

			enemy4[i].sec_enum = &sec_enum[sec];
			sec_enum[sec]++;
			//std::cout << sec_enum[sec];
			break;
		}
	}
}

void Enemy4Pool::run(float* dt)
{
	for (int i = 0; i < pool_Size; i++) {
		enemy4[i].run(dt);
	}
}
