#ifndef C_HELPERS_H
#define C_HELPERS_H

#include "Arduino.h"


// Implementation found in https://arduino.stackexchange.com/a/1237
String get_value(String data, char separator, int index) {
  int found = 0;
  int strIndex[] = { 0, -1 };
  int maxIndex = data.length() - 1;

  for (int i = 0; i <= maxIndex && found <= index; i++) {
    if (data.charAt(i) == separator || i == maxIndex) {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i + 1 : i;
    }
  }
  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}

String bool_to_string(bool Bool) {
  return Bool ? "true" : "false";
}

bool string_to_bool(String string) {
  string.toLowerCase();
  if (string == "true") {
    return true;
  } else if (string == "false") {
    return false;
  } else {
    return false;
  }
}

bool int_to_bool(int Int) {
  if (Int == 1) {
    return true;
  }
  return false;
}

#endif
