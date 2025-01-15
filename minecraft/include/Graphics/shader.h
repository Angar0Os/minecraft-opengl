#ifndef MINECRAFT__ENGINE_GRAPHICS_SHADER_H
#define MINECRAFT__ENGINE_GRAPHICS_SHADER_H
#pragma once

#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

namespace engine::graphics
{
	class Shader 
	{
	private:
		unsigned int m_shader;

		std::string m_vertex_shader;
		std::string m_fragment_shader;

		GLuint	CompileShader(GLenum shaderType, const std::string& source);

	public:
		explicit Shader();
		~Shader() noexcept;

		std::string fragment_shader_path	= "../assets/ShaderFiles/shader.fs";
		std::string vertex_shader_path		= "../assets/ShaderFiles/shader.vs";

		void RecompileShader();
		void ReadAndCompileShader();

		GLuint CreateShaderProgram(const std::string& vertexSource, const std::string& fragmentSource);
		unsigned int GetShaderProgram();

		void SetInt(const std::string& name, int value);
		void SetMat4(const std::string& name, const glm::mat4& mat);
	};
}

#endif //MINECRAFT__ENGINE_GRAPHICS_SHADER_H

