//============================================================================
// Name         : dnaversion-stream.hpp
// Author       : Roger Fraser
// Contributors :
// Version      : 1.00
// Copyright    : Copyright 2017 Geoscience Australia
//
//                Licensed under the Apache License, Version 2.0 (the "License");
//                you may not use this file except in compliance with the License.
//                You may obtain a copy of the License at
//               
//                http ://www.apache.org/licenses/LICENSE-2.0
//               
//                Unless required by applicable law or agreed to in writing, software
//                distributed under the License is distributed on an "AS IS" BASIS,
//                WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//                See the License for the specific language governing permissions and
//                limitations under the License.
//
// Description  : DynAdjust version helper include file
//============================================================================

#ifndef DNAVERSION_STREAM_HPP
#define DNAVERSION_STREAM_HPP

#if defined(_MSC_VER)
	#if defined(LIST_INCLUDES_ON_BUILD) 
		#pragma message("  " __FILE__) 
	#endif
#endif

#include <iomanip>

#include <include/config/dnaversion.hpp>
#include <include/config/dnaconsts-iostream.hpp>

template <class T>
void output_theappname(T& stream)
{
	stream << __the_app_name__ << " " << __COPYRIGHT_YEAR__;
}


template <class T>
void output_binaryname(T& stream)
{
	stream << "Title:        " << __BINARY_NAME__;
}
	

template <class T>
void output_binarydescription(T& stream)
{
	stream << "Description:  " << __BINARY_DESC__;
}
	

template <class T>
void output_globalname(T& stream)
{
	stream << __GLOBAL_BINARY_NAME__ << ", " << __GLOBAL_BINARY_DESC__;
}
	

template <class T>
void output_createdby(T& stream)
{
	stream << "Created by:   " << __BINARY_NAME__ << ", " << __BINARY_DESC__;
}
	

template <class T>
void output_version(T& stream, bool PAD=false)
{
	if (PAD)
		stream << setw(PRINT_VAR_PAD) << left << "Version: ";
	else
		stream << "Version:      ";
	stream << __BINARY_VERSION__ << ", " << __BINARY_BUILDTYPE__;
}
	

template <class T>
void output_build(T& stream, bool PAD=false)
{
	if (PAD)
		stream << setw(PRINT_VAR_PAD) << left << "Build: ";
	else
		stream << "Build:        ";
	stream << __DATE__ << ", " << __TIME__;
	if (strlen(__COMPILER__) > 2)
		stream <<  " (" << __COMPILER__ << " " << __COMPILER_VERSION__ << ")";
}

#endif  // DNAVERSION_HPP