#include <iostream>
#include <string>
#include "TwitterClient.hpp"

int main (int argc, char const *argv[])
{
  srand((unsigned)time(0));

  Twitter client("marksands", "password");

  client.login();
  client.tweet("Testing my twitter framework!");

  return 0;
}