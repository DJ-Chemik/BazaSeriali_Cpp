#pragma once
#include "Serial.h"
class Nieśledzony :
	public Serial
{
public:
	Nieśledzony();
	void zacznij_śledzić();
	virtual ~Nieśledzony();
};

