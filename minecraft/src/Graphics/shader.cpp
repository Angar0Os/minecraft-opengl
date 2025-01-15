#include <Graphics/shader.h>

#include <iostream>
#include <sstream>
#include <fstream>

#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

using namespace engine::graphics;

Shader::Shader()
{

}

Shader::~Shader()
{
	glDeleteShader(m_shader);
}

void Shader::ReadAndCompileShader()
{
	std::string vertexCode;
	std::string fragmentCode;

	std::ifstream vShaderFile;
	std::ifstream fShaderFile;

	vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		fShaderFile.open(fragment_shader_path);
		vShaderFile.open(vertex_shader_path);

		std::stringstream vShaderStream, fShaderStream;

		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();

		vShaderFile.close();
		fShaderFile.close();

		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
		__debugbreak();
	}

	m_vertex_shader = vertexCode.c_str();
	m_fragment_shader = fragmentCode.c_str();

	RecompileShader();
}

void Shader::RecompileShader()
{
	if (!m_vertex_shader.empty() && !m_fragment_shader.empty())
	{
		m_shader = CreateShaderProgram(m_vertex_shader, m_fragment_shader);
	}
	glUseProgram(m_shader);
}

GLuint Shader::CreateShaderProgram(const std::string& vertexSource, const std::string& fragmentSource)
{
	GLuint vertexShader = CompileShader(GL_VERTEX_SHADER, vertexSource);
	GLuint fragmentShader = CompileShader(GL_FRAGMENT_SHADER, fragmentSource);

	if (vertexShader == 0 || fragmentShader == 0)
	{
		return 0;
	}

	GLuint shaderProgram = glCreateProgram();

	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	glValidateProgram(shaderProgram);
	
	GLint success;
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

	if (!success)
	{
		GLint logLength;

		glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &logLength);
		std::vector<char> log(logLength);

		glGetProgramInfoLog(shaderProgram, logLength, &logLength, log.data());
		std::cerr << "Program linking failed : \n" << log.data() << std::endl;

		glDeleteProgram(shaderProgram);
		return 0;
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	return shaderProgram;
}

GLuint Shader::CompileShader(GLenum shaderType, const std::string& source)
{
	GLuint shader = glCreateShader(shaderType);
	const char* sourceCStr = source.c_str();

	glShaderSource(shader, 1, &sourceCStr, nullptr);
	glCompileShader(shader);

	GLint success;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		GLint logLength;

		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);
		std::vector<char> log(logLength);

		glGetProgramInfoLog(shader, logLength, &logLength, log.data());
		std::cerr << "Shader Compilation Failed : \n" << log.data() << std::endl;

		glDeleteShader(shader);

		return 0;
	}

	return shader;
}

unsigned int Shader::GetShaderProgram()
{ 
	return m_shader;
}

void Shader::SetInt(const std::string& name, int value)
{
	glUniform1i(glGetUniformLocation(m_shader, name.c_str()), value);
}

void Shader::SetMat4(const std::string& name, const glm::mat4& mat)
{
	glUniformMatrix4fv(glGetUniformLocation(m_shader, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
