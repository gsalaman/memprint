void memprint_chars( char *mem, int num_bytes)
{
  int i;
  uint8_t myByte;
  char tmp_str[40];

  Serial.println("Addr\thex\tint\tchar");

  for (i = 0; i < num_bytes; i++)
  {
    myByte = *mem;
    
    sprintf(tmp_str, "0x%04x  0x%02x\t%3d\t%c", (unsigned int) mem, myByte, myByte, myByte);
    Serial.println(tmp_str);

    mem++;
  }

}

void memprint_chars( char *mem )
{
  memprint_chars( mem, 10);
}

void memprint_bytes( uint8_t *mem, int num_bytes)
{
  int i;
  uint8_t myByte;
  char tmp_str[40];

  Serial.println("Addr\thex\tint");

  for (i = 0; i < num_bytes; i++)
  {
    myByte = *mem;

    sprintf(tmp_str, "0x%04x  0x%02x\t%3d", (unsigned int) mem, myByte, myByte);
    Serial.println(tmp_str);
    mem++;
  }

}

void memprint_bytes( uint8_t *mem )
{
  memprint_bytes( mem, 16);
}
