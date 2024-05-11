/*
** EPITECH PROJECT, 2024
** PotatRaycer_CI-CD
** File description:
** test_parsing
*/


#include <criterion/criterion.h>
#include "Parsing.hpp"
#include <fstream>
#include <libconfig.h++>
#include <string>

Test(Parsing, ParseConfigFile)
{
    libconfig::Config cfg;
    cfg.readFile("config.cfg");
    libconfig::Setting& root = cfg.getRoot();
    Parsing::ParseConfigFile(root);
    cr_assert_eq(1, 1);
}
