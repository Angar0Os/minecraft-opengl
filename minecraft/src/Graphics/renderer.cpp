//#include <Graphics/renderer.h>
//#include <Graphics/shader.h>
//
//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//
//#include <iostream>
//
//#include <stb_image.h>
//
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//
//using namespace engine::graphics;
//
//Renderer::Renderer(uint32_t width, uint32_t height, Shader& shader)
//	: m_width(width), m_height(height)
//{
//	glEnable(GL_DEPTH_TEST);
//
//	float vertices[] = {
//		   -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//			0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
//			0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//			0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		   -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//		   -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//
//		   -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//			0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//			0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//			0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//		   -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
//		   -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//
//		   -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//		   -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//		   -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		   -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//		   -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//		   -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//			0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//			0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//			0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//			0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//			0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//			0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//		   -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//			0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
//			0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//			0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//		   -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//		   -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//
//		   -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//			0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//			0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//			0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//		   -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
//		   -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
//	};
//
//	glm::vec3 cubePositions[] = {
//		glm::vec3(0.0f,  0.0f,  0.0f),
//		glm::vec3(2.0f,  5.0f, -15.0f),
//		glm::vec3(-1.5f, -2.2f, -2.5f),
//		glm::vec3(-3.8f, -2.0f, -12.3f),
//		glm::vec3(2.4f, -0.4f, -3.5f),
//		glm::vec3(-1.7f,  3.0f, -7.5f),
//		glm::vec3(1.3f, -2.0f, -2.5f),
//		glm::vec3(1.5f,  2.0f, -2.5f),
//		glm::vec3(1.5f,  0.2f, -1.5f),
//		glm::vec3(-1.3f,  1.0f, -1.5f)
//	};
//
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//
//	glBindVertexArray(VAO);
//
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//
//	glGenTextures(1, &texture1);
//	glBindTexture(GL_TEXTURE_2D, texture1);
//
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//	int tex_width, tex_height, tex_nrChannels;
//
//	stbi_set_flip_vertically_on_load(true); 
//	unsigned char* data = stbi_load("../assets/Textures/container.jpg", &tex_width, &tex_height, &tex_nrChannels, 0);
//	if (data)
//	{
//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, tex_width, tex_height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//		glGenerateMipmap(GL_TEXTURE_2D);
//	}
//	else
//	{
//		std::cout << "Failed to load texture" << std::endl;
//	}
//	stbi_image_free(data);
//
//	glGenTextures(1, &texture2);
//	glBindTexture(GL_TEXTURE_2D, texture2);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//	data = stbi_load("../assets/Textures/awesomeface.png", &tex_width, &tex_height, &tex_nrChannels, 0);
//	if (data)
//	{
//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tex_width, tex_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
//		glGenerateMipmap(GL_TEXTURE_2D);
//	}
//	else
//	{
//		std::cout << "Failed to load texture" << std::endl;
//	}
//	stbi_image_free(data);
//
//	shader.RecompileShader();
//	shader.SetInt("texture1", 0);
//	shader.SetInt("texture2", 1);
//}
//
//void Renderer::Render(Shader& shader)
//{
//	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
//
//	glActiveTexture(GL_TEXTURE0);
//	glBindTexture(GL_TEXTURE_2D, texture1);
//	glActiveTexture(GL_TEXTURE1);
//	glBindTexture(GL_TEXTURE_2D, texture2);
//
//	shader.RecompileShader();
//
//	glm::mat4 view = glm::mat4(1.0f); 
//	glm::mat4 projection = glm::mat4(1.0f);
//	projection = glm::perspective(glm::radians(45.0f), (float)m_width / (float)m_height, 0.1f, 100.0f);
//	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
//	shader.SetMat4("projection", projection); 
//	shader.SetMat4("view", view);
//
//	glBindVertexArray(VAO);
//	for (unsigned int i = 0; i < 10; i++)
//	{
//		glm::mat4 model = glm::mat4(1.0f);
//		model = glm::translate(model, cubePositions[i]);
//		float angle = 20.0f * i;
//		model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
//		shader.SetMat4("model", model);
//
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//	}
//
//}
//
//
//Renderer::~Renderer()
//{
//	glDeleteVertexArrays(1, &VAO);
//	glDeleteBuffers(1, &VBO);
//	glDeleteBuffers(1, &EBO);
//}