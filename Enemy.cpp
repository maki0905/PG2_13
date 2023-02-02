#include "Enemy.h"
#include <Novice.h>

Enemy::Enemy() {
	posX_ = 0;
	posY_ = 0;
	radius_ = 30.0f;
	speed_ = 10.0f;
}

void Enemy::Initalize(float posX, float posY)
{
	isActive = 1;
	posX_ = posX;
	posY_ = posY;
}

void Enemy::OnCollision() {
	isActive = 0;
}

void Enemy::Update() {
	if (isActive == 1) {
		posX_ += speed_;
		if (posX_ - radius_ < 0) {
			speed_ *= -1;
		}
		if (posX_ + radius_ > 1280) {
			speed_ *= -1;
		}
	}
	
}

void Enemy::Draw() {
	if (isActive == 1) {
		Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, RED, kFillModeSolid);
	}
	
}