#pragma once
class Bullet
{
public:
	Bullet();
	void Initalize(float posX, float posY);
	void Update();
	void Draw();
	void OnCollision();
	int GetIsActive() { return isActive_; };
	float GetPosX() { return posX_; };
	float GetPosY() { return posY_; };
	float GetRadius() { return radius_; };
private:
	float posX_;
	float posY_;
	float radius_;
	float speed_;
	int isActive_;
};

