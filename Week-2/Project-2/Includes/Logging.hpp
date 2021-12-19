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
    std::string log_file;
protected:
    Logger() {
        if (!exists(log_path) || !is_directory(log_path)) {
            std::filesystem::create_directory(log_path);
        }
        log_file = log_path + "/log.txt";

        std::ofstream ofs(log_file, std::ios_base::app);
        ofs << "[" + get_current_time() + "]: Application started.\n";
    }
    ~Logger() {
        std::ofstream ofs(log_file, std::ios_base::app);
        ofs << "\n"
            << []{ std::string res; for (; res.size() < 80; ) res += "-"; return res; }()
            << "\n\n";
    }

    virtual void log_info(const std::string_view& info) const       = 0;
    virtual void log_error(const std::string_view& error) const     = 0;
    virtual void log_warning(const std::string_view& warning) const = 0;
public:
    static std::string get_current_time();
};

#endif // LOGGER_HPP
