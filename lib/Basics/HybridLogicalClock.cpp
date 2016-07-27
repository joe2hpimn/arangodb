////////////////////////////////////////////////////////////////////////////////
/// DISCLAIMER
///
/// Copyright 2014-2016 ArangoDB GmbH, Cologne, Germany
/// Copyright 2004-2014 triAGENS GmbH, Cologne, Germany
///
/// Licensed under the Apache License, Version 2.0 (the "License");
/// you may not use this file except in compliance with the License.
/// You may obtain a copy of the License at
///
///     http://www.apache.org/licenses/LICENSE-2.0
///
/// Unless required by applicable law or agreed to in writing, software
/// distributed under the License is distributed on an "AS IS" BASIS,
/// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
/// See the License for the specific language governing permissions and
/// limitations under the License.
///
/// Copyright holder is ArangoDB GmbH, Cologne, Germany
///
/// @author Max Neunhoeffer
////////////////////////////////////////////////////////////////////////////////

#include "Basics/HybridLogicalClock.h"

char arangodb::basics::HybridLogicalClock::encodeTable[65] 
    = "-_ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

signed char arangodb::basics::HybridLogicalClock::decodeTable[256]
    = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,        //   0 - 15
       -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,        //  16 - 31
       -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 0,-1,-1,        //  32 - 47
       54,55,56,57,58,59,60,61,62,63,-1,-1,-1,-1,-1,-1,        //  48 - 63
       -1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,        //  64 - 79
       17,18,19,20,21,22,23,24,25,26,27,-1,-1,-1,-1, 1,        //  80 - 95
       -1,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,        //  96 - 111
       43,44,45,46,47,48,49,50,51,52,53,-1,-1,-1,-1,-1,        // 112 - 127
       -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,        // 128 - 143
       -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,        // 144 - 159
       -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,        // 160 - 175
       -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,        // 176 - 191
       -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,        // 192 - 207
       -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,        // 208 - 223
       -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,        // 224 - 239
       -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};       // 240 - 255
