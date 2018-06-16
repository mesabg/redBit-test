#include <ConcreteRenderController.h>

double ConcreteRenderController::lastFrameTime = ConcreteRenderController::getCurrentTime();
double ConcreteRenderController::delta = 0.0f;

ConcreteRenderController::ConcreteRenderController() {
	this->gui = GUI::Instance(this);
	//-- this->stage = Stage::Instance(this);
}

ConcreteRenderController::ConcreteRenderController(const float width, const float height) {
	//-- Initializing complete GUI 
	this->gui = GUI::Instance(this, (int)width, (int)height);
	this->listGraphicsResources();
	//-- this->sideBar = SideBar::Instance(this);

	//-- Initializing Stage
	/*this->stage = Stage::Instance(this);
	this->stage->Notify("InitSideBar", NULL);
	this->stage->Notify("width/height", (void*)(new float[2]{ width, height }));
	this->stage->Notify("init VBOs", NULL);
	this->stage->Notify("shader id", (void*)this->illuminationProgram->getProgramID());
	this->stage->Notify("shader id2", (void*)this->illuminationProgram2->getProgramID());*/

	//-- Reshape screen
	this->gui->reshape(this->gui->getWindow(), (int)width, (int)height);
	//-- this->sideBar->reshape((int)width, (int)height);
}

ConcreteRenderController::~ConcreteRenderController() {
	//-- Kill Everything
}

void ConcreteRenderController::Send(string message, void* data, RenderColleague* renderColleague) {
	if (message == "Reshape" && renderColleague == this->gui) {
		//this->stage->getProjection()->setAspectRatio(((float*)data)[0] / ((float*)data)[1]);
		//this->sideBar->reshape((int)((float*)data)[0], (int)((float*)data)[1]);
	}

	//-- Main Object Initializing
	/*if (message == "MainObject" && renderColleague == this->stage) {
		this->sideBar->setSelectModelTarget(this->stage->getSelectedModelIndex());
		this->sideBar->setSelectLightTarget(this->stage->getSelectedLightIndex());
		this->sideBar->bindPrincipal();
	}*/

	//-- Event processing
	/*if (message == "eventKeyPressed" && renderColleague == this->gui)
		this->stage->Notify(message, data);

	if (message == "eventScroll" && renderColleague == this->gui)
		this->stage->Notify(message, data);

	if (message == "mouseButton" && renderColleague == this->gui)
		this->stage->Notify(message, data);*/

	//-- Options
	/*if (message == "SendSelectedModelProperties" && renderColleague == this->sideBar)
		this->sideBar->setModel(this->stage->getSelectedModel());

	if (message == "SendSelectedLightProperties" && renderColleague == this->sideBar)
		this->sideBar->setModel(this->stage->getSelectedLight());

	//-- Animation
	if (message == "Animate" && renderColleague == this->sideBar)
		this->stage->Notify(message, data);*/
}

void ConcreteRenderController::render() {
	glClearColor(0.2f, 0.2f, 0.2f, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//-- Update Side Bar
	//-- this->sideBar->update();

	double currentFrameTime = getCurrentTime();
	delta = (currentFrameTime - lastFrameTime) / 1000.0f;
	lastFrameTime = currentFrameTime;
}

void ConcreteRenderController::listGraphicsResources() {
	/*Graphic Card Info*/
	std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
	std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
}


double ConcreteRenderController::getCurrentTime() {
	return glfwGetTime() * 1000/*/glfwGetTimerValue()*/;
}

double ConcreteRenderController::getFrameTimeSeconds() {
	return delta;
}

int ConcreteRenderController::infinity() {
	while (!glfwWindowShouldClose(this->gui->getWindow())) {
		this->render();
		glfwSwapBuffers(this->gui->getWindow());
		glfwPollEvents();
	}
	return EXIT_SUCCESS;
}

int ConcreteRenderController::finish() {
	this->gui->Destroy();
	//-- this->sideBar->Destroy();
	return EXIT_SUCCESS;
}