#include "linenoise.hpp"
#include <iostream>
#include <string>

std::string READ(std::string input)
{
        return input;
}

std::string EVAL(std::string input)
{
        return input;
}

std::string PRINT(std::string input)
{
        return input;
}

std::string rep(std::string input)
{
        const std::string ast = READ(input);
        const std::string evaluated_ast = EVAL(ast);
        const std::string result = PRINT(evaluated_ast);
        return result;
}

int main()
{
        const auto history_path = "history.txt";
        linenoise::LoadHistory(history_path);
        std::string input;
        while (true) {
                auto quit = linenoise::Readline("user> ", input);

                if (quit) {
                        break;
                }
                linenoise::AddHistory(input.c_str());
                auto result = rep(input);
                std::cout << result << std::endl;
        }
        linenoise::SaveHistory(history_path);
}
