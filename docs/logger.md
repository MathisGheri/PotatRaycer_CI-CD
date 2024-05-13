# Use the logger

The logger is a class, accessible by a **singleton** wherever u are in the code.\
The purpose of the logger is to print inside the `logfile.txt` the custom messages you will implement throughout the code.

## How to use it

First you'll need to include the logger singleton in the file where you need it.
```bash
#include "SingletonLogger.hpp"
```

Once included you can simply use it like this :
```bash
Logger* logger = LoggerSingleton::getInstance();
logger->log([Option], "[Your message]");
```
where [Option] is either:
```bash
DEBUG
INFO
WARNING
ERROR
CRITICAL
```
You can choose the level of the log based on the code where it is used.\
For exemple, if a log is used in an place where it must not pass throughout, use the **CRITICAL** enum.
