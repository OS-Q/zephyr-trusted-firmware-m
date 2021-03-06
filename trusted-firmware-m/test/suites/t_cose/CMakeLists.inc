#-------------------------------------------------------------------------------
# Copyright (c) 2020, Arm Limited. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#
#-------------------------------------------------------------------------------

#Definitions to compile the T_COSE module.
#This file assumes it will be included from a project specific cmakefile, and
#will not create a library or executable.
#Inputs:
#	TFM_ROOT_DIR - root directory of the TF-M repo.
#
#Outputs:
#	Will modify include directories to make the source compile.
#	ALL_SRC_C: C source files to be compiled will be added to this list. This shall be added to your add_executable or add_library command.
#	ALL_SRC_CXX: C++ source files to be compiled will be added to this list. This shall be added to your add_executable or add_library command.
#	ALL_SRC_ASM: assembly source files to be compiled will be added to this list. This shall be added to your add_executable or add_library command.
#	Include directories will be modified by using the include_directories() commands as needed.

#Get the current directory where this file is located.
set(T_COSE_TEST_SUIT_DIR ${CMAKE_CURRENT_LIST_DIR})

#Verify input parameters
if(NOT DEFINED TFM_ROOT_DIR)
	message(FATAL_ERROR "Please set TFM_ROOT_DIR before including this file.")
endif()

if (NOT DEFINED ENABLE_T_COSE_TESTS)
	message(FATAL_ERROR "Incomplete build configuration: ENABLE_T_COSE_TESTS is undefined.")
elseif(ENABLE_T_COSE_TESTS)
	list(APPEND ALL_SRC_C_NS
		"${T_COSE_TEST_SUIT_DIR}/non_secure/t_cose_ns_testsuite.c"
		$<TARGET_OBJECTS:tfm_t_cose_test>   #See in lib/ext/t_cose/CMakeList.txt
	)
endif()
