/*-*- Mode: C; c-basic-offset: 8; indent-tabs-mode: nil -*-*/

/***
  This file is part of systemd.

  Copyright 2014 Lennart Poettering

  systemd is free software; you can redistribute it and/or modify it
  under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation; either version 2.1 of the License, or
  (at your option) any later version.

  systemd is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with systemd; If not, see <http://www.gnu.org/licenses/>.
***/

#include <seccomp.h>

#include "util.h"
#include "seccomp-util.h"

const char* seccomp_arch_to_string(uint32_t c) {

        if (c == SCMP_ARCH_NATIVE)
                return "native";
        if (c == SCMP_ARCH_X86)
                return "x86";
        if (c == SCMP_ARCH_X86_64)
                return "x86-64";
        if (c == SCMP_ARCH_X32)
                return "x32";
        if (c == SCMP_ARCH_ARM)
                return "arm";

        return NULL;
}

int seccomp_arch_from_string(const char *n, uint32_t *ret) {
        if (!n)
                return -EINVAL;

        assert(ret);

        if (streq(n, "native"))
                *ret = SCMP_ARCH_NATIVE;
        else if (streq(n, "x86"))
                *ret = SCMP_ARCH_X86;
        else if (streq(n, "x86-64"))
                *ret = SCMP_ARCH_X86_64;
        else if (streq(n, "x32"))
                *ret = SCMP_ARCH_X32;
        else if (streq(n, "arm"))
                *ret = SCMP_ARCH_ARM;
        else
                return -EINVAL;

        return 0;
}
