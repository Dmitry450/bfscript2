#ifndef COLOR_H

#define COLOR_H

#if (defined(_WIN32) || defined(_WIN64))

#define ERROR_MSG(str) str
#define WARNING_MSG(str) str
#define BOLD_MSG(str) str
#define GOOD_MSG(str) str

#endif

#if (defined(__linux__) || defined(LINUX))

#define ERROR_MSG(str) (string)"\033[31;1m"+str+"\033[0m"
#define WARNING_MSG(str) (string)"\033[33;1m"+str+"\033[0m"
#define BOLD_MSG(str) (string)"\033[1m"+str+"\033[0m"
#define GOOD_MSG(str) (string)"\033[32;1m"+str+"\033[0m"

#endif

#endif