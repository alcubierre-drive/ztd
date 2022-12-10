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

#include <pwd.h>
#include <sys/types.h>

#include "../types.hxx"

namespace ztd
{
    class passwd
    {
      public:
        passwd() = delete;
        passwd(uid_t uid) noexcept;
        passwd(std::string_view name) noexcept;

      protected:
        void populate() noexcept;

      public:
        std::string name{};     // username
        std::string password{}; // user password
        uid_t uid{};            // user ID
        gid_t gid{};            // group ID
        std::string gecos{};    // user information
        std::string dir{};      // home directory
        std::string shell{};    // shell program

      protected:
        struct ::passwd* pw = {};
    };
} // namespace ztd