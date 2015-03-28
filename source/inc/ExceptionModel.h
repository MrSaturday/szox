/*
 * exception_model.h
 *
 *  Created on: Mar 27, 2015
 *      Author: sajmon
 */

#ifndef EXCEPTION_MODEL_H_
#define EXCEPTION_MODEL_H_

#include <stdexcept>

//TODO: change all parameters to references

namespace ExceptionModel
{

template<typename T>
class exception : public std::runtime_error
{
public:
    exception(const std::string& msg, std::string file, unsigned int line, T& object) :
        std::runtime_error(formatMessage(msg, file, line)), object(object)
    {
    }

    T object;
private:
    std::string formatMessage(std::string msg, std::string file, unsigned int line)
    {
        auto fileNameIdx = file.begin() + file.rfind('/') + 1;
        file.erase(file.begin(), fileNameIdx);
        return std::string(msg + "; location: " + file + "@" + std::to_string(line));
    }
};

template<typename T>
static inline exception<T> create(const std::string& msg, std::string file, unsigned int line, T& object)
{
    return exception<T>(msg, file, line, object);
}

}

#define THROW(str) throw ExceptionModel::create<typename std::remove_reference<decltype(*this)>::type>(str, __FILE__, __LINE__, *this)

#endif /* EXCEPTION_MODEL_H_ */
