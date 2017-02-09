#pragma once
#include <SDL2/SDL.h>
#include <string>
#include <iostream>

class Window
{
	SDL_Window* window;
	std::string title;
	SDL_Event event;
	SDL_Point cursor;
	SDL_Renderer* renderer;
	unsigned int width;
	unsigned int height;
	bool showDecoration;
	bool showWindow;
	bool showLogs;
	bool autoUpdate;
	bool fullScreen;
	SDL_Color color;


	bool mouseButtonDown;

	//Methods
	void setDefaultValues();

public:
	//Constructors
	Window();
	Window(int width, int height);
	Window(std::string title, int width, int height);

	//Destructors
	~Window();

	//Setters
	bool setSize(unsigned int width, unsigned int height);
	bool setVisible(bool showWindow);
	bool setDecoration(bool showDecoration);//working
	bool setTitle(std::string title);//working
	bool setDrawColor(SDL_Color color);
	bool setAutoUpdate(bool autoUpdate);
	bool setLogs(bool showLogs);
	bool setFullScreen(bool fullScreen);
	void setDefaultRenderColor();

	//Getters
	unsigned int getWidth();
	unsigned int getHeight();
	
	int getCursorXPosition();
	int getCursorYPosition();

	bool getEvent();
	bool getCursorPosition(int *x, int *y);
	bool getMouseButtonDown();
	bool getMouseButtonUp();
	bool getMouseClick();
	bool getMouseRelease();
	bool getKeyDown();
	bool getKeyUp();
	bool getExit();
	bool getClose();

	SDL_Keycode getKey();
	SDL_Renderer* getRenderer();
	SDL_Window* getWindow();

	//Commands
	bool upgrade();
	bool update();
};