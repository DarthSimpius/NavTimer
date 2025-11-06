//This file handles all the GPS code and algorithms
//GPS setup
//Get Position
//Get Time
//#include <TinyGPS.h>
#include <NMEAGPS.h>

NMEAGPS gps;
gps_fix fix;
//TinyGPS gps;


void GPS_Setup() {
  Serial3.begin(9600);
}

void Check_GPS() {
  //bool newData = false;
  //If the WHILE breaks, change back to an IF
  /*if*/ while (gps.available(Serial3)) {
    fix = gps.read();
    //char c = Serial3.read();
    //if (gps.encode(c)) {
    //  newData = true;
    //}
  //}

  //if (newData) {
    float flat, flon;
    unsigned long fix_age;
    unsigned long date;
    unsigned long time;
    unsigned long age;

    if (fix.valid.location) {
      //Serial.print( fix.latitude(), 6 );
      //Serial.print( ',' );
      //Serial.print( fix.longitude(), 6 );
    }

    //Serial.print( F(", Altitude: ") );
    //if (fix.valid.altitude)
      //Serial.print( fix.altitude() );

    //Serial.print( F(", Time: "));
    //if (fix.valid.time)
      //Serial.print( fix.dateTime_cs );
    //Serial.println();
    /*
    gps.f_get_position(&flat, &flon, &fix_age);
    gps.get_datetime(&date, &time, &age);

    Serial.print("LAT=");
    Serial.print(flat == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flat, 6);
    Serial.print(" LON=");
    Serial.print(flon == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flon, 6);
    Serial.print(" SAT=");
    Serial.print(gps.satellites() == TinyGPS::GPS_INVALID_SATELLITES ? 0 : gps.satellites());
    Serial.print(" PREC=");
    Serial.print(gps.hdop() == TinyGPS::GPS_INVALID_HDOP ? 0 : gps.hdop());
  
    Serial.print("\nDATE=");
    Serial.print(date);
    Serial.print(" TIME=");
    Serial.print(time);
    Serial.print(" AGE=");
    Serial.print(age);
    Serial.print("\n");
    */
  }
}

//THIS FUNCTION RETURNS THE HOURS MINUTES AND SECONDS OBTAINED FROM THE GPS
void Return_Time(uint8_t* hours, uint8_t* minutes, uint8_t* seconds) {
  //int year;
  //byte month;
  //byte day;
  //byte millis;
  //u_long fix_age;
  //gps.crack_datetime(&year, &month, &day, hours, minutes, seconds, &millis, &fix_age);
  //Serial.println(fix.dateTime.hours);
  //Serial.println(fix.dateTime.minutes);
  //Serial.println(fix.dateTime.seconds);
  *hours = fix.dateTime.hours;
  *minutes = fix.dateTime.minutes;
  *seconds = fix.dateTime.seconds;

}

void Return_Position(float* lat, float* lon) {
  u_long fix_age;
  //gps.f_get_position(lat, lon, &fix_age);
}

bool GPS_Fix() {
  return (fix.satellites != 255);
}

int GPS_Get_Satellites() {
return fix.satellites;
}
