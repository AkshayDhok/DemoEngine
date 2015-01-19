#include "GraphicsSystem.h"
#include <string.h>
#include "ShaderUtil.h"
#include <glm/gtc/matrix_transform.hpp>

// initialize singleton static instance to GraphicsSystem
GraphicsSystem* GraphicsSystem::pGraphics = NULL;

/*!
* getGraphics
* \brief :Method responsible for providing singleton
* instance of graphics system.
* \return: GraphicsSystem*
*/
GraphicsSystem* GraphicsSystem::getGraphics()
{
	if (!pGraphics) {
		pGraphics = new GraphicsSystem();
	}
	return pGraphics;
}

/*!
 * GraphicsSystem
 * \brief :Constructor.
 * \param[in] sf::RenderWindow * window
 * \return 
 */
GraphicsSystem::GraphicsSystem()
{
}


GraphicsSystem::~GraphicsSystem()
{
}

/*!
* Init
* \brief :Method is responsible for initializing the openGl.
* here we load all the textures and create mesh just once and use it
* in update.
* \return void
*/
void GraphicsSystem::setWindow(GLFWwindow *window_context)
{
	pWindow = window_context;
}

/*!
 * Init
 * \brief :Method is responsible for initializing the openGl.
 * here we load all the textures and create mesh just once and use it
 * in update.
 * \return void
 */
void GraphicsSystem::Init()
{
	glewExperimental = true; // Needed in core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return;
	}

	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);

	// Create and compile GLSL program from the shaders
	GLuint programID = LoadShaders("Source/VertexShader.glsl", "Source/FragmentShader.glsl");
	glClearColor(0.0f, 0.4f, 0.4f, 0.0f);

	// Projection matrix
	glm::mat4 Projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
	// Camera matrix
	glm::mat4 View = glm::lookAt(
		glm::vec3(4, 3, 3), // Camera is at (4,3,3), in World Space
		glm::vec3(0, 0, 0), // and looks at the origin
		glm::vec3(0, 1, 0)  // Head is up
		);

	// Model matrix : model will be at the origin
	glm::mat4 Model = glm::mat4(1.0f);  // Changes for each model !

	glm::mat4 MVP = Projection * View * Model; // order is important

	// Get a handle for our "MVP" uniform of shader.
	GLuint MatrixID = glGetUniformLocation(programID, "MVP");

	// Use our shader
	glUseProgram(programID);

	// Send our transformation to the currently bound shader,
	// in the "MVP" uniform
	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

	//todo remove it from here - object creation
	spriteArray.push_back(new Sprite());

	//initialize all the sprite components
	for (unsigned int i = 0; i < spriteArray.size(); ++i)
	{
		spriteArray[i]->Initialize();
	}
}

/*!
 * Update
 * \brief :Method is called every frame by game engine. Here we go through
 * the array of sprite component. pick one component and draw it on screen.
 * \param[in] float deltaTime
 * \return void
 */
void GraphicsSystem::Update(float deltaTime)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for each (Sprite *sprite in spriteArray)
	{
		sprite->Draw();
	}


}

/*!
 * OnMsgEvent
 * \brief :Method is responsible for collecting the broadcast events of engine.
 * \param[in] Msg msg
 * \return void
 */
void GraphicsSystem::OnMsgEvent(Msg msg)
{
	
}