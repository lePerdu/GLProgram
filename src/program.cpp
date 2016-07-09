//
// program.cpp
//
// Copyright (c) 2016 Zach Peltzer.
// Subject to the MIT License.
//

#include <iostream>
#include <vector>
#include <exception>

#include <GL/glew.h>

#include <glexception.hpp>
#include <shader.hpp>
#include <program.hpp>

namespace GLProg {

Program::Program(const std::vector<Shader>& shaders) {
    if (shaders.empty()) {
        throw GLException();
    }

    id = glCreateProgram();
    if (!id) {
        throw GLException();
    }

    for (int i = 0; i < shaders.size(); ++i) {
        glAttachShader(id, shaders[i].get_id());
    }

    glLinkProgram(id);
    int is_linked;
    glGetProgramiv(id, GL_LINK_STATUS, &is_linked);
    if (!is_linked) {
        int len;
        glGetProgramiv(id, GL_INFO_LOG_LENGTH, &len);
        char* info_log = new char[len];
        glGetProgramInfoLog(id, len, NULL, info_log);
        std::cerr << info_log << std::endl;
        delete[] info_log;
        throw GLException();
    }

    for (int i = 0; i < shaders.size(); ++i) {
        glDetachShader(id, shaders[i].get_id());
    }
}

Program::~Program() {
    glDeleteProgram(id);
}

} // namespace GLProg

