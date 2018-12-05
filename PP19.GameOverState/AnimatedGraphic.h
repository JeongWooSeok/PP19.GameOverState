#pragma once
#include "SDLGameObject.h"

class AnimatedGraphic : public SDLGameObject
{
public:
	AnimatedGraphic(const LoaderParams* pParams, int animSpeed);
	void update();
private:
	int m_currentFrame = 1;
	int m_animSpeed = 1;
	int m_numFrames;
};