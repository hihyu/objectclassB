configuration BlinkAppC
{
}
implementation
{
  components MainC, BlinkC, LedsC;
  components new TimerMilliC() as Timer();

  BlinkC -> MainC.Boot;

  BlinkC.Timer() -> Timer();
  BlinkC.Leds -> LedsC;
}
