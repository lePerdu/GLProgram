//
// shader.hpp
//
// Copyright (c) 2016 Zach Peltzer
// Subject to the MIT License.
//

#ifndef SHADER_H_
#define SHADER_H_

#include <fstream>
#include <string>

#include <GL/glew.h>

namespace GLProg {

//
// Creates and stores information for GLSL shaders.
//
class Shader {
public:
    //
    // Enum describing the possible types of shaders.
    //
    typedef enum Type {
        VERTEX_SHADER   = GL_VERTEX_SHADER,
        FRAGMENT_SHADER = GL_FRAGMENT_SHADER
    } Type;

    //
    // Construct a Shader from a source file name.
    // @param filename The name of the source file.
    // @throws std::ios_base::failure If there is an error in
    // opening/closing/reading the file.
    // @throws GLException If there is a compilation error.
    //
    explicit Shader(const std::string& filename, Type type);

    //
    // Construct a Shader from a input stream.
    // @param stream The stream containing the source for the shader.
    // @throws std::ios_base::failure If there is an error in reading from the
    // stream.
    // @throws GLException If there is a compilation error.
    //
    explicit Shader(std::istream& stream, Type type);

    //
    // Deletes the shader.
    //
    ~Shader();

    //
    // Gets the GL id of the shader.
    // @return The id of the shader.
    //
    GLuint get_id() const {
        return id;
    }

    //
    // Gets the type of the shader.
    // @return The type of the shader.
    //
    Type get_type() const {
        return type;
    }

private:
    //
    // The GL id of the shader.
    //
    GLuint id;

    //
    // The type of the shader.
    //
    Type type;

    void compile_shader(std::istream& stream);
};

} // namespace GLProg

#endif // SHADER_H_

