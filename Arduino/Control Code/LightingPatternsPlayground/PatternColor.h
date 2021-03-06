#ifndef PATTERN_COLOR_H
#define PATTERN_COLOR_H

// Due to a problem with how the Arduino IDE processes code, enumerated types need to be
// defined in a header.

enum PatternColor {
  eRed, eBlue, eGreen, eYellow,
  eBlack    ///< This one is only used for clearing the lights.
};

#endif  // PATTERN_COLOR_H

