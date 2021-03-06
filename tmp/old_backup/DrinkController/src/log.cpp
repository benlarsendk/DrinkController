#include "log.h"
#include "unistd.h"

Logger* Logger::instancePtr_ = NULL;

Logger* Logger::instance(){
    instancePtr_ = new Logger;
    return instancePtr_;
}


Logger::Logger()
{
   const char * pluspath = ("/home/root/" + getTime(0)).c_str();
   logfile.open(pluspath, fstream::app);
}


Logger::~Logger()
{
    logfile.close();
}
void Logger::log(string data)
{
    boost::mutex::scoped_lock(mtx_);
    logfile << getTime(1) << ":\t" << data << "\n";
    flush(logfile);

}
string Logger::getTime(int timedate)
{
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];

    time (&rawtime);
    timeinfo = localtime(&rawtime);
    if (timedate == 1){
        strftime(buffer,80,"%d/%m-%Y@%H:%M:%S",timeinfo);
        string str(buffer);
        return str;
    }
    else{
        strftime(buffer,80,"%d%m%Y",timeinfo);
        string str(buffer);
        return str;
    }

}
