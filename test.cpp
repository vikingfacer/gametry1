// open world is easier than Closed 
// probability combat system still doable but orientation needs figuring out + angle from target + distance
// -this an be done with collision detection

#include "raylib.h"
#include "userInlib.h"

Rectangle LoadedArea = {1000, 1000};

Rectangle Screen = {800, 800};
int screenWidth = 800;
int screenHeight= 800;




struct Rectangle boundaries = {1000, 1000};
// overload substraction operator for rectangles for easy of use


void handle_buttons(Rectangle& player, Camera2D& camera, bool& cameraLock);
void show_stats(const Camera2D& camera, const Rectangle& player, const bool& cameraLock);



int main(int argc, char const *argv[])
{
	bool cameraLock = true;
    Camera2D camera;
	InitWindow( screenWidth, screenHeight, "hello World");
    //--------------------------------------------------------------------------------------

    Rectangle player = { 400, 280, 40, 40 };
    Vector2 target = {player.x, player.y};
    // for 2d cam this can be handled directly by the structure of the camera 
    camera.target =  target;
	camera.offset = (Vector2){ 0, 0 };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    Image img = LoadImage("backgrounddetailed1.png");
	// ImageCrop(&img, (Rectangle) {100, 10, 280,380});
	ImageResize(&img, LoadedArea.x, LoadedArea.y);
	Texture2D imgTex = LoadTextureFromImage(img);
	GenTextureMipmaps(&imgTex);
	UnloadImage(img);
		
	SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

    	// I want to make key presses into interupts
    	handle_buttons(player, camera, cameraLock);

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

	    ClearBackground(RAYWHITE);

		BeginMode2D(camera);

			DrawTexture(imgTex, 0, 0, WHITE);
			DrawTexture(imgTex, 1020, 1020, WHITE);
			DrawTexture(imgTex, 20, 1000, WHITE);
			DrawTexture(imgTex, 1000, 0, WHITE);

			// DrawText("test", 0,0, 11, RED); //(const char *text, int posX, int posY, int fontSize, Color color);
			DrawRectangleRec(player, YELLOW);

		EndMode2D();

			show_stats(camera,player,cameraLock);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

	return 0;
}

void handle_buttons(Rectangle& player, Camera2D& camera, bool& cameraLock)
{
    if (IsKeyDown(KEY_RIGHT))
	{
		player.x += 2;
		camera.offset.x -= 2 * camera.zoom;
	}
	else if (IsKeyDown(KEY_LEFT))
	{
		player.x -= 2;
		camera.offset.x += 2 * camera.zoom;
	}
	if(IsKeyDown(KEY_DOWN))
	{
		player.y += 2;
		camera.offset.y -= 2 * camera.zoom;
	}
	else if(IsKeyDown(KEY_UP))
	{
		player.y -= 2;
		camera.offset.y += 2 * camera.zoom;
	}
	if(IsKeyPressed(KEY_EQUAL))
	{
		camera.zoom = camera.zoom + .10f;
	}
	else if(IsKeyPressed(KEY_MINUS))
	{
		camera.zoom = camera.zoom - .10f;

		// camera.offset.x = -player.x/2;
		// camera.offset.y = -player.y/2;

		camera.target.x = player.x;
		camera.target.y = -player.y;


	}

	// camera lock will free the camera to be moved with the keys
	if(IsKeyPressed(KEY_L))
	{
		cameraLock = false; 
	}
}

void show_stats(const Camera2D& camera, const Rectangle& player, const bool& cameraLock)
{
    DrawText(FormatText("camera off (x, y): (%f, %f)", camera.offset.x, camera.offset.y), 200, 80, 20, RED);
    DrawText(FormatText("camera tar (x, y): (%f, %f)", camera.target.x, camera.target.y), 200, 100, 20, RED);
    DrawText(FormatText("camera zoom %f", camera.zoom), 200, 120, 20, RED);

    DrawText(FormatText("player: (x, y): (%f, %f)", player.x, player.y), 200, 140, 20, RED);

}