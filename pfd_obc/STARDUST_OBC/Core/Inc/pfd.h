#ifndef PFD_H
#define PFD_H

#include "main.h"
#include "def.h"
#include "system.h"


void parseKongrulData((uint8_t *)data);  // Kongrul Parse
void parseIllinoisData((uint8_t *)data); // flight2_comp and flight_comp_tri parse
void parseSemrukVData((uint8_t *)data);  // SemrukV Parse
void parseSemruk3Data((uint8_t *)data);  // Semruk3 Parse

#endif
