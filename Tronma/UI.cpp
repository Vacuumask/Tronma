#include "UI.h"

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
}

void PlayerCondition::run()
{
	drawImg(profile_x - profileBorder_thick, profile_y - profileBorder_thick, &pictures[0]);
	drawImg(profile_x, profile_y, &pictures[1]);
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


}

UI::~UI()
{
}
