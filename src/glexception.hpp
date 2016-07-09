//
// glexception.hpp
//
// Copyright (c) 2016 Zach Peltzer.
// Subject to the MIT License.
//

#ifndef GLEXCEPTION_H_
#define GLEXCEPTION_H_

#include <exception>

namespace GLProg {

//
// An error associated with a OpenGL error.
//
class GLException : public std::exception {
public:
    //
    // Constructs a GLException with an empty error message.
    //
    GLException() : GLException("") {}

    //
    // Constructs a GLException with a specified error message.
    //
    explicit GLException(const GLchar *error) : error(error) {}

    ~GLException() {}

    virtual const char* what() const noexcept {
        return error;
    }

private:
    //
    // The error message.
    //
    const GLchar* error;
};

} // namespace GLProg

#endif // GLEXCEPTION_H_

