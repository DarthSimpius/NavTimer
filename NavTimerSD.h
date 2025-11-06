//This file handles all the functions and control of the SD card and storage

#include <SD.h>
#include <SPI.h>

File Store_Location;
int File_Write_Buffer;
int File_Write_Threshold = 30;

void Debug(double leg_time_left, int leg_num, float Lat, float Lon);

//Setup the SD card and initialize it
void SD_Setup() {
  //SD pin
  SD.begin(4);

  File_Write_Buffer = 0;

  Store_Location = SD.open("Location_Tracker.txt", FILE_WRITE);
  Store_Location.print("\n-------------\n----NEW TEST----\n-------------\n");
  Store_Location.close();
}


void SD_WritePosition(double leg_time_left, int leg_num, float Lat, float Lon) {
  Store_Location.print("Leg #");
  Store_Location.print(leg_num);

  Store_Location.print(" Time left in Leg: ");
  Store_Location.print((int)((leg_time_left/60.0)/60.0));
  Store_Location.print(" HRS ");
  Store_Location.print((int)(leg_time_left/60.0)%60);
  Store_Location.print(" MINS ");
  Store_Location.print((int)leg_time_left%60);
  Store_Location.print(" SECS");

  Store_Location.print(" LAT=");
  Store_Location.print(Lat);
  Store_Location.print(" LON=");
  Store_Location.print(Lon);

  Debug(leg_time_left, leg_num, Lat, Lon);
  
  if (File_Write_Buffer >= File_Write_Threshold) {
    Store_Location.close();
    Store_Location = SD.open("Location_Tracker.txt", FILE_WRITE);
    File_Write_Buffer = 0;
  }
  File_Write_Buffer++;
}

void Debug(double leg_time_left, int leg_num, float Lat, float Lon) {
  Serial.print("Leg #");
  Serial.print(leg_num);

  Serial.print(" Time left in Leg: ");
  Serial.print((int)((leg_time_left/60.0)/60.0));
  Serial.print(" HRS ");
  Serial.print((int)(leg_time_left/60.0)%60);
  Serial.print(" MINS ");
  Serial.print((int)leg_time_left%60);
  Serial.print(" SECS");

  Serial.print(" LAT= ");
  Serial.print(Lat);
  Serial.print(" LON= ");
  Serial.print(Lon);

}
