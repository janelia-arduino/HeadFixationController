#include <HeadFixationController.h>


HeadFixationController dev;

void setup()
{
  dev.setup();
  dev.startServer();
}

void loop()
{
  dev.update();
}
