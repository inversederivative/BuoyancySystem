// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Materials/MaterialInterface.h>
#include <Kismet/KismetArrayLibrary.h>
#include <Components/PrimitiveComponent.h>
#include <Engine/Engine.h>
#include <Engine/World.h>
#include <KismetProceduralMeshLibrary.h>
#include <ProceduralMeshComponent.h>
#include <Kismet/KismetMathLibrary.h>
#include <Components/SceneComponent.h>
#include <Components/BoxComponent.h>


#include "WaterPlane.generated.h"

UCLASS()
class SIMPLEBUOYANCY_API AWaterPlane : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWaterPlane();
public:

 // all water plane bp variables
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector WaterPlaneLocation;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float WaterDensity;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Gravity;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float NormalAngularDamping;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float NormalLinearDamping;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float WaterAngularDamping;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float WaterLinearDamping;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector WaterVolumeGizmo;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float MeshverticalOffset;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int NumVerticesX;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int NumVerticesY;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FColor VertexColor;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UMaterialInterface* WaterMaterial;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<int>Triangles;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FVector>Vertices;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FVector2D>UV0;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FVector>Normals;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FProcMeshTangent>Tangents;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FColor>VertexColors;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<UPrimitiveComponent*>PrimitivesList;
	//
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	 USceneComponent* p_DefaultSceneRoot;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	 UProceduralMeshComponent* p_WaterProceduralMesh;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	 class UBoxComponent* p_WaterBoxTrigger;



	// all water place bp local variables
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int x;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int y;

	
public:
	// all water plance bp functions
	void InitAllVariables() noexcept(true);
	UFUNCTION(BlueprintCallable)
	void InitRemainingVariables();
	UFUNCTION()
	void InitAllComponent();
public:
	//constructor break functions sequence
	void C_First_Sequence();

	
	void RunConsScript();

	UFUNCTION(BlueprintCallable)
	void test(float tt);
public:
	// overlap functions
	
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// declare overlap end function
	UFUNCTION()
		void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
	void BindOverlapTriggers();

	//
public:
	//Begin play stuff
	UFUNCTION()
void InitialDetectionHackOnBeginPlay();




public:
	//Event tick stuff
	void RunEventTick();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	FTimerHandle _loopTimerHandle;
  
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
