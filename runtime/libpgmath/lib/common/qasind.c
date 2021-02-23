/*
 * Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
 * See https://llvm.org/LICENSE.txt for license information.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 *
 */

/*
 * Modifications Copyright (c) 2019 Advanced Micro Devices, Inc. All rights reserved.
 * Notified per clause 4(b) of the license.
 */

#include "mthdecls.h"
#include <quadmath.h>

__float128 __attribute__((weak)) asinq( __float128);

__float128
__mth_i_qasind(__float128 q)
{
  return (CNVRTRAD(asinq(q)));
}
