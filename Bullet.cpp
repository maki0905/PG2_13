#include "Bullet.h"
#include <Novice.h>

Bullet::Bullet()
{
	posX_ = 0; 
	posY_ = 0;
	radius_ = 10;
	speed_ = 15;
	isActive_ = 0;
}

void Bullet::Initalize(float posX, float posY)
{
	if (isActive_ == 0) {
		posX_ = posX;
		posY_ = posY;
		isActive_ = 1;
	}
	
}

void Bullet::Update()
{
	if (isActive_ == 1) {
		posY_ -= speed_;
		if (posY_ + radius_ < 0) {
			isActive_ = 0;
		}
	}
	
}

void Bullet::Draw()
{
	if (isActive_ == 1) {
		Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, WHITE, kFillModeSolid);
	}
	
}

void Bullet::OnCollision()
{
	isActive_ = 0;
}
