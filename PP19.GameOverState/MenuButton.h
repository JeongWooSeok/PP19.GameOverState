#pragma once
#include "SDLGameObject.h"
#include "InputHandler.h"

enum Button_states
{
	MOUSE_OUT = 0, MOUSE_OVER = 1, CLICKED = 2
};

class MenuButton : public SDLGameObject
{
public:
	void(*m_callback)();
	bool m_bReleased;
	MenuButton(const LoaderParams* pParams, void(*callback)());
	virtual void draw();
	virtual void update();
	virtual void clean();
};