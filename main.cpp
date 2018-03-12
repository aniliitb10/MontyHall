#include <iostream>
#include <array>
#include <random>

std::random_device rd;
std::mt19937 gen(rd());

enum class Door : uint8_t
{
  Cat = 0,
  Car = 1
};

class Setup
{
public:
  Setup()
  {
    std::uniform_int_distribution<> dis(0,2);
    // putting car at a random door
    _doors[dis(gen)] = Door::Car;
  }

  Door openDoor(int index_)
  {
    return _doors[index_];
  }

private:
  std::array<Door, 3> _doors = {Door::Cat, Door::Cat, Door::Cat};
};

int main()
{
  unsigned int dontSwitch=0, doSwitch=0;

  for (int index=0; index < 10000; index++)
  {
    Setup newSetup;
    std::uniform_int_distribution<> dis(0,2);

    // opening doors at random
    if (newSetup.openDoor(dis(gen)) == Door::Car)
    {
      dontSwitch++;
    }
    else
    {
      doSwitch++;
    }
  }

  std::cout << "Don't switch door:\t" << dontSwitch << "\nSwitch door:\t\t" << doSwitch << std::endl;
}
