#pragma once
#include <SDL2/SDL.h>
#include "../Rectangle/Rectangle.hpp"
#include "../Window/Window.hpp"
#include "../Text/Text.hpp"

class Button
{
private:
	Text text;
	Rectangle rectangle;
	SDL_Color outsideColor;
	SDL_Color insideColor;
	SDL_Color clickColor;
	Window* window;
	bool showLogs;

	void setDefaultValues();
	void setInsideColor();
	void setOutsideColor();
	void setClickColor();
public:
	//Constructor
	Button();
	//Destructor
	~Button();

	//Setters
	void setWindow(Window* window);
	void setText(string text);
	void setSize(int size);
	void setPosition(int x, int y);
	void setLogs(bool showLogs);

	void setInsideColor(int r, int g, int b);
	void setOutsideColor(int r, int g, int b);
	void setClickColor(int r, int g, int b);

	void setInsideColor(SDL_Color color);
	void setOutsideColor(SDL_Color color);
	void setClickColor(SDL_Color color);

	//Commands
	bool listener();
	void print();
};