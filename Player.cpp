#include "Player.h"
#include <Novice.h>

Player::Player() {
	posX_ = 640.0f;
	posY_ = 540.0f;
	radius_ = 50.0f;
	speed_ = 7.0f;
}

void Player::Update(char* keys, char* preKeys) {
	if (keys[DIK_A]) {
		posX_ -= speed_;
	}
	if (keys[DIK_D]) {
		posX_ += speed_;
	}
	if (keys[DIK_W]) {
		posY_ -= speed_;
	}
	if (keys[DIK_S]) {
		posY_ += speed_;
	}
	if (keys[DIK_SPACE] != 0 && preKeys[DIK_SPACE] == 0) {
		bullet.Initalize(posX_, posY_);
	}
	bullet.Update();
}

void Player::BulletOnCollision()
{
	bullet.OnCollision();
}

void Player::Draw() {
	bullet.Draw();
	Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, GREEN, kFillModeSolid);
	
}