//
// shader.cpp
//
// Copyright (c) 2016 Zach Peltzer.
// Subject to the MIT License.
//

#include <iostream>
#include <fstream>
#include <string>

#include <GL/glew.h>

#include <glexception.hpp>
#include <shader.hpp>

namespace GLProg {

Shader::Shader(const std::string& filename, Type type) : type(type) {
    std::ifstream stream(filename);
    compile_shader(stream);
}

Shader::Shader(std::istream& stream, Type type) : type(type) {
    compile_shader(stream);
}

Shader::~Shader() {
    glDeleteShader(id);
}

void Shader::compile_shader(std::istream& stream) {
    id = glCreateShader(type);
    if (id == 0) {
        throw GLException();
    }

    stream.seekg(0, std::ios::end);
    int length = stream.tellg();
    char* buffer = new char[length];
    stream.seekg(0, std::ios::beg);
    stream.read(buffer, length);

    glShaderSource(id, 1, &buffer, NULL);
    delete[] buffer;

    glCompileShader(id);
    int is_compiled = false;
    glGetShaderiv(id, GL_COMPILE_STATUS, &is_compiled);
    if (!is_compiled) {
        int info_log_length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &info_log_length);

        char* info_log = new char[info_log_length];
        glGetShaderInfoLog(id, info_log_length, NULL, info_log);
        std::cerr << info_log << std::endl;
        delete[] info_log;

        glDeleteShader(id);
        throw GLException();
    }
}

} // namespace GLProg

