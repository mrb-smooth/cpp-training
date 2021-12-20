#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <filesystem>
#include <fstream>
#include <ctime>

using std::filesystem::exists;
using std::filesystem::is_empty;
using std::filesystem::is_directory;

namespace logging
{
    class Logger;
}

class logging::Logger
{
protected:
    const std::string log_path;
    const std::string log_file;
protected:
    Logger()
        : log_path("Logs"), log_file(log_path+"/log.txt")
    {
        if (!exists(log_path) || !is_directory(log_path)) {
            std::filesystem::create_directory(log_path);
        }

        std::ofstream ofs(log_file, std::ios_base::app);
        if (!exists(log_file) || is_empty(log_file)) {
            ofs << "[" + get_current_time() + "]: Application started.\n";
        } else {
            ofs << "\n"
                << []{ std::string res; for (; res.size() < 80;) res += "-"; return res; }()
                << "\n\n"
                << "[" + get_current_time() + "]: Application started.\n";
        }
    }
    ~Logger()
    {
    } 
protected: // Virtual
    virtual void log_info(const std::string_view& info) const       = 0;
    virtual void log_error(const std::string_view& error) const     = 0;
    virtual void log_warning(const std::string_view& warning) const = 0;
public: // Public
    static std::string get_current_time();
};

#endif // LOGGER_HPP
