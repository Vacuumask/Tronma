#include "Enemy2.h"

Bullet2::Bullet2()
{
}

Bullet2::~Bullet2()
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

void Bullet2::init(){
	y = 420;
	width = 24;
	height = 10;

	c_x = 0;
	c_y = 0;
	c_width = 24;
	c_height = 10;

	loadPicture();
	animationEnemy = new AnimationEnemy(&x, &y, xspeed, pictures);
}

void Bullet2::loadPicture()
{
	IMAGE img1, img2;
	loadimage(&img1, "../image/enemy/2/bullet1.png", width, height);
	pictures.push_back(img1);
	loadimage(&img2, "../image/enemy/2/bullet2.png", width, height);
	pictures.push_back(img2);

}

void Bullet2::run(float* dt)
{
	if (active == true) {
		x -= *xspeed * 2.5 * *dt * Animation::p_speed;
		if (alive == true) {
			if (type == 1) {
				animationEnemy->run(251);
			}
			else {
				animationEnemy->run(252);
			}

			if (collide()) {
				damage();
				isOver();
			}

			if (collideS()) {
				damageS();
				isOver();
			}
		}

		if (x <= -width || Enemy::EMP == true) {
			isOver();
		}

		if (attackedCollide()) {
			beDamaged();
		}
	}
}

bool Bullet2::collide()
{
	if (active == true && canDamage == true && alive == true && player->canBeDamaged == true) {
		return !(x + c_x > player->x + player->c_x + player->c_width || x + c_x + c_width<player->x + player->c_x ||
			y + c_y>player->y + player->c_y + player->c_height || y + c_y + c_height < player->y + player->c_y);
	}
	return false;
}

bool Bullet2::collideS()
{
	if (active == true && alive == true) {
		return !(x + c_x > shadow->x + shadow->c_x + shadow->c_width || x + c_x + c_width<shadow->x + shadow->c_x ||
			y + c_y>shadow->y + shadow->c_y + shadow->c_height || y + c_y + c_height < shadow->y + shadow->c_y);
	}
	return false;
}

void Bullet2::damage()
{
	canDamage = false;
	if (player->canBeDamaged == true) {
		player->health--;
	}
}

void Bullet2::damageS()
{
	shadow->health = 0;
}

bool Bullet2::attackedCollide()
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

void Bullet2::beDamaged()
{
	isOver();
}

void Bullet2::isOver()
{
	x = -width;
	active = false;
	canDamage = false;
	alive = false;
}

Enemy2::Enemy2()
{
}

Enemy2::~Enemy2()
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

void Enemy2::init() {
	y = 396;
	width = 351;
	height = 78;

	c_x = 264;
	c_y = 12;
	c_width = 11;
	c_height = 21;

	loadPicture();
	animationEnemy = new AnimationEnemy(&x, &y, xspeed, pictures);

	for (int i = 0; i < bullet_Size; i++) {
		bullet2[i].init();
	}
}

void Enemy2::loadPicture()
{
	IMAGE img0_1, img0_2, img0_3, img0_4, img0_5, img0_6, img0_7, img0_8;
	loadimage(&img0_1, "../image/enemy/2/run1.png", width, height);
	pictures.push_back(img0_1);
	loadimage(&img0_2, "../image/enemy/2/run2.png", width, height);
	pictures.push_back(img0_2);
	loadimage(&img0_3, "../image/enemy/2/run3.png", width, height);
	pictures.push_back(img0_3);
	loadimage(&img0_4, "../image/enemy/2/run4.png", width, height);
	pictures.push_back(img0_4);
	loadimage(&img0_5, "../image/enemy/2/run5.png", width, height);
	pictures.push_back(img0_5);
	loadimage(&img0_6, "../image/enemy/2/run6.png", width, height);
	pictures.push_back(img0_6);
	loadimage(&img0_7, "../image/enemy/2/run7.png", width, height);
	pictures.push_back(img0_7);
	loadimage(&img0_8, "../image/enemy/2/run8.png", width, height);
	pictures.push_back(img0_8);

	IMAGE img1_1, img1_2, img1_3, img1_4;
	loadimage(&img1_1, "../image/enemy/2/charge1.png", width, height);
	pictures.push_back(img1_1);
	loadimage(&img1_2, "../image/enemy/2/charge2.png", width, height);
	pictures.push_back(img1_2);
	loadimage(&img1_3, "../image/enemy/2/charge3.png", width, height);
	pictures.push_back(img1_3);
	loadimage(&img1_4, "../image/enemy/2/charge4.png", width, height);
	pictures.push_back(img1_4);

	IMAGE img2_1, img2_2, img2_3, img2_4;
	loadimage(&img2_1, "../image/enemy/2/shoot1.png", width, height);
	pictures.push_back(img2_1);
	loadimage(&img2_2, "../image/enemy/2/shoot2.png", width, height);
	pictures.push_back(img2_2);
	loadimage(&img2_3, "../image/enemy/2/shoot3.png", width, height);
	pictures.push_back(img2_3);
	loadimage(&img2_4, "../image/enemy/2/shoot4.png", width, height);
	pictures.push_back(img2_4);

	IMAGE img3_1, img3_2, img3_3, img3_4, img3_5, img3_6, img3_7;
	loadimage(&img3_1, "../image/enemy/2/dash1.png", width, height);
	pictures.push_back(img3_1);
	loadimage(&img3_2, "../image/enemy/2/dash2.png", width, height);
	pictures.push_back(img3_2);
	loadimage(&img3_3, "../image/enemy/2/dash3.png", width, height);
	pictures.push_back(img3_3);
	loadimage(&img3_4, "../image/enemy/2/dash4.png", width, height);
	pictures.push_back(img3_4);
	loadimage(&img3_5, "../image/enemy/2/dash5.png", width, height);
	pictures.push_back(img3_5);
	loadimage(&img3_6, "../image/enemy/2/dash6.png", width, height);
	pictures.push_back(img3_6);
	loadimage(&img3_7, "../image/enemy/2/dash7.png", width, height);
	pictures.push_back(img3_7);

	IMAGE img4_1, img4_2, img4_3, img4_4, img4_5, img4_6, img4_7, img4_8, img4_9, img4_10, img4_11, img4_12, img4_13;
	loadimage(&img4_1, "../image/effect/ex1p.png", 96, 96);
	pictures.push_back(img4_1);
	loadimage(&img4_2, "../image/effect/ex2p.png", 96, 96);
	pictures.push_back(img4_2);
	loadimage(&img4_3, "../image/effect/ex3p.png", 96, 96);
	pictures.push_back(img4_3);
	loadimage(&img4_4, "../image/effect/ex4p.png", 96, 96);
	pictures.push_back(img4_4);
	loadimage(&img4_5, "../image/effect/ex5p.png", 96, 96);
	pictures.push_back(img4_5);
	loadimage(&img4_6, "../image/effect/ex6p.png", 96, 96);
	pictures.push_back(img4_6);
	loadimage(&img4_7, "../image/effect/ex7p.png", 96, 96);
	pictures.push_back(img4_7);
	loadimage(&img4_8, "../image/effect/ex8p.png", 96, 96);
	pictures.push_back(img4_8);
	loadimage(&img4_9, "../image/effect/ex9p.png", 96, 96);
	pictures.push_back(img4_9);
	loadimage(&img4_10, "../image/effect/ex10p.png", 96, 96);
	pictures.push_back(img4_10);
	loadimage(&img4_11, "../image/effect/ex11p.png", 96, 96);
	pictures.push_back(img4_11);
	loadimage(&img4_12, "../image/effect/ex12p.png", 96, 96);
	pictures.push_back(img4_12);
	loadimage(&img4_13, "../image/effect/void.png", 96, 96);
	pictures.push_back(img4_13);
}

void Enemy2::run(float* dt)
{
	if (active == true) {
		if (alive == true) {
			if (isCharging == false && isShooting == false && isDashing == false) {
				x -= *xspeed * 2 * *dt * Animation::p_speed;
				animationEnemy->run(21);
			}
			else if (isCharging == true) {
				x -= *xspeed * 1.5 * *dt * Animation::p_speed;
				animationEnemy->run(22);
				chargeTime -= *dt * *xspeed / 300;
				if (chargeTime <= 0) {
					isCharging = false;
					isShooting = true;
					chargeTime = 0.5;
					if (Enemy::EMP == false) {
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
			}
			else if (isShooting == true) {
				x -= *xspeed * 1.5 * *dt * Animation::p_speed;
				animationEnemy->run(23);
				shootTime -= *dt * *xspeed / 300;
				if (shootTime <= 0) {
					isShooting = false;
					dashIsReady = true;
					shootTime = 0.3;
				}
			}
			else if (isDashing == true) {
				if (dashIsReady == true) {
					x += 1.8 * width;
					if (x > 1200 - width)x = 1200 - width;
					dashIsReady = false;
				}
				x -= *xspeed * 1.3 * *dt * Animation::p_speed;
				animationEnemy->run(24);
				dashTime -= *dt * *xspeed / 300;
				if (dashTime <= 0) {
					isDashing = false;
					dashTime = 0.5;
				}
			}

			if (collide()) {
				damage();
			}

			if (collideS()) {
				damageS();
			}
		}
		else {
			x -= *xspeed * 2 * *dt * Animation::p_speed;
			animationEnemy->run(-2);
		}
		

		if (x <= -width) {
			isOver();
		}

		if (attackedCollide() && alive == true) {
			beDamaged();
		}

		if (shootDisCollide()) {
			if (dashIsReady == false && isCharging == false && isShooting == false && isDashing == false) {
				isCharging = true;
			}
			else if (dashIsReady == true) {
				isDashing = true;
			}
		}

		for (int i = 0; i < bullet_Size; i++) {
			bullet2[i].run(dt);
			
		}
	}
}

bool Enemy2::collide()
{
	if (active == true && canDamage == true && alive == true) {
		return !(x + c_x > player->x + player->c_x + player->c_width || x + c_x + c_width<player->x + player->c_x ||
			y + c_y>player->y + player->c_y + player->c_height || y + c_y + c_height < player->y + player->c_y);
	}
	return false;
}

bool Enemy2::collideS()
{
	if (active == true && alive == true) {
		return !(x + c_x > shadow->x + shadow->c_x + shadow->c_width || x + c_x + c_width<shadow->x + shadow->c_x ||
			y + c_y>shadow->y + shadow->c_y + shadow->c_height || y + c_y + c_height < shadow->y + shadow->c_y);
	}
	return false;
}

bool Enemy2::shootDisCollide()
{
	if (active == true && canDamage == true && alive == true && Enemy::start == false) {
		return !(x + c_x - shootDis > player->x + player->c_x + player->c_width || x + c_x + c_width<player->x + player->c_x ||
			y + c_y>player->y + player->c_y + player->c_height || y + c_y + c_height < player->y + player->c_y);
	}
	return false;
}

void Enemy2::damage()
{
	canDamage = false;
	if (player->canBeDamaged == true) {
		player->health--;
	}
}

void Enemy2::damageS()
{
	shadow->health = 0;
}

bool Enemy2::attackedCollide()
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

void Enemy2::beDamaged()
{
	canDamage = false;
	alive = false;
	isCharging = false;
	isShooting = false;
	isDashing = false;
	dashIsReady = false;
	if (Enemy::start == false) {
		Player::kill_score += 150;
		Player::kill[1]++;
	}
}

void Enemy2::isOver()
{
	x = -width;
	*sec_enum -= 1;
	active = false;
	canDamage = false;
	alive = false;
	isCharging = false;
	isShooting = false;
	isDashing = false;
	dashIsReady = false;
	chargeTime = 0.5;
	shootTime = 0.3;
	dashTime = 0.5;
	shootNum = 0;
}

void Enemy2::bulletOver()
{
	for (int i = 0; i < bullet_Size; i++) {
		bullet2[i].isOver();
	}
}

void Enemy2::acquire(int bullet)
{
	if (bullet == 1) {
		for (int i = 0; i < bullet_Size - 1; i++) {
			if (bullet2[i].active == false) {
				bullet2[i].x = x + c_x - 20;
				bullet2[i].active = true;
				bullet2[i].canDamage = true;
				bullet2[i].alive = true;
				bullet2[i].type = 1;

				bullet2[i].player = player;
				bullet2[i].shadow = shadow;
				bullet2[i].xspeed = xspeed;
				//std::cout << sec_enum[sec];
				break;
			}
		}
	}
	else {
		bullet2[bullet_Size - 1].x = x + c_x - 20;
		bullet2[bullet_Size - 1].active = true;
		bullet2[bullet_Size - 1].canDamage = true;
		bullet2[bullet_Size - 1].canBeDamaged = false;
		bullet2[bullet_Size - 1].alive = true;
		bullet2[bullet_Size - 1].type = 2;

		bullet2[bullet_Size - 1].player = player;
		bullet2[bullet_Size - 1].shadow = shadow;
		bullet2[bullet_Size - 1].xspeed = xspeed;
	}
}

Enemy2Pool::Enemy2Pool(int& sceneWidth, float* speed, Player* player, Player* shadow, int* sec_enum)
{
	this->player = player;
	this->sec_enum = sec_enum;
	for (int i = 0; i < pool_Size; i++) {
		enemy2[i].player = player;
		enemy2[i].shadow = shadow;
		enemy2[i].start_x = sceneWidth - 200;
		enemy2[i].xspeed = speed;
		enemy2[i].sec_enum = sec_enum;
		enemy2[i].init();
	}
}

Enemy2Pool::~Enemy2Pool()
{
    if (player != NULL) {
        delete player;
        player = NULL;
    }
}

void Enemy2Pool::acquire(int sec)
{
	for (int i = 0; i < pool_Size; i++) {
		if (enemy2[i].active == false) {
			if (Enemy::start == true) {
				enemy2[i].x = 900;
			}
			else {
				enemy2[i].x = enemy2[i].start_x;
			}
			enemy2[i].active = true;
			enemy2[i].canDamage = true;
			enemy2[i].alive = true;

			enemy2[i].sec_enum = &sec_enum[sec];
			sec_enum[sec]++;
			//std::cout << sec_enum[sec];
			break;
		}
	}
}

void Enemy2Pool::run(float* dt)
{
	for (int i = 0; i < pool_Size; i++) {
		enemy2[i].run(dt);
	}
}

void Enemy2Pool::isOver()
{
	for (int i = 0; i < pool_Size; i++) {
		enemy2[i].isOver();
		enemy2[i].animationEnemy->reset();
		enemy2[i].bulletOver();
	}
}

