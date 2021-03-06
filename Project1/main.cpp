#include<DxLib.h>
#include<cassert>
#include<string>
#include<sstream>
#include<iomanip>
#include<cmath>
#include"Geometory.h"


//Position2 GetCurrentMousePosition2()
//{
//	/*int mx, my;
//	GetMousePoint(&mx, &my);
//	return{ mx,my };*/
//}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	DxLib::SetWindowText(L"1916003_石橋雄貴");
	ChangeWindowMode(true);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);

	int groundH = LoadGraph(L"Image/ground.png");

	int asset= LoadGraph(L"Image/Assets.png");

	int arrowH=LoadGraph(L"Image/arrow2.png");

	if (DxLib_Init() == -1)
	{
		return false;
	}

	int frameForAngle = 0;
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{

		int mx, my;
		GetMousePoint(&mx, &my);
		/*Vector2 dir={static_cast<float>(mx)-rc.center.x}*/

		auto currentMouseInput = GetMouseInput();
		/*if ()
		{
			;
		}*/

		ClearDrawScreen();

		constexpr size_t block_size = 32;
		const int width = 400;
		const auto count = width / block_size;

		int imageWidth, imageHight;
		GetGraphSize(arrowH, &imageWidth, &imageHight);
		float weight = (float)imageWidth/(float)width;



		float theta = (float)(frameForAngle)*DX_PI_F / 180.0f;
		int x = 0;
		int y = 240;//+100*sinf(theta);
		Position2 lastPos(x, y);//前の座標
		Position2 p0(x, y);
		//過去1過去2
		Vector2 lastDelta90Vectors[2] = { { 0.0f,0.0f },{0.0f,0.0f} };
		


		//auto px = 0 * block_size;
		//auto py = 240 + 100 * sinf(0.5f*DegreeToRadian(0*block_size+frameForAngle));
		//Position2 currentPos = { px,py };

		
		for (int i = 0; i <= count; i++)
		{
			theta += 0.1f;
			//auto nextX = i*block_size ;
			//Vector2 deltaVec = { block_size,block_size * 2.0f * sinf(0.5f * DegreeToRadian(i*block_size+frameForAngle)) };
			//Position2 nextPos = currentPos + deltaVec;
			//auto nextY = 140 + 100 * sinf((float)(0.5f*nextX+frameForAngle) * DX_PI_F/180.0f);

			//DrawModiGraph(x, y,//始点
			//	nextX, nextY,//終点
			//	nextX,nextY+block_size,
			//	x,y+block_size,
			//	groundH,
			//	true);

			//constexpr int offset = 100;

			//DrawRectModiGraph(
			//	x, y + 100,//始点
			//	nextX, nextY+100,//終点
			//	nextX, nextY + block_size + 100,
			//	x, y + block_size + 100,
			//	48,0,
			//	16,16,
			//	asset,
			//	true);


			//DrawLineAA(x, y,//始点
			//	nextX, nextY,//終点
			//	0xffffff, 3.0f);

			/*x = nextX;
			y = nextY;*/

			auto p1 = p0;
			auto deltaVec = Vector2(block_size, 40.0f *
				sinf(0.5f * (float)(frameForAngle+block_size*i)*DX_PI_F / 180.0f)
			);
			deltaVec = deltaVec.Normalized() * block_size;
			p1 = p0 + deltaVec;
			//p1 = (p0 + deltaVec.Normalize())*block_size;
			//*p1 = p0 + deltaVec.Normalize() * block_size;*/
			//deltavec = deltaVec.Normalize() * block_size;
			//p1 = p0 + deltaVec;

			auto delta90Vec = deltaVec.Rotated90();

			auto middleVecR = delta90Vec;
			auto middleVecL = delta90Vec;
			if (!(lastDelta90Vectors[0] == Vector2(0.0f, 0.0f)))
			{
				middleVecR = (delta90Vec + lastDelta90Vectors[0]).Normalized() * block_size;
				middleVecL = lastDelta90Vectors[0];
			}
			
			if (!(lastDelta90Vectors[1] == Vector2(0.0f, 0.0f)))
			{
				middleVecL = (lastDelta90Vectors[0] + lastDelta90Vectors[1]).Normalized() * block_size;
			}
			lastDelta90Vectors[1] = lastDelta90Vectors[0];
			lastDelta90Vectors[0] = deltaVec.Rotated90();


			//地面の表示
			DrawLineAA(//上辺
				p0.x, p0.y,
				p1.x, p1.y,
				0xffffff, 5.0f);

			DrawCircle(p0.x, p0.y, 3.0f, 0xff0000, true);

			auto leftPos = lastPos + middleVecL;
			auto rightPos = p0 + middleVecR;
			

			//auto leftPos = p0 + deltaVec.Rotated90();
			///*auto middlePos = leftPos;
			//if (!(lastDeltaVec90 == Vector2(0.0f, 0.0f)))
			//{
			//	auto halfPos = deltaVec.Rotated90()+lastDeltaVec90;

			//	middlePos = halfPos;
			//}*/

			//auto rightPos = p1 + deltaVec.Rotated90();


			//auto middlePos = p0 + middleVecR;
			//DrawLineAA(//左辺
			//	p0.x, p0.y,//始点
			//	middlePos.x, middlePos.y,//終点
			//	0xffaaaa, 4.0f);

			//DrawRectModiGraph(
			//	p0.x, p0.y ,//始点
			//	p1.x, p1.y,//終点
			//	rightPos.x, rightPos.y,
			//	leftPos.x, leftPos.y,
			//	48,0,
			//	16,16,
			//	asset,
			//	true);


			//DrawLineAA(//左辺
			//	p0.x, p0.y,//始点
			//	leftPos.x, leftPos.y,//終点
			//	0xff8888, 3.0f);
			//DrawLineAA(//右辺
			//	p1.x, p1.y,//始点
			//	rightPos.x, rightPos.y,//終点
			//	0x8888ff, 3.0f);

			if (i == count)
			{
				/*leftPos = p0 + middleVecL;
				rightPos = p1 + delta90Vec;*/



				DrawRectModiGraph(
					lastPos.x, lastPos.y,
					p0.x, p0.y,//終点
					rightPos.x, rightPos.y,
					leftPos.x, leftPos.y,
					(i-1)*block_size*weight,0,//画像切り抜き左上
					block_size*weight,64,//画像切り抜き右下
					arrowH, true
				);

				leftPos = p0 + middleVecR;
				auto rightPos2 = p1 + delta90Vec;

				DrawRectModiGraph(
					p0.x, p0.y,//終点
					p1.x, p1.y,
					rightPos2.x, rightPos2.y,
					leftPos.x, leftPos.y,
					i * block_size* weight, 0,//画像切り抜き左上
					block_size* weight, 64,//画像切り抜き右下
					arrowH, true
				);

				/*DrawLineAA(
					lastPos.x, lastPos.y,
					leftPos.x, leftPos.y,
					0xffffff, 3.0f
				);*/

				//DrawModiGraph(
				//	p0.x, p0.y,//終点
				//	p1.x, p1.y,
				//	rightPos.x, rightPos.y,
				//	leftPos.x, leftPos.y,
				//	groundH, true
				//);


			}
			else
			{
				/*leftPos = p0 + middleVecR;
				auto rightPos2 = p1 + delta90Vec;*/

				DrawRectModiGraph(
					lastPos.x, lastPos.y,//終点
					p0.x, p0.y,
					rightPos.x, rightPos.y,
					leftPos.x, leftPos.y,
					(i - 1) * block_size* weight, 0,//画像切り抜き左上
					block_size* weight, 64,//画像切り抜き幅、高さ
					arrowH, true
				);
			}
			

			/*DrawLineAA(
				p0.x, p0.y,
				leftPos.x, leftPos.y,
				0xffffff, 3.0f
			);

			DrawLineAA(
				p1.x, p1.y,
				rightPos.x, rightPos.y,
				0xffffff, 3.0f
			);*/

			lastPos = p0;

			p0 = p1;
		}
		frameForAngle = (frameForAngle + 1) %720;
		////地面の表示
		//DrawLineAA(0.0f, 240.0f,//始点
		//	640.0f, 120.0f,//終点
		//	0xffffff, 5);

		//DrawString(100,100,L"GitTest",0xffffff);
		ScreenFlip();
	}

	DxLib::DxLib_End();

	return true;
}