#include "../include/b64.h"

void Base64::encode()
{
  byte b1;
  byte b2;
  byte b3;
  long b_sum;

  for ( unsigned i = 0; i < msg.size(); i += 3 ) {  
    b1 = msg[i];
    b2 = msg[i+1];
    b3 = msg[i+2];

    b_sum = ( b1 << 16 ) + ( b2 << 8 ) + ( b3 );

    encoded += table64[(b_sum >> 18) & 0x3F];
    encoded += table64[(b_sum >> 12) & 0x3F];
    encoded += table64[(b_sum >> 6)  & 0x3F];
    encoded += table64[(b_sum     )  & 0x3F];
  }

  switch(msg.size() % 3) {
    case 1:
      this->encoded[encoded.size()-1] = '=';
      this->encoded[encoded.size()-2] = '=';break;
    case 2:
      this->encoded[encoded.size()-1] = '=';break;
  }
}

void Base64::decode() 
{
  int b_pos1,b_pos2,b_pos3,b_pos4;
  long b_sum;
  
  encoded = encoded == "" ? msg : encoded;

  for ( unsigned i = 0; i < encoded.size(); i += 4 ) {
    for ( unsigned j = 0; j < 64; j++ ) {
      if (encoded[i]   == table64[j]) b_pos1 = j;
      if (encoded[i+1] == table64[j]) b_pos2 = j;
      if (encoded[i+2] == table64[j]) b_pos3 = j;
      if (encoded[i+3] == table64[j]) b_pos4 = j; 
    }

    b_sum = ( b_pos1 << 18 ) + ( b_pos2 << 12 ) + ( b_pos3 << 6 ) + b_pos4;
    this->decoded += (char) ( (b_sum >> 16) & 0xff );
    this->decoded += (char) ( (b_sum >> 8 ) & 0xff );
    this->decoded += (char) (  b_sum & 0xff );
  }
  switch(encoded.size() % 3) {
    case 1:
      decoded[decoded.size()-1] = 0x00;
      decoded[decoded.size()-2] = 0x00;break;
    case 2:
      decoded[decoded.size()-1] = 0x00;break;
  }

}
