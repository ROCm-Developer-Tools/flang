#
# Copyright (c) 2015, NVIDIA CORPORATION.  All rights reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

#
# Copyright (c) 2019, Advanced Micro Devices, Inc. All rights reserved.
#
# Support for longintforall intrinsic.
#

########## Make rule for test longintforall  ########
#===----------------------------------------------------------------------===//
#
# Date of Modification : 19th July 2019
# Added a new test for use of kind of a forall index
#
#===----------------------------------------------------------------------===//


longintforall: .run

longintforall.$(OBJX):  $(SRC)/longintforall.f08
	-$(RM) longintforall.$(EXESUFFIX) core *.d *.mod FOR*.DAT FTN* ftn* fort.*
	@echo ------------------------------------ building test $@
	-$(CC) -c $(CFLAGS) $(SRC)/check.c -o check.$(OBJX)
	-$(FC) -c $(FFLAGS) $(LDFLAGS) $(SRC)/longintforall.f08 -o longintforall.$(OBJX)
	-$(FC) $(FFLAGS) $(LDFLAGS) longintforall.$(OBJX) check.$(OBJX) $(LIBS) -o longintforall.$(EXESUFFIX)


longintforall.run: longintforall.$(OBJX)
	@echo ------------------------------------ executing test longintforall
	longintforall.$(EXESUFFIX)

build:	longintforall.$(OBJX)

verify:	;

run:	 longintforall.$(OBJX)
	@echo ------------------------------------ executing test longintforall
	longintforall.$(EXESUFFIX)

