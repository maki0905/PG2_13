#pragma once
#include "Bullet.h"
class Player
{
public:
	Player();
	void Update(char* keys, char* preKeys);
	void BulletOnCollision();
	void Draw();
	int GetBulletShot() { return bullet.GetIsActive(); };
	float GetBulletPosX() { return bullet.GetPosX(); };
	float GetBulletPosY() { return bullet.GetPosY(); };
	float GetBulletRadius() { return bullet.GetRadius(); };
private:
	float posX_;
	float posY_;
	float radius_;
	float speed_;
	Bullet bullet;
};

