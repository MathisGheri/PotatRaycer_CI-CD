/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** test_exception
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/theories.h>
#include "Exception.hpp"

Test(Exception, GetMessage) {
    Exception ex("Test Exception");
    cr_assert(strcmp(ex.what(), "Test Exception") == 0);
}

Test(Exception, GetLevel) {
    Exception ex("Test Exception", Level::MIDDLE);
    cr_assert(ex.getLevel() == Level::MIDDLE);
}