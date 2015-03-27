/**
 * Source code is heavily based on 
 * SEN136B5B wiki page @ http://www.seeedstudio.com/wiki/index.php?title=Ultra_Sonic_range_measurement_module 
 * Modifications were introduced for simplicity's sake and
 * to easily add more sensors if necessary.
 */

uint8_t sensorPin = 7;
long sensorValue = 0;
  
/**
 *
 */
void setup()
{
  Serial.begin( 9600 );
}


/**
 *
 */
void loop()
{
  sensorValue = measureDistanceCentimeters( sensorPin );
  Serial.print( sensorValue );
  delay(100);
}


/**
 * Measure distance for a sensor on pin {pin}
 */
long measureDistanceCentimeters( uint8_t pin )
{
  pinMode( pin, OUTPUT );
  digitalWrite( pin, LOW );
  delayMicroseconds(2);
  digitalWrite( pin, HIGH );
  delayMicroseconds(5);
  digitalWrite( pin, LOW );
  pinMode( pin, INPUT );
 
  long duration = pulseIn( pin, HIGH );
  return microsecondsToCentimetres( duration );
}


/**
 * Convert response duration to centimetres
 */
long microsecondsToCentimetres( long duration )
{
  return duration/29/2;
} 


/**
 * Convert response duration to inches
 */
long microsecondsToInches( long duration )
{
  return duration/74/2;
} 
