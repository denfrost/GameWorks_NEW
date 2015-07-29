/*
 * Copyright (c) 2008-2015, NVIDIA CORPORATION.  All rights reserved.
 *
 * NVIDIA CORPORATION and its licensors retain all intellectual property
 * and proprietary rights in and to this software, related documentation
 * and any modifications thereto.  Any use, reproduction, disclosure or
 * distribution of this software and related documentation without an express
 * license agreement from NVIDIA CORPORATION is strictly prohibited.
 */


// This file was generated by NxParameterized/scripts/GenParameterized.pl
// Created: 2015.01.18 19:26:16

#ifndef HEADER_ClothingCookedParam_h
#define HEADER_ClothingCookedParam_h

#include "NxParametersTypes.h"

#ifndef NX_PARAMETERIZED_ONLY_LAYOUTS
#include "NxParameterized.h"
#include "NxParameters.h"
#include "NxParameterizedTraits.h"
#include "NxTraitsInternal.h"
#endif

namespace physx
{
namespace apex
{
namespace clothing
{

#pragma warning(push)
#pragma warning(disable: 4324) // structure was padded due to __declspec(align())

namespace ClothingCookedParamNS
{

struct CookedPhysicalSubmesh_Type;

struct U8_DynamicArray1D_Type
{
	physx::PxU8* buf;
	bool isAllocated;
	physx::PxI32 elementSize;
	physx::PxI32 arraySizes[1];
};

struct POINTER_DynamicArray1D_Type
{
	void** buf;
	bool isAllocated;
	physx::PxI32 elementSize;
	physx::PxI32 arraySizes[1];
};

struct CookedPhysicalSubmesh_DynamicArray1D_Type
{
	CookedPhysicalSubmesh_Type* buf;
	bool isAllocated;
	physx::PxI32 elementSize;
	physx::PxI32 arraySizes[1];
};

struct F32_DynamicArray1D_Type
{
	physx::PxF32* buf;
	bool isAllocated;
	physx::PxI32 elementSize;
	physx::PxI32 arraySizes[1];
};

struct U32_DynamicArray1D_Type
{
	physx::PxU32* buf;
	bool isAllocated;
	physx::PxI32 elementSize;
	physx::PxI32 arraySizes[1];
};

struct VEC3_DynamicArray1D_Type
{
	physx::PxVec3* buf;
	bool isAllocated;
	physx::PxI32 elementSize;
	physx::PxI32 arraySizes[1];
};

struct CookedPhysicalSubmesh_Type
{
	physx::PxU32 physicalMeshId;
	physx::PxU32 submeshId;
	physx::PxU32 cookedDataOffset;
	physx::PxU32 cookedDataLength;
	void* deformableMeshPointer;
	physx::PxU32 deformableInvParticleWeightsOffset;
	physx::PxU32 virtualParticleIndicesOffset;
	physx::PxU32 virtualParticleIndicesLength;
};

struct ParametersStruct
{

	physx::PxF32 actorScale;
	U8_DynamicArray1D_Type convexCookedData;
	POINTER_DynamicArray1D_Type convexMeshPointers;
	CookedPhysicalSubmesh_DynamicArray1D_Type cookedPhysicalSubmeshes;
	U8_DynamicArray1D_Type deformableCookedData;
	physx::PxU32 cookedDataVersion;
	F32_DynamicArray1D_Type deformableInvParticleWeights;
	U32_DynamicArray1D_Type virtualParticleIndices;
	VEC3_DynamicArray1D_Type virtualParticleWeights;

};

static const physx::PxU32 checksum[] = { 0x936b7868, 0xbc6f31e7, 0xea489107, 0xb65fdbe5, };

} // namespace ClothingCookedParamNS

#ifndef NX_PARAMETERIZED_ONLY_LAYOUTS
class ClothingCookedParam : public NxParameterized::NxParameters, public ClothingCookedParamNS::ParametersStruct
{
public:
	ClothingCookedParam(NxParameterized::Traits* traits, void* buf = 0, PxI32* refCount = 0);

	virtual ~ClothingCookedParam();

	virtual void destroy();

	static const char* staticClassName(void)
	{
		return("ClothingCookedParam");
	}

	const char* className(void) const
	{
		return(staticClassName());
	}

	static const physx::PxU32 ClassVersion = ((physx::PxU32)0 << 16) + (physx::PxU32)2;

	static physx::PxU32 staticVersion(void)
	{
		return ClassVersion;
	}

	physx::PxU32 version(void) const
	{
		return(staticVersion());
	}

	static const physx::PxU32 ClassAlignment = 8;

	static const physx::PxU32* staticChecksum(physx::PxU32& bits)
	{
		bits = 8 * sizeof(ClothingCookedParamNS::checksum);
		return ClothingCookedParamNS::checksum;
	}

	static void freeParameterDefinitionTable(NxParameterized::Traits* traits);

	const physx::PxU32* checksum(physx::PxU32& bits) const
	{
		return staticChecksum(bits);
	}

	const ClothingCookedParamNS::ParametersStruct& parameters(void) const
	{
		ClothingCookedParam* tmpThis = const_cast<ClothingCookedParam*>(this);
		return *(static_cast<ClothingCookedParamNS::ParametersStruct*>(tmpThis));
	}

	ClothingCookedParamNS::ParametersStruct& parameters(void)
	{
		return *(static_cast<ClothingCookedParamNS::ParametersStruct*>(this));
	}

	virtual NxParameterized::ErrorType getParameterHandle(const char* long_name, NxParameterized::Handle& handle) const;
	virtual NxParameterized::ErrorType getParameterHandle(const char* long_name, NxParameterized::Handle& handle);

	void initDefaults(void);

protected:

	virtual const NxParameterized::DefinitionImpl* getParameterDefinitionTree(void);
	virtual const NxParameterized::DefinitionImpl* getParameterDefinitionTree(void) const;


	virtual void getVarPtr(const NxParameterized::Handle& handle, void*& ptr, size_t& offset) const;

private:

	void buildTree(void);
	void initDynamicArrays(void);
	void initStrings(void);
	void initReferences(void);
	void freeDynamicArrays(void);
	void freeStrings(void);
	void freeReferences(void);

	static bool mBuiltFlag;
	static NxParameterized::MutexType mBuiltFlagMutex;
};

class ClothingCookedParamFactory : public NxParameterized::Factory
{
	static const char* const vptr;

public:
	virtual NxParameterized::Interface* create(NxParameterized::Traits* paramTraits)
	{
		// placement new on this class using mParameterizedTraits

		void* newPtr = paramTraits->alloc(sizeof(ClothingCookedParam), ClothingCookedParam::ClassAlignment);
		if (!NxParameterized::IsAligned(newPtr, ClothingCookedParam::ClassAlignment))
		{
			NX_PARAM_TRAITS_WARNING(paramTraits, "Unaligned memory allocation for class ClothingCookedParam");
			paramTraits->free(newPtr);
			return 0;
		}

		memset(newPtr, 0, sizeof(ClothingCookedParam)); // always initialize memory allocated to zero for default values
		return NX_PARAM_PLACEMENT_NEW(newPtr, ClothingCookedParam)(paramTraits);
	}

	virtual NxParameterized::Interface* finish(NxParameterized::Traits* paramTraits, void* bufObj, void* bufStart, physx::PxI32* refCount)
	{
		if (!NxParameterized::IsAligned(bufObj, ClothingCookedParam::ClassAlignment)
		        || !NxParameterized::IsAligned(bufStart, ClothingCookedParam::ClassAlignment))
		{
			NX_PARAM_TRAITS_WARNING(paramTraits, "Unaligned memory allocation for class ClothingCookedParam");
			return 0;
		}

		// Init NxParameters-part
		// We used to call empty constructor of ClothingCookedParam here
		// but it may call default constructors of members and spoil the data
		NX_PARAM_PLACEMENT_NEW(bufObj, NxParameterized::NxParameters)(paramTraits, bufStart, refCount);

		// Init vtable (everything else is already initialized)
		*(const char**)bufObj = vptr;

		return (ClothingCookedParam*)bufObj;
	}

	virtual const char* getClassName()
	{
		return (ClothingCookedParam::staticClassName());
	}

	virtual physx::PxU32 getVersion()
	{
		return (ClothingCookedParam::staticVersion());
	}

	virtual physx::PxU32 getAlignment()
	{
		return (ClothingCookedParam::ClassAlignment);
	}

	virtual const physx::PxU32* getChecksum(physx::PxU32& bits)
	{
		return (ClothingCookedParam::staticChecksum(bits));
	}
};
#endif // NX_PARAMETERIZED_ONLY_LAYOUTS

} // namespace clothing
} // namespace apex
} // namespace physx

#pragma warning(pop)

#endif