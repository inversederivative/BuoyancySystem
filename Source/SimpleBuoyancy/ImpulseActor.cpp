// Fill out your copyright notice in the Description page of Project Settings.
#include"ImpulseActor.h"
#include "DrawDebugHelpers.h"
#include "Engine/Engine.h"


// Sets default values for this component's properties
UImpulseActor::UImpulseActor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}





// Called every frame
void UImpulseActor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FHitResult Hit;

	const FVector Start = GetComponentLocation();
	FVector End = Start + GetComponentRotation().Vector() * TraceDistance;


	FCollisionQueryParams TraceParams;

	bool bHit = GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, TraceParams);

	if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, TraceParams))
	{
		if (Hit.bBlockingHit)
		{
			GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, FString::Printf(TEXT("You are hitting: %s"), *Hit.GetActor()->GetName()));
			GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Purple, FString::Printf(TEXT("Impact Point: %s"), *Hit.ImpactPoint.ToString()));
			GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Blue, FString::Printf(TEXT("Normal Point: %s"), *Hit.ImpactNormal.ToString()));
		}
	}

	if (bHit) {
		
		
		DrawDebugLine(GetWorld(), Start, End, FColor::Orange, false, 0.1f);

		UStaticMeshComponent*MeshComponent = Cast<UStaticMeshComponent>(Hit.GetActor()->GetRootComponent());
		
		if (MeshComponent && Hit.GetActor()->IsRootComponentMovable()) 
		{
			FVector Forward = this->GetForwardVector();
			
			MeshComponent->AddImpulse(Forward * ImpulseForce * MeshComponent->GetMass());
		}

	}


}

