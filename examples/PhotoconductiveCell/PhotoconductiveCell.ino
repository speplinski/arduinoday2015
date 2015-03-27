#define PHOTORESISTORS_COUNT 1

uint8_t photoresistorPin[] = {A0};
int photoresistorValue[] = {0};

/**
 *
 */
void setup(){
  Serial.begin(9600);
  
}


/**
 *
 */
void loop(){
  
  for( uint8_t i = 0 ; i < PHOTORESISTORS_COUNT ; i++ ){
    photoresistorValue[i] = analogRead( photoresistorPin[i] );
    delay(2);
  }
  
  for( uint8_t i = 0 ;  i < PHOTORESISTORS_COUNT ; i++ ){
    Serial.print( photoresistorValue[i] );
    if( i == PHOTORESISTORS_COUNT - 1 ){
      Serial.println();
    }else{
      Serial.print(',');
    }
  }
  
  delay(10);
}
