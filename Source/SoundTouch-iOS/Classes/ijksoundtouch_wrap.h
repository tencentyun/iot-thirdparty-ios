/*
 * Copyright (c) 2017 Bilibili
 * copyright (c) 2017 Raymond Zheng <raymondzheng1412@gmail.com>
 *
 * This file is part of ijkPlayer.
 *
 * ijkPlayer is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * ijkPlayer is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with ijkPlayer; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef IJKSOUNDTOUCHWRAP_H
#define IJKSOUNDTOUCHWRAP_H

#include <stdint.h>

extern "C" void* ijk_soundtouch_create(float speed, int pitch, int n_channel, int n_sampleRate);
extern "C" int ijk_soundtouch_translate(void *handle, short* data, int len, int bytes_per_sample, int n_channel);
extern "C" void ijk_soundtouch_destroy(void *handle);

#endif /* IJKSOUNDTOUCHWRAP_H */
