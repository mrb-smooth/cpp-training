#include "Logging.hpp"

[[nodiscard]] auto
logging::Logger::get_current_time() -> std::string {

    time_t rawtime;
    time(&rawtime);

    tm* timeinfo;
    char datetime[80];

    timeinfo = localtime(&rawtime);
    strftime(datetime, sizeof(datetime), "%Y-%m-%d  %H:%M:%S", timeinfo);

    return datetime;
}
