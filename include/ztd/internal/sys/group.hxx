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

#include <string>

#include <vector>

#include <grp.h>
#include <sys/types.h>

#include "../types.hxx"

namespace ztd
{
    class group
    {
      public:
        group() = delete;
        group(gid_t gid) noexcept;
        group(std::string_view name) noexcept;

      protected:
        void populate() noexcept;

      public:
        std::string name{};                 // group name
        std::string password{};             // group password
        gid_t gid{};                        // group ID
        std::vector<std::string> members{}; // group members

      protected:
        struct ::group* gr = {};
    };
} // namespace ztd