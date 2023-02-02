#pragma once
class Enemy
{
public:
	static int isActive;
	Enemy();
	void Initalize(float posX, float posY);
	void Update();
	void Draw();
	void OnCollision();
	float GetPositionX() { return posX_; };
	float GetPositionY() { return posY_; };
	float GetRadius() { return radius_; };
private:
	float posX_;
	float posY_;
	float radius_;
	float speed_;
};

