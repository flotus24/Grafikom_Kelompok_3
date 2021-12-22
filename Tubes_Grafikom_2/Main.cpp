#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<stb/stb_image.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

#include"Texture.h"
#include"shaderClass.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"
#include"Camera.h"



const unsigned int width = 1366;
const unsigned int height = 768;



// Vertices coordinates
GLfloat vertices[] =
{ // BANGUNAN DENGAN TEXTURE
		//     COORDINATES     /        COLORS      /   TexCoord  /			Normal			//
	// BANGUNAN 1
	 //SISI ALAS
	-0.35f, -0.40f,  0.35f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,		0.0f, 0.0f,  0.0f,
	 0.35f, -0.40f,  0.35f,     0.83f, 0.70f, 0.44f,	1.0f, 0.0f,		0.0f, 0.0f,  0.1f,
	 0.35f, -0.40f, -0.35f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,		0.0f, 0.0f,  0.0f,
	-0.35f, -0.40f, -0.35f,     0.83f, 0.70f, 0.44f,	1.0f, 0.0f,		0.0f, 0.0f,  0.0f,

	//SISI ATAP
   -0.35f, 0.6f,  0.35f,		0.83f, 0.70f, 0.44f,	0.0f, 1.0f,		0.0f, 0.0f,  0.0f,
	0.35f, 0.6f,  0.35f,		0.83f, 0.70f, 0.44f,	1.0f, 1.0f,		0.0f, 0.0f,  0.1f,
	0.35f, 0.6f, -0.35f,		0.83f, 0.70f, 0.44f,	0.0f, 1.0f,		0.0f, 0.0f,  0.0f,
   -0.35f, 0.6f, -0.35f,		0.83f, 0.70f, 0.44f,	1.0f, 1.0f,		0.0f, 0.0f,  0.0f,

   // BANGUNAN 2
   //SISI ALAS
   -0.25f, 0.6f,  0.25f,		0.83f, 0.70f, 0.44f,	0.0f, 0.0f,		0.0f, 0.0f,  0.0f,
	0.25f, 0.6f,  0.25f,		0.83f, 0.70f, 0.44f,	0.5f, 0.0f,		0.0f, 0.0f,  0.1f,
	0.25f, 0.6f, -0.25f,		0.83f, 0.70f, 0.44f,	0.0f, 0.0f,		0.0f, 0.0f,  0.0f,
   -0.25f, 0.6f, -0.25f,		0.83f, 0.70f, 0.44f,	0.5f, 0.0f,		0.0f, 0.0f,  0.0f,

   //SISI ATAP
   -0.25f, 1.1f,  0.25f,		0.83f, 0.70f, 0.44f,	0.0f, 0.5f,		0.0f, 0.0f,  0.0f,
	0.25f, 1.1f,  0.25f,		0.83f, 0.70f, 0.44f,	0.5f, 0.5f,		0.0f, 0.0f,  0.1f,
	0.25f, 1.1f, -0.25f,		0.83f, 0.70f, 0.44f,	0.0f, 0.5f,		0.0f, 0.0f,  0.0f,
   -0.25f, 1.1f, -0.25f,		0.83f, 0.70f, 0.44f,	0.5f, 0.5f,		0.0f, 0.0f,  0.0f,

   // BANGUNAN 3
   //SISI ATAP
	-0.10f, 1.35f,  0.10f,		0.83f, 0.70f, 0.44f,	0.0f, 0.5f,		0.8f, 0.5f,  0.8f,
	 0.10f, 1.35f,  0.10f,		0.83f, 0.70f, 0.44f,	0.5f, 0.5f,		0.8f, 0.5f,  0.8f,
	 0.10f, 1.35f, -0.10f,		0.83f, 0.70f, 0.44f,	0.0f, 0.5f,		0.8f, 0.5f,  0.8f,
	-0.10f, 1.35f, -0.10f,		0.83f, 0.70f, 0.44f,	0.5f, 0.5f,		0.8f, 0.5f,  0.8f


};

// Indices for vertices order
GLuint indices[] =
{
	//BANGUNAN 1
	0, 1, 4,
	0, 3, 4,
	1, 4, 5,
	1, 2, 5,
	2, 5, 6,
	2, 3, 6,
	3, 6, 7,
	3, 4, 7,
	4, 5, 7,
	5, 6, 7,

	//BANGUNAN 2
	8, 9, 12,
	8, 11, 12,
	9, 12, 13,
	9, 10, 13,
	10, 13, 14,
	10, 11, 14,
	11, 14, 15,
	11, 12, 15,
	12, 13, 15,
	13, 14, 15,

	//BANGUNAN 3
	16, 17, 19,
	17, 18, 19

};

GLfloat vertices2[] = {
	//RUMPUT KIRI
	-1.55f, -0.40f,  0.55f,     0.00f, 0.10f, 0.00f,		0.0f, 0.0f,		0.0f, 0.0f,  0.1f,
	-0.55f, -0.40f,  0.55f,     0.00f, 0.10f, 0.00f,		9.0f, 0.0f,		0.0f, 0.0f,  0.0f,
	-0.55f, -0.40f, -0.55f,     0.00f, 0.10f, 0.00f,		0.0f, 9.0f,		0.0f, 0.0f,  0.0f,
	-1.55f, -0.40f, -0.55f,     0.00f, 0.10f, 0.00f,		9.0f, 9.0f,		0.0f, 0.0f,  0.1f,
			
	//RUMPUT KANAN
	 0.55f, -0.40f,  0.55f,     0.00f, 0.10f, 0.00f,		0.0f, 0.0f,		0.0f, 0.0f,  0.1f,
	 1.55f, -0.40f,  0.55f,     0.00f, 0.10f, 0.00f,		9.0f, 0.0f,		0.0f, 0.0f,  0.0f,
	 1.55f, -0.40f, -0.55f,     0.00f, 0.10f, 0.00f,		0.0f, 9.0f,		0.0f, 0.0f,  0.0f,
	 0.55f, -0.40f, -0.55f,     0.00f, 0.10f, 0.00f,		9.0f, 9.0f,		0.0f, 0.0f,  0.1f

};

GLuint indices2[] = {
	//RUMPUT KIRI
	0, 1, 3,
	1, 2, 3,

	//RUMPUT KANAN
	4, 5, 7,
	5, 6, 7

};

GLfloat vertices3[] = {
	//LAHAN BANGUNAN
	-0.55f, -0.40f,  0.55f,     0.83f, 0.10f, 0.64f,		0.0f, 0.0f,		0.0f, 0.0f,  0.0f, 
	 0.55f, -0.40f,  0.55f,     0.83f, 0.10f, 0.64f,		3.0f, 0.0f,		0.0f, 0.0f,  0.1f,
	 0.55f, -0.40f, -0.55f,     0.83f, 0.10f, 0.64f,		0.0f, 3.0f,		0.0f, 0.0f,  0.0f,
	-0.55f, -0.40f, -0.55f,     0.83f, 0.10f, 0.64f,		3.0f, 3.0f,		0.0f, 0.0f, -0.025f

};

GLuint indices3[] = {
	//LAHAN BANGUNAN
	0, 1, 3,
	1, 2, 3

};

GLfloat vertices4[] = {
	//JALAN
	-1.55f, -0.40f,  1.55f,     0.83f, 0.10f, 0.64f,		0.0f, 0.0f,		 0.0f, 0.5f,  0.3f,
	 1.55f, -0.40f,  1.55f,     0.83f, 0.10f, 0.64f,		3.0f, 0.0f,		 0.0f, 0.5f,  0.4f,
	 1.55f, -0.40f,  0.55f,     0.83f, 0.10f, 0.64f,		0.0f, 3.0f,		 0.0f, 0.5f,  0.4f,
	-1.55f, -0.40f,  0.55f,     0.83f, 0.10f, 0.64f,		3.0f, 3.0f,		 0.0f, 0.5f,  0.4f

};

GLuint indices4[] = {
	//JALAN
	0, 1, 3,
	1, 2, 3

};

GLfloat vertices5[] = {
   // BANGUNAN 3
   //SISI ALAS
   -0.17f, 1.1f,  0.17f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,		0.0f, 0.0f,  0.0f,
	0.17f, 1.1f,  0.17f,     0.83f, 0.70f, 0.44f,	1.0f, 0.0f,		0.0f, 0.0f,  0.1f,
	0.17f, 1.1f, -0.17f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,		0.0f, 0.0f,  0.0f,
   -0.17f, 1.1f, -0.17f,     0.83f, 0.70f, 0.44f,	1.0f, 0.0f,		0.0f, 0.0f,  0.0f,

   //SISI ATAP
   -0.10f, 1.35f,  0.10f,     0.83f, 0.70f, 0.44f,	0.0f, 1.0f,		0.0f, 0.0f,  0.0f,
	0.10f, 1.35f,  0.10f,     0.83f, 0.70f, 0.44f,	1.0f, 1.0f,		0.0f, 0.0f,  0.1f,
	0.10f, 1.35f, -0.10f,     0.83f, 0.70f, 0.44f,	0.0f, 1.0f,		0.0f, 0.0f,  0.0f,
   -0.10f, 1.35f, -0.10f,     0.83f, 0.70f, 0.44f,	1.0f, 1.0f,		0.0f, 0.0f,  0.0f

};

GLuint indices5[] = {
		//BANGUNAN 3
	0, 1, 4,
	0, 3, 4,
	1, 4, 5,
	1, 2, 5,
	2, 5, 6,
	2, 3, 6,
	3, 6, 7,
	3, 4, 7

};

GLfloat lightVertices[] =
{ //     COORDINATES     //
	 1.3f,  1.5f,  1.1f,
	 1.3f,  1.5f,  1.0f,
	 1.5f,  1.5f,  1.0f,
	 1.5f,  1.5f,  1.1f,
	 1.3f,  1.4f,  1.1f,
	 1.3f,  1.4f,  1.0f,
	 1.5f,  1.4f,  1.0f,
	 1.5f,  1.4f,  1.1f
};

GLuint lightIndices[] =
{
	0, 1, 2,
	0, 2, 3,
	0, 4, 7,
	0, 7, 3,
	3, 7, 6,
	3, 6, 2,
	2, 6, 5,
	2, 5, 1,
	1, 5, 4,
	1, 4, 0,
	4, 5, 6,
	4, 6, 7
};


int main()
{
	// Initialize GLFW
	glfwInit();

	// Tell GLFW what version of OpenGL we are using 
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a GLFWwindow object of 800 by 800 pixels, naming it "YoutubeOpenGL"
	GLFWwindow* window = glfwCreateWindow(width, height, "Tubes Grafikom", NULL, NULL);
	// Error check if the window fails to create
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);

	//Load GLAD so it configures OpenGL
	gladLoadGL();
	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
	glViewport(0, 0, width, height);


	// Generates Shader object using shaders default.vert and default.frag
	Shader shaderProgram("default.vert", "default.frag");
	// Generates Vertex Array Object and binds it
	VAO VAO1;
	VAO1.Bind();
	// Generates Vertex Buffer Object and links it to vertices
	VBO VBO1(vertices, sizeof(vertices));
	// Generates Element Buffer Object and links it to indices
	EBO EBO1(indices, sizeof(indices));
	// Links VBO attributes such as coordinates and colors to VAO
	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 11 * sizeof(float), (void*)0);
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 11 * sizeof(float), (void*)(3 * sizeof(float)));
	VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 11 * sizeof(float), (void*)(6 * sizeof(float)));
	VAO1.LinkAttrib(VBO1, 3, 3, GL_FLOAT, 11 * sizeof(float), (void*)(8 * sizeof(float)));
	// Unbind all to prevent accidentally modifying them
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();


	// Generates Shader object using shaders default.vert and default.frag
	Shader plainShader("default.vert", "default.frag");
	// Generates Vertex Array Object and binds it
	VAO VAO2;
	VAO2.Bind();
	// Generates Vertex Buffer Object and links it to vertices
	VBO VBO2(vertices2, sizeof(vertices2));
	// Generates Element Buffer Object and links it to indices
	EBO EBO2(indices2, sizeof(indices2));
	// Links VBO attributes such as coordinates and colors to VAO
	VAO2.LinkAttrib(VBO2, 0, 3, GL_FLOAT, 11 * sizeof(float), (void*)0);
	VAO2.LinkAttrib(VBO2, 1, 3, GL_FLOAT, 11 * sizeof(float), (void*)(3 * sizeof(float)));
	VAO2.LinkAttrib(VBO2, 2, 2, GL_FLOAT, 11 * sizeof(float), (void*)(6 * sizeof(float)));
	VAO2.LinkAttrib(VBO2, 3, 3, GL_FLOAT, 11 * sizeof(float), (void*)(8 * sizeof(float)));
	// Unbind all to prevent accidentally modifying them
	VAO2.Unbind();
	VBO2.Unbind();
	EBO2.Unbind();

	// Generates Shader object using shaders default.vert and default.frag
	Shader landShader("default.vert", "default.frag");
	// Generates Vertex Array Object and binds it
	VAO VAO3;
	VAO3.Bind();
	// Generates Vertex Buffer Object and links it to vertices
	VBO VBO3(vertices3, sizeof(vertices3));
	// Generates Element Buffer Object and links it to indices
	EBO EBO3(indices3, sizeof(indices3));
	// Links VBO attributes such as coordinates and colors to VAO
	VAO3.LinkAttrib(VBO3, 0, 3, GL_FLOAT, 11 * sizeof(float), (void*)0);
	VAO3.LinkAttrib(VBO3, 1, 3, GL_FLOAT, 11 * sizeof(float), (void*)(3 * sizeof(float)));
	VAO3.LinkAttrib(VBO3, 2, 2, GL_FLOAT, 11 * sizeof(float), (void*)(6 * sizeof(float)));
	VAO3.LinkAttrib(VBO3, 3, 3, GL_FLOAT, 11 * sizeof(float), (void*)(8 * sizeof(float)));
	// Unbind all to prevent accidentally modifying them
	VAO3.Unbind();
	VBO3.Unbind();
	EBO3.Unbind();

	// Generates Shader object using shaders default.vert and default.frag
	Shader roadShader("default.vert", "default.frag");
	// Generates Vertex Array Object and binds it
	VAO VAO4;
	VAO4.Bind();
	// Generates Vertex Buffer Object and links it to vertices
	VBO VBO4(vertices4, sizeof(vertices4));
	// Generates Element Buffer Object and links it to indices
	EBO EBO4(indices4, sizeof(indices4));
	// Links VBO attributes such as coordinates and colors to VAO
	VAO4.LinkAttrib(VBO4, 0, 3, GL_FLOAT, 11 * sizeof(float), (void*)0);
	VAO4.LinkAttrib(VBO4, 1, 3, GL_FLOAT, 11 * sizeof(float), (void*)(3 * sizeof(float)));
	VAO4.LinkAttrib(VBO4, 2, 2, GL_FLOAT, 11 * sizeof(float), (void*)(6 * sizeof(float)));
	VAO4.LinkAttrib(VBO4, 3, 3, GL_FLOAT, 11 * sizeof(float), (void*)(8 * sizeof(float)));
	// Unbind all to prevent accidentally modifying them
	VAO4.Unbind();
	VBO4.Unbind();
	EBO4.Unbind();

	// Generates Shader object using shaders default.vert and default.frag
	Shader roofShader("default.vert", "default.frag");
	// Generates Vertex Array Object and binds it
	VAO VAO5;
	VAO5.Bind();
	// Generates Vertex Buffer Object and links it to vertices
	VBO VBO5(vertices5, sizeof(vertices5));
	// Generates Element Buffer Object and links it to indices
	EBO EBO5(indices5, sizeof(indices5));
	// Links VBO attributes such as coordinates and colors to VAO
	VAO5.LinkAttrib(VBO5, 0, 3, GL_FLOAT, 11 * sizeof(float), (void*)0);
	VAO5.LinkAttrib(VBO5, 1, 3, GL_FLOAT, 11 * sizeof(float), (void*)(3 * sizeof(float)));
	VAO5.LinkAttrib(VBO5, 2, 2, GL_FLOAT, 11 * sizeof(float), (void*)(6 * sizeof(float)));
	VAO5.LinkAttrib(VBO5, 3, 3, GL_FLOAT, 11 * sizeof(float), (void*)(8 * sizeof(float)));
	// Unbind all to prevent accidentally modifying them
	VAO5.Unbind();
	VBO5.Unbind();
	EBO5.Unbind();

	// Shader for light cube
	Shader lightShader("light.vert", "light.frag");
	// Generates Vertex Array Object and binds it
	VAO lightVAO;
	lightVAO.Bind();
	// Generates Vertex Buffer Object and links it to vertices
	VBO lightVBO(lightVertices, sizeof(lightVertices));
	// Generates Element Buffer Object and links it to indices
	EBO lightEBO(lightIndices, sizeof(lightIndices));
	// Links VBO attributes such as coordinates and colors to VAO
	lightVAO.LinkAttrib(lightVBO, 0, 3, GL_FLOAT, 3 * sizeof(float), (void*)0);
	// Unbind all to prevent accidentally modifying them
	lightVAO.Unbind();
	lightVBO.Unbind();
	lightEBO.Unbind();


	glm::vec4 lightColor = glm::vec4(2.0f, 2.0f, 2.0f, 2.0f);	//0.5f, 0.5f, -0.5f
	glm::vec3 lightPos = glm::vec3(0.5f, 0.5f, 0.5f);			//1.5f, 1.5f, 1.5f
	glm::mat4 lightModel = glm::mat4(1.0f);
	lightModel = glm::translate(lightModel, lightPos);

	glm::vec3 pyramidPos = glm::vec3(-0.0f, -0.0f, -0.0f);		//-0.5, -0.5, -1.0
	glm::mat4 pyramidModel = glm::mat4(1.0f);
	pyramidModel = glm::translate(pyramidModel, pyramidPos);


	lightShader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(lightShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(lightModel));
	glUniform4f(glGetUniformLocation(lightShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	plainShader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(plainShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(pyramidModel));
	glUniform4f(glGetUniformLocation(plainShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(plainShader.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);
	shaderProgram.Activate();
	glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "model"), 1, GL_FALSE, glm::value_ptr(pyramidModel));
	glUniform4f(glGetUniformLocation(shaderProgram.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(shaderProgram.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);
	landShader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(landShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(pyramidModel));
	glUniform4f(glGetUniformLocation(landShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(landShader.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);
	roadShader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(roadShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(pyramidModel));
	glUniform4f(glGetUniformLocation(roadShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(roadShader.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);
	roofShader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(roofShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(pyramidModel));
	glUniform4f(glGetUniformLocation(roofShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(roofShader.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);

	Texture brickTex("skyscrap.bmp", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	Texture grassTex("grass.bmp", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE); //Photo by pixmike from Pexels
	Texture landTex("land3.bmp", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	Texture roadTex("road.bmp", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	Texture roofTex("glass.bmp", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);

	brickTex.texUnit(plainShader, "tex0", 0);
	grassTex.texUnit(shaderProgram, "tex0", 0);
	landTex.texUnit(landShader, "tex0", 0);
	roadTex.texUnit(roadShader, "tex0", 0);
	roofTex.texUnit(roofShader, "tex0", 0);
	

	// Enables the Depth Buffer
	glEnable(GL_DEPTH_TEST);

	// Creates camera object
	Camera camera(width, height, glm::vec3(0.0f, 0.0f, 2.0f));

	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		// Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Handles camera inputs
		camera.Inputs(window);
		// Updates and exports the camera matrix to the Vertex Shader
		camera.updateMatrix(30.0f, 0.1f, 100.0f);

		// Tells OpenGL which Shader Program we want to use
		shaderProgram.Activate();
		// Exports the camera Position to the Fragment Shader for specular lighting
		glUniform3f(glGetUniformLocation(shaderProgram.ID, "camPos"), camera.Position.x, camera.Position.y, camera.Position.z);
		// Export the camMatrix to the Vertex Shader of the pyramid
		camera.Matrix(shaderProgram, "camMatrix");
		// Binds texture so that is appears in rendering
		brickTex.Bind();
		// Bind the VAO so OpenGL knows to use it
		VAO1.Bind();
		// Draw primitives, number of indices, datatype of indices, index of indices
		glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);

		// Tells OpenGL which Shader Program we want to use
		plainShader.Activate();
		// Exports the camera Position to the Fragment Shader for specular lighting
		glUniform3f(glGetUniformLocation(plainShader.ID, "camPos"), camera.Position.x, camera.Position.y, camera.Position.z);
		// Export the camMatrix to the Vertex Shader of the light cube
		camera.Matrix(plainShader, "camMatrix");
		// Binds texture so that is appears in rendering
		grassTex.Bind();
		// Bind the VAO so OpenGL knows to use it
		VAO2.Bind();
		// Draw primitives, number of indices, datatype of indices, index of indices
		glDrawElements(GL_TRIANGLES, sizeof(indices2) / sizeof(int), GL_UNSIGNED_INT, 0);

		// Tells OpenGL which Shader Program we want to use
		landShader.Activate();
		// Exports the camera Position to the Fragment Shader for specular lighting
		glUniform3f(glGetUniformLocation(landShader.ID, "camPos"), camera.Position.x, camera.Position.y, camera.Position.z);
		// Export the camMatrix to the Vertex Shader of the light cube
		camera.Matrix(landShader, "camMatrix");
		// Binds texture so that is appears in rendering
		landTex.Bind();
		// Bind the VAO so OpenGL knows to use it
		VAO3.Bind();
		// Draw primitives, number of indices, datatype of indices, index of indices
		glDrawElements(GL_TRIANGLES, sizeof(indices3) / sizeof(int), GL_UNSIGNED_INT, 0);

		// Tells OpenGL which Shader Program we want to use
		roadShader.Activate();
		// Exports the camera Position to the Fragment Shader for specular lighting
		glUniform3f(glGetUniformLocation(roadShader.ID, "camPos"), camera.Position.x, camera.Position.y, camera.Position.z);
		// Export the camMatrix to the Vertex Shader of the light cube
		camera.Matrix(roadShader, "camMatrix");
		// Binds texture so that is appears in rendering
		roadTex.Bind();
		// Bind the VAO so OpenGL knows to use it
		VAO4.Bind();
		// Draw primitives, number of indices, datatype of indices, index of indices
		glDrawElements(GL_TRIANGLES, sizeof(indices4) / sizeof(int), GL_UNSIGNED_INT, 0);

		// Tells OpenGL which Shader Program we want to use
		roofShader.Activate();
		// Exports the camera Position to the Fragment Shader for specular lighting
		glUniform3f(glGetUniformLocation(roofShader.ID, "camPos"), camera.Position.x, camera.Position.y, camera.Position.z);
		// Export the camMatrix to the Vertex Shader of the light cube
		camera.Matrix(roofShader, "camMatrix");
		// Binds texture so that is appears in rendering
		roofTex.Bind();
		// Bind the VAO so OpenGL knows to use it
		VAO5.Bind();
		// Draw primitives, number of indices, datatype of indices, index of indices
		glDrawElements(GL_TRIANGLES, sizeof(indices5) / sizeof(int), GL_UNSIGNED_INT, 0);

		// Tells OpenGL which Shader Program we want to use
		lightShader.Activate();
		// Export the camMatrix to the Vertex Shader of the light cube
		camera.Matrix(lightShader, "camMatrix");
		// Bind the VAO so OpenGL knows to use it
		lightVAO.Bind();
		// Draw primitives, number of indices, datatype of indices, index of indices
		glDrawElements(GL_TRIANGLES, sizeof(lightIndices) / sizeof(int), GL_UNSIGNED_INT, 0);

		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}



	// Delete all the objects we've created
	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	shaderProgram.Delete();
	VAO2.Delete();
	VBO2.Delete();
	EBO2.Delete();
	plainShader.Delete();
	VAO3.Delete();
	VBO3.Delete();
	EBO3.Delete();
	landShader.Delete();
	VAO4.Delete();
	VBO4.Delete();
	EBO4.Delete();
	roadShader.Delete();
	VAO5.Delete();
	VBO5.Delete();
	EBO5.Delete();
	roofShader.Delete();
	brickTex.Delete();
	grassTex.Delete();
	landTex.Delete();
	roadTex.Delete();
	roofTex.Delete();
	lightVAO.Delete();
	lightVBO.Delete();
	lightEBO.Delete();
	lightShader.Delete();
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}