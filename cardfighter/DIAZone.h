#pragma once
#include "Zone.h"

class DIAZone : public Zone
{
public:

	void set_size_percent(float new_percent);

protected:
	float size_percent;
};