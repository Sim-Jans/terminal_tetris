#pragma once


class Data {
	private:
		int x;
		int y;
	public:
		Data(int x, int y);
		~Data();
		int setX(int x);
		int getX();
		int setY(int y);
		int getY();
		int run();
};