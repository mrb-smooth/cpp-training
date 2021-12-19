#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <filesystem>
#include <fstream>
#include <ctime>

using std::filesystem::exists;
using std::filesystem::is_directory;

namespace logging
{
    class Logger;
}

class logging::Logger
{
private:
    static const std::string log_path;
protected:
    std::string source;
    std::string file_name;
protected:
    Logger() {
        if (!exists(log_path) || !is_directory(log_path)) {
            std::filesystem::create_directory(log_path);
        }
    }
    ~Logger(){}

    virtual void log_info(std::string info)       = 0;
    virtual void log_error(std::string error)     = 0;
    virtual void log_warning(std::string warning) = 0;
protected:
    std::string get_current_time();
};

#endif // LOGGER_HPP
