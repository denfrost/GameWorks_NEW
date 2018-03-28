// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

/*=============================================================================
	ShaderDerivedDataVersion.h: Shader derived data version.
=============================================================================*/

#pragma once

#include "CoreMinimal.h"

// In case of merge conflicts with DDC versions, you MUST generate a new GUID and set this new
// guid as version

// NVCHANGE_BEGIN: Add VXGI
#if WITH_GFSDK_VXGI

//Our FShaderResource class is not compatible with this define on
#define GLOBALSHADERMAP_DERIVEDDATA_VER			TEXT("9AFE22DFA96340989CDA7DECB4F73116")
#define MATERIALSHADERMAP_DERIVEDDATA_VER		TEXT("DFF9D5836ECF4F5296456DA1D5B6E445")

#else
// NVCHANGE_END: Add VXGI

#define GLOBALSHADERMAP_DERIVEDDATA_VER			TEXT("3E5171BCD5265736B84BA594D4D08444")
#define MATERIALSHADERMAP_DERIVEDDATA_VER		TEXT("24CFB3A24FF7412DB1277B5C2B5936DE")

// NVCHANGE_BEGIN: Add VXGI
#endif
// NVCHANGE_END: Add VXGI