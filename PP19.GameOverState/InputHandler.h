#pragma once
#include <SDL.h>
#include <vector>
#include "Vector2D.h"

enum mouse_buttons
{
	LEFT = 0, MIDDLE = 1, RIGHT = 2
};

class InputHandler
{
public:
	static InputHandler* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}
	void update();
	void clean();
	bool isKeyDown(SDL_Scancode key);
	bool getMouseButtonState(int buttonNumber);
	Vector2D* getMousePosition();

	void onMouseButtonDown(SDL_Event event);
	void onMouseButtonUp(SDL_Event event);
	void onKeyDown();
	void onKeyUp();
	Vector2D* onMouseMove(SDL_Event event);

	std::vector<bool> m_mouseButtonStates;
private:
	InputHandler();
	~InputHandler() {}
	static InputHandler* s_pInstance;

	const Uint8* m_keystates;
	Vector2D* m_mousePosition;
};

typedef InputHandler TheInputHandler;