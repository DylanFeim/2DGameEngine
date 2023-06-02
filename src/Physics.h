#pragma once


class Physics {
public:

	Physics();
	~Physics();

	void move(Character* chr, bool w, bool a, bool s, bool d);
	void dash(Character* chr);
};