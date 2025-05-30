#include <pqxx/pqxx>
#include <iostream>
// #include <source_location>
int main()
{
    std::cout << "libpqxx version: " << PQXX_VERSION_MAJOR << "." << PQXX_VERSION_MINOR << std::endl;
    pqxx::connection c;

    return 0;
}