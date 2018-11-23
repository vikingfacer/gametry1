
#ifndef USERINLIB_H

#define USERINLIB_H

#include <math.h>

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

	// no zoom right now

	// if(IsKeyPressed(KEY_EQUAL))
	// {
	// 	camera.zoom = camera.zoom + .10f;
	// }
	// else if(IsKeyPressed(KEY_MINUS))
	// {
	// 	camera.target.x = 480;
	// 	camera.target.y = 200;
	// 	camera.zoom = camera.zoom - .10f;

	// 	camera.offset.x = 0;
	// 	camera.offset.y = 0;
	// 	// camera.target.x = 400 * camera.zoom;
	// 	// camera.target.y = 280 * camera.zoom;

	// }

	// camera lock will free the camera to be moved with the keys
	if(IsKeyPressed(KEY_L))
	{
		cameraLock = false; 
	}
}
#endif