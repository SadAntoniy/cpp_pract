#include "Framework.h"
#include <iostream>
#include "windows.h"
#include "windowsx.h"
#include <vector>
#include <math.h>

#define HIT_IN_PLATFORM ((ball.X + ball.diameter > platform.X && ball.X < (platform.X + platform.width)) && ball.Y > platform.Y - platform.height)
#define HIT_IN_PLATFORM_2 ((ball.X > platform.X && ball.X < (platform.X + platform.width)) && ball.Y > platform.Y - platform.height)

#define HIT_IN_BOOTOM_OF_BLOCK (ball.X  > block[i].X && ball.X < block[i].X + block[i].width) && (ball.Y < block[i].Y + block[i].height)
#define HIT_IN_BOOTOM_OF_BLOCK_1 (ball.X + ball.diameter/2 > block[i].X && ball.X + ball.diameter/2 < block[i].X + block[i].width) && (ball.Y < block[i].Y + block[i].height)
#define HIT_IN_BOOTOM_OF_BLOCK_2 (ball.X + ball.diameter > block[i].X && ball.X + ball.diameter < block[i].X + block[i].width) && (ball.Y < block[i].Y + block[i].height)

#define HIT_IN_TOP_OF_BLOCK (ball.X  > block[i].X && ball.X < block[i].X + block[i].width) && (ball.Y + ball.diameter == block[i].Y)
#define HIT_IN_TOP_OF_BLOCK_1 (ball.X + ball.diameter/2 > block[i].X && ball.X + ball.diameter/2 < block[i].X + block[i].width) && (ball.Y + ball.diameter == block[i].Y)
#define HIT_IN_TOP_OF_BLOCK_2 (ball.X + ball.diameter > block[i].X && ball.X + ball.diameter < block[i].X + block[i].width) && (ball.Y + ball.diameter == block[i].Y)


#define HIT_IN_LEFT_OF_BLOCK (ball.X + ball.diameter == block[i].X  && ball.Y > block[i].Y && ball.Y < block[i].Y + block[i].height)
#define HIT_IN_LEFT_OF_BLOCK_1 (ball.X + ball.diameter == block[i].X && ball.Y + ball.diameter > block[i].Y && ball.Y + ball.diameter < block[i].Y + block[i].height)) 
#define HIT_IN_LEFT_OF_BLOCK_2 (ball.X + ball.diameter == block[i].X && ball.Y + ball.diameter / 2 > block[i].Y && ball.Y + ball.diameter / 2 < block[i].Y + block[i].height)

#define HIT_IN_RIGHT_OF_BLOCK (ball.X == block[i].X + block[i].width && ball.Y > block[i].Y && ball.Y < block[i].Y + block[i].height)
#define HIT_IN_RIGHT_OF_BLOCK_1 (ball.X == block[i].X + block[i].width && ball.Y + ball.diameter > block[i].Y && ball.Y + ball.diameter < block[i].Y + block[i].height)) 
#define HIT_IN_RIGHT_OF_BLOCK_2 (ball.X == block[i].X + block[i].width && ball.Y + ball.diameter / 2 > block[i].Y && ball.Y + ball.diameter / 2 < block[i].Y + block[i].height)

class Platform
{
public:
	Sprite* sprite;
	double speed;
	int width;
	int height;
	double X;
	double Y;
};

class Ball
{
public:
	Sprite* sprite;
	double speed;
	int diameter;
	double X;
	double Y;
};

class Block {
public:
	const static int bcount = 32;
	Sprite* sprite;
	int width;
	int height;
	double X;
	double Y;
};

/* Test Framework realization */
class MyFramework : public Framework {
public:

	MyFramework() {
		//std::cin >> widthOfScreen >> heightOfScreen;
		delta = heightOfScreen / 80;

		//For Platform
		platform.width = widthOfScreen / 4;
		platform.height = heightOfScreen / 20;
		platform.X = widthOfScreen / 2 - platform.width / 2;
		platform.Y = heightOfScreen - platform.height - delta;
		platform.speed = 1;

		//For Ball
		ball.diameter = widthOfScreen / 25;
		ball.speed = 1;
		ball.X = (static_cast<double>(widthOfScreen) / 2 - ball.diameter / 2);
		ball.Y = (static_cast<double>(heightOfScreen - platform.height - ball.diameter - delta));

		//For Block
		block[0].X = delta;
		block[0].Y = delta;
		row = 0;
		for (int i = 0; i < Block::bcount; ++i)
		{
			block[i].width = widthOfScreen / 8 - delta * 1.11;
			block[i].height = heightOfScreen / 22;			
		}
		for (int i = 1; i < Block::bcount; ++i)
		{
			block[i].X = block[i-1].X + block[i-1].width + delta;
			block[i].Y = block[row].Y;
			if ((block[i].X + block[i].width + delta) > widthOfScreen)
			{
				block[i].X = delta;
				block[i].Y = block[row].Y + block[i-1].height + delta;
				row = i;
			}
		}		
	}

	virtual void PreInit(int& width, int& height, bool& fullscreen)
	{
		width = widthOfScreen;
		height = heightOfScreen;		
		fullscreen = false;
	}

	virtual bool Init() {
		background = createSprite("background.jpg");
		setSpriteSize(background, widthOfScreen, heightOfScreen);

		platform.sprite = createSprite(pathToPlatform);
		setSpriteSize(platform.sprite, platform.width, platform.height);

		ball.sprite = createSprite(pathToBall);
		setSpriteSize(ball.sprite, ball.diameter, ball.diameter);

		for (int i = 0; i < Block::bcount; ++i) 
		{
			block[i].sprite = createSprite(pathToBlocks);
			setSpriteSize(block[i].sprite, block[i].width, block[i].height);
		}
		return true;
	}

	virtual void Close() {
		
	}

	virtual bool Tick() {		
		drawSprite(background, 0, 0);
		drawSprite(platform.sprite, platform.X, platform.Y);
		drawSprite(ball.sprite, ball.X, ball.Y);
		for (int i = 0;i < Block::bcount; ++i)
		{
			drawSprite(block[i].sprite, block[i].X, block[i].Y);				
		}
		if (GetAsyncKeyState(VK_RIGHT))
		{
			key = FRKey::RIGHT;
			onKeyPressed(key);
		}
		if (GetAsyncKeyState(VK_LEFT))
		{
			key = FRKey::LEFT;
			onKeyPressed(key);
		}
		if (rightKey)
		{
			platform.X += platform.speed * 2;
		}
		if (leftKey)
		{
			platform.X -= platform.speed * 2;
		}
		if (GetKeyState(WM_RBUTTONDOWN))
		{
			butt = FRMouseButton::RIGHT;
			onMouseButtonClick(butt, butt_isR);
		}

		if (count > 0)
		{			
			if (state == 1 && ball.X + ball.diameter > widthOfScreen-ball.speed)
				state = 0;
			else if (state == 0 && ball.Y < 0)
				state = 3;
			else if (state == 3 && ball.X < 0)
				state = 2;
			else if (state == 2 && HIT_IN_PLATFORM)
				state = 1;
			else if ((state == 1 && ball.Y < 0))
				state = 2;
			else if (state == 2 && ball.X + ball.diameter > widthOfScreen-ball.speed)
				state = 3;
			else if (state == 3 && HIT_IN_PLATFORM)
				state = 0;
			else if (state == 0 && ball.X < 0)
				state = 1;
			else if ((state == 2 && ball.Y >= heightOfScreen) || (state == 3 && ball.Y > heightOfScreen))
				state = 4;
			switch (state)
			{
			case 0:
				ball.X -= ball.speed;
				ball.Y -= ball.speed;
				break;
			case 1:
				ball.X += ball.speed;
				ball.Y -= ball.speed;
				break;
			case 2:
				ball.X += ball.speed;
				ball.Y += ball.speed;
				break;
			case 3:
				ball.X -= ball.speed;
				ball.Y += ball.speed;
				break;
			case 4:
				ball.Y = heightOfScreen - ball.diameter;
				break;
			}

			std::cout << ball.X << " " << ball.Y << std::endl;
			for (int i = 0; i < Block::bcount; ++i)
			{
				if (block[i].sprite)
				{
					if (state == 1 && HIT_IN_BOOTOM_OF_BLOCK && HIT_IN_BOOTOM_OF_BLOCK_1 || state == 1 && HIT_IN_BOOTOM_OF_BLOCK_2 && HIT_IN_BOOTOM_OF_BLOCK_1 || state == 1 && HIT_IN_BOOTOM_OF_BLOCK || state == 1 && HIT_IN_BOOTOM_OF_BLOCK_2)
					{
						state = 2;
						//setSpriteSize(block[i].sprite, 0, 0);
						block[i].X = widthOfScreen;
						block[i].Y = heightOfScreen;
						destroySprite(block[i].sprite);
					}
					else if ((state == 1 && HIT_IN_LEFT_OF_BLOCK || HIT_IN_LEFT_OF_BLOCK_1 || HIT_IN_LEFT_OF_BLOCK_2)
					{
						state = 0;
							//setSpriteSize(block[i].sprite, 0, 0);
							block[i].X = widthOfScreen;
							block[i].Y = heightOfScreen;
							destroySprite(block[i].sprite);
					}
					else if ((state == 0 || state == 5) && HIT_IN_BOOTOM_OF_BLOCK && HIT_IN_BOOTOM_OF_BLOCK_1 || (state == 0 || state == 5) && HIT_IN_BOOTOM_OF_BLOCK_2 && HIT_IN_BOOTOM_OF_BLOCK_1 || (state == 0 || state == 5) && HIT_IN_BOOTOM_OF_BLOCK || (state == 0 || state == 5) && HIT_IN_BOOTOM_OF_BLOCK_2)
					{
						state = 3;
							//setSpriteSize(block[i].sprite, 0, 0);
						block[i].X = widthOfScreen;
						block[i].Y = heightOfScreen;
						destroySprite(block[i].sprite);
					}
					else if (((state == 0 || state == 5) && HIT_IN_RIGHT_OF_BLOCK || (state == 0 || state == 5) && HIT_IN_RIGHT_OF_BLOCK_1 || (state == 0 || state == 5) && HIT_IN_RIGHT_OF_BLOCK_2)
					{
						state = 1;
							//setSpriteSize(block[i].sprite, 0, 0);
							block[i].X = widthOfScreen;
							block[i].Y = heightOfScreen;
							destroySprite(block[i].sprite);
					}
					else if ((state == 3 && HIT_IN_RIGHT_OF_BLOCK || state == 3 && HIT_IN_RIGHT_OF_BLOCK_1 || state == 3 && HIT_IN_RIGHT_OF_BLOCK_2)
					{
						state = 2;
							//setSpriteSize(block[i].sprite, 0, 0);
							block[i].X = widthOfScreen;
							block[i].Y = heightOfScreen;
							destroySprite(block[i].sprite);
					}
					else if ((state == 2 && HIT_IN_LEFT_OF_BLOCK || state == 2 && HIT_IN_LEFT_OF_BLOCK_1 || state == 2 && HIT_IN_LEFT_OF_BLOCK_2)
					{
						state = 3;
							//setSpriteSize(block[i].sprite, 0, 0);
							block[i].X = widthOfScreen;
							block[i].Y = heightOfScreen;
							destroySprite(block[i].sprite);
					}
					if (state == 3 && HIT_IN_TOP_OF_BLOCK && HIT_IN_TOP_OF_BLOCK_1 || state == 3 && HIT_IN_TOP_OF_BLOCK_2 && HIT_IN_TOP_OF_BLOCK_1 || state == 3 && HIT_IN_TOP_OF_BLOCK || state == 3 && HIT_IN_TOP_OF_BLOCK_2)
					{
						state = 0;
							//setSpriteSize(block[i].sprite, 0, 0);
						block[i].X = widthOfScreen;
						block[i].Y = heightOfScreen;
						destroySprite(block[i].sprite);
					}
					if (state == 2 && HIT_IN_TOP_OF_BLOCK && HIT_IN_TOP_OF_BLOCK_1 || state == 3 && HIT_IN_TOP_OF_BLOCK_2 && HIT_IN_TOP_OF_BLOCK_1 || state == 3 && HIT_IN_TOP_OF_BLOCK || state == 3 && HIT_IN_TOP_OF_BLOCK_2)
					{
						state = 1;
						//setSpriteSize(block[i].sprite, 0, 0);
						block[i].X = widthOfScreen;
						block[i].Y = heightOfScreen;
						destroySprite(block[i].sprite);
					}
				}	
			}
		}		
		return false;
	}

	virtual void onMouseMove(int x, int y, int xrelative, int yrelative) {
		
		
	}

	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased) {
		if (butt_isR) {
			count++;
			std::cout << count << std::endl;
			GetCursorPos(&p);
			ScreenToClient(FindWindowA(NULL, GetTitle()), &p);
			std::cout << p.x << " " << p.y << std::endl;

			if (widthOfScreen / 2 < p.x)
				state = 1;
			else if (widthOfScreen / 2 > p.x)
				state = 0;
			headingX = ball.X - p.x;
			headingRX = p.x - ball.X;
			headingY = ball.Y - p.y;
			headingRY = p.y - ball.Y;
			modul = sqrt((headingX) * (headingX)+(headingY) * (headingY));
			modulR = sqrt((headingRX) * (headingRX)+(headingRY) * (headingRY));

			std::cout << p.x << " " << p.y << std::endl;
			butt_isR = false;
		}		
	}

	virtual void onKeyPressed(FRKey k) {
		if (k == FRKey::RIGHT)
			rightKey = true;
		else if (k == FRKey::LEFT)
			leftKey = true;
	}

	virtual void onKeyReleased(FRKey k) {
		if (k == FRKey::RIGHT)
			rightKey = false;
		else if (k == FRKey::LEFT)
			leftKey = false;
	}

	virtual const char* GetTitle() override
	{
		return "Arcanoid";
	}

private:
	Platform platform;
	const char* pathToPlatform = "50-Breakout-Tiles.png";

	Ball ball;
	const char* pathToBall = "64-Breakout-Tiles.png";

	Block block[Block::bcount];
	const char* pathToBlocks = "01-Breakout-Tiles.png";

	Sprite* background;
	FRKey key;	
	FRMouseButton butt;
	bool butt_isR = true;
	double widthOfScreen = 800;
	double heightOfScreen = 600;
	int delta;
	bool rightKey = false;
	bool leftKey = false;	
	int row;

	POINT p;
	int count = 0;
	double cosA;
	int state = 0;
	double headingX;
	double headingY;
	double modul;
	double headingRX;
	double headingRY;
	double modulR;
};

int main(int argc, char* argv[])
{	
	return run(new MyFramework);
}
