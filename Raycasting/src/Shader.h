#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <string>
#include <fstream>

#include <unordered_map>

class Shader {
public:
	/* file must contain vertex and fragment shader
	- first line of vertex shader must be: #shader vertex
	- first line of fragment shader must be: #shader fragment 
	The file will be closed automatically in this function */
	Shader(std::ifstream& fileStream);

	// manually input vertex and fragent shaders as std::strings
	Shader(const std::string& vertexShader, const std::string& fragmentShader);

	// stores the id of an already initialized shader program
	Shader(GLuint existingShader);

	void setUniform1f(const std::string& uniformName, float  value);
	void setUniform2f(const std::string& uniformName, float* values);
	void setUniform3f(const std::string& uniformName, float* values);
	void setUniform4f(const std::string& uniformName, float* values);

	void setUniform2f(const std::string& uniformName, float a, float b);
	void setUniform3f(const std::string& uniformName, float a, float b, float c);
	void setUniform4f(const std::string& uniformName, float a, float b, float c, float d);

	void setUniform1i(const std::string& uniformName, int value);

	GLuint getUniformLocation(const std::string& name);

	void bind() const;
	void unbind() const;

	void freeMemory();

private:
	GLuint createShader(const std::string& vertexShader, const std::string& fragmentShader);
	GLuint compileShader(GLuint type, const std::string& source);

private:
	GLuint id;
	std::unordered_map<std::string, int> uniformLocationCache;

};