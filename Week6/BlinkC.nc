#include "Timer.h"

module BlinkC @safe()
{
  uses interface Timer<TMilli> as Timer();
  uses interface Leds;
  uses interface Boot;
}
implementation
{
  event void Boot.booted()
  {
    call Timer().startPeriodic( 250 );
  }
  event void Timer().fired()
  {
    call Leds.led0Toggle();
  }
}
