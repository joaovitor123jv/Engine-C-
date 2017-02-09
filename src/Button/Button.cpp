#include "Button.hpp"

//Constructor
Button::Button()
{
	this->setDefaultValues();
}


//Destructor
Button::~Button()
{
	if(this->window != NULL)
	{
		this->window = NULL;
	}
}

//Setters
void Button::setDefaultValues()
{
	this->outsideColor = {0, 255, 255, 255};
	this->insideColor = {255, 0, 255, 255};
	this->clickColor = {255, 255, 0, 255};
	this->rectangle.setColor(outsideColor);
	this->text.setFont("font/default.ttf", 30);
	this->text.setText("Button");
	this->rectangle.setSize(this->text.getWidth(), this->text.getHeight());
	this->window == NULL;
	this->showLogs = false;
}


void Button::setWindow(Window* window)
{
	if(window == NULL)
	{
		if(this->showLogs)
		{
			cout<<"On: Button setWindow(Window* window)"<<endl;
			cout<<"\tERROR: Window* == NULL, aborting"<<endl;
		}
		return;
	}
	this->window = window;
	this->text.setWindow(this->window);
	this->text.update();
}

void Button::setText(string text) { this->text.setText(text); this->rectangle.setSize(this->text.getWidth(), this->text.getHeight()); }

void Button::setPosition(int x, int y) { this->text.setPosition(x, y); this->rectangle.setPosition(x,y); }

void Button::setSize(int size) { this->text.setFontSize(size); this->rectangle.setSize(this->text.getWidth(), this->text.getHeight()); }

void Button::setLogs(bool showLogs) { this->showLogs = showLogs; }

void Button::setInsideColor()
{
	this->rectangle.setColor(this->insideColor);
}
void Button::setOutsideColor()
{
	this->rectangle.setColor(this->outsideColor);
}
void Button::setClickColor()
{
	this->rectangle.setColor(this->clickColor);
}


void Button::setInsideColor(int r, int g, int b)
{
	this->insideColor.r = r;
	this->insideColor.g = g;
	this->insideColor.b = b;
}

void Button::setOutsideColor(int r, int g, int b)
{
	this->outsideColor.r = r;
	this->outsideColor.g = g;
	this->outsideColor.b = b;
}

void Button::setClickColor(int r, int g, int b)
{
	this->clickColor.r = r;
	this->clickColor.g = g;
	this->clickColor.b = b;
}

void Button::setOutsideColor(SDL_Color color)
{
	this->outsideColor = color;
}

void Button::setInsideColor(SDL_Color color)
{
	this->insideColor = color;
}

void Button::setClickColor(SDL_Color color)
{
	this->clickColor = color;
}



//Commands
bool Button::listener()
{
	if(this->window == NULL)
	{
		if(this->showLogs)
		{
			cout<<"On: Button listener()"<<endl;
			cout<<"\tERROR: window to listen, not specified yet, aborting"<<endl;
		}
		return false;
	}
	int x, y;
	this->window->getCursorPosition(&x,&y);
	if(x < this->rectangle.getX())
	{
		this->setOutsideColor();
		return false;
	}
	if(x > this->rectangle.getX()+this->rectangle.getWidth())
	{
		this->setOutsideColor();
		return false;
	}
	if(y < this->rectangle.getY())
	{
		this->setOutsideColor();
		return false;
	}
	if(y > this->rectangle.getY()+this->rectangle.getHeight())
	{
		this->setOutsideColor();
		return false;
	}
	if(!this->window->getMouseButtonDown())
	{
		this->setInsideColor();
		return false;
	}
	if(this->window->getMouseButtonDown())
	{
		this->setClickColor();
		return true;
	}
	return false;
}

void Button::print()
{
	this->rectangle.printFilled(this->window);
	this->text.print();
}