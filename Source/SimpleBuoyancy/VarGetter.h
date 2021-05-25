// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <ProceduralMeshComponent.h>
#include "VarGetter.generated.h"

UCLASS()
class SIMPLEBUOYANCY_API AVarGetter : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVarGetter();

	//

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<FVector>Verticesxx;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<FVector2D>UV0xx;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<FVector>Normalsxx;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<FProcMeshTangent>Tangentsxx;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<FColor>VertexColorsxx;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
