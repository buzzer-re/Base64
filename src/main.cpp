#include <iostream>
#include <getopt.h>

#include "../include/b64.h"

struct Args {
  int argLen;
  char** argv;
  bool encode;
  bool decode;
  const char* msg;
};


void argParse(Args& arg) {
  
  const char* char_op = "d:e:r";
  int op;
  while ( (op = getopt_long(arg.argLen, arg.argv,char_op,NULL,NULL) ) != -1 ) {
    switch(op) {
      case 'e':
        arg.encode = true;
        arg.decode = false;
        arg.msg = optarg;break;
      case 'd':
        arg.decode = true;
        arg.encode = false;
        arg.msg = optarg;break; 
    }
  }
}

void usage(const char* programName) {
  
  fprintf(stderr,"Usage: %s <options> <msg>\n\nOptions:\n  -d\tDecode <msg>\n  -e\tEncode <msg>\n  -f\tRead file\n",programName);
  exit(1);
}

int main(int argc, char** argv) {

  if ( argc < 2 ) usage(argv[0]);
  
  Args args;
  args.argLen = argc;
  args.argv   = argv;
  argParse(args);

  Base64 b64(args.msg);
  std::string str_output;

  if ( args.encode && args.decode ) usage(argv[0]); // sanity check

  if ( args.encode ) {
    b64.encode();
    str_output = b64.getEncode();
  }
  else if ( args.decode ){
    b64.decode();
    str_output = b64.getDecode();
  }
  
  std::cout << str_output << std::endl;

  return 0;
}
