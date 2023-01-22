/**
 * Copyright (C) 2023 Brandon Zorn <brandonzorn@cock.li>
 *
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

#include <gtest/gtest.h>

#include <string>

#include "ztd/ztd.hxx"

/**
 * Zettabyte and Yottabyte support is disabled because there are no
 * integer types large enough to hold their size in bytes.
 * They can be enabled when the C++ standard has uint128_t.
 */
#define NO_VERY_LARGE_INT_TYPE

// clang-format off

/**
 * Byte        1
 * Kibibyte    1,024
 * Mebibyte    1,048,576
 * Gibibyte    1,073,741,824
 * Tebibyte    1,099,511,627,776
 * Pebibyte    1,125,899,906,842,624
 * Exbibyte    1,152,921,504,606,846,976
 * Zebibyte    1,180,591,620,717,411,303,424
 * Yobibyte    1,208,925,819,614,629,174,706,176
 */
constexpr std::uint64_t SIZE_BYTE     = 1;
constexpr std::uint64_t SIZE_KIBIBYTE = 1024;
constexpr std::uint64_t SIZE_MEBIBYTE = 1048576;
constexpr std::uint64_t SIZE_GIBIBYTE = 1073741824;
constexpr std::uint64_t SIZE_TEBIBYTE = 1099511627776;
constexpr std::uint64_t SIZE_PEBIBYTE = 1125899906842624;
constexpr std::uint64_t SIZE_EXBIBYTE = 1152921504606846976;

#ifndef NO_VERY_LARGE_INT_TYPE
constexpr std::uint64_t SIZE_ZEBIBYTE = 1180591620717411303424;
constexpr std::uint64_t SIZE_YOBIBYTE = 1208925819614629174706176;
#endif

// clang-format on

TEST(FileSize, size_zero)
{
    std::string formatted;

    const auto size = ztd::FileSize(0);
    formatted = size.get_formated_size();
    EXPECT_EQ(formatted, "0 B");
}

TEST(FileSize, rand_sizes)
{
    std::string formatted;

    const auto size01 = ztd::FileSize(4488998912);
    formatted = size01.get_formated_size();
    EXPECT_EQ(formatted, "4.2 GiB");

    const auto size02 = ztd::FileSize(12544835584);
    formatted = size02.get_formated_size();
    EXPECT_EQ(formatted, "11.7 GiB");

    const auto size03 = ztd::FileSize(111031328768);
    formatted = size03.get_formated_size();
    EXPECT_EQ(formatted, "103.4 GiB");

    const auto size04 = ztd::FileSize(249008676864);
    formatted = size04.get_formated_size();
    EXPECT_EQ(formatted, "231.9 GiB");

    const auto size05 = ztd::FileSize(5973753856);
    formatted = size05.get_formated_size();
    EXPECT_EQ(formatted, "5.6 GiB");

    const auto size06 = ztd::FileSize(942819);
    formatted = size06.get_formated_size();
    EXPECT_EQ(formatted, "920.7 KiB");

    const auto size07 = ztd::FileSize(19260);
    formatted = size07.get_formated_size();
    EXPECT_EQ(formatted, "18.8 KiB");

    const auto size08 = ztd::FileSize(360);
    formatted = size08.get_formated_size();
    EXPECT_EQ(formatted, "360 B");
}

TEST(FileSize, get_formated_size__int__B)
{
    std::string formatted;

    const auto size = ztd::FileSize(SIZE_BYTE);

    formatted = size.get_formated_size(0);
    EXPECT_EQ(formatted, "1 B");

    formatted = size.get_formated_size(1);
    EXPECT_EQ(formatted, "1 B");

    formatted = size.get_formated_size(2);
    EXPECT_EQ(formatted, "1 B");

    formatted = size.get_formated_size(3);
    EXPECT_EQ(formatted, "1 B");
}

TEST(FileSize, get_formated_size__int__KiB)
{
    std::string formatted;

    const auto size = ztd::FileSize(SIZE_KIBIBYTE);

    formatted = size.get_formated_size(0);
    EXPECT_EQ(formatted, "1 KiB");

    formatted = size.get_formated_size(1);
    EXPECT_EQ(formatted, "1.0 KiB");

    formatted = size.get_formated_size(2);
    EXPECT_EQ(formatted, "1.00 KiB");

    formatted = size.get_formated_size(3);
    EXPECT_EQ(formatted, "1.000 KiB");
}

TEST(FileSize, get_formated_size__int__MiB)
{
    std::string formatted;

    const auto size = ztd::FileSize(SIZE_MEBIBYTE);

    formatted = size.get_formated_size(0);
    EXPECT_EQ(formatted, "1 MiB");

    formatted = size.get_formated_size(1);
    EXPECT_EQ(formatted, "1.0 MiB");

    formatted = size.get_formated_size(2);
    EXPECT_EQ(formatted, "1.00 MiB");

    formatted = size.get_formated_size(3);
    EXPECT_EQ(formatted, "1.000 MiB");
}

TEST(FileSize, get_formated_size__int__GiB)
{
    std::string formatted;

    const auto size = ztd::FileSize(SIZE_GIBIBYTE);

    formatted = size.get_formated_size(0);
    EXPECT_EQ(formatted, "1 GiB");

    formatted = size.get_formated_size(1);
    EXPECT_EQ(formatted, "1.0 GiB");

    formatted = size.get_formated_size(2);
    EXPECT_EQ(formatted, "1.00 GiB");

    formatted = size.get_formated_size(3);
    EXPECT_EQ(formatted, "1.000 GiB");
}

TEST(FileSize, get_formated_size__int__TiB)
{
    std::string formatted;

    const auto size = ztd::FileSize(SIZE_TEBIBYTE);

    formatted = size.get_formated_size(0);
    EXPECT_EQ(formatted, "1 TiB");

    formatted = size.get_formated_size(1);
    EXPECT_EQ(formatted, "1.0 TiB");

    formatted = size.get_formated_size(2);
    EXPECT_EQ(formatted, "1.00 TiB");

    formatted = size.get_formated_size(3);
    EXPECT_EQ(formatted, "1.000 TiB");
}

TEST(FileSize, get_formated_size__int__PiB)
{
    std::string formatted;

    const auto size = ztd::FileSize(SIZE_PEBIBYTE);

    formatted = size.get_formated_size(0);
    EXPECT_EQ(formatted, "1 PiB");

    formatted = size.get_formated_size(1);
    EXPECT_EQ(formatted, "1.0 PiB");

    formatted = size.get_formated_size(2);
    EXPECT_EQ(formatted, "1.00 PiB");

    formatted = size.get_formated_size(3);
    EXPECT_EQ(formatted, "1.000 PiB");
}

TEST(FileSize, get_formated_size__int__EiB)
{
    std::string formatted;

    const auto size = ztd::FileSize(SIZE_EXBIBYTE);

    formatted = size.get_formated_size(0);
    EXPECT_EQ(formatted, "1 EiB");

    formatted = size.get_formated_size(1);
    EXPECT_EQ(formatted, "1.0 EiB");

    formatted = size.get_formated_size(2);
    EXPECT_EQ(formatted, "1.00 EiB");

    formatted = size.get_formated_size(3);
    EXPECT_EQ(formatted, "1.000 EiB");
}

#ifndef NO_VERY_LARGE_INT_TYPE
TEST(FileSize, get_formated_size__int__ZiB)
{
    std::string formatted;

    const auto size = ztd::FileSize(SIZE_ZEBIBYTE);

    formatted = size.get_formated_size(0);
    EXPECT_EQ(formatted, "1 ZiB");

    formatted = size.get_formated_size(1);
    EXPECT_EQ(formatted, "1.0 ZiB");

    formatted = size.get_formated_size(2);
    EXPECT_EQ(formatted, "1.00 ZiB");

    formatted = size.get_formated_size(3);
    EXPECT_EQ(formatted, "1.000 ZiB");
}

TEST(FileSize, get_formated_size__int__YiB)
{
    std::string formatted;

    const auto size = ztd::FileSize(SIZE_YOBIBYTE);

    formatted = size.get_formated_size(0);
    EXPECT_EQ(formatted, "1 YiB");

    formatted = size.get_formated_size(1);
    EXPECT_EQ(formatted, "1.0 YiB");

    formatted = size.get_formated_size(2);
    EXPECT_EQ(formatted, "1.00 YiB");

    formatted = size.get_formated_size(3);
    EXPECT_EQ(formatted, "1.000 YiB");
}
#endif

TEST(FileSize, get_filesize_parts_B)
{
    const auto size = ztd::FileSize(SIZE_BYTE);
    const auto [filesize, label] = size.get_filesize_parts();
    EXPECT_EQ(filesize, 1.0);
    EXPECT_EQ(label, "B");
}

TEST(FileSize, get_filesize_parts_KiB)
{
    const auto size = ztd::FileSize(SIZE_KIBIBYTE);
    const auto [filesize, label] = size.get_filesize_parts();
    EXPECT_EQ(filesize, 1.0);
    EXPECT_EQ(label, "KiB");
}

TEST(FileSize, get_filesize_parts_MiB)
{
    const auto size = ztd::FileSize(SIZE_MEBIBYTE);
    const auto [filesize, label] = size.get_filesize_parts();
    EXPECT_EQ(filesize, 1.0);
    EXPECT_EQ(label, "MiB");
}

TEST(FileSize, get_filesize_parts_GiB)
{
    const auto size = ztd::FileSize(SIZE_GIBIBYTE);
    const auto [filesize, label] = size.get_filesize_parts();
    EXPECT_EQ(filesize, 1.0);
    EXPECT_EQ(label, "GiB");
}

TEST(FileSize, get_filesize_parts_TiB)
{
    const auto size = ztd::FileSize(SIZE_TEBIBYTE);
    const auto [filesize, label] = size.get_filesize_parts();
    EXPECT_EQ(filesize, 1.0);
    EXPECT_EQ(label, "TiB");
}

TEST(FileSize, get_filesize_parts_PiB)
{
    const auto size = ztd::FileSize(SIZE_PEBIBYTE);
    const auto [filesize, label] = size.get_filesize_parts();
    EXPECT_EQ(filesize, 1.0);
    EXPECT_EQ(label, "PiB");
}

TEST(FileSize, get_filesize_parts_EiB)
{
    const auto size = ztd::FileSize(SIZE_EXBIBYTE);
    const auto [filesize, label] = size.get_filesize_parts();
    EXPECT_EQ(filesize, 1.0);
    EXPECT_EQ(label, "EiB");
}

#ifndef NO_VERY_LARGE_INT_TYPE
TEST(FileSize, get_filesize_parts_ZiB)
{
    const auto size = ztd::FileSize(SIZE_ZEBIBYTE);
    const auto [filesize, label] = size.get_filesize_parts();
    EXPECT_EQ(filesize, 1.0);
    EXPECT_EQ(label, "ZiB");
}

TEST(FileSize, get_filesize_parts_YiB)
{
    const auto size = ztd::FileSize(SIZE_YOBIBYTE);
    const auto [filesize, label] = size.get_filesize_parts();
    EXPECT_EQ(filesize, 1.0);
    EXPECT_EQ(label, "YiB");
}
#endif

/**
 * is_*()
 */

TEST(FileSize, is_byte)
{
    const auto size = ztd::FileSize(SIZE_BYTE);

    EXPECT_TRUE(size.is_byte());
    EXPECT_FALSE(size.is_kilobyte());
    EXPECT_FALSE(size.is_megabyte());
    EXPECT_FALSE(size.is_gigabyte());
    EXPECT_FALSE(size.is_terrabyte());
    EXPECT_FALSE(size.is_petabyte());
    EXPECT_FALSE(size.is_exabyte());
    EXPECT_FALSE(size.is_zettabyte());
    EXPECT_FALSE(size.is_yottabyte());
}

TEST(FileSize, is_kilobyte)
{
    const auto size = ztd::FileSize(SIZE_KIBIBYTE);

    EXPECT_FALSE(size.is_byte());
    EXPECT_TRUE(size.is_kilobyte());
    EXPECT_FALSE(size.is_megabyte());
    EXPECT_FALSE(size.is_gigabyte());
    EXPECT_FALSE(size.is_terrabyte());
    EXPECT_FALSE(size.is_petabyte());
    EXPECT_FALSE(size.is_exabyte());
    EXPECT_FALSE(size.is_zettabyte());
    EXPECT_FALSE(size.is_yottabyte());
}

TEST(FileSize, is_megabyte)
{
    const auto size = ztd::FileSize(SIZE_MEBIBYTE);

    EXPECT_FALSE(size.is_byte());
    EXPECT_FALSE(size.is_kilobyte());
    EXPECT_TRUE(size.is_megabyte());
    EXPECT_FALSE(size.is_gigabyte());
    EXPECT_FALSE(size.is_terrabyte());
    EXPECT_FALSE(size.is_petabyte());
    EXPECT_FALSE(size.is_exabyte());
    EXPECT_FALSE(size.is_zettabyte());
    EXPECT_FALSE(size.is_yottabyte());
}

TEST(FileSize, is_gigabyte)
{
    const auto size = ztd::FileSize(SIZE_GIBIBYTE);

    EXPECT_FALSE(size.is_byte());
    EXPECT_FALSE(size.is_kilobyte());
    EXPECT_FALSE(size.is_megabyte());
    EXPECT_TRUE(size.is_gigabyte());
    EXPECT_FALSE(size.is_terrabyte());
    EXPECT_FALSE(size.is_petabyte());
    EXPECT_FALSE(size.is_exabyte());
    EXPECT_FALSE(size.is_zettabyte());
    EXPECT_FALSE(size.is_yottabyte());
}

TEST(FileSize, is_terrabyte)
{
    const auto size = ztd::FileSize(SIZE_TEBIBYTE);

    EXPECT_FALSE(size.is_byte());
    EXPECT_FALSE(size.is_kilobyte());
    EXPECT_FALSE(size.is_megabyte());
    EXPECT_FALSE(size.is_gigabyte());
    EXPECT_TRUE(size.is_terrabyte());
    EXPECT_FALSE(size.is_petabyte());
    EXPECT_FALSE(size.is_exabyte());
    EXPECT_FALSE(size.is_zettabyte());
    EXPECT_FALSE(size.is_yottabyte());
}

TEST(FileSize, is_petabyte)
{
    const auto size = ztd::FileSize(SIZE_PEBIBYTE);

    EXPECT_FALSE(size.is_byte());
    EXPECT_FALSE(size.is_kilobyte());
    EXPECT_FALSE(size.is_megabyte());
    EXPECT_FALSE(size.is_gigabyte());
    EXPECT_FALSE(size.is_terrabyte());
    EXPECT_TRUE(size.is_petabyte());
    EXPECT_FALSE(size.is_exabyte());
    EXPECT_FALSE(size.is_zettabyte());
    EXPECT_FALSE(size.is_yottabyte());
}

TEST(FileSize, is_exabyte)
{
    const auto size = ztd::FileSize(SIZE_EXBIBYTE);

    EXPECT_FALSE(size.is_byte());
    EXPECT_FALSE(size.is_kilobyte());
    EXPECT_FALSE(size.is_megabyte());
    EXPECT_FALSE(size.is_gigabyte());
    EXPECT_FALSE(size.is_terrabyte());
    EXPECT_FALSE(size.is_petabyte());
    EXPECT_TRUE(size.is_exabyte());
    EXPECT_FALSE(size.is_zettabyte());
    EXPECT_FALSE(size.is_yottabyte());
}

#ifndef NO_VERY_LARGE_INT_TYPE
TEST(FileSize, is_zettabyte)
{
    const auto size = ztd::FileSize(SIZE_ZEBIBYTE);

    EXPECT_FALSE(size.is_byte());
    EXPECT_FALSE(size.is_kilobyte());
    EXPECT_FALSE(size.is_megabyte());
    EXPECT_FALSE(size.is_gigabyte());
    EXPECT_FALSE(size.is_terrabyte());
    EXPECT_FALSE(size.is_petabyte());
    EXPECT_FALSE(size.is_exabyte());
    EXPECT_TRUE(size.is_zettabyte());
    EXPECT_FALSE(size.is_yottabyte());
}

TEST(FileSize, is_yottabyte)
{
    const auto size = ztd::FileSize(SIZE_YOBIBYTE);

    EXPECT_FALSE(size.is_byte());
    EXPECT_FALSE(size.is_kilobyte());
    EXPECT_FALSE(size.is_megabyte());
    EXPECT_FALSE(size.is_gigabyte());
    EXPECT_FALSE(size.is_terrabyte());
    EXPECT_FALSE(size.is_petabyte());
    EXPECT_FALSE(size.is_exabyte());
    EXPECT_FALSE(size.is_zettabyte());
    EXPECT_TRUE(size.is_yottabyte());
}
#endif

/**
 * is_*() alias
 */

TEST(FileSize, is_kibibyte)
{
    const auto size = ztd::FileSize(SIZE_KIBIBYTE);

    EXPECT_TRUE(size.is_kibibyte());
    EXPECT_FALSE(size.is_mebibyte());
    EXPECT_FALSE(size.is_gibibyte());
    EXPECT_FALSE(size.is_tebibyte());
    EXPECT_FALSE(size.is_pebibyte());
    EXPECT_FALSE(size.is_exbibyte());
    EXPECT_FALSE(size.is_zebibyte());
    EXPECT_FALSE(size.is_yobibyte());
}

TEST(FileSize, is_mebibyte)
{
    const auto size = ztd::FileSize(SIZE_MEBIBYTE);

    EXPECT_FALSE(size.is_kibibyte());
    EXPECT_TRUE(size.is_mebibyte());
    EXPECT_FALSE(size.is_gibibyte());
    EXPECT_FALSE(size.is_tebibyte());
    EXPECT_FALSE(size.is_pebibyte());
    EXPECT_FALSE(size.is_exbibyte());
    EXPECT_FALSE(size.is_zebibyte());
    EXPECT_FALSE(size.is_yobibyte());
}

TEST(FileSize, is_gibibyte)
{
    const auto size = ztd::FileSize(SIZE_GIBIBYTE);

    EXPECT_FALSE(size.is_kibibyte());
    EXPECT_FALSE(size.is_mebibyte());
    EXPECT_TRUE(size.is_gibibyte());
    EXPECT_FALSE(size.is_tebibyte());
    EXPECT_FALSE(size.is_pebibyte());
    EXPECT_FALSE(size.is_exbibyte());
    EXPECT_FALSE(size.is_zebibyte());
    EXPECT_FALSE(size.is_yobibyte());
}

TEST(FileSize, is_tebibyte)
{
    const auto size = ztd::FileSize(SIZE_TEBIBYTE);

    EXPECT_FALSE(size.is_kibibyte());
    EXPECT_FALSE(size.is_mebibyte());
    EXPECT_FALSE(size.is_gibibyte());
    EXPECT_TRUE(size.is_tebibyte());
    EXPECT_FALSE(size.is_pebibyte());
    EXPECT_FALSE(size.is_exbibyte());
    EXPECT_FALSE(size.is_zebibyte());
    EXPECT_FALSE(size.is_yobibyte());
}

TEST(FileSize, is_pebibyte)
{
    const auto size = ztd::FileSize(SIZE_PEBIBYTE);

    EXPECT_FALSE(size.is_kibibyte());
    EXPECT_FALSE(size.is_mebibyte());
    EXPECT_FALSE(size.is_gibibyte());
    EXPECT_FALSE(size.is_tebibyte());
    EXPECT_TRUE(size.is_pebibyte());
    EXPECT_FALSE(size.is_exbibyte());
    EXPECT_FALSE(size.is_zebibyte());
    EXPECT_FALSE(size.is_yobibyte());
}

TEST(FileSize, is_exbibyte)
{
    const auto size = ztd::FileSize(SIZE_EXBIBYTE);

    EXPECT_FALSE(size.is_kibibyte());
    EXPECT_FALSE(size.is_mebibyte());
    EXPECT_FALSE(size.is_gibibyte());
    EXPECT_FALSE(size.is_tebibyte());
    EXPECT_FALSE(size.is_pebibyte());
    EXPECT_TRUE(size.is_exbibyte());
    EXPECT_FALSE(size.is_zebibyte());
    EXPECT_FALSE(size.is_yobibyte());
}

#ifndef NO_VERY_LARGE_INT_TYPE
TEST(FileSize, is_zebibyte)
{
    const auto size = ztd::FileSize(SIZE_ZEBIBYTE);

    EXPECT_FALSE(size.is_kibibyte());
    EXPECT_FALSE(size.is_mebibyte());
    EXPECT_FALSE(size.is_gibibyte());
    EXPECT_FALSE(size.is_tebibyte());
    EXPECT_FALSE(size.is_pebibyte());
    EXPECT_FALSE(size.is_exbibyte());
    EXPECT_TRUE(size.is_zebibyte());
    EXPECT_FALSE(size.is_yobibyte());
}

TEST(FileSize, is_yobibyte)
{
    const auto size = ztd::FileSize(SIZE_YOBIBYTE);

    EXPECT_FALSE(size.is_kibibyte());
    EXPECT_FALSE(size.is_mebibyte());
    EXPECT_FALSE(size.is_gibibyte());
    EXPECT_FALSE(size.is_tebibyte());
    EXPECT_FALSE(size.is_pebibyte());
    EXPECT_FALSE(size.is_exbibyte());
    EXPECT_FALSE(size.is_zebibyte());
    EXPECT_TRUE(size.is_yobibyte());
}
#endif
