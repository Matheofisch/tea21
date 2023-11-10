#include <fmt/chrono.h>
#include <fmt/format.h>

#include <iostream>
#include <random>

#include "CLI/CLI.hpp"
#include "config.h"
 int foo;
 static int bss;
 int stack = -1, inp_array[4];
auto main(int argc, char **argv) -> int
{
    auto count{20};
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    CLI::App app{PROJECT_NAME};
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }
    
    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Value of variable foo {} address of variable foo{}\n", 
    foo,
    fmt::ptr(&foo));

    fmt::print("Value of variable bss {} address of variable bss{}\n", 
    bss,
    fmt::ptr(&bss));

    fmt::print("Value of variable stack {} address of variable stack{}\n", 
    stack,
    fmt::ptr(&stack));

    return 0; /* exit gracefully*/

}
