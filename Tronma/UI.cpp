#include "UI.h"

UI::~UI()
{
}

PlayerCondition::PlayerCondition(Player* player)
{
	loadPicture();

	health = &player->health;
	energy = &player->energy;
}

PlayerCondition::~PlayerCondition()
{

}

void PlayerCondition::loadPicture()
{
	IMAGE img1, img2, img3;
	loadimage(&img1, "../image/ui/inventory_slot_active.png", profile_width + 2 * profileBorder_thick - 1, profile_height + 2 * profileBorder_thick - 1);
	pictures.push_back(img1);
	loadimage(&img2, "../image/ui/Jason.png", profile_width, profile_height);
	pictures.push_back(img2);
	loadimage(&img3, "../image/ui/selected_=true.png", profile_width + 2 * profileBorder_thick - 1, profile_height + 2 * profileBorder_thick - 1);
	pictures.push_back(img3);

	IMAGE img4, img5, img6, img7;
	loadimage(&img4, "../image/ui/red.png", hs_width, health_height);
	pictures.push_back(img4);
	loadimage(&img5, "../image/ui/health.png", hs_width + 2 * hsBorder_thick, health_height + 2 * hsBorder_thick);
	pictures.push_back(img5);
	loadimage(&img6, "../image/ui/silver.png", hs_width, stamina_height);
	pictures.push_back(img6);
	loadimage(&img7, "../image/ui/stamina.png", hs_width + 2 * hsBorder_thick, stamina_height + 2 * hsBorder_thick);
	pictures.push_back(img7);

	IMAGE img8;
	loadimage(&img8, "../image/ui/Jason2.png", profile_width, profile_height);
	pictures.push_back(img8);
}

void PlayerCondition::run()
{
	FPS();
	drawImg(profile_x - profileBorder_thick, profile_y - profileBorder_thick, &pictures[0]);
	drawImg(profile_x, profile_y, &pictures[1]);
	if (temp_health > *health) {
		attack_time = 0.1;
	}
	if (attack_time > 0) {
		attack_time -= dt;
		drawImg(profile_x, profile_y, &pictures[7]);
	}
	drawImg(profile_x - profileBorder_thick, profile_y - profileBorder_thick, &pictures[2]);
	
	health_height= 133.0f * (float)*health / 7.0f;
	IMAGE temp3 = pictures[3];
	temp3.Resize(hs_width, health_height + 1);
	stamina_height = 133.0f * (float)*energy / 100.0f;
	IMAGE temp5 = pictures[5];
	temp5.Resize(hs_width, stamina_height + 1);

	drawImg(health_x, hs_y, &temp3);
	drawImg(health_x - hsBorder_thick, hs_y - hsBorder_thick, &pictures[4]);
	drawImg(stamina_x, hs_y, &temp5);
	drawImg(stamina_x - hsBorder_thick, hs_y - hsBorder_thick, &pictures[6]);

	temp_health = *health;
}

MenuOptions::MenuOptions(bool* enterGame)
{
	option_x = (sceneWidth - option_width) / 2;
	option1_y = 260;
	option2_y = option1_y + option_height + option_gap;
	option3_y = option1_y + 2 * option_height + 2 * option_gap;

	loadPicture();
	this->enterGame = enterGame;
}

MenuOptions::~MenuOptions()
{

}

void MenuOptions::loadPicture()
{
	IMAGE img1;
	loadimage(&img1, "../image/background/menu/option1.png", option_width,option_height);
	pictures.push_back(img1);
}


void MenuOptions::run()
{
	FPS();
	if (*enterGame == false) {
		enterTime -= dt;
	}
	if (enterTime <= 0) {
		if (*enterGame == false)*enterGame = true;
		drawImg(option_x, option1_y, &pictures[0]);
		drawImg(option_x, option2_y, &pictures[0]);
		drawImg(option_x, option3_y, &pictures[0]);
		settextcolor(WHITE);
		settextstyle(50, 0, "Î¢ÈíÑÅºÚ");
		setbkmode(TRANSPARENT);
		outtextxy(470, 265, "¿ªÊ¼");
		outtextxy(470, 345, "½ÌÑ§");
		outtextxy(470, 425, "ÍË³ö");
	}

}


Title::Title(bool* enterGame)
{
	this->enterGame = enterGame;
	loadPicture();
}

Title::~Title()
{

}

void Title::loadPicture()
{
	IMAGE img1;
	loadimage(&img1, "../image/ui/title.png", title_width, title_height);
	pictures.push_back(img1);
}

void Title::run()
{
	FPS();
	if (*enterGame == false) {
		titleTime -= dt;
	}
	if (titleTime <= 0) {
		drawImg((sceneWidth - title_width) / 2, title_y, &pictures[0]);
	}
	
}

int MainOptions::map = 1;
int MainOptions::music = 1;

MainOptions::MainOptions(bool* startGame, bool* chooseMap, bool* chooseMusic)
{
	this->startGame = startGame;
	this->chooseMap = chooseMap;
	this->chooseMusic = chooseMusic;
	loadPicture();
}

MainOptions::~MainOptions()
{

}

void MainOptions::loadPicture()
{
	IMAGE img1, img2;
	loadimage(&img1, "../image/ui/start.png", start_width, start_height);
	pictures.push_back(img1);
	loadimage(&img2, "../image/ui/exit.png", exit_width, exit_height);
	pictures.push_back(img2);

	IMAGE img3, img4;
	loadimage(&img3, "../image/ui/sl1.png", sl_width, sl_height);
	pictures.push_back(img3);
	loadimage(&img4, "../image/ui/sl2(123).png", sl_width * 1.205, sl_height);
	pictures.push_back(img4);
}

void MainOptions::run()
{
	FPS();

	drawImg(start_x, start_y, &pictures[0]);
	drawImg(exit_x, exit_y, &pictures[1]);

	settextcolor(WHITE);
	setbkmode(TRANSPARENT);

	if (*chooseMap == true) {
		for (int i = 1; i <= 3; i++) {
			drawImg(map_x - sl_width * 0.2, sl_y + i * dis1, &pictures[3]);
			settextstyle(29, 0, "Î¢ÈíÑÅºÚ");
			switch (i) {
			case 1:
				outtextxy(map_x + 10, sl_y + i * dis1 + 3, "Ò¹Íí");
				break;
			case 2:
				outtextxy(map_x + 10, sl_y + i * dis1 + 3, "»Æ»è");
				break;
			case 3:
				outtextxy(map_x + 10, sl_y + i * dis1 + 3, "°×Öç");
				break;
			}
			
		}
		settextstyle(200, 0, "Î¢ÈíÑÅºÚ");
		outtextxy(map_x - 40, sl_y + map * dis1 - 93, "¡¤");
		if (dis1 < 40) {
			dis1 += dt * 10 * (40 - dis1);
		}
	}
	else if (dis1 != 0) {
		dis1 = 0;
	}
	drawImg(map_x, sl_y, &pictures[2]);
	settextstyle(29, 0, "Î¢ÈíÑÅºÚ");
	outtextxy(map_x + 10, sl_y + 3, "±³¾°");


	if (*chooseMusic == true) {
		for (int i = 1; i <= 4; i++) {
			drawImg(music_x - sl_width * 0.2, sl_y + i * dis2, &pictures[3]);
			settextstyle(29, 0, "Arial Black");
			switch (i) {
			case 1:
				outtextxy(music_x + 10, sl_y + i * dis2 + 3, "Encounter");
				break;
			case 2:
				outtextxy(music_x + 10, sl_y + i * dis2 + 3, "Conflict");
				break;
			case 3:
				outtextxy(music_x + 10, sl_y + i * dis2 + 3, "The Orb");
				break;
			case 4:
				outtextxy(music_x + 10, sl_y + i * dis2 + 3, "Air");
				break;
			}
		}
		settextstyle(200, 0, "Î¢ÈíÑÅºÚ");
		outtextxy(music_x - 40, sl_y + music * dis2 - 93, "¡¤");
		if (dis2 < 40) {
			dis2 += dt * 10 * (40 - dis2);
		}
	}
	else if (dis2 != 0) {
		dis2 = 0;
	}
	drawImg(music_x, sl_y, &pictures[2]);
	settextstyle(29, 0, "Î¢ÈíÑÅºÚ");
	outtextxy(music_x + 10, sl_y + 3, "ÒôÀÖ");
}

SkillCondition::SkillCondition(Op* op)
{
	this->op = op;
	loadPicture();
}

SkillCondition::~SkillCondition()
{

}

void SkillCondition::loadPicture()
{
	IMAGE img1, img2, img3, img4, img5, img6, img7, img8;
	loadimage(&img1, "../image/ui/skill1.png", skill_width, skill_height);
	pictures.push_back(img1);
	loadimage(&img2, "../image/ui/skill2.png", skill_width, skill_height);
	pictures.push_back(img2);
	loadimage(&img3, "../image/ui/D.png", skill_width - 20, skill_height - 20);
	pictures.push_back(img3);
	loadimage(&img4, "../image/ui/A.png", skill_width - 20, skill_height - 20);
	pictures.push_back(img4);
	loadimage(&img5, "../image/ui/L.png", skill_width - 20, skill_height - 20);
	pictures.push_back(img5);
	loadimage(&img6, "../image/ui/U.png", skill_width - 20, skill_height - 20);
	pictures.push_back(img6);
	loadimage(&img7, "../image/ui/I.png", skill_width - 20, skill_height - 20);
	pictures.push_back(img7);
	loadimage(&img8, "../image/ui/O.png", skill_width - 20, skill_height - 20);
	pictures.push_back(img8);
}

void SkillCondition::run()
{
	for (int i = 0; i < 5; i++) {
		if (op->getCd(i + 1) > 0) {
			drawImg(skill_x + i * (skill_width + skill_gap), skill_y, &pictures[1]);
		}
		else {
			drawImg(skill_x + i * (skill_width + skill_gap), skill_y, &pictures[0]);
		}
		if (i == 0 && op->getTele() == true) {
			drawImg(skill_x + 10, skill_y + 10, &pictures[2]);
		}
		else {
			drawImg(skill_x + i * (skill_width + skill_gap) + 10, skill_y + 10, &pictures[i + 3]);
		}
	}
}

Progress::Progress()
{
	loadPicture();
}

void Progress::loadPicture()
{
	IMAGE img1;
	loadimage(&img1, "../image/ui/Btn_Primary_Hover.png", score_width, score_height);
	pictures.push_back(img1);
}

void Progress::run()
{
	drawImg(score_x, score_y, &pictures[0]);
}

EndTable::EndTable(int* play_num)
{
	this->play_num = play_num;
	loadPicture();
}

void EndTable::loadPicture()
{
	IMAGE img1, img2, img3, img4, img5, img6, img7, img8;
	loadimage(&img1, "../image/ui/Main_Menu_Bk.png", table_width, table_height);
	pictures.push_back(img1);
	loadimage(&img2, "../image/ui/tab.png", score_width, score_height);
	pictures.push_back(img2);
	loadimage(&img3, "../image/ui/sl1.png", back_width, back_height);
	pictures.push_back(img3);
	loadimage(&img4, "../image/ui/tab2.png", kill_width, kill_height);
	pictures.push_back(img4);
	loadimage(&img5, "../image/ui/e1.png", e_size, e_size);
	pictures.push_back(img5);
	loadimage(&img6, "../image/ui/e2.png", e_size, e_size);
	pictures.push_back(img6);
	loadimage(&img7, "../image/ui/e3.png", e_size, e_size);
	pictures.push_back(img7);
	loadimage(&img8, "../image/ui/e4.png", e_size, e_size);
	pictures.push_back(img8);

}

void EndTable::run()
{
	FPS();
	if (all_y > 0) {
		all_y -= dt * 2000;
	}
	else {
		all_y = 0;
	}
	drawImg((sceneWidth - table_width) / 2, (sceneHeight - table_height) / 2 - 40 + all_y, &pictures[0]);
	drawImg(score_x, score_y + all_y, &pictures[1]);
	settextcolor(WHITE);
	setbkmode(TRANSPARENT);
	settextstyle(28, 0, "Î¢ÈíÑÅºÚ");
	outtextxy(240, 150 + all_y, "·ÖÊý");
	outtextxy(240, 180 + all_y, "×î¼Ñ³É¼¨");
	for (int i = 0; i < *play_num; i++) {
		char text[50];
		sprintf_s(text, "%d", Player::allScore[i]);
		outtextxy(240, 180 + (i + 1) * 30 + all_y, text);
	}
	outtextxy(240, 360 + all_y, "±¾´Î³É¼¨");
	char text[50];
	sprintf_s(text, "%d", Player::dis_score + Player::kill_score);
	outtextxy(240, 390 + all_y, text);
	drawImg(kill_x, kill_y + all_y, &pictures[3]);

	outtextxy(554, 150 + all_y, "ÏûÃð");
	for (int i = 0; i < 4; i++) {
		drawImg(e_x, e_y + i * (e_size + e_gap) + all_y, &pictures[i + 4]);
		sprintf_s(text, "%d", Player::kill[i]);
		outtextxy(e_x + 50, e_y + i * (e_size + e_gap) + 6 + all_y, text);
	}

	drawImg(back_x, back_y + all_y, &pictures[2]);
	outtextxy(650, 406 + all_y, "ÍË³ö");
}
