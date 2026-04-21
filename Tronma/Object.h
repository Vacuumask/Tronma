#pragma once
#include<graphics.h>
#include<windows.h>
#include<iostream>

#include"Animation.h"

class Object {
public:
	Object() = default;
	virtual ~Object() = 0;
protected:
	Animation* animation = NULL;
};