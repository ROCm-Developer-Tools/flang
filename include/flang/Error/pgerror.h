/*
 * Copyright (c) 2016-2018, NVIDIA CORPORATION.  All rights reserved.
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

#ifndef PGERROR_H_
#define PGERROR_H_

/** \file
 * \brief Error handling and reporting.
 */

#include "universal.h"

#ifndef IN_FLANG2
BEGIN_DECL_WITH_C_LINKAGE
#endif

/** \brief Severity of an error message.
 */
typedef enum error_severity {
  ERR_unused = 0,
  ERR_Informational = 1,
  ERR_Warning = 2,
  ERR_Severe = 3,
  ERR_Fatal = 4,
  ERR_SEVERITY_SIZE  // must be last!
} error_severity;

#ifdef IN_FLANG2
#include "errmsgdf.h"
#endif

/** \brief Error code type
 */
typedef enum error_code error_code_t;

#ifdef IN_FLANG2
#include "error.h"
#endif

#ifdef FE90
void errWithSrc(error_code_t ecode, enum error_severity sev, int eline,
                const char *op1, const char *op2, int col, int deduceCol,
                bool uniqDeduc, const char *deduceVal);
char * getDeduceStr(char * ptoken);
#endif

/** \brief Assert that cond is true, and emit an internal compiler error
 * otherwise.
 *
 * Note that unlike the C standard <assert.h> assert() macro, this version is
 * active in both debug and release builds, and expands to a statement,
 * not an expression.
 */
#define assert(cond, txt, val, sev) \
  if (cond)                         \
    ;                               \
  else                              \
  interr((txt), (val), (sev))

/** \brief If DEBUG!=0 and cond is false, emit an internal compiler error.
 *
 * Like the C standard <assert.h> assert macro, this version expands to an
 * expression and is active only in debug builds.  Severity of an error
 * is implicitly maximal.
 *
 * \param cond is the condition to be checked
 * \param txt is an additional info string, which may be NULL.
 */
#if DEBUG
#define DEBUG_ASSERT(cond, txt) \
  ((cond) ? (void)0 : dassert_err(__FILE__, __LINE__, #cond, (txt)))
void dassert_err(const char *, int line, const char *exp, const char *txt);
#else
#define DEBUG_ASSERT(cond, txt) ((void)0)
#endif

#if DEBUG
void asrt_failed(const char* file, int line);
#endif

#ifndef IN_FLANG2
END_DECL_WITH_C_LINKAGE
#endif

#endif /* PGERROR_H_ */
