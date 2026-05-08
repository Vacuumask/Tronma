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
	
	health_height = 133.0f * ((float)*health >= 0.0f ? (float)*health : 0.0f) / 7.0f;
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
		settextstyle(50, 0, "微软雅黑");
		setbkmode(TRANSPARENT);
		outtextxy(470, 265, "开始");
		outtextxy(470, 345, "教学");
		outtextxy(470, 425, "退出");
	}

}


Title::Title(bool* enterGame)
{
	this->enterGame = enterGame;
	loadPicture();
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
			settextstyle(29, 0, "微软雅黑");
			switch (i) {
			case 1:
				outtextxy(map_x + 10, sl_y + i * dis1 + 3, "夜晚");
				break;
			case 2:
				outtextxy(map_x + 10, sl_y + i * dis1 + 3, "黄昏");
				break;
			case 3:
				outtextxy(map_x + 10, sl_y + i * dis1 + 3, "白昼");
				break;
			}
			
		}
		settextstyle(200, 0, "微软雅黑");
		outtextxy(map_x - 40, sl_y + map * dis1 - 93, "·");
		if (dis1 < 40) {
			dis1 += dt * 10 * (40 - dis1);
		}
	}
	else if (dis1 != 0) {
		dis1 = 0;
	}
	drawImg(map_x, sl_y, &pictures[2]);
	settextstyle(29, 0, "微软雅黑");
	outtextxy(map_x + 10, sl_y + 3, "背景");


	if (*chooseMusic == true) {
		for (int i = 1; i <= 5; i++) {
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
			case 5:
				outtextxy(music_x + 10, sl_y + i * dis2 + 3, "???");
				break;
			}
		}
		settextstyle(200, 0, "微软雅黑");
		outtextxy(music_x - 40, sl_y + music * dis2 - 93, "·");
		if (dis2 < 40) {
			dis2 += dt * 10 * (40 - dis2);
		}
	}
	else if (dis2 != 0) {
		dis2 = 0;
	}
	drawImg(music_x, sl_y, &pictures[2]);
	settextstyle(29, 0, "微软雅黑");
	outtextxy(music_x + 10, sl_y + 3, "音乐");
}

SkillCondition::SkillCondition(Op* op)
{
	this->op = op;
	loadPicture();
}

SkillCondition::SkillCondition()
{
	loadPicture();
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
	if (op != NULL) {
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
	else {
		for (int i = 0; i < 5; i++) {
			drawImg(skill_x + i * (skill_width + skill_gap), skill_y - 40, &pictures[0]);
			drawImg(skill_x + i * (skill_width + skill_gap) + 10, skill_y - 30, &pictures[(i == 0 ? 2 : i + 3)]);
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
	settextstyle(28, 0, "微软雅黑");
	outtextxy(240, 150 + all_y, "分数");
	outtextxy(240, 180 + all_y, "最佳成绩");
	for (int i = 0; i < *play_num; i++) {
		char text[50];
		sprintf_s(text, "%d", Player::allScore[i]);
		outtextxy(240, 180 + (i + 1) * 30 + all_y, text);
	}
	outtextxy(240, 360 + all_y, "本次成绩");
	char text[50];
	sprintf_s(text, "%d", Player::dis_score + Player::kill_score);
	outtextxy(240, 390 + all_y, text);
	drawImg(kill_x, kill_y + all_y, &pictures[3]);

	outtextxy(554, 150 + all_y, "消灭");
	for (int i = 0; i < 4; i++) {
		drawImg(e_x, e_y + i * (e_size + e_gap) + all_y, &pictures[i + 4]);
		sprintf_s(text, "%d", Player::kill[i]);
		outtextxy(e_x + 50, e_y + i * (e_size + e_gap) + 6 + all_y, text);
	}

	drawImg(back_x, back_y + all_y, &pictures[2]);
	outtextxy(650, 406 + all_y, "退出");
}

InsTable::InsTable(int* ins_num)
{
	this->ins_num = ins_num;
	loadPicture();
}

void InsTable::loadPicture()
{
	IMAGE img1, img2, img3, img4, img5, img6, img7, img8, img9, img10;
	loadimage(&img1, "../image/ui/background.png", table_width, table_height);
	pictures.push_back(img1);
	loadimage(&img2, "../image/ui/Main_Menu_Bk.png", ins_width, ins_height);
	pictures.push_back(img2);
	loadimage(&img3, "../image/ui/ArrowLeft.png", arrow_width, arrow_height);
	pictures.push_back(img3);
	loadimage(&img4, "../image/ui/ArrowRight.png", arrow_width, arrow_height);
	pictures.push_back(img4);
	loadimage(&img5, "../image/player/idle/01.png", player_size, player_size);
	pictures.push_back(img5);
	loadimage(&img6, "../image/ui/e1.png", e1_size, e1_size);
	pictures.push_back(img6);
	loadimage(&img7, "../image/ui/e2.png", e2_size, e2_size);
	pictures.push_back(img7);
	loadimage(&img8, "../image/ui/e3.png", e3_size, e3_size);
	pictures.push_back(img8);
	loadimage(&img9, "../image/ui/e4.png", e4_size, e4_size);
	pictures.push_back(img9);
	loadimage(&img10, "../image/ui/sl1.png", back_width, back_height);
	pictures.push_back(img10);
}

void InsTable::run()
{
	settextcolor(WHITE);
	setbkmode(TRANSPARENT);
	drawImg(0, 0, &pictures[0]);
	drawImg(player_x, (table_height - player_size) / 2, &pictures[4]);
	drawImg(e_x, e_y * 1, &pictures[5]);
	drawImg(e_x + 25, e_y * 2 + 25, &pictures[6]);
	drawImg(e_x + 20, e_y * 3 + 20, &pictures[7]);
	drawImg(e_x, e_y * 4, &pictures[8]);
	drawImg((table_width - back_width) / 2, back_y, &pictures[9]);
	settextstyle(36, 0, "微软雅黑");
	outtextxy(484, 556, "返回");
	if (*ins_num != 0) {
		drawImg((table_width - ins_width) / 2, ins_y, &pictures[1]);
		switch(*ins_num) {
		case 11:
			drawImg(table_width / 2 + arrow_dis, arrow_y, &pictures[3]);

			settextstyle(title_size, 0, "微软雅黑");
			outtextxy(380, title_y, "基础信息——Jason");
			settextstyle(text_size, 0, "微软雅黑");
			outtextxy(text_x, text_y, "血量：7   能量：100");
			outtextxy(text_x, text_y + text_dis * 1, "能量回复速度：4/s");
			break;
		case 12:
			drawImg(table_width / 2 - arrow_dis - arrow_width, arrow_y, &pictures[2]);
			drawImg(table_width / 2 + arrow_dis, arrow_y, &pictures[3]);

			settextstyle(title_size, 0, "微软雅黑");
			outtextxy(480, title_y, "跳跃");
			settextstyle(text_size, 0, "微软雅黑");
			outtextxy(text_x, text_y, "按键：W   冷却：0s   能量消耗：0");
			outtextxy(text_x, text_y + text_dis * 1, "向上跳跃，空中使用可二段跳");
			break;
		case 13:
			drawImg(table_width / 2 - arrow_dis - arrow_width, arrow_y, &pictures[2]);
			drawImg(table_width / 2 + arrow_dis, arrow_y, &pictures[3]);

			settextstyle(title_size, 0, "微软雅黑");
			outtextxy(450, title_y, "快速落地");
			settextstyle(text_size, 0, "微软雅黑");
			outtextxy(text_x, text_y, "按键：S   冷却：0s   能量消耗：0");
			outtextxy(text_x, text_y + text_dis * 1, "快速降落至地面");
			break;
		case 14:
			drawImg(table_width / 2 - arrow_dis - arrow_width, arrow_y, &pictures[2]);
			drawImg(table_width / 2 + arrow_dis, arrow_y, &pictures[3]);

			settextstyle(title_size, 0, "微软雅黑");
			outtextxy(480, title_y, "冲刺");
			settextstyle(text_size, 0, "微软雅黑");
			outtextxy(text_x, text_y, "按键：K   冷却：0.1s   能量消耗：2");
			outtextxy(text_x, text_y + text_dis * 1, "向前冲刺，可延长滞空时间");
			break;
		case 15:
			drawImg(table_width / 2 - arrow_dis - arrow_width, arrow_y, &pictures[2]);
			drawImg(table_width / 2 + arrow_dis, arrow_y, &pictures[3]);

			settextstyle(title_size, 0, "微软雅黑");
			outtextxy(480, title_y, "斩击");
			settextstyle(text_size, 0, "微软雅黑");
			outtextxy(text_x, text_y, "按键：J   冷却：0s   能量消耗：2");
			outtextxy(text_x, text_y + text_dis * 1, "向前斩击，根据纵向速度分为上、中、下斩击");
			outtextxy(text_x, text_y + text_dis * 2, "可摧毁敌人和敌方红色攻击");
			outtextxy(text_x, text_y + text_dis * 3, "具有一定后摇（可被其他动作打断）");
			outtextxy(text_x, text_y + text_dis * 4, "快速落地时释放斩击并在落地后命中敌人，将");
			outtextxy(text_x, text_y + text_dis * 5, "强化下一次斩击");
			break;
		case 16:
			drawImg(table_width / 2 - arrow_dis - arrow_width, arrow_y, &pictures[2]);

			settextstyle(title_size, 0, "微软雅黑");
			outtextxy(430, title_y, "斩击（强化）");
			settextstyle(text_size, 0, "微软雅黑");
			outtextxy(text_x, text_y, "按键：J   冷却：0s   能量消耗：2");
			outtextxy(text_x, text_y + text_dis * 1, "在释放普通斩击的同时，向前释放一道光刃");
			outtextxy(text_x, text_y + text_dis * 2, "可摧毁一切敌方单位");
			break;
		case 21:
			settextstyle(title_size, 0, "微软雅黑");
			outtextxy(480, title_y, "影跃");
			settextstyle(text_size, 0, "微软雅黑");
			outtextxy(text_x, text_y, "按键：D/A   冷却：10s   能量消耗：20");
			outtextxy(text_x, text_y + text_dis * 1, "按下D跃迁至前方，之后可随时使用第二段");
			outtextxy(text_x, text_y + text_dis * 2, "第二段：按下A跃迁回原位（不消耗能量）");
			outtextxy(text_x, text_y + text_dis * 3, "每次跃迁过程中，角色都处于无敌状态");
			outtextxy(text_x, text_y + text_dis * 4, "角色回到原位后技能进入冷却");
			break;
		case 22:
			settextstyle(title_size, 0, "微软雅黑");
			outtextxy(480, title_y, "滞缓");
			settextstyle(text_size, 0, "微软雅黑");
			outtextxy(text_x, text_y, "按键：L   冷却：5s   能量消耗：15");
			outtextxy(text_x, text_y + text_dis * 1, "持续时间：1.5s");
			outtextxy(text_x, text_y + text_dis * 2, "减缓一切单位的速度，直至进行下一步操作或");
			outtextxy(text_x, text_y + text_dis * 3, "持续时间结束");
			outtextxy(text_x, text_y + text_dis * 4, "技能结束后进入冷却");
			break;
		case 23:
			settextstyle(title_size, 0, "微软雅黑");
			outtextxy(480, title_y, "脉冲");
			settextstyle(text_size, 0, "微软雅黑");
			outtextxy(text_x, text_y, "按键：U   冷却：12s   能量消耗：20");
			outtextxy(text_x, text_y + text_dis * 1, "持续时间：6s");
			outtextxy(text_x, text_y + text_dis * 2, "持续释放电磁脉冲，屏蔽敌方一切射击");
			outtextxy(text_x, text_y + text_dis * 3, "持续时间结束后技能进入冷却");
			break;
		case 24:
			settextstyle(title_size, 0, "微软雅黑");
			outtextxy(480, title_y, "残像");
			settextstyle(text_size, 0, "微软雅黑");
			outtextxy(text_x, text_y, "按键：I   冷却：10s   能量消耗：30");
			outtextxy(text_x, text_y + text_dis * 1, "持续时间：8s");
			outtextxy(text_x, text_y + text_dis * 2, "向后生成一个只能奔跑的残像，残像受到攻击");
			outtextxy(text_x, text_y + text_dis * 3, "立即死亡。持续时间结束后，若残像存活：①");
			outtextxy(text_x, text_y + text_dis * 4, "若角色存活，角色回复一点血量；②若角色死");
			outtextxy(text_x, text_y + text_dis * 5, "亡，角色复活并回复至一点血量。残像消失");
			outtextxy(text_x, text_y + text_dis * 6, "持续时间结束或残像死亡后技能进入冷却");
			break;
		case 25:
			settextstyle(title_size, 0, "微软雅黑");
			outtextxy(480, title_y, "炽月");
			settextstyle(text_size, 0, "微软雅黑");
			outtextxy(text_x, text_y, "按键：O   冷却：20s   能量消耗：60");
			outtextxy(text_x, text_y + text_dis * 1, "向前释放一道灭绝一切敌人的炽热剑气");
			outtextxy(text_x, text_y + text_dis * 2, "可摧毁一切敌方单位");
			outtextxy(text_x, text_y + text_dis * 3, "释放后技能进入冷却");
			break;
		case 31:
			settextstyle(title_size, 0, "微软雅黑");
			outtextxy(452, title_y, "“骑士”");
			settextstyle(text_size, 0, "微软雅黑");
			outtextxy(text_x, text_y, "地面敌方单位   击杀分数奖励：50");
			outtextxy(text_x, text_y + text_dis * 1, "它们数量庞大，永远只遵循一个指令——");
			outtextxy(text_x, text_y + text_dis * 2, "摧毁面前的一切敌人");
			break;
		case 32:
			settextstyle(title_size, 0, "微软雅黑");
			outtextxy(452, title_y, "“猎手”");
			settextstyle(text_size, 0, "微软雅黑");
			outtextxy(text_x, text_y, "地面敌方单位   击杀分数奖励：150");
			outtextxy(text_x, text_y + text_dis * 1, "每发射两次红色子弹，发射一次蓝色子弹");
			outtextxy(text_x, text_y + text_dis * 2, "看到玩家后将短暂蓄力并射击，随后若再次看");
			outtextxy(text_x, text_y + text_dis * 3, "到玩家，则会迅速后撤并重复上述过程");
			outtextxy(text_x, text_y + text_dis * 4, "它们的狡黠程度，往往超出我们的想象");
			break;
		case 33:
			settextstyle(title_size, 0, "微软雅黑");
			outtextxy(452, title_y, "“天使”");
			settextstyle(text_size, 0, "微软雅黑");
			outtextxy(text_x, text_y, "空中敌方单位   击杀分数奖励：50");
			outtextxy(text_x, text_y + text_dis * 1, "每发射两次红色子弹，发射一次蓝色子弹");
			outtextxy(text_x, text_y + text_dis * 2, "每隔一段时间进行一次射击");
			outtextxy(text_x, text_y + text_dis * 3, "它们在你头顶上徘徊，为天空带来安详");
			break;
		case 34:
			settextstyle(title_size, 0, "微软雅黑");
			outtextxy(452, title_y, "“卫星”");
			settextstyle(text_size, 0, "微软雅黑");
			outtextxy(text_x, text_y, "空中敌方单位   击杀分数奖励：150");
			outtextxy(text_x, text_y + text_dis * 1, "出现并蓄力后，发射一道横向贯穿屏幕的蓝色");
			outtextxy(text_x, text_y + text_dis * 2, "激光，随后原路返回");
			outtextxy(text_x, text_y + text_dis * 3, "它们从四周汇聚能量，让前方的阻碍化为灰烬");
			break;
		}
	}
}
