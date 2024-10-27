// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BallanceUnreal/SpherePawn.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSpherePawn() {}

// Begin Cross Module References
BALLANCEUNREAL_API UClass* Z_Construct_UClass_ASpherePawn();
BALLANCEUNREAL_API UClass* Z_Construct_UClass_ASpherePawn_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APawn();
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UFloatingPawnMovement_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USphereComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_BallanceUnreal();
// End Cross Module References

// Begin Class ASpherePawn
void ASpherePawn::StaticRegisterNativesASpherePawn()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASpherePawn);
UClass* Z_Construct_UClass_ASpherePawn_NoRegister()
{
	return ASpherePawn::StaticClass();
}
struct Z_Construct_UClass_ASpherePawn_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "SpherePawn.h" },
		{ "ModuleRelativePath", "SpherePawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SphereComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Sphere Component for collision and physics simulation\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "SpherePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Sphere Component for collision and physics simulation" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BallMesh_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Static Mesh for the visual representation of the ball\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "SpherePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Static Mesh for the visual representation of the ball" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpringArm_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Spring Arm and Camera for following the ball\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "SpherePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Spring Arm and Camera for following the ball" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Camera_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "SpherePawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FloatingPawnMovement_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Movement Component\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "SpherePawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Movement Component" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SphereComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BallMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpringArm;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Camera;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FloatingPawnMovement;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASpherePawn>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASpherePawn_Statics::NewProp_SphereComponent = { "SphereComponent", nullptr, (EPropertyFlags)0x004000000008001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASpherePawn, SphereComponent), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SphereComponent_MetaData), NewProp_SphereComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASpherePawn_Statics::NewProp_BallMesh = { "BallMesh", nullptr, (EPropertyFlags)0x004000000008001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASpherePawn, BallMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BallMesh_MetaData), NewProp_BallMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASpherePawn_Statics::NewProp_SpringArm = { "SpringArm", nullptr, (EPropertyFlags)0x004000000008001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASpherePawn, SpringArm), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpringArm_MetaData), NewProp_SpringArm_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASpherePawn_Statics::NewProp_Camera = { "Camera", nullptr, (EPropertyFlags)0x004000000008001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASpherePawn, Camera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Camera_MetaData), NewProp_Camera_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASpherePawn_Statics::NewProp_FloatingPawnMovement = { "FloatingPawnMovement", nullptr, (EPropertyFlags)0x004000000008001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASpherePawn, FloatingPawnMovement), Z_Construct_UClass_UFloatingPawnMovement_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FloatingPawnMovement_MetaData), NewProp_FloatingPawnMovement_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASpherePawn_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpherePawn_Statics::NewProp_SphereComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpherePawn_Statics::NewProp_BallMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpherePawn_Statics::NewProp_SpringArm,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpherePawn_Statics::NewProp_Camera,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASpherePawn_Statics::NewProp_FloatingPawnMovement,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASpherePawn_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ASpherePawn_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APawn,
	(UObject* (*)())Z_Construct_UPackage__Script_BallanceUnreal,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASpherePawn_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ASpherePawn_Statics::ClassParams = {
	&ASpherePawn::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ASpherePawn_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ASpherePawn_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASpherePawn_Statics::Class_MetaDataParams), Z_Construct_UClass_ASpherePawn_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ASpherePawn()
{
	if (!Z_Registration_Info_UClass_ASpherePawn.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASpherePawn.OuterSingleton, Z_Construct_UClass_ASpherePawn_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ASpherePawn.OuterSingleton;
}
template<> BALLANCEUNREAL_API UClass* StaticClass<ASpherePawn>()
{
	return ASpherePawn::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ASpherePawn);
ASpherePawn::~ASpherePawn() {}
// End Class ASpherePawn

// Begin Registration
struct Z_CompiledInDeferFile_FID_unreal_c_Source_BallanceUnreal_SpherePawn_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ASpherePawn, ASpherePawn::StaticClass, TEXT("ASpherePawn"), &Z_Registration_Info_UClass_ASpherePawn, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASpherePawn), 246802134U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_unreal_c_Source_BallanceUnreal_SpherePawn_h_360948734(TEXT("/Script/BallanceUnreal"),
	Z_CompiledInDeferFile_FID_unreal_c_Source_BallanceUnreal_SpherePawn_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_unreal_c_Source_BallanceUnreal_SpherePawn_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
