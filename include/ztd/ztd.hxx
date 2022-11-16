/**
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

// header order matters

#include "./internal/types.hxx"

#include "./internal/string_python.hxx"
#include "./internal/string_random.hxx"
#include "./internal/string_utils.hxx"

#include "./internal/c_utils.hxx"

#include "./internal/array_templates.hxx"
#include "./internal/vector_templates.hxx"

#include "./internal/timer.hxx"

#include "./internal/files/filesize_IEC.hxx"
#include "./internal/files/filesize_SI.hxx"

#include "./internal/sort/alphanumeric.hxx"
#include "./internal/sort/compare.hxx"
#include "./internal/sort/random.hxx"

#include "./internal/sys/chmod.hxx"
#include "./internal/sys/chown.hxx"
#include "./internal/sys/fnmatch.hxx"
#include "./internal/sys/stat.hxx"
#include "./internal/sys/statvfs.hxx"
#include "./internal/sys/strdup.hxx"
#include "./internal/sys/utime.hxx"