// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SpherePawn.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef BALLANCEUNREAL_SpherePawn_generated_h
#error "SpherePawn.generated.h already included, missing '#pragma once' in SpherePawn.h"
#endif
#define BALLANCEUNREAL_SpherePawn_generated_h

#define FID_BallanceUnreal_Source_BallanceUnreal_SpherePawn_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASpherePawn(); \
	friend struct Z_Construct_UClass_ASpherePawn_Statics; \
public: \
	DECLARE_CLASS(ASpherePawn, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/BallanceUnreal"), NO_API) \
	DECLARE_SERIALIZER(ASpherePawn)


#define FID_BallanceUnreal_Source_BallanceUnreal_SpherePawn_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ASpherePawn(ASpherePawn&&); \
	ASpherePawn(const ASpherePawn&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASpherePawn); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASpherePawn); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ASpherePawn) \
	NO_API virtual ~ASpherePawn();


#define FID_BallanceUnreal_Source_BallanceUnreal_SpherePawn_h_11_PROLOG
#define FID_BallanceUnreal_Source_BallanceUnreal_SpherePawn_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_BallanceUnreal_Source_BallanceUnreal_SpherePawn_h_14_INCLASS_NO_PURE_DECLS \
	FID_BallanceUnreal_Source_BallanceUnreal_SpherePawn_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BALLANCEUNREAL_API UClass* StaticClass<class ASpherePawn>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_BallanceUnreal_Source_BallanceUnreal_SpherePawn_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
