#include "WindowSystem.h"

/*!
 * WindowSystem
 * \brief :Constructor.
 * This is the main window component system which handles window creation and
 * event handling.
 * \param[in] const char * title
 * \param[in] unsigned int width
 * \param[in] unsigned int height
 */
WindowSystem::WindowSystem(unsigned int width, unsigned int height) :
window_width(width), window_height(height)
{
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		return;
	}
}

WindowSystem::~WindowSystem()
{
}

/*!
 * Init
 * \brief :Method is responsible for activating the context window.
 * \return void
 */
void WindowSystem::Init()
{
	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // For OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //We don't want the old OpenGL

	// Open a window and create its OpenGL context
	window = glfwCreateWindow(window_width, window_height, "", NULL, NULL);
	if (window == NULL){
		fprintf(stderr, "Failed to open window.\n");
		glfwTerminate();
		return;
	}

	glfwMakeContextCurrent(window); // Initialize GLEW

	// Capture the escape key being pressed.
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
}

/*!
 * Update
 * \brief :Method is responsible for handling the events. We send a broadcast
 * from here to the engine, which in turn sends the msg to all the systems.
 * \param[in] float deltaTime
 * \return void
 */
void WindowSystem::Update(float deltaTime)
{

	// Swap buffers
	glfwSwapBuffers(window);

	glfwPollEvents();
	// Check if the ESC key was pressed or the window was closed
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS ||
		glfwWindowShouldClose(window) == 1){
		GameEngine::GetEngine()->SendBroadCastMsg(Msg::msg_quit);
	}
}