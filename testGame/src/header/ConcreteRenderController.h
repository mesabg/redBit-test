#pragma once
#ifndef __CONCRETE_RENDER_CONTROLLER_H_
#define __CONCRETE_RENDER_CONTROLLER_H_

//-- Class Includes
#include <RenderInterface.h>
#include <GUI.h>
#include <iostream>
//-- #include <Stage.h>
//-- #include <SideBar.h>

class ConcreteRenderController : public RenderController
{
private:
	//-- All Instances of Colleagues
	//-- Stage * stage;
	//-- SideBar * sideBar;
	GUI* gui;

	//-- Functions
	void render();
public:
	static double lastFrameTime;
	static double delta;
	static double getCurrentTime();
	static double getFrameTimeSeconds();

	ConcreteRenderController();
	ConcreteRenderController(const float width, const float height);
	~ConcreteRenderController();

	//-- Override
	void Send(string message, void* data, RenderColleague* colleague);

	//-- Initializing functions
	void listGraphicsResources();

	//-- Play and Pause
	int finish();
	int infinity();
};

#endif