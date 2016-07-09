//
// program.hpp
//
// Copyright (c) 2016 Zach Peltzer.
// Subject to the MIT License.
//

#ifndef PROGRAM_H_
#define PROGRAM_H_

#include <string>
#include <vector>

#include <GL/glew.h>

#include <shader.hpp>

namespace GLProg {

//
// Stores information about a GLSL program.
// Upon construction, the shaders are linked together into a program.
//
class Program {
public:
    //
    // Constructs a program given a vector of shaders.
    //
    explicit Program(const std::vector<Shader>& shaders);

    //
    // Deletes the program.
    //
    ~Program();

    //
    // Gets the GL id of the program.
    // @return The id of the program.
    //
    GLuint get_id() {
        return id;
    }

private:
    //
    // The GL id of the program.
    //
    GLuint id;
};

} // namespace GLProg

#endif // PROGRAM_H_

