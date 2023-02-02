#include <Novice.h>
#include "Player.h"
#include "Enemy.h"
#include "Collision.h"

const char kWindowTitle[] = "LC1A_21_マキユキノリ_タイトル";

int Enemy::isActive = 1;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);
	Player* player = new Player;
	Enemy* enemy[2];
	for (int i = 0; i < 2; i++) {
		enemy[i] = new Enemy;
	}
	enemy[0]->Initalize(100.0f, 100.0f);
	enemy[1]->Initalize(1180.0f, 360.0f);
	

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		if (keys[DIK_R] != 0 && preKeys[DIK_R] == 0) {
			enemy[0]->Initalize(100.0f, 100.0f);
			enemy[1]->Initalize(1180.0f, 360.0f);
		}
		player->Update(keys, preKeys);
		for (int i = 0; i < 2; i++) {
			enemy[i]->Update();
			if (player->GetBulletShot() == 1) {
				if (Collision(enemy[i]->GetPositionX(), enemy[i]->GetPositionY(), player->GetBulletPosX(), player->GetBulletPosY()) 
					<= enemy[i]->GetRadius() + player->GetBulletRadius()) {
					enemy[i]->OnCollision();
					player->BulletOnCollision(); 
				}
			}
			
		}
		
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		player->Draw();
		for (int i = 0; i < 2; i++) {
			enemy[i]->Draw();
		}
		Novice::ScreenPrintf(0, 0, "enemyA isAlive = %d", Enemy::isActive);
		Novice::ScreenPrintf(0, 15, "enemyB isAlive = %d", Enemy::isActive);
		Novice::ScreenPrintf(0, 30, "WASD : player Move");
		Novice::ScreenPrintf(0, 45, "shot : SPACE");
		Novice::ScreenPrintf(0, 60, "enemy respawn : R");
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
