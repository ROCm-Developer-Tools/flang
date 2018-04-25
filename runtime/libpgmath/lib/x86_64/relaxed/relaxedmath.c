/*
 * Copyright (c) 2018, NVIDIA CORPORATION.  All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#define TABLE_TARGET
#include "relaxedmathc.h"
#undef TABLE_TARGET

#define TARGET_VEX_OR_FMA       vex
#include "relaxedmathc.h"
#undef  TARGET_VEX_OR_FMA

#define TARGET_FMA
#define TARGET_VEX_OR_FMA       fma4
#define VFMA_IS_FMA3_OR_FMA4    FMA4
#include "relaxedmathc.h"
#undef  TARGET_VEX_OR_FMA
#undef  VFMA_IS_FMA3_OR_FMA4

#define TARGET_FMA
#define TARGET_VEX_OR_FMA       avx2
#define VFMA_IS_FMA3_OR_FMA4    FMA3
#include "relaxedmathc.h"
#undef  TARGET_VEX_OR_FMA
#undef  VFMA_IS_FMA3_OR_FMA4
