/**
 * Source code is heavily based on 
 * SEN136B5B wiki page @ http://www.seeedstudio.com/wiki/index.php?title=Ultra_Sonic_range_measurement_module 
 * Modifications were introduced for simplicity's sake and
 * to easily add more sensors if necessary.
 */

#define SENSORS_COUNT 2
 
uint8_t sensorPin[] = {7,8};
long sensorValue[] = {0,0};
  
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
  for( uint8_t i = 0 ; i < SENSORS_COUNT ; i++ ){
    sensorValue[i] = measureDistanceCentimeters( sensorPin[i] );
  }
  
  for( uint8_t i = 0 ;  i < SENSORS_COUNT ; i++ ){
    Serial.print( sensorValue[i] );
    if( i == SENSORS_COUNT - 1 ){
      Serial.println();
    }else{
      Serial.print(',');
    }
  }

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
