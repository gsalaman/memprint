#include <Arduino.h>
#include "memprint.h"
#include "SoftwareSerial.h"

void memprint_chars( char *mem, int num_bytes)
{
  int i;
  unsigned char myByte;
  char tmp_str[40];

  Serial.println("Addr\thex\tint\tchar");

  for (i = 0; i < num_bytes; i++)
  {
    myByte = *mem;
    
    sprintf(tmp_str, "0x%04x  0x%02x\t%3d\t%c", (unsigned int) mem, myByte, myByte, myByte);
    Serial.println(tmp_str);

    mem++;
  }

  Serial.println("=====================");
}

void memprint_chars( char *mem )
{
  memprint_chars( mem, 10);
}

void memprint_chars( void *mem )
{
  memprint_chars( (char *) mem, 10);
}

void memprint_chars( void *mem, int num_chars )
{
  memprint_chars( (char *) mem, num_chars);
}

void memprint_bytes( unsigned char *mem, int num_bytes)
{
  int i;
  unsigned char myByte;
  char tmp_str[40];

  Serial.println("Addr\thex\tint");

  for (i = 0; i < num_bytes; i++)
  {
    myByte = *mem;

    sprintf(tmp_str, "0x%04x  0x%02x\t%3d", (unsigned int) mem, myByte, myByte);
    Serial.println(tmp_str);
    mem++;
  }

  Serial.println("=====================");
}

void memprint_bytes( unsigned char *mem )
{
  memprint_bytes( mem, 16);
}

void memprint_bytes( void *mem )
{
  memprint_bytes( (unsigned char * ) mem, 16);
}

void memprint_bytes( void *mem, int num_bytes )
{
  memprint_bytes( (unsigned char *) mem, num_bytes);
}

void memprint_ints( int *mem, int num_ints)
{
  int i;
  int integer;
  char tmp_str[40];

  Serial.println("Addr\tint\thex");

  for (i = 0; i < num_ints; i++)
  {
    integer = *mem;

    sprintf(tmp_str, "0x%04x %5d 0x%04x", (unsigned int) mem, integer, integer);
    Serial.println(tmp_str);

    mem++;
  }

  Serial.println("=====================");

}

void memprint_ints( int *mem )
{
  memprint_ints(mem, 10);
}

void memprint_CRGB( void *mem, int num)
{
  int i;
  int j;
  char tmp_str[40];
  char *byte_ptr;
  
  Serial.println("Addr\tR\tG\tB");

  byte_ptr = (uint8_t *) mem;
  
  for (i = 0; i < num; i++)
  {
    sprintf(tmp_str, "0x%04x\t", (unsigned int) mem);
    Serial.print(tmp_str);

    for (j = 0; j < 3; j++)
    {
       sprintf(tmp_str, "0x%01x\t", *byte_ptr);
       Serial.print(tmp_str);
       byte_ptr++;
    }
    
    Serial.println();

  } 

  Serial.println("=====================");
}

void memprint_CRGB( void *mem )
{
  memprint_CRGB( mem, 16 );
}
