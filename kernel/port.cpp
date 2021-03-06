/*
 * Copyright (c) 2020 Ferhat Gecdogan
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "../include/port.h"


Port::Port(uint16_t portnumber) {
    this->portnumber = portnumber;
}

Port::~Port() {}

Port8Bit::Port8Bit(uint16_t portnumber)
    : Port(portnumber) {}

Port8Bit::~Port8Bit() {}

void Port8Bit::Write(uint8_t data) {
    Write8(portnumber, data);
}

uint8_t Port8Bit::Read() {
    return Read8(portnumber);
}

Port8BitSlow::Port8BitSlow(uint16_t portnumber)
    : Port8Bit(portnumber) {}

Port8BitSlow::~Port8BitSlow() {}

void Port8BitSlow::Write(uint8_t data) {
    Write8Slow(portnumber, data);
}

Port16Bit::Port16Bit(uint16_t portnumber)
    : Port(portnumber) {}

Port16Bit::~Port16Bit() {}

void Port16Bit::Write(uint16_t data) {
    Write16(portnumber, data);
}

uint16_t Port16Bit::Read() {
    return Read16(portnumber);
}

Port32Bit::Port32Bit(uint16_t portnumber)
    : Port(portnumber) {}

Port32Bit::~Port32Bit() {}

void Port32Bit::Write(uint32_t data) {
    Write32(portnumber, data);
}

uint32_t Port32Bit::Read() {
    return Read32(portnumber);
}
