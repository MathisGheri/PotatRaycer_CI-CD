/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** test_logger
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/theories.h>
#include "Logger.hpp"
#include "SingletonLogger.hpp"

Test(SingletonLogger, getInstance){
    Logger* logger1 = LoggerSingleton::getInstance();
    Logger* logger2 = LoggerSingleton::getInstance();
    cr_assert_eq(logger1, logger2);
}

Test(SingletonLogger, getInstanceValidPointer) {
    Logger* logger = LoggerSingleton::getInstance();
    cr_assert_not_null(logger);
}

Test(SingletonLogger, destroyInstance) {
    Logger* logger = LoggerSingleton::getInstance();
    LoggerSingleton::destroyInstance();
    Logger* newLogger = LoggerSingleton::getInstance();
    cr_assert_eq(logger == newLogger, false);
}
